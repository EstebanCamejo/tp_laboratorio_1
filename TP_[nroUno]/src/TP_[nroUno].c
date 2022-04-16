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


int main (void){
	setbuf(stdout, NULL);

	int opcion; // swich
	int respuestaMenu;// menu OK
	int respuesta1; // 1
	int kmIngresados; //1
	float respuesta2Latam; //2
	float latamPrecioTotalVuelo;
	float respuesta2Aerolineas;//2
	float aerolineasPrecioTotalVuelo;;//2
//-------------------------------------------------- VALIDACIONES
	int tarjetaDebitoLatam;// 3 LATAM
	int tarjetaCreditoLatam;// 3 LATAM
	int btcLatam;// 3 LATAM
	int KmLatam;// 3 LATAM
	int tarjetaDebitoAerolineas; // 3 AREOLINEAS
	int tarjetaCreditoAerolineas;// 3 AREOLINEAS
	int btcAerolineas;// 3 AREOLINEAS
	int KmAerolineas;// 3 AREOLINEAS
	int diferencia;
	//--------------------------------------------------
	int salir = 0;
	float resuladoDescuentoLatam;
	float resultadoDescuentoAerolineas;
	float descuento = 10;
	float resuladoInteresLatam;
	float resuladoInteresAerolineas;
	float interes = 25;
	float resultadoBitcoinLatam;
	float resultadoBitcoinAerolineas;
	float bitcoin = 4606954.55;
	float precioKMlatam;
	float precioKMaerolineas;
	float diffPrecios;
//	--------------------------------------------Carga forzada
	int valCargaFtarjetaDebitoLatam;
	float cargaFdescLatam;
	int valCargaFtarjetaDebitoAerolineas;
	float cargaFdescAero;
	int valCargaFtarjetaCreditoLatam;
	float cargaFintLatam;
	int valCargaFtarjetaCreditoAerolineas;
	float cargaFintAero;
	int valCargaFbtcLatam;
	float cargaFbtcLatam;
	int valCargaFbtcAerolineas;
	float cargaFbtcAero;
	int valCargaFKmLatam;
	float cargaFKMLatam;
	int valCargaFKmAerolineas;
	float cargaFKMAero;
	int valCargaFdiferencia;
	float cargaFDiff;

	int flagCaseDos = 0;
	int flagCaseTres = 0;

do {
	respuestaMenu = utn_getNumero(&opcion," Ingrese una opcion del 1 al 6. \n\n"
										"1- KMs del vuelo. \n"
										"2- Precio por aerolinea. \n"
										"3- Calculo segun tipo pago \n"
										"4- Informe de calculos. \n"
										"5- Carga forzada \n"
										"6- SALIR \n",
										" No es una opcion valida \n",1,6,9);

	if (respuestaMenu == 0){
		switch (opcion){

				case 1 :
					respuesta1 = utn_getNumero(&kmIngresados,"Ingresar Kilómetros:\n",
								"Por favor ingrese la cantidad de KMs",0,999999999,3);
						if (respuesta1 != 0	){
						printf("No fue posible realizar la operacion:\n");
						}
					break;

				case 2 :
					if (flagCaseDos == 0 ){
						respuesta2Latam = utn_getNumeroFloat(&latamPrecioTotalVuelo,"Ingresar Precio de Vuelos Latam:\n",
							"Por favor ingrese el precio del vuelo para Latam",0,999999999,3);
						respuesta2Aerolineas = utn_getNumeroFloat(&aerolineasPrecioTotalVuelo,"Ingresar Precio de Vuelos Aerolineas:\n",
							"Por favor ingrese el precio del vuelo para Aerolineas",0,999999999,3);
							if (respuesta2Latam == 0 && respuesta2Aerolineas == 0){
								flagCaseDos = 1;
							}
							else {
								printf("No fue posible realizar la operacion:\n");
							}
					}
					break;

				case 3 :
					if (flagCaseDos == 1){
						tarjetaDebitoLatam = calculoDescuento(&resuladoDescuentoLatam,latamPrecioTotalVuelo,descuento);//LATAM
						tarjetaDebitoAerolineas = calculoDescuento(&resultadoDescuentoAerolineas,aerolineasPrecioTotalVuelo,descuento);
						tarjetaCreditoLatam = calculoInteres(&resuladoInteresLatam,latamPrecioTotalVuelo, interes);
						tarjetaCreditoAerolineas = calculoInteres(&resuladoInteresAerolineas,aerolineasPrecioTotalVuelo, interes);
						btcLatam = calculoBitcoin(&resultadoBitcoinLatam, latamPrecioTotalVuelo, bitcoin);
						btcAerolineas = calculoBitcoin(&resultadoBitcoinAerolineas, aerolineasPrecioTotalVuelo, bitcoin);
						KmLatam = calculoDivision(&precioKMlatam,latamPrecioTotalVuelo, kmIngresados);
						KmAerolineas = calculoDivision(&precioKMaerolineas,aerolineasPrecioTotalVuelo,kmIngresados);
						diferencia = calculoDiferencia(&diffPrecios, latamPrecioTotalVuelo, aerolineasPrecioTotalVuelo);
						 if (tarjetaDebitoLatam != 0|| tarjetaDebitoAerolineas!= 0 || tarjetaCreditoLatam != 0 || tarjetaDebitoAerolineas!= 0 || btcLatam != 0 || btcAerolineas!= 0 || KmLatam != 0|| KmAerolineas != 0 || diferencia!= 0 ){
							 printf("No es posible realizar la operacion:\n Debe realizar el paso de la opcion 2");
						 }
						 else{
								flagCaseTres = 1;
						 }
					}
					break;

				case 4 :
						if(flagCaseTres == 1){
							imprimirResultado (kmIngresados,aerolineasPrecioTotalVuelo,resultadoDescuentoAerolineas,
									resuladoInteresAerolineas,resultadoBitcoinAerolineas,precioKMaerolineas,latamPrecioTotalVuelo,
									resuladoDescuentoLatam,resuladoInteresLatam,resultadoBitcoinLatam,precioKMlatam,diffPrecios);
						}
						else{
							printf("No es posible realizar la operacion:\n Debe realizar el paso de la opcion 3");
						}
						break;

				case 5 :
						valCargaFtarjetaDebitoLatam = calculoDescuento(&cargaFdescLatam,159339,descuento);
						valCargaFtarjetaDebitoAerolineas = calculoDescuento(&cargaFdescAero,162965,descuento);
						valCargaFtarjetaCreditoLatam = calculoInteres(&cargaFintLatam,159339, interes);
						valCargaFtarjetaCreditoAerolineas = calculoInteres(&cargaFintAero,162965, interes);
						valCargaFbtcLatam = calculoBitcoin(&cargaFbtcLatam, 159339, bitcoin);
						valCargaFbtcAerolineas = calculoBitcoin(&cargaFbtcAero, 162965, bitcoin);
						valCargaFKmLatam = calculoDivision(&cargaFKMLatam,159339, 7090);
						valCargaFKmAerolineas = calculoDivision(&cargaFKMAero,162965,7090);
						valCargaFdiferencia = calculoDiferencia(&cargaFDiff, 159339, 162965);
						if (valCargaFtarjetaDebitoLatam == 0 && valCargaFtarjetaDebitoAerolineas == 0 && valCargaFtarjetaCreditoLatam == 0
								&& valCargaFtarjetaCreditoAerolineas == 0 && valCargaFbtcLatam == 0 && valCargaFbtcAerolineas == 0
								&& valCargaFKmLatam == 0 && valCargaFKmAerolineas == 0 && valCargaFdiferencia == 0 )
						{
							printf ("KMs Ingresados: 7090 KM \n\n");
							printf ("Precio Aerolineas: $ 1335000.66 \n");
							printf ("a) Precio con tarjeta de debito: $ %2.f \n",cargaFdescAero);
							printf ("b) Precio con tarjeta de credito: $ %2.f \n",cargaFintAero);
							printf ("c) Precio pagado con bitcoin: %2.f BTC \n",cargaFbtcAero);
							printf ("d) Mostrar precio unitario : $ %2.f \n\n",cargaFKMAero);
							printf (" Precio Latam: $ 1350000.76 \n");
							printf ("a) Precio con tarjeta de debito: $ %2.f \n",cargaFdescLatam);
							printf ("b) Precio con tarjeta de credito: $ %2.f \n",cargaFintLatam);
							printf ("c) Precio pagado con bitcoin: %2.f BTC \n",cargaFbtcLatam);
							printf ("d) Mostrar precio unitario : $ %2.f \n\n\n",cargaFKMLatam);
							printf ("La diferencia de precios es: $ %2.f",cargaFDiff);
						}
						else {
							printf("No es posible realizar la operacion:\n");
						}
					break;
				case 6 : salir = -1; // En vez de usar la fx de salir desde ek while salgo cambiando respuestaMenu al valor 1.
						break;
					} // CIERRE DEL SWICH
				} // IF del RESPUESTA MENU
	} while (salir == 0);
	return EXIT_SUCCESS;
}

