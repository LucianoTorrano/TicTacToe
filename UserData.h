/*
 * UserData.h
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#ifndef USERDATA_H_
#define USERDATA_H_
#include <iostream>
#include <string>
#include "type.h"

const int NUMBER_PLAYER_ONE = 1;
const int NUMBER_PLAYER_TWO = 2;
const uint MAX_NAME_LENGTH = 12;
const int OPTION_ONE = 1;
const int OPTION_TWO = 2;


typedef struct{
			std::string name;
			std::string simbolChosen;
			}UserData;

/* Obtiene el nombre de un jugador y lo asigna dentro de una estructura de dato 'UserData' */
status_t getPlayerName(UserData * player, int playerNumber);

/* Pregunta al 'playerOne' qué simbolo desea utilizar durante la partida, a 'playerTwo' le asigna
 * por defecto el simbolo que sobre*/
status_t setSimbolSelected(UserData * playerOne, UserData * playerTwo);


#endif /* USERDATA_H_ */
