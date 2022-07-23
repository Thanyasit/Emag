            CPU     "Z80.TBL"
            HOF     "INT8"
; ***************************************
CW        EQU       8BH
CONPORT   EQU       23H
PORTC     EQU       22H
PORTA     EQU       20H
FRFLAG    EQU       8250H
SPEEDVC   EQU       8251H
STEPCOUNT EQU       8252H
MUXDISP   EQU       8253H





      ORG     8000H
MAIN:
        LD      A ,CW
        OUT     (CONPORT) ,A
        LD      HL ,FSTEPTAB1
        LD      BC ,DISPFTAB1
        LD      A, 0H
        LD      (STEPCOUNT), A
        LD      A, 15H
        LD      (SPEEDVC), A
M:
        CALL    MUX
        IN      A, (PORTC)
        BIT     3, A
        JR      NZ, M
        CALL    DELAY_20M
STOPSW:
        IN      A, (PORTC)
        BIT     4, A
        JR      NZ, FSW
        CALL    DELAY_20M
        LD      BC, DISPTAB4
        JR      M
FSW:
        IN      A, (PORTC)
        BIT     5, A
        JR      NZ, REVSW
        CALL    DELAY_20M
        LD      A, 1
        LD      (FRFLAG), A
REVSW:
        IN      A,  (PORTC)
        BIT     6, A
        JR      NZ, SPEEDSW
        CALL    DELAY_20M
        LD      A, 0
        LD      (FRFLAG), A
SPEEDSW:
        IN      A,  (PORTC)
        BIT     7, A
        JR      NZ, DRIVEMOTER
        CALL    DELAY_20M
        CALL    SPEEDLEVEL
DRIVEMOTER:
        LD      A, (STEPCOUNT)
        LD      L, A
        LD      A, (HL)
        OUT     (PORTA), A
        PUSH    DE
        LD      A, (SPEEDVC)
        LD      D, A
SPEED:
        CALL    MUX
        DEC     D
        LD      A, D
        CP      0
        JR      NZ, SPEED
        POP     DE
        LD      A, (FRFLAG)
        CP      1
        JR      NZ, DSTEPC
        LD      A, (STEPCOUNT)
        INC     A
        CP      4
        JR      NZ, SECON
        LD      A, 0
        JR      SECON
DSTEPC:
        LD      A, (STEPCOUNT)
        DEC     A
        CP      -1
        JR      NZ, SECON
        LD      A, 4
        JR      SECON
SECON:
        LD      (STEPCOUNT), A
        JR      STOPSW
;***********************************
        ORG     809FH
MUX:
        LD       A, (MUXDISP)
        LD       C, A
        LD       A, (BC)
        OUT     (01H), A
        LD       A, C
        OUT     (00H), A
        CALL    DELAY_1M
        LD       A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        INC      C
        LD       A, C
        CP       6
        JR       NZ, CP6
        LD       A, 0
CP6:
        LD       C, A
        LD       (MUXDISP), A
        RET
;***********************************
        ORG    8130H
SPEEDLEVEL:
        IN      A, (PORTC)
        AND     07H
        CP      01H
        JR      NZ, MID
        LD      A, 15
        LD      (SPEEDVC), A
        LD      A, (FRFLAG)
        CP      1
        JR      NZ, LOR1
        LD      BC, DISPFTAB1
LOR1:
        LD      BC, DISPRTAB1
        JR      SRET
MID:
        CP      02H
        JR      NZ, MAX
        LD      A, 50
        LD      (SPEEDVC), A
        LD      A, (FRFLAG)
        CP      1
        JR      NZ, LOR2
        LD      BC, DISPFTAB2
        JR      SRET
LOR2:
        LD      BC, DISPRTAB2
        JR      SRET
MAX:
        CP      04H
        JR      NZ, SRET
        LD      A, 250
        LD      (SPEEDVC), A
        LD      A, (FRFLAG)
        CP      1
        JR      NZ, LOR3
        LD      BC, DISPFTAB1
        JR      SRET
LOR3:
        LD      BC, DISPRTAB1
SRET:
        JP      DRIVEMOTER
;*****************************
        ORG      80E5H
DELAY_1M:
        PUSH     BC
        LD       BC, 153
LOOP:
        DEC      BC
        LD       A, B
        OR       C
        JR       NZ, LOOP
        POP      BC
        RET
;*****************************
        ORG      80F0H
DELAY_20M:
        PUSH     BC
        LD       BC, 3076
LOOPB:
        DEC      BC
        LD       A, B
        OR       C
        JR       NZ, LOOPB
        POP      BC
        RET
;**************************************
        ORG 8100H
FSTEPTAB1:  DFB 01H,02H,04H,08H
;****************************************
        ORG 8104H
FSTEPTAB2:  DFB 03H,06H,0BH,09H
;****************************
        ORG 8108H
HSTEPTAB:  DFB 09H,08H,0BH,04H,06H,02H,03H,01H
;*****************************
        ORG 8200H
DISPFTAB1:  DFB 71H,30H,6DH,73H,30H,06H
;*********************************
        ORG 8300H
DISPFTAB2:  DFB 71H,30H,6DH,73H,30H,5BH
;*********************************
        ORG 8400H
DISPFTAB3:  DFB 71H,30H,6DH,73H,30H,4FH
;*********************************
        ORG 8500H
DISPRTAB1:  DFB 50H,30H,6DH,73H,30H,06H
;*********************************
        ORG 8600H
DISPRTAB2:  DFB 50H,30H,6DH,73H,30H,5BH
;*********************************
        ORG 8700H
DISPRTAB3:  DFB 50H,30H,6DH,73H,30H,4FH
;*********************************
        ORG 8800H
DISPTAB4:  DFB  40H,40H,40H,40H,40H,3FH
;*********************************






















