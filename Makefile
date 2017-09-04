all:
	dd if=/dev/zero of=disk.flp bs=512 count=2880
	nasm boot1s.asm -f bin -o boot1s.bin
	nasm boot2s.asm -f bin -o boot2s.bin

	as86 lib.asm -o kernel_asm.o

	bcc -ansi -c format_disk.c -o format_disk.o
	bcc -ansi -c reserve_block.c -o reserve_block.o
	ld86 -0 -d format_disk.o kernel_asm.o -o format_disk.bin
	ld86 -0 -d reserve_block.o kernel_asm.o -o reserve_block.bin

	dd if=boot1s.bin of=disk.flp bs=512 seek=0 conv=notrunc
	dd if=boot2s.bin of=disk.flp bs=512 seek=1 conv=notrunc
	dd if=format_disk.bin of=disk.flp bs=512 seek=2 conv=notrunc
	dd if=reserve_block.bin of=disk.flp bs=512 seek=4 conv=notrunc

clean:
	rm *.bin
	rm *.o
	rm *.flp
