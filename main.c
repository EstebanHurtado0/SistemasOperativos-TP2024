//------------BIBLIOTECAS------------

#include <../include/estructuras.h>
#include <../include/inicioYFin.h>
#include <../include/planificador.h>

//------------CODIGO MAIN INTERFAZ------------

int main(int argc, char* argv[])
{
    //Declaro las variables necesarias
    char* entrada;
    char* texto;
    char* nombreInterfaz;
    char* filepath;

    //Inicializo un logger
    t_log* logger = iniciarLogger();
    log_info(logger,"Arranco la interfaz");

    //Inicializo el config y cargo sus valores
    t_config* config = iniciarConfig();
    t_valores valores = cargarConfig(config);

    //Creo las conexiones
    int conexionKernel = crearConexion(valores.ipKernel,valores.puertoKernel, logger); 
    int conexionMemoria = crearConexion(valores.ipMemoria,valores.puertoMemoria, logger);

    //------------CONSOLA INTERACTIVA------------

    //!COMENTAR EL CODIGO
    entrada = readline("> Ingrese el tipo de interfaz que desea iniciar:  ");
    log_info(logger,">> %s",entrada);
    
    while (strcmp(entrada,"") !=0 )
    {    
        if(strcmp(entrada,"GENERICA") == 0)
        {
            log_info(logger, "Interfaz Generica Conectada ");
            //Pido el nombre de la interfaz
            nombreInterfaz = readline(">> Ingrese nombre de la interfaz Generica: ");
            filepath = readline(">> Ingrese el path del archivo .config");
            
            t_config* configGenerica = iniciarConfig(filepath);
            t_valores valoresGenericas = cargarConfig(configGenerica);

            enviarInterfaz(conexionKernel, INTERFAZ);
            enviarMensaje("Me llego la interfaz", conexionKernel);
            log_info(logger,"Interfaz %s enviada al kernel con el identificador #%d correctamente\n", nombreInterfaz, TECLADO);
        }

        if (strcmp(entrada,"STDIN") == 0)
        {
             log_info(logger, "Interfaz Generica Conectada ");
            //Pido el nombre de la interfaz
            texto = readline(">> Ingrese el texto de la interfaz STDIN: ");
            enviarMensajeStdin(texto,conexionMemoria);
            log_info(logger,"Texto enviado a memoria");
        }

		free(entrada);
        break;
    }

    //------------BUCLE INFINITO------------

    while(1)
    {
        //Espero a recibir un codigo de operacion
        op_code codOp = recibirOperacion(conexionKernel);
        
        //Checkeo que realmente sea una peiticion para una interfaz generica
        if(codOp == PETICION_GENERICA)
        {
            //Recibo la cantidad de unidades
            u_int8_t unidades;
            recibirSleep(conexionKernel, &unidades, logger);
            
            unidades = unidades * valoresGenerica.tiempoUnidadTrabajo;
            //Hago el sleep
            sleep(unidades);

            log_info(logger, "TERMINE EL SLEEP");
        }
    }
    
    //Libero recursos
    terminarPrograma(conexionKernel, conexionMemoria,logger,config);

    return 0;
}