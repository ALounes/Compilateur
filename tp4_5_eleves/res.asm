	inc 1
main:
	push 0
	pushr	0.000000
	move 1
	push 0
	push 0
	copy 1	
	pushr	1.000000
	add
	move 1
	push 0
	copy 1	
	output
	pushr	1.000000
	output
L_while_0:
	push 0
	copy 1	
	pushr	4.000000
	ls
	jf Next_while_0
	push 0
	push 0
	copy 1	
	pushr	1.000000
	add
	move 1
	push 0
	copy 1	
	output
	jp L_while_0
Next_while_0:
	halt
	end
