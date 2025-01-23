#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
typedef struct {
    char* data;
    unsigned long hash;
    unsigned long prevhash;
} Block;


unsigned long gethash(const char* str);
void init_block(Block* block, unsigned long prevhash);
#endif