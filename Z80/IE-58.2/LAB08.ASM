        CPU     "Z80.TBL"
        HOF     "INT8"
; **************************************

        ORG  8000H
START:
        LD A,80H       ;control word
        OUT (03H),A
LOOPM:
        LD HL, TAB     ;HL point to TAB
;Display digit 1
        LD A,(HL)
        OUT (01H),A
        LD A,0
        OUT (00H),A
        CALL DELAY
        LD A,0
        OUT (01H),A
;Display digit 2
        INC HL
        LD A,(HL)
        OUT (01H),A
        LD A,1
        OUT (00H),A
        CALL DELAY
        LD A,0
        OUT (01H),A
;Display digit 3
        INC HL
        LD A,(HL)
        OUT (01H),A
        LD A,2
        OUT (00H),A
        CALL DELAY
        LD A,0
        OUT (01H),A
;Display digit 4
        INC HL
        LD A,(HL)
        OUT (01H),A
        LD A,3
        OUT (00H),A
        CALL DELAY
        LD A,0
        OUT (01H),A
;Display digit 5
        INC HL
        LD A,(HL)
        OUT (01H),A
        LD A,4
        OUT (00H),A
        CALL DELAY
        LD A,0
        OUT (01H),A
;Display digit 6
        INC HL
        LD A,(HL)
        OUT (01H),A
        LD A,5
        OUT (00H),A
        CALL DELAY
        LD A,0
        OUT (01H),A

        JR LOOPM

;***************************************
        ORG 8100H
DELAY:
        PUSH BC
        LD BC,153
LOOPD:
        DEC BC
        LD A,B
        OR C
        JR NZ,LOOPD
        POP BC
        RET
;**************************************
        ORG 8200H
TAB: DFB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH
;*************************************
END