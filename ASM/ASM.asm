.586
.model flat, stdcall

includelib kernel32.lib
includelib libucrt.lib
includelib ../Debug/Library.lib

ExitProcess PROTO : DWORD
outtxt PROTO : DWORD
outlit PROTO : SDWORD
copyline PROTO : DWORD,:DWORD
range PROTO : DWORD

.stack 4096

.const
	mesdivbyzero byte 'Divide by zero',0
	mesoverflow byte 'Overflow',0
	T0 byte 'Sum:', 0
	T1 byte 'Sub:', 0
	T2 byte 'Mul:', 0
	T3 byte 'Div:', 0
	L0 sdword 2
	L1 sdword 0
	L2 sdword 1
	L3 sdword 0
	T4 byte '==========', 0
	T5 byte '*AIM-2021*', 0
	T6 byte '==========', 0
	T7 byte 'Ivan', 0
	T8 byte 'Name length: ', 0
	L4 sdword 10
	L5 sdword 5
	T9 byte 'Sum + Sub + Mul + Div: ', 0
	L6 sdword 18
	T10 byte 'Number:', 0
	L7 sdword 18
	L8 sdword 1
	T11 byte 'Even', 0
	T12 byte 'Odd', 0
	T13 byte 'Name', 0
	T14 byte 'Adnomakh', 0
	T15 byte 'Str1:', 0
	T16 byte 'Str2:', 0
	T17 byte 'Str1:', 0
	L9 sdword 0
	L10 sdword 2
	T18 byte 'Text', 0
	L11 sdword 2020
	T19 byte 'HEX: 7E4', 0
	T20 byte 'DEC:', 0
	L12 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	name00000 byte 255 dup(0)
	length00000 sdword ?
	sum00000 sdword ?
	sub00000 sdword ?
	mul00000 sdword ?
	div00000 sdword ?
	result100000 sdword ?
	a00000 sdword ?
	b00000 sdword ?
	value00000 sdword ?
	T0T byte 255 dup(0)
	T1T byte 255 dup(0)
	T2T byte 255 dup(0)
	T3T byte 255 dup(0)
	x00000 sdword ?
	y00000 sdword ?
	z00000 sdword ?
	result200000 sdword ?
	str100000 byte 255 dup(0)
	str200000 byte 255 dup(0)
	resultstr00000 byte 255 dup(0)
	hex00000 sdword ?
	cycleisneg1 dword 0
	cyclestartvalue1 dword 0
	T4T byte 255 dup(0)
	T5T byte 255 dup(0)
	T6T byte 255 dup(0)
	T7T byte 255 dup(0)
	T8T byte 255 dup(0)
	T9T byte 255 dup(0)
	T10T byte 255 dup(0)
	T11T byte 255 dup(0)
	T12T byte 255 dup(0)
	T13T byte 255 dup(0)
	T14T byte 255 dup(0)
	T15T byte 255 dup(0)
	T16T byte 255 dup(0)
	T17T byte 255 dup(0)
	T18T byte 255 dup(0)
	T19T byte 255 dup(0)
	T20T byte 255 dup(0)

.code

proc_lengthname proc, l01000 : ptr dword
	push l01000
	pop edx
	push l01000
	call range
	push eax
	pop length00000
	mov eax,length00000
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
	call ExitProcess
overflow:
	push offset mesoverflow
	call outtxt
	call ExitProcess
toend:
	ret
proc_lengthname endp
proc_calculator proc, number102000 : dword, number202000 : dword
	push number102000
	push number202000
	pop eax
	pop ebx
	add eax, ebx
	push eax
	jo overflow
	pop sum00000
	push offset T0
	call outtxt
	push sum00000
	call outlit
	push number102000
	push number202000
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	jo overflow
	pop sub00000
	push offset T1
	call outtxt
	push sub00000
	call outlit
	push number102000
	push number202000
	pop eax
	pop ebx
	mul ebx
	push eax
	jo overflow
	pop mul00000
	push offset T2
	call outtxt
	push mul00000
	call outlit
	push number102000
	push number202000
	pop ebx
	pop eax
	cmp ebx,0
	je divbyzero
	mov edx,0
	idiv ebx
	push eax
	pop div00000
	push offset T3
	call outtxt
	push div00000
	call outlit
	push sum00000
	push sub00000
	pop eax
	pop ebx
	add eax, ebx
	push eax
	jo overflow
	push mul00000
	pop eax
	pop ebx
	add eax, ebx
	push eax
	jo overflow
	push div00000
	pop eax
	pop ebx
	add eax, ebx
	push eax
	jo overflow
	pop result100000
	mov eax,result100000
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
	call ExitProcess
