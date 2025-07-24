#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

void crear_archivo(Sistema S, Cadena nombreArchivo);
void crear_directorio (Sistema S, Cadena nombreDirectorio);
Sistema inc (Sistema s,Cadena nombreArchivo, Cadena texto);
Sistema inf (Sistema s,Cadena nombreArchivo, Cadena texto);
Sistema df(Sistema s, Cadena nombreArchivo, int k);
void Type(Sistema s, Cadena nombreArchivo);
Sistema Attrib(Sistema s,Cadena nombreArchivo,Cadena parametro);
Sistema liberarMemoria(Sistema s);
bool Search (Sistema s,Cadena nombreArchivo,Cadena texto);
Sistema Replacer (Sistema s, Cadena nombreArchivo, Cadena texto1, Cadena texto2);
Sistema Deleteador (Sistema s, Cadena nombreArchivo);
Sistema dc(Sistema s, Cadena nombreArchivo, int k);
Sistema Cambiar_directorio(Sistema S, Cadena nombreDirectorio);
void dir(Sistema s, Cadena parametro);
void borradorDir(Sistema s,Cadena nombreDirectorio);
void mover(Sistema s, Cadena nombre, Cadena directorioDestino);

	
#endif
