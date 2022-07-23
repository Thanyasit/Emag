        CPU     "Z80.TBL"
        HOF     "INT8"
; ***************************************
CW      EQU     9AH
CONPORT EQU     23H
PORTC   EQU     22H
PW      EQU     8380H
SD      EQU     83A0H
R1      EQU     4
R2      EQU     5
R3      EQU     6
R4      EQU     7
SCAN_C0 EQU     0FEH
SCAN_C1 EQU     0FDH
SCAN_C2 EQU     0FBH


       ORG     8000H
MAIN:
        LD      A, CW
        OUT     (CONPORT), A
RESTART:
        LD      HL, PW
        CALL    DISPLAYENTER
        LD      D, 6
        LD      B, 0
LS_SCAN:
        LD      A, 40H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    S_SCAN
        JR      LS_SCAN
;********************************************
         ORG 8030H
R:      LD      (HL), A
        CALL    S_SCAN_2
        INC     HL
        INC     B
        DEC     D
        LD      A, D
        CP      0
        JP      NZ, LS_SCAN
        LD      HL, PW
        LD      BC, SD
        LD      D, 6
LOOPTEST:
        PUSH    DE
        LD      A, (BC)
        LD      D, A
        LD      A, (HL)
        CP      D
        JP      NZ, NOPASS
        INC     HL
        INC     BC
        POP     DE
        DEC     D
        LD      A ,D
        CP      0
        JR      NZ, LOOPTEST
        CALL    PASS
;****************************************
         ORG    8060H
DISPLAYENTER:
        LD      D, 200
LOOP_DR:
        LD      B, 0
        LD      A, 79H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 54H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 07H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 79H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 50H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        DEC     D
        LD      A, D
        CP      0
        JR      NZ, LOOP_DR
        RET
;****************************************
        ORG     8100H
S_SCAN:
        LD      A, SCAN_C0
        OUT     (PORTC), A

        IN      A,(PORTC)

        BIT     R1, A
        JR      Z, DIGIT_1
        BIT     R2, A
        JR      Z, DIGIT_4
        BIT     R3, A
        JR      Z, DIGIT_7
        BIT     R4, A
        JR      Z, DIGIT_D

        CALL    DELAY_10M

        LD      A, SCAN_C1
        OUT     (PORTC), A

        IN      A,(PORTC)

        BIT     R1, A
        JR      Z, DIGIT_2
        BIT     R2, A
        JR      Z, DIGIT_5
        BIT     R3, A
        JR      Z, DIGIT_8
        BIT     R4, A
        JR      Z, DIGIT_0

        CALL    DELAY_10M

        LD      A, SCAN_C2
        OUT     (PORTC), A

        IN      A,(PORTC)

        BIT     R1, A
        JR      Z, DIGIT_3
        BIT     R2, A
        JR      Z, DIGIT_6
        BIT     R3, A
        JR      Z, DIGIT_9
        BIT     R4, A
        JR      Z, DIGIT_CHAB

        CALL    DELAY_10M

        RET
;***********************************************
            ORG 8150H
DIGIT_1:
        LD      A, 1H
        CALL    R
DIGIT_4:
        LD      A, 4H
        CALL    R
DIGIT_7:
        LD      A, 7H
        CALL    R
DIGIT_CHAB:
        LD      A, 0BH
        CALL    R
DIGIT_2:
        LD      A, 2H
        CALL    R
DIGIT_5:
        LD      A, 5H
        CALL    R
DIGIT_8:
        LD      A, 8H
        CALL    R
DIGIT_0:
        LD      A, 0H
        CALL    R
DIGIT_3:
        LD      A, 3H
        CALL    R
DIGIT_6:
        LD      A, 6H
        CALL    R
DIGIT_9:
        LD      A, 9H
        CALL    R
DIGIT_D
        LD      A, 0AH
        CALL    R
;*********************************************
         ORG 8200H
S_SCAN_2:
        LD      A, SCAN_C0
        OUT     (PORTC), A

        IN      A,(PORTC)

        BIT     R1, A
        JR      Z, S_SCAN_2
        BIT     R2, A
        JR      Z, S_SCAN_2
        BIT     R3, A
        JR      Z, S_SCAN_2
        BIT     R4, A
        JR      Z, S_SCAN_2

        CALL    DELAY_10M

        LD      A, SCAN_C1
        OUT     (PORTC), A

        IN      A,(PORTC)

        BIT     R1, A
        JR      Z, S_SCAN_2
        BIT     R2, A
        JR      Z, S_SCAN_2
        BIT     R3, A
        JR      Z, S_SCAN_2
        BIT     R4, A
        JR      Z, S_SCAN_2

        CALL    DELAY_10M

        LD      A, SCAN_C2
        OUT     (PORTC), A

        IN      A,(PORTC)

        BIT     R1, A
        JR      Z, S_SCAN_2
        BIT     R2, A
        JR      Z, S_SCAN_2
        BIT     R3, A
        JR      Z, S_SCAN_2
        BIT     R4, A
        JR      Z, S_SCAN_2

        CALL    DELAY_10M

        RET
;***********************************
           ORG 8250H
PASS:
        LD      E, 2
LOOP_PE:
        LD      D, 188
LOOP_P:
        LD      B, 0
        LD      A, 73H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 77H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 6DH
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 6DH
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        DEC     D
        LD      A ,D
        CP      0
        JR      NZ ,LOOP_P
        DEC     E
        LD      A, E
        CP      0
        JR      NZ ,LOOP_PE
        JP      RESTART
        RET
;****************************
        ORG 82C0H
NOPASS:
        LD      D, 250
LOOP_NP:
        LD      B, 0
        LD      A, 54H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 5CH
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 73H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 77H
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 6DH
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC     B
        LD      A, 6DH
        OUT     (01H), A
        LD      A, B
        OUT     (00H), A
        CALL    DELAY_1M
        LD      A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        DEC     D
        LD      A, D
        CP      0
        JR      NZ, LOOP_NP
        JP      RESTART
;********************************
        ORG 8340H
DELAY_1M:
        PUSH     BC
        LD       BC,153
LOOPA:
        DEC      BC
        LD       A,B
        OR       C
        JR       NZ,LOOPA
        POP      BC
        RET
;*********************************************
        ORG 8350H
DELAY_30M:
        PUSH     BC
        LD       BC,4615
LOOPB:
        DEC      BC
        LD       A,B
        OR       C
        JR       NZ,LOOPB
        POP      BC
        RET
;********************************************
        ORG 8360H
DELAY_10M:
        PUSH     BC
        LD       BC, 1538
LOOPC:
        DEC      BC
        LD       A, B
        OR       C
        JR       NZ, LOOPC
        POP      BC
        RET
;*****************************************