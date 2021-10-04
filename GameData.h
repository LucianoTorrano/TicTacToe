/*
 * GameData.h
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#ifndef GAMEDATA_H_
#define GAMEDATA_H_
#include <iostream>
#include <string>
#include "type.h"
#include "UserData.h"

const int MAX_TOKEN = 3;
const int MAX_ROWS = 3;
const int MAX_COLS = 3;
const std::string xSimbol = "|X|";
const std::string oSimbol = "|O|";
const std::string emptySimbol = "| |";

typedef struct{
			bool_t winner;
			int playCounter;
			std::string winnerName;
			std::string board[MAX_ROWS][MAX_COLS];
			}GameData;

/* Coloca una celda vacia en todas las posiciones del tablero y lo imprimer por consola */
void setEmptyBoard(GameData * game);


/* Le preguna al usuario en qué posicion desea colocar la ficha numero 'i' */
status_t placeToken(UserData * player,GameData * game ,int i);

/* Posiciona una ficha del jugador 'player' en la posicion del tablero que haya indicado mediante 'position'.
 * Si la celda esta vacia realiza el posicionamiento.*/
void locateToken(int position, GameData * game, UserData * player);

/* Imprimer el estado actual del tablero por consola */
void printBoard(GameData * game);

/* Pide al jugador 'player' la posicion de la ficha que desea mover y a qué posicion moverla.
 * Posteriormente realiza el movimiento.*/
status_t changeTokenPosition(UserData * player, GameData * game);

/* Mueve una ficha del jugador 'player' de la posicion 'initPosition' hacia 'finalPosition' */
void moveToken(UserData * player, GameData * game, int initPosition, int finalPosition);

/* Reinicia el estado de la celda dejandola vacia.*/
void resetCell( int position,GameData * game);

/* Verifica si hay un ganador con el estado actual del tablero */
void checkWinnerState(GameData * game,UserData * player);

/* Imprime quién gano la partida */
void printWinnerMessage(GameData *game);





#endif /* GAMEDATA_H_ */
