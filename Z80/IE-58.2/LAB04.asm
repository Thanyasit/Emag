        CPU     "Z80.TBL"
        HOF     "INT8"
; ***************************************
CW      EQU     8AH
CONPORT EQU     23H
PORTC   EQU     22H
PORTA   EQU     20H
PWA     EQU     8301H
SCAN_C0 EQU     0FEH  ;1111 1110
SCAN_C1 EQU     0FDH  ;1111 1101
SCAN_C2 EQU     0FBH  ;1111 1011
R1      EQU     4
R2      EQU     5
R3      EQU     6
R4      EQU     7
SEGMBIT EQU     8300H
SD      EQU     82E0H


        ORG     8000H
MAIN:
        LD      A, CW
        OUT     (CONPORT), A
RESTART:
        LD      HL, PWA
        LD      A, 0FEH
        LD      (SEGMBIT), A
        OUT     (PORTA), A
        LD      D, 00H
LOOP:
        CALL    S_SCAN
        JR      LOOP
;****************************************
        ORG     8050H
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
        JR      Z, DIGIT_ENTER

        CALL    DELAY_10M

        RET
;*********************************************
            ORG 80B0H
DIGIT_1:
        LD      A, 0F9H
        CALL    ENTER
DIGIT_4:
        LD      A, 99H
        CALL    ENTER
DIGIT_7:
        LD      A, 0F8H
        CALL    ENTER
DIGIT_ENTER:
        LD      A, 86H
        CALL    ENTER
DIGIT_2:
        LD      A, 0A4H
        CALL    ENTER
DIGIT_5:
        LD      A, 92H
        CALL    ENTER
DIGIT_8:
        LD      A, 80H
        CALL    ENTER
DIGIT_0:
        LD      A, 0C0H
        CALL    ENTER
DIGIT_3:
        LD      A, 0B0H
        CALL    ENTER
DIGIT_6:
        LD      A, 82H
        CALL    ENTER
DIGIT_9:
        LD      A, 90H
        CALL    ENTER
;*****************************************
        ORG     8100H
ENTER:
        LD      (SD) ,A
        CALL    DELAY_30M
        LD      A, (SD)
        CP      86H
        JR      Z, DISPLAY
        LD      (HL), A
        INC     HL
        INC     D
        LD      A, (SEGMBIT)
        RLC     A
        CP      7FH
        JR      NZ, SB
        LD      A, 0FEH
SB:
        LD      (SEGMBIT), A
        OUT     (PORTA), A
        CALL     S_SCAN_2
        CALL     DELAY_30M
LOOP1:
        CALL     S_SCAN
        JR       LOOP1
        RET
;********************************************
        ORG     8150H
DISPLAY:
        LD      A, 0BFH
        OUT     (PORTA), A
        LD      A, SCAN_C0
        OUT     (PORTC), A

        IN      A,(PORTC)
        BIT     R4, A
        JR      NZ, DISPLAY
        LD      HL, PWA
DCOUNT:
        LD      A, (HL)
        OUT     (PORTA), A
        CALL    DELAY_1S
        INC     HL
        DEC     D
        LD      A,  D
        CP      0
        JR      NZ, DCOUNT
        JP      RESTART
;**************************************
        ORG      81A0H
DELAY_30M:
        LD       BC, 7012H
LOOPM:
        DEC      BC
        LD       A, B
        OR       C
        JR       NZ, LOOPM
        RET
;****************************************
          ORG     81B0H
DELAY_1S:
         PUSH     DE
         LD       B, 05H
LOOS:
         LD       DE, 7831H
LOOPC:
         DEC      DE
         LD       A, D
         OR       E
         JR       NZ, LOOPC
         DJNZ     LOOS
         POP      DE
         RET
;*****************************************
        ORG      81C0H
DELAY_10M:
        LD       BC, 0600H
LOOPB:
        DEC      BC
        LD       A, B
        OR       C
        JR       NZ, LOOPB
        RET
;******************************************
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

        CALL    DELAY_10M

        RET
;*************************************
