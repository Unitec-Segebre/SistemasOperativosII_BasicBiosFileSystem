// #include <stdio.h>

#define FS_BLOCKS_PER_FD_BLOCK 	2
#define FD_BLOCK_SIZE 			512
#define BLOCK_COUNT 			1440


int main()
{
    extern printc();
	extern printInt();
	extern readsect();

    char buffer[FD_BLOCK_SIZE];
    int block_index, space_left, i;
    int *bii;

    for(i = 0; i < FD_BLOCK_SIZE; i++)
        buffer[i] = 0;
    readsect(buffer, 2, 0, 1);
    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    block_index = bii[0];

    space_left = 0;
	while(block_index != 0){
        space_left++;
        readsect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
        bii = buffer + FD_BLOCK_SIZE - sizeof(int);
        block_index = bii[0];
    }

    printc('S');
    printc('i');
    printc('z');
    printc('e');
    printc(' ');
    printc('o');
    printc('f');
    printc(' ');
    printc('d');
    printc('i');
    printc('s');
    printc('k');
    printc(':');
    printc(' ');
    printInt(BLOCK_COUNT*(FD_BLOCK_SIZE*FS_BLOCKS_PER_FD_BLOCK/1024));
    printc(' ');
    printc('K');
    printc('B');
    printc('\n');
    printc('\r');
    printc('S');
    printc('p');
    printc('a');
    printc('c');
    printc('e');
    printc(' ');
    printc('l');
    printc('e');
    printc('f');
    printc('t');
    printc(':');
    printc(' ');
    if(space_left > 16384/((FD_BLOCK_SIZE/4)*FS_BLOCKS_PER_FD_BLOCK))
        printInt(space_left*(FD_BLOCK_SIZE*FS_BLOCKS_PER_FD_BLOCK/1024));
    else
        printInt(space_left*FD_BLOCK_SIZE*FS_BLOCKS_PER_FD_BLOCK);
    printc(' ');
    if(space_left > 16384/((FD_BLOCK_SIZE/4)*FS_BLOCKS_PER_FD_BLOCK))
        printc('K');
    printc('B');
    printc('\n');
    printc('\r');
}

/*
Sector Size 512
Sectores 	1-18
Side 		0-1
Tracks 		0-79
*/