/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "quad.h"
#include "optim.h"
#include "codegen.h"

extern int nb_ligne;
extern int nb_col;
extern FILE *yyin;
extern char *yytext;

int yylex(void);
void yyerror(const char *s);

/* on garde le type courant quand on declare INTEGER : A, B, C ; */
TypeVar type_courant;
int nb_erreurs = 0;

/* compteur pour generer des etiquettes L0, L1, L2... */
int label_count = 0;

char* label_nouveau(void) {
    static char buf[20];
    sprintf(buf, "L%d", label_count);
    label_count++;
    return buf;
}

#line 103 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MC_PROGRAM = 3,                 /* MC_PROGRAM  */
  YYSYMBOL_MC_DECL = 4,                    /* MC_DECL  */
  YYSYMBOL_MC_ENDDECL = 5,                 /* MC_ENDDECL  */
  YYSYMBOL_MC_BEGIN = 6,                   /* MC_BEGIN  */
  YYSYMBOL_MC_END = 7,                     /* MC_END  */
  YYSYMBOL_MC_INTEGER = 8,                 /* MC_INTEGER  */
  YYSYMBOL_MC_FLOAT = 9,                   /* MC_FLOAT  */
  YYSYMBOL_MC_CONST = 10,                  /* MC_CONST  */
  YYSYMBOL_MC_IF = 11,                     /* MC_IF  */
  YYSYMBOL_MC_ELSE = 12,                   /* MC_ELSE  */
  YYSYMBOL_MC_FOR = 13,                    /* MC_FOR  */
  YYSYMBOL_MC_WHILE = 14,                  /* MC_WHILE  */
  YYSYMBOL_MC_READ = 15,                   /* MC_READ  */
  YYSYMBOL_MC_WRITE = 16,                  /* MC_WRITE  */
  YYSYMBOL_OP_AND = 17,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 18,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 19,                    /* OP_NOT  */
  YYSYMBOL_OP_EQ = 20,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 21,                    /* OP_NEQ  */
  YYSYMBOL_OP_GE = 22,                     /* OP_GE  */
  YYSYMBOL_OP_LE = 23,                     /* OP_LE  */
  YYSYMBOL_OP_GT = 24,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 25,                     /* OP_LT  */
  YYSYMBOL_CST_INT = 26,                   /* CST_INT  */
  YYSYMBOL_CST_FLOAT = 27,                 /* CST_FLOAT  */
  YYSYMBOL_IDF = 28,                       /* IDF  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* ':'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_programme = 44,                 /* programme  */
  YYSYMBOL_declarations = 45,              /* declarations  */
  YYSYMBOL_declaration = 46,               /* declaration  */
  YYSYMBOL_type_decl = 47,                 /* type_decl  */
  YYSYMBOL_liste_var = 48,                 /* liste_var  */
  YYSYMBOL_instructions = 49,              /* instructions  */
  YYSYMBOL_instruction = 50,               /* instruction  */
  YYSYMBOL_affectation = 51,               /* affectation  */
  YYSYMBOL_condition_instr = 52,           /* condition_instr  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_condition = 54,                 /* condition  */
  YYSYMBOL_boucle_for = 55,                /* boucle_for  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_boucle_while = 57,              /* boucle_while  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_ecriture = 60,                  /* ecriture  */
  YYSYMBOL_lecture = 61,                   /* lecture  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_terme = 63,                     /* terme  */
  YYSYMBOL_facteur = 64                    /* facteur  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    31,    29,    38,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    34,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    77,    78,    82,    83,    98,   110,   125,
     126,   130,   139,   151,   152,   156,   157,   158,   159,   160,
     161,   165,   186,   206,   213,   212,   228,   235,   242,   249,
     256,   263,   270,   277,   284,   291,   300,   299,   331,   336,
     330,   354,   361,   376,   387,   397,   405,   415,   430,   438,
     455,   477,   482,   487,   492,   497,   502,   507
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MC_PROGRAM",
  "MC_DECL", "MC_ENDDECL", "MC_BEGIN", "MC_END", "MC_INTEGER", "MC_FLOAT",
  "MC_CONST", "MC_IF", "MC_ELSE", "MC_FOR", "MC_WHILE", "MC_READ",
  "MC_WRITE", "OP_AND", "OP_OR", "OP_NOT", "OP_EQ", "OP_NEQ", "OP_GE",
  "OP_LE", "OP_GT", "OP_LT", "CST_INT", "CST_FLOAT", "IDF", "'+'", "'-'",
  "'*'", "'/'", "':'", "';'", "'['", "']'", "'='", "','", "'('", "')'",
  "'{'", "'}'", "$accept", "programme", "declarations", "declaration",
  "type_decl", "liste_var", "instructions", "instruction", "affectation",
  "condition_instr", "$@1", "condition", "boucle_for", "$@2",
  "boucle_while", "$@3", "$@4", "ecriture", "lecture", "expression",
  "terme", "facteur", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -25,    23,    25,  -100,  -100,   145,    40,  -100,  -100,
      14,  -100,    44,  -100,    16,    53,    84,    61,    49,   -18,
    -100,    74,    92,  -100,    95,    99,   -11,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,    55,    86,   134,  -100,   148,    32,
     149,   123,   150,   102,   102,   102,  -100,  -100,   137,  -100,
      32,  -100,  -100,   144,    88,   -12,   122,    36,  -100,   147,
      32,   141,    96,    -8,    43,   127,   151,  -100,   102,   140,
     143,   -10,    81,    32,    32,   142,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,     0,   152,    56,
     153,   154,  -100,  -100,   103,   155,   156,   157,   158,  -100,
    -100,  -100,   165,  -100,   119,   119,   119,   119,   119,   119,
      36,    36,  -100,  -100,   107,  -100,  -100,  -100,   102,  -100,
    -100,  -100,  -100,  -100,    -1,   102,   159,   129,   172,   135,
    -100,  -100,  -100,   102,    34,   160,    79,  -100,  -100,  -100,
      41,   161,  -100,  -100,    50,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     9,    10,
       0,     3,     0,    14,     0,     0,     0,     0,    12,     0,
       2,     0,     0,    38,     0,     0,     0,    13,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,    11,
       0,    51,    52,    49,     0,     0,     0,    45,    48,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     6,     0,     0,     0,     0,     0,    35,
      53,    32,    33,    14,    30,    31,    28,    29,    26,    27,
      43,    44,    46,    47,     0,    39,    42,    41,     0,    50,
      54,    56,    55,    57,     0,     0,     0,     0,    23,     0,
      14,    22,    24,     0,     0,     0,     0,    40,    14,    36,
       0,     0,    25,    14,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,  -100,  -100,  -100,   -99,  -100,  -100,  -100,
    -100,    20,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   -43,
      89,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,    11,    12,    19,    16,    27,    28,    29,
     135,    55,    30,   141,    31,    41,   126,    32,    33,    56,
      57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    64,    65,     3,   124,    73,    74,    73,    74,     1,
      21,    72,    22,    23,    24,    25,    37,    73,    74,    89,
      38,    82,    83,     4,    44,    94,    45,    26,    75,     5,
      99,   134,    90,   104,   105,   106,   107,   108,   109,   140,
     115,   128,    14,   114,   144,    21,    13,    22,    23,    24,
      25,    50,    21,    17,    22,    23,    24,    25,    51,    52,
      53,    21,    26,    22,    23,    24,    25,    84,    85,    26,
      67,    54,    82,    83,    71,   127,   137,    15,    26,    91,
      87,    18,   129,   142,    36,    82,    83,    34,    35,    46,
     136,    20,   145,   101,   102,    21,   100,    22,    23,    24,
      25,    76,    77,    78,    79,    80,    81,    50,    82,    83,
      82,    83,    26,    39,    51,    52,    53,    69,    70,   139,
      47,   100,    51,    52,    53,    69,    70,    54,    51,    52,
      53,    40,    82,    83,    42,    62,    82,    83,    43,   119,
     125,    62,    76,    77,    78,    79,    80,    81,    82,    83,
       7,    82,    83,     8,     9,    10,    82,    83,    82,    83,
      48,    92,    60,   131,    82,    83,    95,    96,   133,    97,
      98,   110,   111,    66,   112,   113,    49,    59,    61,    68,
      86,    88,    73,   103,   132,    93,   116,   117,     0,     0,
       0,   118,     0,     0,     0,   120,   121,   122,   123,     0,
     130,   138,   143
};

static const yytype_int16 yycheck[] =
{
      43,    44,    45,    28,   103,    17,    18,    17,    18,     3,
      11,    54,    13,    14,    15,    16,    34,    17,    18,    62,
      38,    29,    30,     0,    35,    68,    37,    28,    40,     4,
      40,   130,    40,    76,    77,    78,    79,    80,    81,   138,
      40,    42,    28,    86,   143,    11,     6,    13,    14,    15,
      16,    19,    11,    37,    13,    14,    15,    16,    26,    27,
      28,    11,    28,    13,    14,    15,    16,    31,    32,    28,
      50,    39,    29,    30,    54,   118,    42,    33,    28,    36,
      60,    28,   125,    42,    35,    29,    30,    26,    27,    34,
     133,     7,    42,    73,    74,    11,    40,    13,    14,    15,
      16,    20,    21,    22,    23,    24,    25,    19,    29,    30,
      29,    30,    28,    39,    26,    27,    28,    29,    30,    40,
      34,    40,    26,    27,    28,    29,    30,    39,    26,    27,
      28,    39,    29,    30,    39,    39,    29,    30,    39,    36,
      33,    39,    20,    21,    22,    23,    24,    25,    29,    30,
       5,    29,    30,     8,     9,    10,    29,    30,    29,    30,
      26,    34,    39,    34,    29,    30,    26,    27,    33,    26,
      27,    82,    83,    36,    84,    85,    28,    28,    28,    35,
      33,    40,    17,    41,    12,    34,    34,    34,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    40,    40,    40,    40,    -1,
      41,    41,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    28,     0,     4,    45,     5,     8,     9,
      10,    46,    47,     6,    28,    33,    49,    37,    28,    48,
       7,    11,    13,    14,    15,    16,    28,    50,    51,    52,
      55,    57,    60,    61,    26,    27,    35,    34,    38,    39,
      39,    58,    39,    39,    35,    37,    34,    34,    26,    28,
      19,    26,    27,    28,    39,    54,    62,    63,    64,    28,
      39,    28,    39,    62,    62,    62,    36,    54,    35,    29,
      30,    54,    62,    17,    18,    40,    20,    21,    22,    23,
      24,    25,    29,    30,    31,    32,    33,    54,    40,    62,
      40,    36,    34,    34,    62,    26,    27,    26,    27,    40,
      40,    54,    54,    41,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    62,    40,    34,    34,    37,    36,
      40,    40,    40,    40,    49,    33,    59,    62,    42,    62,
      41,    34,    12,    33,    49,    53,    62,    42,    41,    40,
      49,    56,    42,    41,    49,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    51,    51,    52,    53,    52,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    56,    55,    58,    59,
      57,    60,    61,    62,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     4,     7,     5,     5,     1,
       1,     3,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     4,     7,     7,     0,    12,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     0,    14,     0,     0,
       9,     5,     5,     3,     3,     1,     3,     3,     1,     1,
       4,     1,     1,     3,     4,     4,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programme: MC_PROGRAM IDF MC_DECL declarations MC_ENDDECL MC_BEGIN instructions MC_END  */
