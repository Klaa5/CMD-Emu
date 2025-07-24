#ifndef PROTOTIPOS_B_H
#define PROTOTIPOS_B_H
#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

Sistema crear_sistema();
void 	mostrar_temporal(Sistema s);
void 	sp();
bool 	es_null(Sistema s);
bool 	archivo_existe_modificable(Sistema s,Cadena nombreArchivo,char n);
bool 	dir_existe(Sistema s, Cadena nombreDirectorio);
Sistema buscador(Sistema S, Cadena nombreArchivo);
void 	compatibilidad(char so,char o);
int 	contador_de_nodos(Sistema s,bool carpeta);
Sistema Puntero_anterior(Sistema s, Cadena nombreArchivo);
bool 	verificador(Cadena nombreArchivo);
Cadena  detectorI(Cadena ingreso);												//Guarda n carácteres antes del primer espacio.
Cadena  detectorII(Cadena ingreso);												//Guarda n carácteres luego del primer espacio y antes del segundo.
Cadena  eliminar_primer_elemento(Cadena ingreso);
Cadena  detectorIII(Cadena ingreso, Cadena t_anterior);
int 	detectorIV(Cadena ingreso,Cadena t_anterior);
Cadena  detectorV(Cadena ingreso, Cadena t_anterior);
Cadena  detectorVI(Cadena ingreso);
Cadena  eliminar_ultima_comilla(Cadena ingreso);
Sistema ultimo_hermano(Sistema S);
Sistema root(Sistema S);
bool 	comprobador(Sistema S, Cadena nombreDirectorio);
void 	direccion(Sistema D);
void 	imprime(int cant, Sistema s, bool C);
void 	mensaje(string comando);
void 	mostrar_ruta_ARC(Sistema s);
void 	mostrar_ruta_DIR(Sistema s);
Sistema buscadorII(Sistema s, Cadena elemento);
Sistema Puntero_anterior_DIR(Sistema s, Cadena nombreDirectorio);
int 	tam_ext(Cadena ingreso);
bool 	pase(Cadena nombreArchivo);
Sistema buscar_FULL(Sistema S, Cadena nombre);
Cadena  acortador(Cadena direccion);
Cadena detector_D1(Cadena ingreso);

#endif
