all:
	dd if=/dev/zero of=disk.flp bs=512 count=2880
	nasm boot.asm -f bin -o boot.bin
	nasm menu.asm -f bin -o loader.bin

	as86 lib.asm -o kernel_asm.o

	bcc -ansi -c format.c -o format.o
	ld86 -0 -d format.o kernel_asm.o -o format.bin

	dd if=boot.bin of=disk.flp bs=512 seek=0 conv=notrunc
	dd if=loader.bin of=disk.flp bs=512 seek=1 conv=notrunc
	dd if=format.bin of=disk.flp bs=512 seek=2 conv=notrunc
