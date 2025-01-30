# nothing much to say, its just a lib<br>

you can read the headers, its pretty simple<br>

# to install:<br>

download the `dist` release in the releases<br>
extract it<br>
run:<br>
`cd dist`<br>
`chmod +x install.sh`<br>
`./install.sh`<br>
you can delete the `dist` folder after<br>

# to link<br>
provided you've already installed the lib, to link, just use `gcc my_file.c -lblockchain` 



# libblockchain DOCS:<br>

``` c
#include <stdio.h>
#include <stdlib.h>
#include <blockchain.h>

void init_block(Block* block, unsigned long prevhash);
void print_block(Block* block);
void blockchain_alloc(Blockchain* bc, int size);
void blockchain_free(Blockchain* bc);
void add_to_blockchain(Blockchain* bc, Block* block);

```

how to use the funcs:<br>

A typical program:<br>

```c
// include headers

int main() {
    Blockchain bc;
    blockchain_alloc(&bc, 5);


    // always malloc the block manually
    Block *block = (Block *)malloc(sizeof(Block));

    // add the data before initializing the block
    block->data = "hello";
    /* 
    Here, i set the prevhash of the block to zero, but if you actually want to link two blocks you would:
    create block 1 and init it with a prevhash (say 0 for genisis)
    Then, you create another block, but this time make the prevhash point to the hash of block1 (block1->prevhash)
    */
    init_block(block, 0);

    // make sure to always use the address of the blockchain, and not the blockchain directly. not for the block though
    add_to_blockchain(&bc, block);
    print_block(block);
    // although there is a helper function for freeing the blockchain, there is no helper for freeing the block. i will work on that later
    blockchain_free(&bc);
    free(block);

    return 0;
}
```

# the structs
```c
typedef struct {
    char* data;
    unsigned long hash;
    unsigned long prevhash;
} Block;

typedef struct {
    Block* blocks;
    int size;

} Blockchain;

```