/*
 * main.cpp
 *
 *  Created on: 17 sep. 2021
 *      Author: lucho
 */
#include <iostream>
#include <string>
#include <fstream>
#include "main.h"
#include "UserData.h"
#include "GameData.h"
#include "error.h"
#include "utilities.h"


int main(){

	int i;
	status_t st;
	UserData * playerOne,* playerTwo;
	GameData * gameData;
	std::string * matchResume;


	playerOne = new UserData;
	playerTwo = new UserData;
	gameData = new GameData;
	matchResume = new std::string;

	/*Imprime por consola las condiciones y reglas de juego*/
	printGameInitPage();

	/*Crea un archivo con el historial de jugadas, en el caso que el usuario lo desee*/
	if((st = createMatchResumeArchive(matchResume)) != OK){

		freeMemory(playerOne,playerTwo,gameData,matchResume);
		showError(st);
		return st;
	}

	/*Pide los nombres de los jugadores*/
	if((st = getPlayerName(playerOne, NUMBER_PLAYER_ONE)) != OK){

		freeMemory(playerOne,playerTwo,gameData,matchResume);
		showError(st);
		return st;
	}

	if((st = getPlayerName(playerTwo, NUMBER_PLAYER_TWO)) != OK){

		freeMemory(playerOne,playerTwo,gameData,matchResume);
		showError(st);
		return st;
	}

	/*Asigna los simbolos que utilizarán los jugadores*/
	if((st = setSimbolSelected(playerOne,playerTwo)) != OK){

		freeMemory(playerOne,playerTwo,gameData,matchResume);
		showError(st);
		return st;
	}

	setEmptyBoard(gameData);
	setMatchResumeArchiveTitle(*matchResume,playerOne,playerTwo);


	/*Posiciona las fichas de los jugadores*/
	for(i = 1;i <= MAX_TOKEN;i++){

		if((st = placeToken(playerOne,gameData,i)) != OK){

			freeMemory(playerOne,playerTwo,gameData,matchResume);
			showError(st);
			return st;
		}

		printBoardInGameResume(gameData,*matchResume);

		if((st = placeToken(playerTwo,gameData,i)) != OK){

			freeMemory(playerOne,playerTwo,gameData,matchResume);
			showError(st);
			return st;
		}
		printBoardInGameResume(gameData,*matchResume);
	}

	/*Verifica si hubo algún ganador luego de colocar las fichas*/
	checkWinnerState(gameData,playerOne);

	if(gameData->winner == FALSE){
		checkWinnerState(gameData,playerTwo);
	}

	/*Mueve las fichas de los jugadores hasta que haya un ganador*/
	while(gameData->winner == FALSE){

		if((st = changeTokenPosition(playerOne,gameData))){

			freeMemory(playerOne,playerTwo,gameData,matchResume);
			showError(st);
			return st;
		}

		printBoard(gameData);
		printBoardInGameResume(gameData,*matchResume);

		if(gameData->winner == TRUE)
			break;

		if((st = changeTokenPosition(playerTwo,gameData))){

			freeMemory(playerOne,playerTwo,gameData,matchResume);
			showError(st);
			return st;
		}

		printBoard(gameData);
		printBoardInGameResume(gameData,*matchResume);

		if(gameData->winner == TRUE)
			break;
	}

	/*Imprime quién gano la partida*/
	printWinnerMessage(gameData);

	freeMemory(playerOne,playerTwo,gameData,matchResume);

	return EXIT_SUCCESS;

}



void printGameInitPage(){

	std::cout<<"**************************************************"<<std::endl;
	std::cout<< "\t\tTa-Te-Ti"<<std::endl;
	std::cout<<"**************************************************"<<std::endl;
	std::cout<<"-> Bienvenidos a la página principal del juego"<<std::endl;
	std::cout<<"\t\tTa-Te-Ti"<<std::endl;
	std::cout<<"-> Recuerden que las posiciones dentro del tablero"<<std::endl;
	std::cout<<"   son las siguientes:"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"\t\t|1||2||3|"<<std::endl;
	std::cout<<"\t\t|4||5||6|"<<std::endl;
	std::cout<<"\t\t|7||8||9|"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"  Las necesitarán para saber en que posición"<<std::endl;
	std::cout<<"  colocaran o moveran sus fichas."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"-> REGLAS GENERALES:"<<std::endl;
	std::cout<<" 1) Solo pueden mover las fichas de forma horizontal"<<std::endl;
	std::cout<<"  o vertical a las celdas limitrofes que estén vacias"<<std::endl;
	std::cout<<"  Cualquier movimiento distinto a este se considerará ilegal"<<std::endl;
	std::cout<<"  y perderán la partida."<<std::endl;
	std::cout<<" 2) Esta prohibido intentar mover una ficha del contrincante"<<std::endl;
	std::cout<<"  Si algún jugador intenta hacer esto, perderá automaticamente"<<std::endl;
	std::cout<<std::endl;
}


status_t printBoardInGameResume(GameData * game, std::string matchResume){

	if(matchResume == VOID_ARCHIVE_NAME){
		return OK;
	}

	std::ofstream output;
	output.open(matchResume,std::ios::app);

	output<<"Jugada Número: "<<game->playCounter<<std::endl;
	int i, j;
	for(i = 0; i < MAX_ROWS ; i++){
		for(j=0 ; j< MAX_COLS ; j++){

			output<< game->board[i][j];
		}
	output<<std::endl;
	}
	output<<std::endl;

	game->playCounter++;

	output.close();

	return OK;
}

status_t createMatchResumeArchive(std::string * matchResume){

	std::string matchResumeName;
	std::ofstream output;
	char selection;

	std::cout<<"-> Desean Guardar el historial de la partida?"<<std::endl;
	std::cout<<"-> Presione la tecla 'S' en el caso que lo deseen o 'N' en caso contrario"<<std::endl;
	std::cin>>selection;
	std::cout<<std::endl;

	if(selection != 'S' && selection != 's' && selection != 'N' && selection != 'n'){
		return ERROR_INVALID_INPUT;
	}

	if(selection == 's' || selection == 'S' ){

		std::cout<<"-> Ingrese el nombre del archivo de texto que desea crear para guardar la partida"<<std::endl;
		std::cout<<"   (sin la terminación '.txt')"<<std::endl;
		std::cin>>matchResumeName;
		std::cout<<std::endl;

		 *matchResume = matchResumeName + TXT_ARCHIVE_ENDING;
		 output.open(*matchResume);
		 output.close();

	}else {
		*matchResume = VOID_ARCHIVE_NAME;
	}

	return OK;
}

status_t setMatchResumeArchiveTitle(std::string matchResume,UserData * playerOne,UserData * playerTwo){

	if(matchResume == VOID_ARCHIVE_NAME){
		return OK;
	}

	std::ofstream output;
	output.open(matchResume,std::ios::app);

	output<<"Resumen de partida de TaTeTi disputada entre "<<playerOne->name<<" y "<< playerTwo->name<<std::endl;
	output<<std::endl;
	output<<playerOne->name<< " jugó con "<< playerOne->simbolChosen<<" y "<<playerTwo->name<<" jugó con "<<playerTwo->simbolChosen<<std::endl;
	output<<std::endl;

	output.close();

	return OK;

}

void freeMemory(UserData * playerOne, UserData *playerTwo, GameData *game, std::string * matchResumeName){

	delete playerOne;
	delete playerTwo;
	delete game;
	delete matchResumeName;

}
