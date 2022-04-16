/*
 * utn_getNumero.h
 *
 *  Created on: 12 abr 2022
 *      Author: Usuario
 */
#ifndef UTN_GETNUMERO_H_
#define UTN_GETNUMERO_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);//menu OK
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int calculoDescuento(float* resultadoDescuento, float precio, float descuento);
int calculoInteres(float* resultadoInteres, float precio, float interes);
int calculoBitcoin(float* resultadoBitcoin, float precio, float bitcoin);
int calculoDivision(float* resultadoDivision,float operador1, float operador2);
int calculoDiferencia(float* resuladoDiferencia, float operador1, float operador2);
void imprimirResultado (int kms ,float precio1, float formaDePago1,float formaDePago2,float formaDePago3,float formaDePago4,float precio2, float formaDePago5, float formaDePago6, float formaDePago7, float formaDePago8,  float diffDePago);

#endif /* UTN_GETNUMERO_H_ */
