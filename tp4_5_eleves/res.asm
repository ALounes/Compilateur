main:
	push 0
	move 1
	push	0
	copy 1	
	pushr	1.000000
	ls
	jf Else_if_0
	push	0
	copy 1	
	output
	jp Next_if_0
Else_if_0
	pushr	3.000000
	output
Next_if_0:
L_while_1:
	push	0
	copy 1	
	pushr	2.000000
	ls
	jf Next_while_1
	push 0
	move 1
	push	0
	copy 1	
	output
	jp L_while_1
Next_while_1:
	halt
	end
