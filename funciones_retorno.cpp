#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

using namespace std;
TipoRet CD (Sistema &s, Cadena nombreDirectorio)
{
	
	if(s != NULL && comprobador(s,nombreDirectorio))
	{
		bool pass = true;
		
		if(strcmp("..",nombreDirectorio) == 0)		//Ir a directorio anterior
		{
			s = s->padre;
			pass = false;
		}
		
		if(strcmp("RAIZ",nombreDirectorio) == 0)	//Ir a raiz
		{
			s = root(s);
			pass = false;
		}
		
		if(pass == true) 		//Si no es para ir a dir anterior o a raiz
		{
			s = Cambiar_directorio(s->hijo,nombreDirectorio);
			
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
	
	
	
	
}
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio)
{
	if (s != NULL && strlen(nombreDirectorio) <= 15) 
	{
		if (!strchr(nombreDirectorio,'.')) 
		{
			if (s != NULL && !dir_existe(s,nombreDirectorio) && strcmp(nombreDirectorio,"RAIZ")	&& strcmp(nombreDirectorio,"Raiz") && strcmp(nombreDirectorio,"raiz") && strlen(nombreDirectorio) != 0) 
			{	
				crear_directorio(s,nombreDirectorio);
				
				return OK;
			}
			else
			{
				return ERROR;
			}
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}
TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio)
{
	
	if(s != NULL && dir_existe(s,nombreDirectorio))
	{
		borradorDir(s,nombreDirectorio);
		
		return OK;
	}
	else
	{
		return ERROR;
	}
	
	
}
TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino)
{
	if (dir_existe(s,nombre) || archivo_existe_modificable(s,nombre,'n')) 
	{
		/*mover(s,nombre,directorioDestino);*/
		return NO_IMPLEMENTADA;
	}
	else
	{
		return ERROR;
	}
}
TipoRet DIR (Sistema &s, Cadena parametro)
{
	
	if (s != NULL) 
	{
		sp();
		dir(s,parametro);
		sp();
		return OK;
	}
	
	return ERROR;
}

TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo)
{


	if (s != NULL && pase(nombreArchivo)) 
	{
		if (verificador(nombreArchivo)) //Se verifica que si tenga una extensión válida.
		{
			if (!archivo_existe_modificable(s,nombreArchivo,'n'))
			{
				crear_archivo(s, nombreArchivo);
				
				return OK;
			}
		}
		
	}
	
	
	
	return ERROR;
	
}
TipoRet DELETE (Sistema &s, Cadena nombreArchivo)
{
	
	if (s != NULL) 
	{
		if(archivo_existe_modificable(s,nombreArchivo,'s'))
		{
			
			s = Deleteador(s,nombreArchivo);
			
			return OK;
			
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro)
{	
	Cadena cont = new char[3];
	Cadena cont2 = new char[3];
	strcpy(cont,"+W");				//Se almacena el parametro para comparar
	strcpy(cont2,"-W");				//Se almacena el parametro para comparar
	
	if(s != NULL && archivo_existe_modificable(s,nombreArchivo,'n')) //Si existe el archivo especificado entra
	{
		if (strcmp(parametro,cont) == 0 || strcmp(parametro,cont2) == 0)
		{
			s = Attrib(s,nombreArchivo,parametro);
			
			return OK;	
		}
		else
		{
			
			return ERROR;
		}
	}
	else
	{
		
		return ERROR;
	}
}

TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto)
{
	
	if(archivo_existe_modificable(s,nombreArchivo,'s')) //Si existe el archivo especificado y es modificable entra
	{
		s = inc(s,nombreArchivo,texto);
		
		return OK;
	}
	else
	{
		return ERROR;
		
	}
	
	
}

TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto)
{

	if(archivo_existe_modificable(s,nombreArchivo,'s')) //Si existe el archivo especificado y es modificable entra
	{
		s = inf(s,nombreArchivo,texto);
		
		return OK;
	}
	else
	{
		return ERROR;
		
	}
	
	
}

TipoRet DF (Sistema &s, Cadena nombreArchivo, int k)
{
	
	if(archivo_existe_modificable(s,nombreArchivo,'s')) //Si existe el archivo especificado y es modificable entra
	{
		s = df(s,nombreArchivo,k);
		
		return OK;
	}
	else
	{
		return ERROR;
		
	}
	
}

TipoRet DC (Sistema &s, Cadena nombreArchivo, int k)
{
	if(archivo_existe_modificable(s,nombreArchivo,'s')) //Si existe el archivo especificado y es modificable entra
	{
		s = dc(s,nombreArchivo,k);
		
		return OK;
	}
	else
	{
		return ERROR;
		
	}
}

TipoRet TYPE (Sistema &s, Cadena nombreArchivo)
{
	if(archivo_existe_modificable(s,nombreArchivo,'n')) //Si existe el archivo especificado entra
	{
		Type(s,nombreArchivo);
		
		return OK;
	}
	else
	{
		return ERROR;
	}
}
	
TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto)
{
	if (s != NULL && archivo_existe_modificable(s,nombreArchivo,'n'))
	{
		if (Search(s,nombreArchivo,texto))
		{
			return OK;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2)
{
	if (archivo_existe_modificable(s,nombreArchivo,'s')) 
	{
		Sistema s_aux = new nodo;
		s_aux = s;
		
		s_aux = buscador(s->hijo,nombreArchivo);
		
		if (strlen(s_aux->contenido) != 0 && Search(s,nombreArchivo,texto1)) 	//Busca si existe el texto en ese archivo.
		{
			s_aux = Replacer(s_aux,nombreArchivo,texto1,texto2);
			
			return OK;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

TipoRet CREARSISTEMA(Sistema &s)
{
	
	s = crear_sistema();
	
	return OK;
	
}

TipoRet DESTRUIRSISTEMA(Sistema &s)
{
	s = root(s);				//Lleva el puntero hacia la raíz para borrar todo.
	s = liberarMemoria(s); 
	
	return OK;
	
}
void Funcion(TipoRet retorno)
{
	
	switch(retorno)
	{
		case OK:					cout << "OK" << endl;					break;
		
		case ERROR:					cout << "ERROR" << endl;				break;
		
		case NO_IMPLEMENTADA:		cout << "NO IMPLEMENTADO" << endl;		break;	
	}
	
}
