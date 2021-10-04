/*
 * main.h
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <string>
#include "type.h"
#include "GameData.h"
#include "UserData.h"
#include "utilities.h"

const std::string VOID_ARCHIVE_NAME = "-";
const std::string TXT_ARCHIVE_ENDING = ".txt";

/* Imprime por consola las condiciones y reglas de juego */
void printGameInitPage();


/* Pregunta a los usuarios si desean guardar el historial de jugadas. En el caso que lo deseen
 * les pide un nombre de archivo. Posteriormente crea un archivo de texto con el nombre dado.
 * Si no desean guardar el historial se le asigna a matchResume una cadena predeterminada como
 * VOID_ARCHIVE_NAME, por el cual el programa interpretara que no hay archivo cuando se utilice
 * esta cadena */
status_t createMatchResumeArchive(std::string * matchResume);


/* Imprime el titulo en el archivo de texto creado indicando quienes son los jugadores y sus
 * respectivas fichas */
status_t setMatchResumeArchiveTitle(std::string matchResume,UserData * playerOne,UserData * playerTwo);


/* Imprime el estado actual del tablero y el numero de jugada que se esta llevando a cabo */
status_t printBoardInGameResume(GameData * game, std::string matchResume);

/* Libera la memoria pedida */
void freeMemory(UserData * playerOne, UserData *playerTwo, GameData *game, std::string * matchResumeName);




#endif /* MAIN_H_ */