#line 68 "parser.y"
        {
            if (nb_erreurs == 0)
                printf("Compilation terminee avec succes.\n");
            else
                printf("Compilation terminee avec %d erreur(s).\n", nb_erreurs);
        }
#line 1258 "parser.tab.c"
    break;

  case 6: /* declaration: type_decl ':' IDF '[' CST_INT ']' ';'  */
#line 84 "parser.y"
        {
            if ((yyvsp[-2].entier) <= 0) {
                printf("Erreur Semantique : ligne %d, taille de tableau invalide pour '%s'\n",
                    nb_ligne, (yyvsp[-4].str));
                nb_erreurs++;
            } else {
                int idx = ts_inserer((yyvsp[-4].str), type_courant, NATURE_TAB, (yyvsp[-2].entier));
                if (idx == -1) {
                    printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                        nb_ligne, (yyvsp[-4].str));
                    nb_erreurs++;
                }
            }
        }
#line 1277 "parser.tab.c"
    break;

  case 7: /* declaration: MC_CONST IDF '=' CST_INT ';'  */
#line 99 "parser.y"
        {
            int idx = ts_inserer((yyvsp[-3].str), TYPE_INTEGER, NATURE_CONST, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                    nb_ligne, (yyvsp[-3].str));
                nb_erreurs++;
            } else {
                ts.entries[idx].val.val_int = (yyvsp[-1].entier);
                ts.entries[idx].is_init = 1;
            }
        }
