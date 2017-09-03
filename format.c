// #include <stdio.h>

#define FS_BLOCK_SIZE 	1024
#define FD_BLOCK_SIZE 	512
#define BLOCK_COUNT 	1440


int main()
{
	extern readc();
	extern printc();
	extern writesect();
	// extern readsect();
	extern printInt();

	// create_disk(name, n_blocks);
	// ofstream outfile;
 //    outfile.open(name, ios::binary | ios::out | ios::trunc);
 //    if(!outfile)
 //        return -1;
 //    outfile.seekp(n_blocks*BLOCK_SIZE, ios::beg);
 //    outfile.write("", 1);
 //    outfile.close();


    // unsigned int file_size = n_blocks*BLOCK_SIZE;

    // set_start(name, 2);
    char buffer[FD_BLOCK_SIZE];// = (char*)calloc(1, BLOCK_SIZE);
    int *bii;//(Buffer Int Indexer)
    // read_block(name, 1, buffer);
    // ifstream infile;
    // infile.open(name, ios::binary | ios::in);
    // if(!infile)
    // //     return -1;
    // infile.seekg(block_index*BLOCK_SIZE, ios::beg);
    // infile.read(buffer, BLOCK_SIZE);
    // infile.close();

    int block_index, i;
    for(i = 0; i < FD_BLOCK_SIZE; i++)
    	buffer[i] = 0;

    bii = buffer + FD_BLOCK_SIZE - 2*sizeof(int);
    bii[0] = 19;
    bii[1] = BLOCK_COUNT-1;
 //    printc(',');
	// printc(' ');
 //    printInt(*((int*)(buffer+504)));
 //    printc(',');
	// printc(' ');
 //    printInt(*((int*)&buffer[508]));
    writesect(buffer, 1, 0, 1);
    // write_block(name, 1, buffer);
    // return value;

    // set_end(name, n_blocks-1);
    // char* buffer = (char*)calloc(1, BLOCK_SIZE);
    // read_block(name, 1, buffer);
    // *((unsigned int*)(&(buffer[BLOCK_SIZE-1*sizeof(unsigned int)]))) = value;
    // write_block(name, 1, buffer);
    // return value;

    for(block_index = 19; block_index < BLOCK_COUNT; block_index++){
    	if(block_index < 40){
    		printInt((block_index*2)-(18*((block_index*2)/18))+1);
    		printc(',');
    		printc(' ');
    		printInt(((block_index*2)/18)-(2*(((block_index*2)/18)/2)));
    		printc(',');
    		printc(' ');
    		printInt(((block_index*2)/18)/2);
    		printc('\n');
    		printc('\r');
    	}

        if(block_index+1 != BLOCK_COUNT){
            // set_next(name, i, i+1);
        	// char* buffer = (char*)calloc(1, BLOCK_SIZE);
        	for(i = 0; i < FD_BLOCK_SIZE; i++)
		    	buffer[i] = 0;
		    // *((int*)(&(buffer[FD_BLOCK_SIZE-1*sizeof(int)]))) = i+1;
		    bii = buffer + FD_BLOCK_SIZE - sizeof(int);
		    bii[0] = block_index+1;
		    writesect(buffer, (block_index*2)-(18*((block_index*2)/18))+1, ((block_index*2)/18)-(2*(((block_index*2)/18)/2)), ((block_index*2)/18)/2);

		    // write_block(name, block_index, buffer);
		    // return value;
        }else{
            // set_next(name, i, 0);
            // char* buffer = (char*)calloc(1, BLOCK_SIZE);
            for(i = 0; i < FD_BLOCK_SIZE; i++)
		    	buffer[i] = 0;
		    // *((int*)(&(buffer[FD_BLOCK_SIZE-1*sizeof(int)]))) = 0;
		    bii = buffer + FD_BLOCK_SIZE - sizeof(int);
		    bii[0] = 0;
		    writesect(buffer, (block_index*2)-(18*((block_index*2)/18))+1, ((block_index*2)/18)-(2*(((block_index*2)/18)/2)), ((block_index*2)/18)/2);
		    // write_block(name, block_index, buffer);
		    // return value;
		}

    }

	printInt(7842);

	readc();
}


//writesect(buffer, sector, track, side);

/*
Sector Size 512
Sectores 	1-18
Side 		0-1
Tracks 		0-79
*/

// https://ubuntuforums.org/printthread.php?t=2308173&pp=10&page=1