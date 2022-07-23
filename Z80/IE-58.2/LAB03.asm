        CPU     "Z80.TBL"
        HOF     "INT8"
; ***************************************
CW      EQU     89H
CONPORT EQU     23H
PORTC   EQU     22H
PORTA   EQU     20H
PORTB   EQU     21H
FLAG    EQU     8400H
SEC     EQU     8401H
SEC10   EQU     8402H
SEC1    EQU     8403H

        ORG     8000H
MAIN:
        LD      A, CW
        OUT     (CONPORT), A
RESET:
        LD      A, (FLAG)
        RES     0, A
        LD      (FLAG), A
        LD      A, 3FH
        OUT     (PORTA), A
        LD      A, 0C0H
        OUT     (PORTB), A
SW1:
        IN      A, (PORTC)
        BIT     0, A
        JR      NZ, SW1

        CALL    DELAY_10M
SEC0:
        LD      A, 00H
        LD      (SEC), A
COUNT:
        LD      D, 64H
        LD      A, (SEC)
        AND     0FH
        CP      0AH
        JR      NZ, NORMAL
        LD      A, (SEC)
        ADD     A, 06H
        LD      (SEC), A
        AND     0FH
NORMAL:
        LD      (SEC1), A
        LD      A,(SEC)
        SRL     A
        SRL     A
        SRL     A
        SRL     A
        LD      (SEC10), A
        LD      HL, ATAB
        LD      A, (SEC1)
        LD      L, A
        LD      A, (HL)
        OUT     (PORTB), A
        LD      HL, BTAB
        LD      A, (SEC10)
        LD      L, A
        LD      A, (HL)
        OUT     (PORTA), A
DELAY:
        CALL    DELAY_10M
SW_RESET:
        IN      A, (PORTC)
        BIT     2, A
        JR      Z, RESET
SW_STOP:
        IN      A, (PORTC)
        BIT     1, A
        JR      NZ, SW2

        CALL    DELAY_10M

        LD      A, (FLAG)
        SET     0, A
        LD      (FLAG), A
        JR      DCOUNT
SW2:
        IN      A, (PORTC)
        BIT     0, A
        JR      NZ, DCOUNT

        CALL    DELAY_10M

        LD      A, (FLAG)
        RES     0, A
        LD      (FLAG), A
        LD      D, 64H
DCOUNT:
        DEC     D
        LD      A, D
        CP      00
        JR      NZ, DELAY
        LD      A, (FLAG)
        BIT     0, A
        JR      Z, ISEC
        LD      D, 01H
        JR      NZ, DELAY
ISEC:
        LD      A, (SEC)
        INC     A
        LD      (SEC), A
        CP      9AH
        JP      Z, SEC0
        JP      COUNT
;**********************************************
        ORG     8300H
DELAY_10M:
          PUSH     BC
          LD       BC, 0602H
LOOPM:
          DEC      BC
          LD       A, B
          OR       C
          JR       NZ, LOOPM
          POP      BC
          RET

;**************************************************
          ORG 8500H
ATAB: DFB 0C0H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,90H


;**************************************************
          ORG 8600H
BTAB: DFB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH


