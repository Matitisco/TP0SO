#include "client.h"



int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	//-----------  logger = iniciar_logger();

	logger = log_create("/home/utnso/Documents/tp0/tp0.log","prueba",true, LOG_LEVEL_INFO);



	log_info(logger, "asd");


	//log_destroy(logger);

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */
/*
	char* juan;
	char* a="asd";

	config = config_create("/home/utnso/Documents/tp0/tp0.config");

	if( config == NULL){
		printf("No encontro tp0.config ");
	}

	juan = config_get_string_value(config,"VALOR");


	log_info(logger, juan);
	//log_destroy(logger);
	config_destroy(config);

*/

	/* ---------------- LEER DE CONSOLA ---------------- */

	//Usamos readline.h para esto.

	/*Recuerden que readline() no te libera la memoria que devuelve,
	 por lo que es necesario liberarla usando free(1).
	*/

	//Leer la guia de readline() si necesitas mas info (en la pagina utnso->tp0->parte de Leer consola)

	//char* leer;
	//leer = readline("> ");

	//log_info(logger,leer);

	//log_destroy(logger);


	/* ---------------- STRINGS ---------------- */

	//TP0 Tiene que leer todas las lineas que se ingresen y loguearlas
	//Si se ingresa una vacia, terminar con el programa
/*
	char* leer;

	leer = readline("> ");
	log_info(logger,leer);

	while(leer[0] != '\0'){

		leer = readline("> ");
		log_info(logger,leer);

	}
	log_destroy(logger);
*/

	/* ---------------- ETAPA 3: CLIENTE-SERVIDOR ---------------- */

	/* ---------------- IMPORTANTE LEER: PARA MANEJAR VARIAS CONSOLAS, UNA POR EL SERVER Y OTRA POR EL CLIENTE TENES QUE IR AL APARTADO DE CONSOLA Y BUSCAR EL ICONITO, TIENE UNA FLECHA PARA ABAJO CHIQUITA QUE TOCANDOLA TE MUESTRA TODAS LAS CONSOLAS. ---------------- */
	/*--------------- PARA EJECUTAR EL CLIENTE LE DAS RUN ESTANDO PARADO EN CLIENTE, PARA EL SERVER LE DAS RUN ESTANDO PARADO EN SERVER ---------------- */
	//Cualquier cosa consultenme

	//El objetivo es
	/* 1)Enviarle al servidor el valor de CLAVE(config)
	 * 2)Luego enviarle todas las lineas que se ingresaron por
	  consola juntas en paquete
	*/




	config = config_create("/home/utnso/Documents/tp0/tp0.config");
	char* clave;

	clave = config_get_string_value(config, "CLAVE");


	log_info(logger,clave);
	//log_info(logger,leer1);


	/*-----------	CONEXION AL SERVIDOR	-------------*/

	// 1) iniciar_servidor() se hace en el server.c
	// 2) esperar_cliente() se hace en el server.c

	// 3) crear_conexion(ip, puerto) se hace en el client.c
	int socket_cliente;
	socket_cliente = crear_conexion("127.0.0.1","4444");

	// 4) enviar_mensaje(Config, socket_cliente) se hace en client.c

	enviar_mensaje(clave, socket_cliente);



	/*-----------	FIN DE EXPLICACION UTILS	-------------*/


	/*-----------	CONTINUO JUNTANDO LINEAS POR CONSOLA Y ENVIANDOLAS	-------------*/


	char* leer;
	t_paquete* paqueteConsola; //Nos sirve para mandar mucha info junta, ya que sino no se puede

	paqueteConsola = crear_paquete(); //Nos crea/devuelve el paquete que vamos a mandar.


	leer = readline("> ");
	log_info(logger,leer);

	agregar_a_paquete(paqueteConsola,leer, strlen(leer)+1 ); //Dado un stream(el *char) y su tamaño, lo agrega al paquete.



	//Leo y guardo la consola hasta que se ingrese algo en blanco
	while(leer[0] != '\0'){
		leer = readline("> ");
		log_info(logger,leer);
		agregar_a_paquete(paqueteConsola,leer, strlen(leer)+1 );
	}


	//Envio el paquete al server.c

	enviar_paquete(paqueteConsola,socket_cliente);

	//Elimino cosas

	eliminar_paquete(paqueteConsola);
	log_destroy(logger);
	config_destroy(config);

	/*-----------	CIERRO LA CONEXION	-------------*/

	//libero el socket
	liberar_conexion(socket_cliente);



	/*-----------	NOTAS IMPORTANTISIMAS	-------------*/

	//LA EXPLICACION DE LAS FUNCIONES ESTA:
	//EN LA PAGINA DE UTNSO->TP0->ETAPA3->APARTADO "Funciones"
	//Sino podes ver su funcionalidad poniendo el cursor sobre la funcion y haciendo CTRL+CLICK

	//Es necesario pegarle una leida a los apuntes que van tirando a lo largo del TP0 (guia sockets, guia serializacion,etc)

}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
