/*
 * type.h
 *
 *  Created on: 28 sep. 2021
 *      Author: lucho
 */

#ifndef TYPE_H_
#define TYPE_H_

#include <iostream>


/* La asignación extra en cada elemento del tipo enumerativo se realiza por si
 * en algun futuro una persona que utilice el codigo elige ordenarlo alfabeticamente
 *  no cambia los mensajes que imprima la funcion 'showError()'. De esta forma
 *  el cambio alfabetico no modifica la funcionalidad del programa*/
typedef enum {
				OK = 0,
				ERROR_NULL_POINTER = 1,
				ERROR_INVALID_INPUT = 2,
				ERROR_INVALID_NAME_LENGTH = 3,
				ERROR_INVALID_POSITION = 4,
				ERROR_INVALID_MOVEMENT = 5,
				ERROR_WRONG_TOKEN = 6
			}status_t;

typedef enum {
			TRUE,
			FALSE
			}bool_t;

typedef unsigned int uint;



#endif /* TYPE_H_ */
