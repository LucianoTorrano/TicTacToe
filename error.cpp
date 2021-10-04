/*
 * error.cpp
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */
#include <iostream>
#include <string>
#include "type.h"
#include "error.h"



void showError(status_t st){
	std::string errorMsg[TOTAL_ERRORS]={
												OK_MSG,
												ERROR_MSG_NULL_POINTER,
												ERROR_MSG_INVALID_INPUT,
												ERROR_MSG_INVALID_NAME_LENGHT,
												ERROR_MSG_INVALID_POSITION,
												ERROR_MSG_INVALID_MOVEMENT,
												ERROR_MSG_WRONG_TOKEN
												};

	std::cout<<errorMsg[st]<<std::endl;
}




