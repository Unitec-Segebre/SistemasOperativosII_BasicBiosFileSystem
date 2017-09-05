all:
	make cmpl
	make run

cmpl:
	dd if=/dev/zero of=disk.flp bs=512 count=2880
	nasm boot1s.asm -f bin -o boot1s.bin
	nasm boot2s.asm -f bin -o boot2s.bin

	as86 lib.asm -o kernel_asm.o

	bcc -ansi -c format_disk.c -o format_disk.o
	bcc -ansi -c reserve_block.c -o reserve_block.o
	bcc -ansi -c free_block.c -o free_block.o
	bcc -ansi -c statistics.c -o statistics.o

	ld86 -0 -d format_disk.o kernel_asm.o -o format_disk.bin
	ld86 -0 -d reserve_block.o kernel_asm.o -o reserve_block.bin
	ld86 -0 -d free_block.o kernel_asm.o -o free_block.bin
	ld86 -0 -d statistics.o kernel_asm.o -o statistics.bin

	dd if=boot1s.bin of=disk.flp bs=512 seek=0 conv=notrunc
	dd if=boot2s.bin of=disk.flp bs=512 seek=1 conv=notrunc
	dd if=format_disk.bin of=disk.flp bs=512 seek=2 conv=notrunc
	dd if=reserve_block.bin of=disk.flp bs=512 seek=4 conv=notrunc
	dd if=free_block.bin of=disk.flp bs=512 seek=9 conv=notrunc
	dd if=statistics.bin of=disk.flp bs=512 seek=13 conv=notrunc

run:
	qemu-system-x86_64 -fda disk.flp

clean:
	rm *.bin
	rm *.o
	rm *.flp
