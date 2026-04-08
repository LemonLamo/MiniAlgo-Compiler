CC = gcc
CFLAGS = -Wall
FLEX = flex
BISON = bison
TARGET = minialgo

# fix permission issue sur Windows
export TMPDIR = .
export TMP = .
export TEMP = .

all: $(TARGET)

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) lexer.l

$(TARGET): parser.tab.c lex.yy.c ts.c quad.c
	$(CC) $(CFLAGS) -o $(TARGET) parser.tab.c lex.yy.c ts.c quad.c

clean:
	rm -f parser.tab.c parser.tab.h lex.yy.c $(TARGET).exe $(TARGET)

test: $(TARGET)
	./$(TARGET) tests/test1.algo

.PHONY: all clean test
