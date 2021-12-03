
BEGIN:	   LXI H,1000
	
	   MOV A,M
	   LXI H,1000
	   LXI D,8050
	   MOV A,M
	   INX H
	   MOV B,M
	   MVI C,08

LOOP:	   RAR
	   JC CHECK
	   MOV H,A
	   MOV A,B
	   RAR
	   MOV B,A

DCRM:	   MOV A,H
	   INR L
	   DCR C
	   JNZ LOOP
	   HLT

CHECK:	   MOV H,A
	   MOV A,B
	   RAR
	   JNC WRITE
	   JMP DCRM

WRITE:	   MOV B,A
	   MOV A,L
	   STAX D
	   INX D
	   JMP DCRM
