CODE SEGMENT    ;definition of the program segment
    ORG 100h    
    ASSUME DS:CODE  
Start:  ;entry point to the program     
;var 15
;a/(b*(c+1))-d
    MOV AX, c   ;declare AX=c
    ADD AX, 1   ;add AX=c+1
   
    MOV BX, b   ;declare BX=b
    IMUL BX     ;multiplication AX*BX
    
    MOV CX, AX  ;declare AX=CX
    MOV AX, a   ;declare AX=a
    IDIV CL     ;divide AX\CL
   
    MOV DX, d   ;declare DX=d
    SUB CX, DX  ;substract DX-CX, store CX 
    
    INT 21h     ;calling the DOS termination function
    
a   DW 120  ;definition of variable a
b   DW 3    ;definition of variable b
c   DW 1    ;definition of variable c
d   DW 1    ;definition of variable d 
CODE ENDS   ;end of the program segment
    END Start   ;determining the entry point to the program
