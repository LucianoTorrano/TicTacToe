/*
 * error.h
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <iostream>
#include <string>
#include "type.h"

const int TOTAL_ERRORS = 7;

const std::string OK_MSG = "Ok";
const std::string ERROR_MSG_NULL_POINTER = "ERROR DE SISTEMA";
const std::string ERROR_MSG_INVALID_INPUT = "ERROR: El carácter ingresado es inválido, deberán reiniciar la partida";
const std::string ERROR_MSG_INVALID_NAME_LENGHT = "ERROR: El nombre ingresado es demasiado largo, por favor reinicien la partida e ingrese un nombre mas corto";
const std::string ERROR_MSG_INVALID_POSITION = "ERROR: La posición ingresada no existe en el tablero, deberán reiniciar la partida";
const std::string ERROR_MSG_INVALID_MOVEMENT = "Realizaste un movimiento ilegal, perdiste por tramposo";
const std::string ERROR_MSG_WRONG_TOKEN = "Intentaste mover una ficha de tu contrincante, perdiste por tramposo";


/* Imprime en consola el mensaje del error que haya sucedido*/
void showError(status_t st);





#endif /* ERROR_H_ */
