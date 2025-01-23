#include <stdio.h>
#include <stdlib.h>
#include "blockchain.h"



int main() {
    Block* genisis = malloc(sizeof(Block));
    Block* block2 = malloc(sizeof(Block));
    genisis->data = "i nate higgers";
    init_block(genisis, 0);

}