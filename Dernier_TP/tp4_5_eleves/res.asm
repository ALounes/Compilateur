	inc 5
	jp main
F001:
	savebp 
	push 0
	cont
	push 1
	cont
	add
	output
	pushr	123.000000
	output
	rstrbp 
	ret 
main:
	pushr	666.000000
	output
	call F001
	pushr	444.000000
	output
	halt
	end
