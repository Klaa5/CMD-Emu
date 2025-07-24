#ifndef STRUCT_H
#define STRUCT_H
#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

using namespace std;

typedef char* Cadena;

typedef struct nodo
{
	Cadena nombre = new char [NOMBRE_MAX];
	Cadena contenido = new char [TEXTO_MAX];
	bool contiene_sn;									//true si contiene algo
	nodo *padre;
	nodo *hijo;
	nodo *hermano;
	int index;
	int asc = 0;										//Para ordenar alfabeticamente en DIR.
	bool wr;											//True si es legible y editable, false si es solo legible
	bool carpeta; 										//True si es carpeta, false si es archivo
	
}*Sistema;



#endif
