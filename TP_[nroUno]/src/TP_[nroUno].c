/*
 ============================================================================
 Name        : TP_[nroUno].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_getNumero.h"

int utn_getNumero ();

int utnTP1calculo (char* pResultado, float operador1, float operador2, float operador3);

int main (void){
	setbuf(stdout, NULL);

	int opcion;
		// ingresa en el 1 CANT de KM totales del vuelo
	float kmIngresados;
	char resultado;
	float latamPrecioTotalVuelo;
	float aerolineasPrecioTotalVuelo;
	int respuesta;
	int respuestaMenu;
	int salir;
	//int precioTotal;

	// meter todo el swich dentro de un do while

	respuestaMenu = utn_getNumero(&opcion," Ingrese una opcion del 1 al 6. \n 1- KMs del vuelo. \n2- Precio por aerolinea. \n3- Calculo segun tipo pago \n4- Informe de calculos. \n5- Carga forzada 6- SALIR \n", " No es una opcion valida \n",1,3,2);
	if (respuestaMenu == 0){


	}

do {
		switch (opcion){

			case 1 :
				printf("Ingresar Kil�metros:\n");
				scanf("%d", &kmIngresados);
				// agregar el if de comprobacion numero
				break;

			case 2 :
				printf("Ingresar Precio de Vuelos Latam:\n");
				scanf("%d", &latamPrecioTotalVuelo);

				// agregar el if de comprobacion numero
				printf("Ingresar Precio de Vuelos Aerolineas:\n");
				scanf("%d", &aerolineasPrecioTotalVuelo);

				// agregar el if de comprobacion numero

				break;

			case 3 :

				break;

			case 4 :
				respuesta = utnTP1calculo (&resultado, latamPrecioTotalVuelo, aerolineasPrecioTotalVuelo, kmIngresados);
				if (respuesta == 0)
					{
						printf(resultado);
					}
					else{
						printf("No es posible realizar la operacion. Ingrese los datos nuevamente \n");
					}
				break;

			case 5 : // carga forzada
				break;

			case 6 : salir = -1;
				break;
			}

	} while (salir == -1 );

	//El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
	// hay que ponerle un precio al km de cada empresa


	/* MENU
	int respuesta;

	do {
		respuesta = utn_getNumero(&opcion,"Selecione una opcion \n \n 1- Leer \n 2- Mostrar \n 3- Salir\n ","No es una opcion valida\n",1,3,2)
			if (respuesta == 0){
				switch(opcion){

					case 1:
						printf("Entre al caso 1\n");
						break;
					case 2:
						printf("Entre al caso 1\n");
						break;
					}
			}
	}while (opcion != 3);*/

	return EXIT_SUCCESS;
}
