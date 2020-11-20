#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"
#include <string.h>

int main(int argc, char * argv[]){
    int numOfNodes = 0;
    int i = 0;
    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);

    for(i = 0; i < HSIZE; i++){
        if(htable[i]->init == 1){
            numOfNodes++;
        }
    }

    printf("%d\n",numOfNodes);

}