/*
 * GameData.cpp
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */
#include <iostream>
#include <string>
#include "type.h"
#include "utilities.h"
#include "UserData.h"
#include "GameData.h"


void setEmptyBoard(GameData * game){
	int i, j;

	for(i = 0; i < MAX_ROWS ; i++){

		for(j=0 ; j< MAX_COLS ; j++){

			game->board[i][j] = emptySimbol;

			std::cout<<game->board[i][j];

		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;

	game->winner = FALSE;
}

status_t placeToken(UserData * player,GameData * game ,int i){

	status_t st;
	int position;

	if(player == NULL){
		return ERROR_NULL_POINTER;
	}

	std::cout<< player->name << " ingrese la posición de la ficha número "<< i << std::endl;
	std::cin>>position;

	if((st = validatePosition(position)) != OK)
		return st;

	locateToken(position, game, player);
	printBoard(game);

	return OK;
}

void locateToken(int position, GameData * game, UserData * player){

	if(position == 1 && !emptySimbol.compare(game->board[0][0])){
		game->board[0][0] = player->simbolChosen;

	}else if(position == 2 && !emptySimbol.compare(game->board[0][1])){

		game->board[0][1] = player->simbolChosen;

	}else if(position == 3 && !emptySimbol.compare(game->board[0][2])){

		game->board[0][2] = player->simbolChosen;

	}else if(position == 4 && !emptySimbol.compare(game->board[1][0])){

		game->board[1][0] = player->simbolChosen;

	}else if(position == 5 && !emptySimbol.compare(game->board[1][1])){

		game->board[1][1] = player->simbolChosen;

	}else if(position == 6 && !emptySimbol.compare(game->board[1][2])){

		game->board[1][2] = player->simbolChosen;

	}else if(position == 7 && !emptySimbol.compare(game->board[2][0])){

		game->board[2][0] = player->simbolChosen;

	}else if(position == 8 && !emptySimbol.compare(game->board[2][1])){

		game->board[2][1] = player->simbolChosen;

	}else if(position == 9 && !emptySimbol.compare(game->board[2][2])){

		game->board[2][2] = player->simbolChosen;
	}
}


void printBoard(GameData * game){

	int i, j;
	for(i = 0; i < MAX_ROWS ; i++){
		for(j=0 ; j< MAX_COLS ; j++){

			std::cout<< game->board[i][j];
		}
	std::cout<<std::endl;
	}
	std::cout<<std::endl;
}


status_t changeTokenPosition(UserData * player, GameData * game){

	int initPosition, finalPosition;
	status_t st;

	std::cout<< player->name<<" Ingrese la posición de la ficha que desea mover:"<<std::endl;
	std::cin>>initPosition;

	if((st = validatePosition(initPosition)) != OK){
		return st;
	}

	std::cout<<player->name<<" Ingrese la posición donde quiere depositar la ficha:"<< std::endl;
	std::cin>>finalPosition;

	if((st = validatePosition(finalPosition))!= OK){
		return st;
	}

	if((st = validateMovement(initPosition,finalPosition,player,game)) != OK){
		return st;
	}

	moveToken(player, game, initPosition, finalPosition);

	return OK;
}

void moveToken(UserData * player, GameData * game, int initPosition, int finalPosition){

	resetCell(initPosition,game);
	locateToken(finalPosition,game,player);
	checkWinnerState(game,player);
}

void resetCell( int position,GameData * game){

	if(position == 1){

		game->board[0][0] = emptySimbol;

	}else if(position == 2){

		game->board[0][1] = emptySimbol;

	}else if(position == 3){

		game->board[0][2] = emptySimbol;

	}else if(position == 4){

		game->board[1][0] = emptySimbol;

	}else if(position == 5){

		game->board[1][1] = emptySimbol;

	}else if(position == 6){

		game->board[1][2] = emptySimbol;

	}else if(position == 7){

		game->board[2][0] = emptySimbol;

	}else if(position == 8){

		game->board[2][1] = emptySimbol;

	}else if(position == 9){

		game->board[2][2] = emptySimbol;

	}
}

void checkWinnerState(GameData * game,UserData * player){

	int i;

	for(i=0; i < MAX_ROWS;i++){
		if(game->winner == FALSE && game->board[i][0] == game->board[i][1] && game->board[i][0] == game->board[i][2]){   //analizo ganador por fila

			game->winner = TRUE;
			game->winnerName = player->name;

		}else if(game->winner == FALSE && game->board[0][i] == game->board[1][i] && game->board[0][i]== game->board[2][i]){	//analizo ganador por columna

			game->winner = TRUE;
			game->winnerName = player->name;
		}
	}

	if(game->winner == FALSE && game->board[0][0] == game->board[1][1] && game->board[0][0] == game->board[2][2]){ 	//analizo ganador por diagonal

		game->winner = TRUE;
		game->winnerName = player->name;

	}else if(game->winner == FALSE && game->board[0][2] == game->board[1][1] && game->board[0][2] == game->board[2][0]){	//analizo ganador por diagnoal

		game->winner = TRUE;
		game->winnerName = player->name;

	}

}

void printWinnerMessage(GameData *game){

	std::cout << "Felicidades " << game->winnerName <<" ganaste la partida!"<< std::endl;

}




