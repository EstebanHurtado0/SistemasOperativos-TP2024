//------------- BIBLIOTECAS --------------

#include <../include/inicioYFin.h>

//------------------- FUNCIONES -----------------------

//Funcion para iniciar el logger
t_log* iniciarLogger(void)
{
	t_log* nuevo_logger;
	nuevo_logger = log_create("entradasalida.log","ENTRADASALIDA",1,LOG_LEVEL_INFO);

	return nuevo_logger;
}

//Funcion para iniciar el config del main
t_config* iniciarConfig(char* path)
{
    t_config* nuevo_config = config_create(path);
	//t_config* nuevo_config = config_create("/home/utnso/Desktop/tp-2024-1c-BCM/entradasalida/entradasalida.config");
	//t_config* nuevo_config = config_create("/home/barla/Escritorio/tp-2024-1c-BCM/entradasalida/entradasalida.config");

	if(nuevo_config == NULL)
	{
		perror("Error al crear el config");

		exit(EXIT_FAILURE);
	}

	return nuevo_config;
}

//Funcion para cargar el config del main
t_valores cargarConfig(t_config* config)
{
    t_valores valores;

    valores.ipKernel = config_get_string_value(config,"IP_KERNEL");
	valores.puertoKernel = config_get_string_value(config,"PUERTO_KERNEL");
    valores.ipMemoria = config_get_string_value(config,"IP_MEMORIA");
	valores.puertoMemoria = config_get_string_value(config,"PUERTO_MEMORIA");
	valores.tipoInterfaz = config_get_string_value(config,"TIPO_INTERFAZ");
	valores.tiempoUnidadTrabajo = config_get_int_value(config,"TIEMPO_UNIDAD_TRABAJO");

    return valores;
}

//Funcion para librar los recursos
void terminarPrograma(int conexionKernel, int conexionMemoria, t_log* logger, t_config* config)
{
	config_destroy(config);
	close(conexionKernel);
    close(conexionMemoria);
	log_destroy(logger);
}

void* interfazGenerica(char* nombreInterfaz,char* path){
	t_config* config = iniciarConfig(path);
	t_valores valores = cargarConfig(config);
	
	enviarInterfaz(conexionKernel, INTERFAZ);
    enviarMensaje("Me llego la interfaz", conexionKernel);
   
}