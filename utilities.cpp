/*
 * utilities.cpp
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

const int MAX_POSITION = 9;
const int MIN_POSITION = 1;



status_t validatePosition(int position){

	if(position > MAX_POSITION || position < MIN_POSITION)
		return ERROR_INVALID_POSITION;

	return OK;
}

status_t validateMovement(int initPosition,int finalPosition,UserData * player,GameData * game){
	int distance;
	status_t st;

	if((st = checkPlayerToken(initPosition,game,player)) != OK){
		return st;
	}

	distance = initPosition - finalPosition;

	if(distance != -1 && distance != 1 && distance != -3 && distance != 3){

		return ERROR_INVALID_MOVEMENT;
	}

	return OK;
}

status_t checkPlayerToken(int position,GameData * game,UserData * player){

	if(position == 1 && !(player->simbolChosen).compare(game->board[0][0])){

		return OK;

	}else if(position == 2 && !(player->simbolChosen).compare(game->board[0][1])){

		return OK;

	}else if(position == 3 && !(player->simbolChosen).compare(game->board[0][2])){

		return OK;

	}else if(position == 4 && !(player->simbolChosen).compare(game->board[1][0])){

		return OK;

	}else if(position == 5 && !(player->simbolChosen).compare(game->board[1][1])){

		return OK;

	}else if(position == 6 && !(player->simbolChosen).compare(game->board[1][2])){

		return OK;

	}else if(position == 7 && !(player->simbolChosen).compare(game->board[2][0])){

		return OK;

	}else if(position == 8 && !(player->simbolChosen).compare(game->board[2][1])){

		return OK;

	}else if(position == 9 && !(player->simbolChosen).compare(game->board[2][2])){

		return OK;
	}else{
		return ERROR_WRONG_TOKEN;
	}


}


