// #include <stdio.h>

#define FS_BLOCKS_PER_FD_BLOCK 	2
#define FD_BLOCK_SIZE 			512
#define BLOCK_COUNT 			1440


int main()
{
	extern printc();
	extern printInt();
	extern writesect();
	extern readsect();

    char buffer[FD_BLOCK_SIZE];
    int block_index, i;
    int *bii;

    for(i = 0; i < FD_BLOCK_SIZE; i++)
    	buffer[i] = 0;
    readsect(buffer, 2, 0, 1);
    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    block_index = bii[0];

    if(block_index == 0){
    	printc('\n');
    	printc('\r');
		printc('E');
		printc('l');
		printc(' ');
		printc('d');
		printc('i');
		printc('s');
		printc('c');
		printc('o');
		printc(' ');
		printc('e');
		printc('s');
		printc('t');
		printc('a');
		printc(' ');
		printc('l');
		printc('l');
		printc('e');
		printc('n');
		printc('o');
		printc('!');
		printc('\n');
    	printc('\r');
		return 0;
    }else{
    	printc('\n');
    	printc('\r');
    	printc('B');
    	printc('l');
    	printc('o');
    	printc('c');
    	printc('k');
    	printc(' ');
    	printc('a');
    	printc('l');
    	printc('l');
    	printc('o');
    	printc('c');
    	printc('a');
    	printc('t');
    	printc('e');
    	printc('d');
    	printc(':');
    	printc(' ');
    	printInt(block_index);
    	printc('\n');
    	printc('\r');
    }
    
	for(i = 0; i < FD_BLOCK_SIZE; i++)
    	buffer[i] = 0;
    readsect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
    bii = buffer + FD_BLOCK_SIZE - sizeof(int);
    block_index = bii[0];

    for(i = 0; i < FD_BLOCK_SIZE; i++)
    	buffer[i] = 0;
    readsect(buffer, 2, 0, 1);
    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    bii[0] = block_index;
    writesect(buffer, 2, 0, 1);
}

/*
Sector Size 512
Sectores 	1-18
Side 		0-1
Tracks 		0-79
*/

// https://ubuntuforums.org/printthread.php?t=2308173&pp=10&page=1