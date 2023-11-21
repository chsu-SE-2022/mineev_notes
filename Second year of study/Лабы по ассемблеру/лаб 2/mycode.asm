CODE SEGMENT    ;definition of the program segment
    ORG 100h    
    ASSUME DS:CODE  
Start:  ;entry point to the program      

;var 15
;(a ^ 3) / ((b | 9) * (!c + 1)) - (d & 2)

MOV AX, c
NOT AX
INC AX
MOV BX, b
OR BX, 9
IMUL BX
MOV CX, d
AND CX, 2
SUB CX, AX


INT 21h    

a	DW	1			
b	DW	2			
c	DW	3			
d	DW	4
    
    
CODE ENDS   ;end of the program segment
    END Start   ;determining the entry point to the program