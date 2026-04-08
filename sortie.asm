; Code assembleur 8086 genere par le compilateur MiniAlgo
.MODEL SMALL
.STACK 100h

.DATA
    A DW 0
    B DW 0
    T0 DW 0
    T1 DW 0
    T2 DW 0
    T3 DW 0

.CODE
    MOV AX, @DATA
    MOV DS, AX

    MOV AX, 8
    MOV T0, AX
    MOV AX, T0
    MOV A, AX
    MOV AX, 20
    MOV T1, AX
    MOV AX, T1
    MOV B, AX
    MOV AX, B
    MOV T2, AX
    MOV AX, T2
    MOV B, AX
    MOV AX, A
    MOV T3, AX
    MOV AX, T3
    MOV A, AX
    ; WRITE A
    MOV AX, A
    ; appel affichage
    CALL AFFICHE
    ; WRITE B
    MOV AX, B
    ; appel affichage
    CALL AFFICHE

    ; fin du programme
    MOV AX, 4C00h
    INT 21h

END
