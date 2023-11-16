%MACRO INIT 2
    MOV %1, 20H
    CALL %2
%ENDMACRO
%MACRO INIT2 2
    MOV %1, 0
    CALL %2
%ENDMACRO
MYCODE: segment .code
org 100h
START:
    ;CALL FUNC1
    ;CALL FUNC2
    ;CALL FUNC3
    ;CALL FUNC4
    ;CALL FUNC8
    ;CALL FUNC11
    CALL FUNC12
	MOV AX, 4C00h
	INT 21h
PRINT:
    MOV DWORD[0], "ABCD"
    MOV DWORD[4], "EFGH"
    MOV BYTE[8], 0
RET
;1 
FUNC1:
    MOV BYTE[0], 0
    MOV BYTE [32], 0
    MOV BYTE[64], 0
RET
;2
STR:
    MOV BYTE[BX], 0  
RET
FUNC2:
    INIT BX, STR
RET
;3
FUNC3:
    MOV CX, 2
    MOV SI, 0
    LOOP1:
        MOV DWORD[SI], "####"
        MOV DWORD[SI+20H], "####"
        MOV DWORD[SI+40H], "####"
        ADD SI, 4
    LOOP LOOP1
RET
;4
Z4:
    CALL PRINT
    MOV BX, 0
    M1:
        MOV AH, BYTE[SI]
        INC SI
        CMP AH, 0
        JZ EXIT1
        INC BX
        JNZ M1
    EXIT1:

RET    
FUNC4:
    INIT2 SI, Z4
RET
;5
FUNC8:
    CALL PRINT
    MOV SI, 0H
    MOV BX, 4 ;5-Я ПОЗИЦИЯ
    M2:
        MOV AH, BYTE[SI]
        INC SI
        CMP AH, 0
        JZ EXIT21
        JNZ M2
    EXIT21:
        MOV AH, BYTE[SI]
        MOV BYTE[SI+1], AH
        CMP SI, BX
        JZ EXIT22
        DEC SI
        JNZ EXIT21
    EXIT22:
        MOV BYTE[BX], "#" 
RET

FUNC11:
    MOV SI, 20H
    MOV DWORD[SI], "A,BB"
    MOV DWORD[SI+4], "CCCD"
    MOV DWORD[SI+8], "DD,D"
    MOV BYTE[SI+12], 0
    MOV DX, 0 ;СЧИТАЕМ ЗАПЯТЫЕ
    MOV BX, 0 ;НОМЕР ПОЗИЦИИ - РЕЗУЛЬТАТ
    M3:
        MOV AH, BYTE[SI]
        INC BX
        INC SI
        CMP AH, ","
        JNZ M3
        INC DX
        CMP DX, 2
        JNZ M3
RET

FUNC12:
    MOV SI, 20H
    MOV DWORD[SI], "A   "
    MOV DWORD[SI+4], "C  D"
    MOV DWORD[SI+8], "   D" ;ВСЕГО ПРОБЕЛОВ = 8
    MOV BYTE[SI+12], 0
    MOV BX, 0
    M4:
        MOV AH, BYTE[SI]
        INC SI
        CMP AH, 0
        JZ EXIT4
        CMP AH, " "
        JNZ M4
        INC BX
        JMP M4
    EXIT4:
RET