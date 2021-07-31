;Justin Liu, jl8wf	Date:10/25/2020		Filename: linearSearch.s

	global linearSearch

	section .text



; Parameter 1 is a pointer to the int array, rdi
; Parameter 2 is the size of the array, rsi
; Parameter 3 is the target number to be found, rdx
	; to be found iteratively, loops 
	; Return type is int, -1 if not found
	;; rdi, rsi, rdx, rcx, r8, r9

linearSearch:
	;; basic idea: compare i to size-1 first to know whether still in bound
	;; [rdi] compared to target, if equal, set rax to index, r10 
	;; if not, increase rdi by 4 (actual i++), inc r10 to rep i++, jump back to loop.
	;; if i = size -1 and still not found, set rax to r11, -1
	;; if i = size , return rax

	;; prologue
	push	rdi		;store base address
	push 	rsi		;store size of array to be able to compare repeatedly
	push 	rdx		;store target number
	dec 	rsi		;to get size - 1
	push 	rcx		;store so we can restore later
	mov  	rcx, rsi	;rcx = size - 1		;store OG r8, and used for a[i]
	xor  	r10, r10	;int i = 0
	xor  	r11, r11	;value of -1 if target not found
	dec  	r11
	inc	rsi		;rsi = OG size
loop:
	cmp 	r10, rsi	;if i = n, jump to done
	je  	done
	jl	compare		;jump if i < n
compare:
	cmp	edx, [rdi + r10*4];compares target to what rsp is pointing at,   error? at [rdi]
	je	found		;if equal, go to found
	cmp	r10, rcx	;if i = size - 1, jump to not found
	je	notFound	;able to jump to notFound because if it were found, it would have jumped to found already
	inc	r10		;i++
	jmp	loop		;restart
	
found:
	mov	rax, r10	;set rax to i to return
	jmp	done

notFound:
	mov	rax, r11	;set rax to -1 to return
	jmp 	done
done:
	pop	rcx
	pop	rdx
	pop	rsi
	pop	rdi
	ret
