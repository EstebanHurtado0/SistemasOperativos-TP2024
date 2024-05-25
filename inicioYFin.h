#ifndef ENTRADASALIDA_INICIO_Y_FIN_H_
#define ENTRADASALIDA_INICIO_Y_FIN_H_

//----------- BIBLIOTECAS -----------

#include <../../utils/include/utils.h>
#include <../include/estructuras.h>
#include <../../utils/include/sockets.h>

// ----------- DECLARACION DE FUNCIONES ------------

t_config* iniciarConfig(char*);
t_valores cargarConfig(t_config*);
t_log* iniciarLogger(void);
void terminarPrograma(int, int, t_log*, t_config*);


#endif