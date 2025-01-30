#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
typedef struct {
    char* data;
    unsigned long hash;
    unsigned long prevhash;
} Block;

typedef struct {
    Block* blocks;
    int size;

} Blockchain;



unsigned long gethash(const char* str);
void init_block(Block* block, unsigned long prevhash);
void print_block(Block* block);
void blockchain_alloc(Blockchain* bc, int size);
void blockchain_free(Blockchain* bc);
void add_to_blockchain(Blockchain* bc, Block* block);
#endif