#line 1293 "parser.tab.c"
    break;

  case 8: /* declaration: MC_CONST IDF '=' CST_FLOAT ';'  */
#line 111 "parser.y"
        {
            int idx = ts_inserer((yyvsp[-3].str), TYPE_FLOAT, NATURE_CONST, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                    nb_ligne, (yyvsp[-3].str));
                nb_erreurs++;
            } else {
                ts.entries[idx].val.val_float = (yyvsp[-1].reel);
                ts.entries[idx].is_init = 1;
            }
        }
#line 1309 "parser.tab.c"
    break;

  case 9: /* type_decl: MC_INTEGER  */
#line 125 "parser.y"
                    { type_courant = TYPE_INTEGER; }
#line 1315 "parser.tab.c"
    break;

  case 10: /* type_decl: MC_FLOAT  */
#line 126 "parser.y"
                    { type_courant = TYPE_FLOAT; }
#line 1321 "parser.tab.c"
    break;

  case 11: /* liste_var: liste_var ',' IDF  */
#line 131 "parser.y"
        {
            int idx = ts_inserer((yyvsp[0].str), type_courant, NATURE_VAR, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                    nb_ligne, (yyvsp[0].str));
                nb_erreurs++;
            }
        }
#line 1334 "parser.tab.c"
    break;

  case 12: /* liste_var: IDF  */
