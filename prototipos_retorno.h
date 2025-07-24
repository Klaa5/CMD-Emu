#ifndef PROTOTIPOS_RETORNO_H
#define PROTOTIPOS_RETORNO_H
#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

TipoRet CD (Sistema &s, Cadena nombreDirectorio);										//Finalizado
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio);									//Finalizado
TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio);									//Mateo
TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino);						//Mateo
TipoRet DIR (Sistema &s, Cadena parametro);												//Finalizado
TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo);									//Finalizado
TipoRet DELETE (Sistema &s, Cadena nombreArchivo);										//Finalizado
TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro);					//Finalizado
TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto);							//Finalizado
TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto);							//Finalizado
TipoRet DF (Sistema &s, Cadena nombreArchivo, int k);									//Finalizado
TipoRet DC (Sistema &s, Cadena nombreArchivo, int k);									//Finalizado
TipoRet TYPE (Sistema &s, Cadena nombreArchivo);										//Finalizado 
TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto);						//Finalizado
TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2);		//Finalizado
TipoRet CREARSISTEMA(Sistema &s);														//Finalizado
TipoRet DESTRUIRSISTEMA(Sistema &s);													//Finalizado
void Funcion(TipoRet retorno);

#endif
