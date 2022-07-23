            CPU     "Z80.TBL"
            HOF     "INT8"
; ***************************************
CW        EQU       8BH
CONPORT   EQU       23H
PORTC     EQU       22H
PORTA     EQU       20H
FRFLAG    EQU       8150H
SPEEDVC   EQU       8151H
STEPCOUNT EQU       8152H
MUXDISP   EQU       8153H




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
STOPSW:
        LD      A, 01
        OUT     (01H), A
        LD       A, 0
        OUT     (00H), A
        CALL    DELAY_1M
        LD       A, 0
        OUT     (01H), A
        CALL    DELAY_1M
        JR      STOPSW
;***********************************
        ORG     8090H
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
;**************************************
        ORG 8100H
FSTEPTAB1:  DFB 01H,02H,04H,08H
;****************************************
        ORG 8104H
FSTEPTAB2:  DFB 03H,06H,0BH,09H
;****************************
        ORG 8108H
HSTEPTAB:  DFB 09H,08H,0BH,04H,06H,02H,03H,01H
;******************************
        ORG 8110H
DISPFTAB1:  DFB 0F1H,0CFH,92H,8CH,0CFH,0F9H
;*********************************
        ORG 8116H
DISPFTAB2:  DFB 0F1H,0CFH,92H,8CH,0CFH,0A4H
;*********************************
        ORG 811CH
DISPFTAB3:  DFB 0F1H,0CFH,92H,8CH,0CFH,0B0H
;*********************************
        ORG 8122H
DISPRTAB1:  DFB 0AFH,0CFH,92H,8CH,0CFH,0F9H
;*********************************
        ORG 8128H
DISPRTAB2:  DFB 0AFH,0CFH,92H,8CH,0CFH,0A4H
;*********************************
        ORG 812EH
DISPRTAB3:  DFB 0AFH,0CFH,92H,8CH,0CFH,0B0H
;*********************************
        ORG 8134H
DISPTAB4:  DFB  0BFH,0BFH,0BFH,0BFH,0BFH,0C0H
;*********************************






















