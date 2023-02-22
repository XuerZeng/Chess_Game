//
//  GameState.cpp
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

#include "globals.h"
#include "GameState.h"

// ECE244 Student: add you code below
#include <iostream>
using namespace std;
#include <string>
// The constructor. It initializes:
    //     selectedRow to 0
    //     selectedColum to 0
    //     moveValid to true
    //     gameOver to false
    //     winCode to 0
    //     turn to true
    //     gameBoad locations to Empty (see globals.h)
GameState::GameState(){
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    winCode = 0;
    turn =true;
    //set the board initially to be empty
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            gameBoard[i][j]=0;
        }
    }
}
int GameState::get_selectedRow(){
    return selectedRow;
}

int GameState::get_selectedColumn(){
    return selectedColumn;
}

void GameState::set_selectedRow(int value){
    selectedRow = value;
}

void GameState::set_selectedColumn(int value){
    selectedColumn = value;
}

bool GameState::get_moveValid(){
    return moveValid;
}

void GameState::set_moveValid(bool value){
    moveValid = value;
}

void GameState::set_gameOver(bool value){
    gameOver = value;
}

bool GameState::get_gameOver(){
    return gameOver;
}

int GameState::get_winCode(){
    return winCode;
}

void GameState::set_winCode(int value){
    winCode = value;
}

bool GameState::get_turn(){
    //true to be x moving and false to be o moving
    return turn;
}

void GameState::set_turn(bool value){
    turn = value;
}

int GameState::get_gameBoard(int row, int col){
    return gameBoard[row][col];
}

void GameState::set_gameBoard(int row, int col, int value){
    gameBoard[row][col] = value;
}
