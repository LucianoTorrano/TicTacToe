/*
 * UserData.cpp
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#include <iostream>
#include <string>
#include "type.h"
#include "UserData.h"
#include "GameData.h"



status_t getPlayerName(UserData * player, int playerNumber){
	if(player == NULL)
		return ERROR_NULL_POINTER;

	std::cout<<"-> Ingrese el nombre del jugador "<<playerNumber<<std::endl;
	std::cin>>player->name;
	std::cout<<std::endl;

	if((player->name).length() > MAX_NAME_LENGTH)
		return ERROR_INVALID_NAME_LENGTH;

	return OK;
}

status_t setSimbolSelected(UserData * playerOne, UserData * playerTwo){
	int simbolSelected;

	if(playerOne == NULL || playerTwo == NULL)
		return ERROR_NULL_POINTER;

	std::cout<< playerOne->name <<" seleccione con que simbolo desea jugar."<<std::endl;
	std::cout<<"->Ingrese 1 para elegir el simbolo '|X|'." <<std::endl;
	std::cout<<"->Ingrese 2 para elegir el simbolo '|O|'." <<std::endl;
	std::cout<<std::endl;

	std::cin>>simbolSelected;

	if(simbolSelected != OPTION_ONE && simbolSelected != OPTION_TWO)
		return ERROR_INVALID_INPUT;

	if(simbolSelected == OPTION_ONE){
		playerOne->simbolChosen = xSimbol;
		playerTwo->simbolChosen = oSimbol;
	}else{
		playerOne->simbolChosen = oSimbol;
		playerTwo->simbolChosen = xSimbol;
	}

	std::cout<<playerOne->name<< " tu simbolo será: "<<playerOne->simbolChosen<<std::endl;
	std::cout<<playerTwo->name<< " tu simbolo será: "<<playerTwo->simbolChosen<<std::endl;
	std::cout<<std::endl;

	return OK;
}



