#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"
#include <string.h>

void init_boards(){
    int i = 0;
    for(i = 0; i < HSIZE; i++){
        htable[i].init = 0;
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
        if(board[pos2idx[WINS[i][0]]] == 'X' && board[pos2idx[WINS[i][1]]] == 'X' && board[pos2idx[WINS[i][2]]] == 'X'){
            return('X');
        }
        else if((board[pos2idx[WINS[i][0]]] == 'O' && board[pos2idx[WINS[i][1]]] == 'O' && board[pos2idx[WINS[i][2]]] == 'O')){
            return('O');
        }
    }

    if(depthOfBoard < 9){
        return('?');
    } else{
        return('-');
    }
}

char turn(Board board){
    int depthOfBoard = depth(board);
    if(depthOfBoard == 9){
        return('-');
    }

    if(depthOfBoard % 2 == 0){
        return('X');
    }
    else{
        return('O');
    }
}

void init_board(Board board){
    int hashNumOfBoard = board_hash(board);

    htable[hashNumOfBoard].init = 1;
    htable[hashNumOfBoard].turn = turn(board);
    htable[hashNumOfBoard].depth = depth(board);
    strcpy( htable[hashNumOfBoard].board,board);
    htable[hashNumOfBoard].winner = winner(board);
}

void join_graph(Board board){
    int hashNumOfBoard = board_hash(board);
    int hashNumOfCopiedBoard = 0;
    Board copyOfBoard;
    int i = 0;

    for(i = 0; i < 9; i++){
        if(htable[hashNumOfBoard].board[pos2idx[i]] == 'X' || htable[hashNumOfBoard].board[pos2idx[i]] == 'O'){
            htable[hashNumOfBoard].move[i] = -1;
        }
        else{
            strcpy(copyOfBoard,htable[hashNumOfBoard].board);
            copyOfBoard[pos2idx[i]] = turn(copyOfBoard);
            hashNumOfCopiedBoard = board_hash(copyOfBoard);
            htable[hashNumOfBoard].move[i] = hashNumOfCopiedBoard;

            if(htable[hashNumOfCopiedBoard].init == 0){
                init_board(copyOfBoard);
                join_graph(copyOfBoard);
            }
        }
    }
}
/*
void compute_score(){
    int i = 0;
    int moveIndex = 0;
    int depth = 9;
    int score = 0;
    
    for(depth = 9; depth >= 0; depth--){
        for(i = 0; i < HSIZE; i++){
            if(htable[i].init == 1 && htable[i].depth == depth){
                if(htable[i].winner == 'X'){
                    htable[i].score = 1;
                }
                else if(htable[i].winner == 'O'){
                    htable[i]->score = -1;
                }
                else if(htable[i].winner == '-'){
                    htable[i]->score = 0;
                }
                else if(htable[i].turn == 'X'){
                    for(moveIndex = 0; moveIndex < 9; moveIndex++){
                        if(htable.move[i] != -1){
                            htable[i].score++;
                        }
                    }
                }
                else if(htable[i].turn == 'O'){
                    for(moveIndex = 0; moveIndex < 9; moveIndex++){
                        if(htable.move[i] != -1){
                            htable[i].score++;
                        }
                    }
                }
                
            }
        }
    }
    
}


int best_move(int board){
    int i = 0;
    int bestMoveHashNum = 0;
    int bestScore = -100000;
    for(i = 0; i < 9; i++){
        if(htable[board].move[i] != -1 && htable[htable[board].move[i]].score < bestScore){
            bestMoveHashNum = htable[board].move[i];
        }
    }
    return(bestMoveHashNum);
}
*/
