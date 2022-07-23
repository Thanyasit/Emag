        CPU     "Z80.TBL"
        HOF     "INT8"
; ***************************************
R1      EQU     4
R2      EQU     5
R3      EQU     6
R4      EQU     7
SCAN_C0 EQU     0FEH
SCAN_C1 EQU     0FDH
SCAN_C2 EQU     0FBH
PORTC   EQU     22H


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



        RET