#include "blockchain.h"
#include <stdio.h>
#include <stdlib.h>
unsigned long gethash(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;

    }

    return hash;
}


void link_blocks(Block *blocks[], int size ) {

    for (int i = 0; i < size; i++) {
        blocks[i]->prevhash = blocks[i - 1]->hash;

    }
}

void init_block(Block* block, unsigned long prevhash) {
    block->hash = gethash(block->data);


    block->prevhash = prevhash;

    printf("init block\n hash: %lu\n prevhash: %lu\n",  block->hash, block->prevhash);

}
void print_block(Block* block) {
    printf("hash: %lu\n prevhash: %lu\n data: %s\n", block->hash, block->prevhash, block->data);

}

void blockchain_alloc(Blockchain* bc, int size) {
    bc->blocks = (Block*)malloc(size * sizeof(Block));
    bc->size = size;
    printf("blockchain allocated\n");
}


void blockchain_free(Blockchain* bc) {
    free(bc->blocks);
    printf("blockchain freed\n");
}

void add_to_blockchain(Blockchain* bc, Block* block) {
    bc->blocks[bc->size] = *block;
    bc->size++;
    printf("block added to blockchain\n");
}
