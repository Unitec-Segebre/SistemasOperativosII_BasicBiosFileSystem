// #include <stdio.h>

#define FS_BLOCKS_PER_FD_BLOCK 	2
#define FD_BLOCK_SIZE 			512
#define BLOCK_COUNT 			1440


int main()
{
    extern readc();
    extern printc();
	extern printInt();
	extern writesect();
	extern readsect();

    char buffer[FD_BLOCK_SIZE];
    int block_index, block_index_to_free, i;
    int *bii;

    printc('\n');
    printc('\r');
    printc('B');
    printc('l');
    printc('o');
    printc('c');
    printc('k');
    printc(' ');
    printc('t');
    printc('o');
    printc(' ');
    printc('f');
    printc('r');
    printc('e');
    printc('e');
    printc('(');
    printInt(19);
    printc(' ');
    printc('-');
    printc(' ');
    printInt(BLOCK_COUNT-1);
    printc(')');
    printc(':');
    printc(' ');

    //block_index being used as a temporal
    block_index_to_free = 0;
    for(i = 1000; i >= 1;){
        block_index = readc();
        if (block_index >= 48 && block_index <= 57){
            printc(block_index);
            block_index -= 48;
            block_index_to_free += block_index*i;
            i /= 10;
        }
    }

    if(block_index_to_free < 19 || block_index_to_free >= BLOCK_COUNT){
        printc('\n');
        printc('\r');
        printc('B');
        printc('l');
        printc('o');
        printc('c');
        printc('k');
        printc(' ');
        printc('i');
        printc('n');
        printc('d');
        printc('e');
        printc('x');
        printc(' ');
        printc('o');
        printc('u');
        printc('t');
        printc(' ');
        printc('o');
        printc('f');
        printc(' ');
        printc('r');
        printc('a');
        printc('n');
        printc('g');
        printc('e');
        printc('!');

        return 0;
    }

    for(i = 0; i < FD_BLOCK_SIZE; i++)
        buffer[i] = 0;
    readsect(buffer, 2, 0, 1);
    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    block_index = bii[0];

    if(block_index == 0){
        bii[0] = block_index_to_free;
        bii[1] = block_index_to_free;
        writesect(buffer, 2, 0, 1);
        for(i = 0; i < FD_BLOCK_SIZE; i++)
            buffer[i] = 0;
        block_index = block_index_to_free;
        writesect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
		return 0;
    }

	while(block_index != 0){
        if(block_index == block_index_to_free){
            printc('\n');
            printc('\r');
            printc('N');
            printc('o');
            printc(' ');
            printc('s');
            printc('e');
            printc(' ');
            printc('h');
            printc('i');
            printc('z');
            printc('o');
            printc(' ');
            printc('n');
            printc('a');
            printc('d');
            printc('a');
            printc('!');
            return 0;
        }
        readsect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
        bii = buffer + FD_BLOCK_SIZE - sizeof(int);
        block_index = bii[0];
    }
    readsect(buffer, 2, 0, 1);
    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    block_index = bii[1];//block index guarda el ultimo viejo
    bii[1] = block_index_to_free;//block index to free el ultimo nuevo
    writesect(buffer, 2, 0, 1);//reescbribimos la metadata////////////////////////////SET_END
    for(i = 0; i < FD_BLOCK_SIZE; i++)//limpiamos el buffer
        buffer[i] = 0;//leemos el ultimo viejo
    // readsect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
    bii = buffer + FD_BLOCK_SIZE - sizeof(int);
    bii[0] = block_index_to_free;//el siguiente del ultimo viejo es el ultimo nuevo
    //deberiamos escribirlo
    // for(i = 0; i < FD_BLOCK_SIZE; i++)
    //     buffer[i] = 0;
    // block_index = block_index_to_free;
    ///////////////////////////////////////////////////SET_NEXT_1
    writesect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);
    for(i = 0; i < FD_BLOCK_SIZE; i++)//limpiamos el buffer
        buffer[i] = 0;
    block_index = block_index_to_free;
    writesect(buffer, (block_index*FS_BLOCKS_PER_FD_BLOCK)-(18*((block_index*FS_BLOCKS_PER_FD_BLOCK)/18))+2, ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)-(2*(((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2)), ((block_index*FS_BLOCKS_PER_FD_BLOCK)/18)/2);

}

/*
Sector Size 512
Sectores 	1-18
Side 		0-1
Tracks 		0-79
*/