        CPU     "Z80.TBL"
        HOF     "INT8"
; ***************************************
CW      EQU     8AH
CONPORT EQU     23H
SCAN_C0 EQU     0FEH  ;1111 1110
SCAN_C1 EQU     0FDH  ;1111 1101
SCAN_C2 EQU     0FBH  ;1111 1011
PORTC   EQU     22H
R1      EQU     4
R2      EQU     5
R3      EQU     6
R4      EQU     7
PORTA   EQU     20H

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
        JP      Z, DIGIT_1
        BIT     R2, A
        JP      Z, DIGIT_4
        BIT     R3, A
        JP      Z, DIGIT_7
        BIT     R4, A
        JP      Z, DIGIT_STAR
CONTINUE:
        CALL    DELAY_50M
        JR      BEGIN
;***************************************************
              ORG 8050H
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
;*************************
                ORG 8100H
DELAY_50M:
        PUSH     BC
        LD       BC, 7690H
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