#line 140 "parser.y"
        {
            int idx = ts_inserer((yyvsp[0].str), type_courant, NATURE_VAR, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                    nb_ligne, (yyvsp[0].str));
                nb_erreurs++;
            }
        }
#line 1347 "parser.tab.c"
    break;

  case 21: /* affectation: IDF '=' expression ';'  */
#line 166 "parser.y"
        {
            int idx = ts_rechercher((yyvsp[-3].str));
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                    nb_ligne, (yyvsp[-3].str));
                nb_erreurs++;
            } else if (ts.entries[idx].nature == NATURE_CONST) {
                printf("Erreur Semantique : ligne %d, modification de constante '%s' interdite\n",
                    nb_ligne, (yyvsp[-3].str));
                nb_erreurs++;
            } else {
                if (ts.entries[idx].type == TYPE_INTEGER && (yyvsp[-1].expr).type == 1) {
                    printf("Erreur Semantique : ligne %d, incompatibilite de type pour '%s'\n",
                        nb_ligne, (yyvsp[-3].str));
                    nb_erreurs++;
                }
                generer("=", (yyvsp[-1].expr).nom, "", (yyvsp[-3].str));
                ts.entries[idx].is_init = 1;
            }
        }
#line 1372 "parser.tab.c"
    break;

  case 22: /* affectation: IDF '[' expression ']' '=' expression ';'  */
#line 187 "parser.y"
        {
            int idx = ts_rechercher((yyvsp[-6].str));
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, tableau '%s' non declare\n",
                    nb_ligne, (yyvsp[-6].str));
                nb_erreurs++;
            } else if (ts.entries[idx].nature != NATURE_TAB) {
                printf("Erreur Semantique : ligne %d, '%s' n'est pas un tableau\n",
                    nb_ligne, (yyvsp[-6].str));
                nb_erreurs++;
            } else {
                char buf[30];
                sprintf(buf, "%s[%s]", (yyvsp[-6].str), (yyvsp[-4].expr).nom);
                generer("=", (yyvsp[-1].expr).nom, "", buf);
            }
        }
#line 1393 "parser.tab.c"
    break;

  case 23: /* condition_instr: MC_IF '(' condition ')' '{' instructions '}'  */
#line 207 "parser.y"
        {
            char lbl_fin[20];
            strcpy(lbl_fin, label_nouveau());
            generer("LABEL", lbl_fin, "", "");
        }
