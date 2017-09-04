// #include <stdio.h>

#define FS_BLOCKS_PER_FD_BLOCK 	2
#define FD_BLOCK_SIZE 			512
#define BLOCK_COUNT 			1440


int main()
{
	extern printc();
	extern writesect();

    char buffer[FD_BLOCK_SIZE];
    int block_index, i;
    int *bii;

    for(i = 0; i < FD_BLOCK_SIZE; i++)
    	buffer[i] = 0;

    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    bii[0] = 19;
    bii[1] = BLOCK_COUNT-1;
    writesect(buffer, 1, 0, 1);
    
    for(block_index = 19; block_index < BLOCK_COUNT; block_index++){
    	for(i = 0; i < FD_BLOCK_SIZE; i++)
	    	buffer[i] = 0;
	    bii = buffer + FD_BLOCK_SIZE - sizeof(int);
        if(block_index+1 != BLOCK_COUNT)
		    bii[0] = block_index+1;
        else
		    bii[0] = 0;
	    writesect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
    }
	printc('\n');
	printc('F');
	printc('o');
	printc('r');
	printc('m');
	printc('a');
	printc('t');
	printc(' ');
	printc('c');
	printc('o');
	printc('m');
	printc('p');
	printc('l');
	printc('e');
	printc('t');
	printc('e');
	printc('!');
	printc('\n');
}


//writesect(buffer, sector, track, side);

/*
Sector Size 512
Sectores 	1-18
Side 		0-1
Tracks 		0-79
*/

// https://ubuntuforums.org/printthread.php?t=2308173&pp=10&page=1