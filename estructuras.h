#ifndef ENTRADASALIDA_ESTRUCTURAS_H_
#define ENTRADASALIDA_ESTRUCTURAS_H_

//----------------- ESTRUCTURAS DE CONFIGURACIONES-----------------------

//Estructura para leer el config
typedef struct
{
    char* ipKernel;
	char* puertoKernel;
    char* ipMemoria;
	char* puertoMemoria;
	char* tipoInterfaz;
	int tiempoUnidadTrabajo;
}t_valores;

typedef struct
{
    char* ipKernel;
	char* puertoKernel;
    char* ipMemoria;
	char* puertoMemoria;
	char* tipoInterfaz;
	int tiempoUnidadTrabajo;
}t_valores_gen;

typedef struct
{
    char* ipKernel;
	char* puertoKernel;
    char* ipMemoria;
	char* puertoMemoria;
	char* tipoInterfaz;
	int tiempoUnidadTrabajo;
}t_valores_stdin;

typedef struct
{
    char* ipKernel;
	char* puertoKernel;
    char* ipMemoria;
	char* puertoMemoria;
	char* tipoInterfaz;
	int tiempoUnidadTrabajo;
}t_valores_stdout;

#endif