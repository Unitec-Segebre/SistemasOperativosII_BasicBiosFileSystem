[BITS 16]
[ORG 0x0000]

mov ax, cs
mov ds, ax

mainloop:
	call MainMenu
	jmp mainloop

menu db '-- MENU --', 0x0D, 0x0A, 0
format_disk db '1. Format disk', 0x0D, 0x0A, 0
reserve_block db '2. Reserve block', 0x0D, 0x0A, 0
free_block db '3. Free block', 0x0D, 0x0A, 0
statistics db '4. Statistics', 0x0D, 0x0A, 0
error_input db 'Wrong Input', 0x0D, 0x0A, 0

print_string:
	lodsb                  ; grab a byte from SI

	or al, al              ; logical or AL by itself
	jz .done               ; if the result is zero, get out

	mov ah, 0x0E
	int 0x10               ; otherwise, print out the character!

	jmp print_string

	.done:
		ret

PrintCharacter:
	mov ah, 0x0E
	int 0x10
	ret

GetCharacter:
	mov ah, 0
	int 0x16
	ret

Println:
	mov al, 0

	mov ah, 0x0E
	mov al, 0x0D
	int 0x10
	mov al, 0x0A
	int 0x10
	ret

MainMenu:
  enter 0, 0

	call Println
	call Println

	mov si, menu
	call print_string
  	mov si, format_disk
	call print_string
  	mov si, reserve_block
	call print_string
  	mov si, free_block
	call print_string
  	mov si, statistics
	call print_string

	call GetCharacter
	mov bl, al
	call PrintCharacter
	sub bl, 48               ;Input to decimal

	mov ah, 0x02
	mov al, 1
	mov dl, 0x00
	mov ch, 0
	mov dh, 0

  check_one:
  	cmp bl, 1
  	jnz check_two
    call callProgram1
    jmp end

  check_two:
  	cmp bl, 2
  	jnz check_three
    call callProgram2
    jmp end

  check_three:
  	cmp bl, 3
  	jnz check_four
    call callProgram3
    jmp end

  check_four:
  	cmp bl, 4
  	jnz bad_input
    call callProgram4
    jmp end

  bad_input:
  	call Println
  	mov si, error_input
  	call print_string
  	call Println
    jmp end

  end:
    leave
    ret


;Arbitrary number 0x8000 as the loaded program position
callProgram1:
	enter 0, 0

  	mov al, 2
	mov cl, 3
	mov bx, 0x8200
	int 0x13

	call 0x8200
  leave
  ret

callProgram2:
  enter 0, 0

  	mov al, 5;3
	mov cl, 5
	mov bx, 0x8200
	int 0x13

	call 0x8200
  leave
  ret

callProgram3:
  enter 0, 0

  	mov al, 4
	mov cl, 10
	mov bx, 0x8200
	int 0x13

	call 0x8200
  leave
  ret

callProgram4:
  enter 0, 0

  	mov al, 2
	;mov cl, 13
	mov bx, 0x8200
	int 0x13

	call 0x8200
  leave
  ret

times (512-($-$$)) db 0
