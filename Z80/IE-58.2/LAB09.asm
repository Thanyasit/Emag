        CPU"Z80.TBL"
        HOF"INT8"
;#############################################
        ORG 8000H
START:
        LD   A,9AH
        OUT  (23H), A
BEGIN:
        LD   HL,FSTEP1_TAB
        LD   D,4
LOOPM:
        LD   A,(HL)
        OUT  (22H),A
        CALL  DELAY1S
        INC   HL
        DEC   D
        JR    NZ,LOOPM

        JR    BEGIN
;*****************************************
        ORG 8100H

DELAY200MS:
        PUSH BC
        LD   BC,30760
LOOPD20:
        DEC  BC
        LD   A,B
        OR   C
        JR   NZ,LOOPD20
        POP  BC
        RET
;#################################
DELAY1S:
        PUSH  DE
        LD    D,5
LOOP1S:
        CALL  DELAY200MS
        DEC   D
        JR    NZ,LOOP1S
        POP   DE
        RET

;**************************************
        ORG  8200H
FSTEP1_TAB:  DFB 01H,02H,04H,08H
;*****************************************
        ORG 8210H
FSTEP2_TAB:  DFB 03H,06H,0BH,09H
;****************************
        ORG 8220H
HSTEP2_TAB:  DFB 01H,03H,02H,06H,04H,0BH,08H,09H,
;******************************
END