overflow:
	push offset mesoverflow
	call outtxt
	call ExitProcess
toend:
	ret
proc_calculator endp
proc_mod proc, number03000 : dword
	push number03000
	push L0
	pop ebx
	pop eax
	cmp ebx,0
	je divbyzero
	mov edx,0
	idiv ebx
	push edx
	pop x00000
	push x00000
	push L1
	pop eax
	pop ebx
	cmp eax,ebx
	jne WHENNOT1
	push L2
	pop result200000
jmp OUTWHEN1
WHENNOT1 :
	push L3
	pop result200000
OUTWHEN1 :
	mov eax,result200000
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
	call ExitProcess
overflow:
	push offset mesoverflow
	call outtxt
	call ExitProcess
toend:
	ret
proc_mod endp

main proc
	START :
	push offset T4
	call outtxt
	push offset T5
	call outtxt
	push offset T6
	call outtxt
	push offset T7
	push offset name00000
	call copyline
	push offset name00000
	call outtxt
	push offset name00000
	pop edx
	push offset name00000
	call proc_lengthname
	push eax
	pop length00000
	push offset T8
	call outtxt
	push length00000
	call outlit
	push L4
	pop a00000
	push L5
	pop b00000
	push a00000
	call outlit
	push b00000
	call outlit
	push a00000
	push b00000
	pop edx
	pop edx
	push b00000
	push a00000
	call proc_calculator
	push eax
	pop value00000
	push offset T9
	call outtxt
	push value00000
	call outlit
	push L6
	pop z00000
	push offset T10
	call outtxt
	push L7
	call outlit
	push z00000
	pop edx
	push z00000
	call proc_mod
	push eax
	pop y00000
	push y00000
	push L8
	pop eax
	pop ebx
	cmp eax,ebx
	jne WHENNOT2
	push offset T11
	call outtxt
jmp OUTWHEN2
WHENNOT2 :
	push offset T12
	call outtxt
OUTWHEN2 :
	push offset T13
	push offset str100000
	call copyline
	push offset T14
	push offset str200000
	call copyline
	push offset T15
	call outtxt
	push offset str100000
	call outtxt
	push offset T16
	call outtxt
	push offset str200000
	call outtxt
	push offset str100000
	push offset str200000
	pop edx
	pop edx
	push offset str200000
	push offset str100000
	call copyline
	push eax
	push offset resultstr00000
	call copyline
	push offset T17
	call outtxt
	push offset resultstr00000
	call outtxt
	push L9
	push L10
	pop eax
	pop ebx
	mov edx,eax
	sub eax,ebx
	cmp eax,0
	jl negative1
	mov buffer00000,ebx
	mov cyclestartvalue1,eax
	add eax,1
	mov ecx,eax
	mov eax,0
	mov cycleisneg1,eax
	jmp endcondcycle1
negative1 :
	mov buffer00000,ebx
	mov cyclestartvalue1,edx
	neg eax
	mov ecx,eax
	add ecx,1
	mov eax,1
	mov cycleisneg1,eax
endcondcycle1 :
	push ecx
MARK1:pop ecx
	cmp ecx,0
je MARKOUT1
	sub ecx,1
	push ecx
	mov eax,cycleisneg1
	cmp eax,0
	je iter1
	mov eax,cyclestartvalue1
	pop ecx
	add eax,ecx
	push ecx
	mov buffer00000,eax
	jmp enditer1
iter1:
	mov eax,cyclestartvalue1
	pop ecx
	sub eax,ecx
	push ecx
	mov buffer00000,eax
	enditer1:
	push offset T18
	call outtxt
jmp MARK1
MARKOUT1:
	push L11
	pop hex00000
	push offset T19
	call outtxt
	push offset T20
	call outtxt
	push hex00000
	call outlit
	mov eax,L12
	push 0
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
jmp toend
overflow:
	push offset mesoverflow
	call outtxt
toend:
	call ExitProcess
main endp
end main

