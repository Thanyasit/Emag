        CPU     "Z80.TBL"
        HOF     "INT8"
; ***************************************
CW      EQU     8AH
CONPORT EQU     23H
SCAN_C0 EQU     0FEH  ;1111 1110
SCAN_C1 EQU     0FDH  ;1111 1101
SCAN_C2 EQU     0FBH  ;1111 1011
PORTC   EQU     22H
R1      EQU     4 ;0000 0100
R2      EQU     5 ;0000 0101
R3      EQU     6 ;0000 0110
R4      EQU     7 ;0000 0111
PORTA   EQU     20H
PORTB   EQU     21H

        ORG     8000H
MAIN:
        LD      HL, TAB
        LD      A, CW
        OUT     (CONPORT), A
        LD      A, 0FFH
        OUT     (PORTA), A
BEGIN:
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
        JR      Z, DIGIT_STAR

        CALL    DELAY_30M

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

        CALL    DELAY_30M

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
        JR      Z, DIGIT_STAR1
CONTINUE:
        CALL    DELAY_30M
        JR      BEGIN
;******************************
        ORG 8060H
DIGIT_1:
        LD      L, 1
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_4:
        LD      L, 4
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_7:
        LD      L, 7
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_STAR:
        LD      L, 0AH
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_2:
        LD      L, 2
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_5:
        LD      L, 5
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_8:
        LD      L, 8
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_0:
        LD      L, 0
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_3:
        LD      L, 3
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_6:
        LD      L, 6
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_9:
        LD      L, 9
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
DIGIT_STAR1:
        LD      L, 0BH
        LD      A, (HL)
        OUT     (PORTA), A
        JR      CONTINUE
;********************************
        ORG 8100H
DELAY_30M:
        PUSH     BC
        LD       BC, 7012H
LOOPM:
        DEC      BC
        LD       A, B
        OR       C
        JR       NZ, LOOPM
        POP      BC
        RET
;***************************************************
        ORG 8200H
TAB: DFB 0C0H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,90H,89H,0C9H,
END
