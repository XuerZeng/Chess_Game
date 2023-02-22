//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"
#include <iostream>
#include <string>
using namespace std;
//if i understand correctly, then this function is to change the value in the game state class.
//so in the tic tac toe file, we need to pass the game_state variable in and change the value of it to the newest version.
bool positionInBound(int row, int col){
    if(row<0 || row>2 || col<0 || col>2){
        return false;
    }
    return true;
}

void playMove(GameState& game_state) {
    //the class game_state in passed in as a reference
    //we first need to know if there is already a number on it.
    int row = game_state.get_selectedRow();
    int col = game_state.get_selectedColumn();
    int current = game_state.get_gameBoard(row,col);
    int round;
    //set the variable round to a Value so that we know which chess we are playing rn
    if(game_state.get_turn()){
        round = 1;
    }else if(!game_state.get_turn()){
        round = -1;
    }
    //determine if the board at the selected location is empty or no.
    //if the board is empty, set the value of that location be the round and set moveValid to true
    //if that's already occupied, no need to do the next steps, return and set the moveValid to false
    if (current != 0){
        game_state.set_moveValid(false);
        return;
    }else{
        game_state.set_moveValid(true);
        game_state.set_gameBoard(row,col,round);
    }
    //move is played and set the turn to another one
    if(round ==1){
        game_state.set_turn(false);
    }else{
        game_state.set_turn(true);
    }
    //after updating the board, we now need to see if someone wins the game and update the win code as well as the game over.
    
    int rDir[] = {1,-1,-1,1,-1,1,0,0};
    int cDir[] = {1,-1,1,-1,0,0,-1,1};
    int newRow,newCol;
    for (int i=0,j=0;i<8&&j<8;i++,j++){
        //cout<<rDir[i]<<cDir[j]<<endl;
        if(game_state.get_gameBoard(row+rDir[i],col+cDir[j])==game_state.get_gameBoard(row,col)&&positionInBound(row+rDir[i],col+cDir[j])){
            //determine whether this location is in the middle of at the beginning
            if (!positionInBound(row+2*rDir[i],col+2*cDir[j])){
                newRow = row - rDir[i];
                newCol = col - cDir[j];
                //cout<<"hhh";
            }else{
                newRow = row+2*rDir[i];
                newCol = col+2*cDir[j];
                //cout<<"ddd";
            }
            //cout<<newRow<<newCol;
            if(game_state.get_gameBoard(newRow,newCol)==game_state.get_gameBoard(row,col)){
                game_state.set_gameOver(true);
                //cout<<rDir[i]<<cDir[j];
                if(rDir[i]!=0&&cDir[j]!=0){
                    if(rDir[i]==cDir[j]){
                        game_state.set_winCode(7);
                        return;
                    }else if(rDir[i]!=cDir[j]){
                        game_state.set_winCode(8);
                        return;
                    }
                }else if(rDir[i]!=0&&cDir[j]==0){
                    if(col == 0){                                               
                        game_state.set_winCode(4);
                        return;
                    }else if(col == 1){
                        game_state.set_winCode(5);
                        return;
                    }else if(col ==2){
                        game_state.set_winCode(6);
                        return;
                    }
                  
                }else if(rDir[i]==0 && cDir[j] != 0){
                    if(row == 0){
                        game_state.set_winCode(1);
                        return;
                    }else if(row ==1){
                        game_state.set_winCode(2);
                        return;
                    }else if(row ==2){
                        game_state.set_winCode(3);
                        return;
                    }
                }
            }else{
                game_state.set_gameOver(false);
            }
        }
    }
    bool empty = false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(game_state.get_gameBoard(i,j)==0){
                empty = true;
            }
        }
    }
    if(!empty){
        game_state.set_gameOver(true);
        game_state.set_winCode(0);
        return;
    }
    
    
    
}

