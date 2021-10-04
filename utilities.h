/*
 * utilities.h
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <iostream>
#include "type.h"
#include "GameData.h"
#include "UserData.h"

/* Valida si la posicion ingresada existe entre los limites del tablero*/
status_t validatePosition(int position);

/* Valida el movimiento que el jugador quiera realizar segun las reglas del juego*/
status_t validateMovement(int initPosition,int finalPosition,UserData * player,GameData *game);

/* Valida si la ficha que el jugador esta intentando mover es suya o no*/
status_t checkPlayerToken(int position,GameData * game,UserData * player);




#endif /* UTILITIES_H_ */
