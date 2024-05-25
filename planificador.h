#ifndef ENTRADASALIDA_PLANIFICADOR_H_
#define ENTRADASALIDA_PLANIFICADOR_H_

//------------BIBLIOTECAS------------

#include <../../utils/include/utils.h>
#include <../include/estructuras.h>
#include <../../utils/include/comunicacion.h>

//------------DECLARACION DE FUNCIONES------------

void interfazGenerica(char*,t_config*);
void interfazSTDIN(char*, t_config*);
t_config* iniciarConfig(void);

#endif