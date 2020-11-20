#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"
#include <string.h>

void init_boards(){
    int i = 0;

    for(i = 0; i < HSIZE; i++){
        htable[i]->init = 0;
    }
}

int depth(Board board){
    int i = 0;
    int depth = 0;
    for(i = 0; i < 9;i++){
        if(board[pos2idx[i]] == 'X' || board[pos2idx[i]] == 'O'){
            depth++;
        }
    }
    return(depth);
}

char winner(Board board){
    int depthOfBoard = depth(board);
    int i = 0;

    for(i = 0; i < 8; i++){
        if(WINS[i][0] == 'X' && WINS[i][1] == 'X' && WINS[i][2] == 'X'){
            return('X');
        }
        else if(WINS[i][0] == 'O' && WINS[i][1] == 'O' && WINS[i][2] == 'O'){
            return('O');
        }
    }

    if(depthOfBoard < 9){
        return(?);
    } else{
        return(-);
    }
}

char turn(Board board){
    int depthOfBoard = depth(board);
    if(depthOfBoard % 2 == 0){
        return('X');
    }
    else{
        return('O');
    }
}

void init_board(Board board){
    int hashNumOfBoard = board_hash(board);
    BoardNode * nodeOfHashTable = htable[hashNumOfBoard];

    nodeOfHashTable->init = 1;
    nodeOfHashTable->turn = turn(board);
    nodeOfHashTable->depth = depth(board);
    strcpy(nodeOfHashTable->board,board);
    nodeOfHashTable->winner = winner(board);
}

void join_graph(Board board){
    int hashNumOfBoard = board_hash(board);
    Board copyOfBoard[BSIZE];
    BoardNode * nodeOfHashTable = htable(hashNumOfBoard);
    int i = 0;
    for(i = 0; i < 9; i++){
        if(nodeOfHashTable->board[pos2idx(i)] == 'X' || nodeOfHashTable->board[pos2idx(i)] == 'O'){
            nodeOfHashTable->move[i] = -1l
        }
        else{

        }
    }


}