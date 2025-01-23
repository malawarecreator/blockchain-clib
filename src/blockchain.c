#include "blockchain.h"
#include <stdio.h>
unsigned long gethash(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;

    }

    return hash;
}




void init_block(Block* block, unsigned long prevhash) {
    block->hash = gethash(block->data);


    block->prevhash = prevhash;

    printf("init block\n hash: %lu\n prevhash: %lu\n",  block->hash, block->prevhash);

} 