#line 1403 "parser.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 213 "parser.y"
        {
            char *lbl_else_fin = label_nouveau();
            generer("BR", "", "", lbl_else_fin);
            char *lbl_else = label_nouveau();
            generer("LABEL", lbl_else, "", "");
        }
#line 1414 "parser.tab.c"
    break;

  case 25: /* condition_instr: MC_IF '(' condition ')' '{' instructions '}' MC_ELSE $@1 '{' instructions '}'  */
#line 220 "parser.y"
        {
            char lbl[20];
            sprintf(lbl, "L%d", label_count - 2);
            generer("LABEL", lbl, "", "");
        }
#line 1424 "parser.tab.c"
    break;

  case 26: /* condition: expression OP_GT expression  */
#line 229 "parser.y"
        {
            char *t = temp_nouveau();
            generer(">", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1435 "parser.tab.c"
    break;

  case 27: /* condition: expression OP_LT expression  */
#line 236 "parser.y"
        {
            char *t = temp_nouveau();
            generer("<", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1446 "parser.tab.c"
    break;

  case 28: /* condition: expression OP_GE expression  */
#line 243 "parser.y"
        {
            char *t = temp_nouveau();
            generer(">=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1457 "parser.tab.c"
    break;

  case 29: /* condition: expression OP_LE expression  */
#line 250 "parser.y"
        {
            char *t = temp_nouveau();
            generer("<=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1468 "parser.tab.c"
    break;

  case 30: /* condition: expression OP_EQ expression  */
#line 257 "parser.y"
        {
            char *t = temp_nouveau();
            generer("==", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1479 "parser.tab.c"
    break;

  case 31: /* condition: expression OP_NEQ expression  */
#line 264 "parser.y"
        {
            char *t = temp_nouveau();
            generer("!=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1490 "parser.tab.c"
    break;

  case 32: /* condition: condition OP_AND condition  */
#line 271 "parser.y"
        {
            char *t = temp_nouveau();
            generer("&&", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1501 "parser.tab.c"
    break;

  case 33: /* condition: condition OP_OR condition  */
#line 278 "parser.y"
        {
            char *t = temp_nouveau();
            generer("||", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1512 "parser.tab.c"
    break;

  case 34: /* condition: OP_NOT condition  */
#line 285 "parser.y"
        {
            char *t = temp_nouveau();
            generer("!", (yyvsp[0].expr).nom, "", t);
            strcpy((yyval.expr).nom, t);
            (yyval.expr).type = 0;
        }
#line 1523 "parser.tab.c"
    break;

  case 35: /* condition: '(' condition ')'  */
#line 292 "parser.y"
        {
            strcpy((yyval.expr).nom, (yyvsp[-1].expr).nom);
            (yyval.expr).type = (yyvsp[-1].expr).type;
        }
#line 1532 "parser.tab.c"
    break;

  case 36: /* $@2: %empty  */
#line 300 "parser.y"
        {
            int idx = ts_rechercher((yyvsp[-7].str));
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                    nb_ligne, (yyvsp[-7].str));
                nb_erreurs++;
            }
            /* i = debut */
            generer("=", (yyvsp[-5].expr).nom, "", (yyvsp[-7].str));
            /* label debut de boucle */
            char *lbl_deb = label_nouveau();
            generer("LABEL", lbl_deb, "", "");
        }
#line 1550 "parser.tab.c"
    break;

  case 37: /* boucle_for: MC_FOR '(' IDF ':' expression ':' expression ':' expression ')' $@2 '{' instructions '}'  */
#line 314 "parser.y"
        {
            /* i = i + pas */
            char *t = temp_nouveau();
            generer("+", (yyvsp[-11].str), (yyvsp[-7].expr).nom, t);
            generer("=", t, "", (yyvsp[-11].str));
            /* verifier condition : i <= fin */
            char *cond = temp_nouveau();
            generer("<=", (yyvsp[-11].str), (yyvsp[-5].expr).nom, cond);
            /* si vrai, on retourne au debut */
            char lbl_deb[20];
            sprintf(lbl_deb, "L%d", label_count - 1);
            generer("BNZ", cond, "", lbl_deb);
        }
#line 1568 "parser.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 331 "parser.y"
        {
            char *lbl = label_nouveau();
            generer("LABEL", lbl, "", "");
        }
#line 1577 "parser.tab.c"
    break;

  case 39: /* $@4: %empty  */
#line 336 "parser.y"
        {
            char *lbl = label_nouveau();
            generer("BZ", (yyvsp[-1].expr).nom, "", lbl);
        }
#line 1586 "parser.tab.c"
    break;

  case 40: /* boucle_while: MC_WHILE $@3 '(' condition ')' $@4 '{' instructions '}'  */
#line 341 "parser.y"
        {
            /* retour au debut de la boucle */
            char lbl_deb[20];
            sprintf(lbl_deb, "L%d", label_count - 2);
            generer("BR", "", "", lbl_deb);
            /* fin de boucle */
            char lbl_fin[20];
            sprintf(lbl_fin, "L%d", label_count - 1);
            generer("LABEL", lbl_fin, "", "");
        }
#line 1601 "parser.tab.c"
    break;

  case 41: /* ecriture: MC_WRITE '(' expression ')' ';'  */
#line 355 "parser.y"
        {
            generer("WRITE", (yyvsp[-2].expr).nom, "", "");
        }
#line 1609 "parser.tab.c"
    break;

  case 42: /* lecture: MC_READ '(' IDF ')' ';'  */
#line 362 "parser.y"
        {
            int idx = ts_rechercher((yyvsp[-2].str));
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                    nb_ligne, (yyvsp[-2].str));
                nb_erreurs++;
            } else {
                generer("READ", "", "", (yyvsp[-2].str));
                ts.entries[idx].is_init = 1;
            }
        }
#line 1625 "parser.tab.c"
    break;

  case 43: /* expression: expression '+' terme  */
#line 377 "parser.y"
        {
            char *t = temp_nouveau();
            generer("+", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            /* si un des deux est FLOAT, le resultat est FLOAT */
            if ((yyvsp[-2].expr).type == 1 || (yyvsp[0].expr).type == 1)
                (yyval.expr).type = 1;
            else
                (yyval.expr).type = 0;
        }
#line 1640 "parser.tab.c"
    break;

  case 44: /* expression: expression '-' terme  */
#line 388 "parser.y"
        {
            char *t = temp_nouveau();
            generer("-", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            if ((yyvsp[-2].expr).type == 1 || (yyvsp[0].expr).type == 1)
                (yyval.expr).type = 1;
            else
                (yyval.expr).type = 0;
        }
#line 1654 "parser.tab.c"
    break;

  case 45: /* expression: terme  */
#line 398 "parser.y"
        {
            strcpy((yyval.expr).nom, (yyvsp[0].expr).nom);
            (yyval.expr).type = (yyvsp[0].expr).type;
        }
#line 1663 "parser.tab.c"
    break;

  case 46: /* terme: terme '*' facteur  */
#line 406 "parser.y"
        {
            char *t = temp_nouveau();
            generer("*", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            if ((yyvsp[-2].expr).type == 1 || (yyvsp[0].expr).type == 1)
                (yyval.expr).type = 1;
            else
                (yyval.expr).type = 0;
        }
#line 1677 "parser.tab.c"
    break;

  case 47: /* terme: terme '/' facteur  */
#line 416 "parser.y"
        {
            /* verifier division par zero */
            if (strcmp((yyvsp[0].expr).nom, "0") == 0) {
                printf("Erreur Semantique : ligne %d, division par zero\n", nb_ligne);
                nb_erreurs++;
            }
            char *t = temp_nouveau();
            generer("/", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            if ((yyvsp[-2].expr).type == 1 || (yyvsp[0].expr).type == 1)
                (yyval.expr).type = 1;
            else
                (yyval.expr).type = 0;
        }
#line 1696 "parser.tab.c"
    break;

  case 48: /* terme: facteur  */
#line 431 "parser.y"
        {
            strcpy((yyval.expr).nom, (yyvsp[0].expr).nom);
            (yyval.expr).type = (yyvsp[0].expr).type;
        }
#line 1705 "parser.tab.c"
    break;

  case 49: /* facteur: IDF  */
#line 439 "parser.y"
        {
            int idx = ts_rechercher((yyvsp[0].str));
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                    nb_ligne, (yyvsp[0].str));
                nb_erreurs++;
                strcpy((yyval.expr).nom, (yyvsp[0].str));
                (yyval.expr).type = 0;
            } else {
                strcpy((yyval.expr).nom, (yyvsp[0].str));
                if (ts.entries[idx].type == TYPE_FLOAT)
                    (yyval.expr).type = 1;
                else
                    (yyval.expr).type = 0;
            }
        }
#line 1726 "parser.tab.c"
    break;

  case 50: /* facteur: IDF '[' expression ']'  */
#line 456 "parser.y"
        {
            int idx = ts_rechercher((yyvsp[-3].str));
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, tableau '%s' non declare\n",
                    nb_ligne, (yyvsp[-3].str));
                nb_erreurs++;
            } else if (ts.entries[idx].nature != NATURE_TAB) {
                printf("Erreur Semantique : ligne %d, '%s' n'est pas un tableau\n",
                    nb_ligne, (yyvsp[-3].str));
                nb_erreurs++;
            }
            char *t = temp_nouveau();
            char buf[30];
            sprintf(buf, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].expr).nom);
            generer("=", buf, "", t);
            strcpy((yyval.expr).nom, t);
            if (idx != -1 && ts.entries[idx].type == TYPE_FLOAT)
                (yyval.expr).type = 1;
            else
                (yyval.expr).type = 0;
        }
#line 1752 "parser.tab.c"
    break;

  case 51: /* facteur: CST_INT  */
#line 478 "parser.y"
        {
            sprintf((yyval.expr).nom, "%d", (yyvsp[0].entier));
            (yyval.expr).type = 0;
        }
#line 1761 "parser.tab.c"
    break;

  case 52: /* facteur: CST_FLOAT  */
#line 483 "parser.y"
        {
            sprintf((yyval.expr).nom, "%.2f", (yyvsp[0].reel));
            (yyval.expr).type = 1;
        }
#line 1770 "parser.tab.c"
    break;

  case 53: /* facteur: '(' expression ')'  */
#line 488 "parser.y"
        {
            strcpy((yyval.expr).nom, (yyvsp[-1].expr).nom);
            (yyval.expr).type = (yyvsp[-1].expr).type;
        }
#line 1779 "parser.tab.c"
    break;

  case 54: /* facteur: '(' '+' CST_INT ')'  */
#line 493 "parser.y"
        {
            sprintf((yyval.expr).nom, "%d", (yyvsp[-1].entier));
            (yyval.expr).type = 0;
        }
#line 1788 "parser.tab.c"
    break;

  case 55: /* facteur: '(' '-' CST_INT ')'  */
#line 498 "parser.y"
        {
            sprintf((yyval.expr).nom, "%d", -(yyvsp[-1].entier));
            (yyval.expr).type = 0;
        }
#line 1797 "parser.tab.c"
    break;

  case 56: /* facteur: '(' '+' CST_FLOAT ')'  */
#line 503 "parser.y"
        {
            sprintf((yyval.expr).nom, "%.2f", (yyvsp[-1].reel));
            (yyval.expr).type = 1;
        }
#line 1806 "parser.tab.c"
    break;

  case 57: /* facteur: '(' '-' CST_FLOAT ')'  */
#line 508 "parser.y"
        {
            sprintf((yyval.expr).nom, "%.2f", -(yyvsp[-1].reel));
            (yyval.expr).type = 1;
        }
#line 1815 "parser.tab.c"
    break;


#line 1819 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 514 "parser.y"


void yyerror(const char *s) {
    printf("Erreur Syntaxique : ligne %d, colonne %d, %s (pres de '%s')\n",
        nb_ligne, nb_col, s, yytext);
    nb_erreurs++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s fichier.algo\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Impossible d'ouvrir le fichier %s\n", argv[1]);
        return 1;
    }

    printf("=== Compilation de %s ===\n\n", argv[1]);

    ts_init();
    quad_init();

    yyparse();

    fclose(yyin);

    ts_afficher();
    quad_afficher();

    if (nb_erreurs == 0) {
        /* optimisation du code intermediaire */
        optimiser();
        quad_afficher_optimise();

        /* generation du code assembleur 8086 */
        generer_asm8086("sortie.asm");
    }

    return (nb_erreurs > 0) ? 1 : 0;
}
