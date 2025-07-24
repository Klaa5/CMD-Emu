#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

using namespace std;

void crear_archivo(Sistema S, Cadena nombreArchivo)	//Es un ingreso al inicio, hacerlo al final estaria bueno
{
	Sistema nuevonodo = new nodo;
	nuevonodo->nombre = nombreArchivo;
	strcpy(nuevonodo->contenido,"");
	nuevonodo->contiene_sn = false;
	nuevonodo->padre = S;
	nuevonodo->hijo = NULL;
	nuevonodo->hermano = NULL;
	nuevonodo->wr = true;
	nuevonodo->carpeta = false;
	
	if(S->hijo != NULL)	//Significa que ya hay uno o más elementos en ese directorio.
	{
		S = ultimo_hermano(S->hijo); //Al existir elementos en ese dir, se buscará el ultimo elemento de sus hijos.
		S->hermano = nuevonodo;
	}
	else	//Si el directorio no tiene elementos (es null hijo)
	{
		S->hijo = nuevonodo;	//Se ingresa ese nodo como el primero;
	}
}

void crear_directorio(Sistema S, Cadena nombreDirectorio)
{
	Sistema nuevonodo = new nodo;
	nuevonodo->nombre = nombreDirectorio;
	nuevonodo->contenido = NULL;			//Cambiar si no funciona como se esperaba.
	nuevonodo->contiene_sn = false;
	nuevonodo->padre = S;
	nuevonodo->hijo = NULL;
	nuevonodo->hermano = NULL;
	nuevonodo->wr = false;
	nuevonodo->carpeta = true;
	
	if(S->hijo != NULL)	//Significa que ya hay uno o más elementos en ese directorio.
	{
		S = ultimo_hermano(S->hijo); //Al existir elementos en ese dir, se buscará el ultimo elemento de sus hijos.
		S->hermano = nuevonodo;
	}
	else	//Si el directorio no tiene elementos (es null hijo)
	{
		S->hijo = nuevonodo;	//Se ingresa ese nodo como el primero;
	}
}

Sistema inc (Sistema s, Cadena nombreArchivo, Cadena texto) //Ingreso al inicio
{
	Sistema s_aux = new nodo;
	
	s_aux = buscador(s->hijo,nombreArchivo); //Busca la ubicacion de ese nodo exacto.
	
	
	// Si lo encontró y ya tiene algo contenido...
	if(s != NULL && s_aux->contiene_sn == true) 
	{
		int *l = new int;
		
		*l = strlen(s_aux->contenido) + strlen(texto);	//Suma del total de esas dos cadenas.
		
		if (*l <= TEXTO_MAX) //Si los espacios de la cadena alcanzan.
		{
			s_aux->contenido = strcat(texto,s_aux->contenido); //Almacena lo que tiene s->contenido en texto, y eso luego queda dentro de s->contenido, de esta manera queda al inicio
		}
		else
		{
			Cadena almacen = new char[100];			//Se crea un almacen de gran capacidad.
			
			strcpy(almacen,texto);					//Se copia el texto ingresado primero.
			
			*l = strlen(almacen);					//Se averigua que tan grande es el espacio que ocupa.
			*l = TEXTO_MAX - *l;					//Se consigue el espacio que quedaría libre en la cadena.
			
			strncat(almacen,s_aux->contenido,*l);	//Se ingresa lo que se pueda sobre el espacio libre.
			
			strcpy(s_aux->contenido,"");			//Se vacía el contenido del archivo.
			strcpy(s_aux->contenido,almacen);		//Se guarda el resultado en el archivo.
			
			delete almacen;							//Libera espacios de memoria.
		}
	}
	
	//Si el archivo estaba vacío.
	if(s_aux != NULL && s_aux->contiene_sn == false) //Se averigua si es el primer dato a ingresar, es editable y si es carpeta
	{
		int *l = new int;
		
		*l = strlen(s_aux->contenido) + strlen(texto);	//Suma del total de esas dos cadenas.
		
		if (*l <= TEXTO_MAX) 
		{
			s_aux->contenido = texto;		//Se ingresa texto.
			s_aux->contiene_sn = true;		//Se modifica estado a archivo con contenido.
		}
		else
		{
			Cadena almacen = new char[100];					//Se crea un almacen de gran capacidad.
			
			strcpy(almacen,texto);							//Se almacena texto ingresado en el almacen.
			
			strncat(s_aux->contenido,almacen,TEXTO_MAX);	//Se ingresa el contenido de almacen hasta llenar los espacios libres de archivo.
		}
		
	}

	
	s_aux = s;
	
	return s;
}
Sistema inf (Sistema s,Cadena nombreArchivo, Cadena texto)	//Ingreso al final
{
	Sistema s_aux = new nodo;

	
	s_aux = buscador(s->hijo,nombreArchivo); 	//Busca la ubicacion de ese nodo exacto.
	
	
	if(s_aux != NULL && s_aux->contiene_sn == true) // Si ya tiene algo contenido...
	{
		int *l = new int;
		
		*l = strlen(s_aux->contenido) + strlen(texto);	//Suma del total de esas dos cadenas.
		
		
		if (*l <= TEXTO_MAX) //Si los espacios de la cadena alcanzan.
		{
			strcat(s_aux->contenido,texto); 		//Almacena el contenido de texto al final de s->contenido.
		}
		else	//Si no alcanza la cadena...
		{
			Cadena almacen = new char[100];		//Se crea un almacen de gran capacidad.
			
			strcpy(almacen,s_aux->contenido);	//Se copia el texto contenido en el archivo primero.
			
			*l = strlen(almacen);				//Se averigua que tan grande es el espacio que ocupa.
			*l = TEXTO_MAX - *l;				//Se consigue el espacio que quedaría libre en la cadena.
			
			strncat(almacen,texto,*l);			//Se ingresa lo que se pueda sobre el espacio libre.
			
			strcpy(s_aux->contenido,"");		//Se vacía el contenido del archivo.
			strcpy(s_aux->contenido,almacen);	//Se guarda el resultado en el archivo.
			
			delete almacen;						//Libera espacios de memoria.
			
		}
		
		delete l; //Se libera la memoria.
		
	}
	
	//Esta parte solo ingresa texto 
	if(s_aux != NULL && s_aux->contiene_sn == false) //Se averigua si es editable y si es carpeta.
	{
		int *l = new int;
		
		*l = strlen(s_aux->contenido) + strlen(texto);	//Suma del total de esas dos cadenas.
		
		if (*l <= TEXTO_MAX) 
		{
			s_aux->contenido = texto;		//Se ingresa texto.
			s_aux->contiene_sn = true;		//Se modifica estado a archivo con contenido.
		}
		else
		{
			Cadena almacen = new char[100];		//Se crea un almacen de gran capacidad.
			
			strcpy(almacen,texto);				//Se almacena texto ingresado en el almacen.
			
			strncat(s_aux->contenido,almacen,TEXTO_MAX);	//Se ingresa el contenido de almacen hasta llenar los espacios libres de archivo.
		}
		
	}

	
	s_aux = s;
	
	return s;
}

Sistema df(Sistema s, Cadena nombreArchivo, int k)
{
	Sistema s_aux = new nodo;
	
	Cadena aux = new char[10]; 						//Creo cadena auxiliar.
	int *largo = new int;							//Numero necesario para la operación.
	
	s_aux = buscador(s->hijo,nombreArchivo); 				//Busca la ubicacion de ese nodo exacto.
	
	if (s_aux != NULL) //Se almacena el largo del texto objetivo si lo encuentra.
	{		
		*largo = strlen(s_aux->contenido); 				
	}
	

	if(s_aux != NULL && s_aux->contiene_sn == true && k < *largo ) // Si la cantidad de caracteres a borrar son menores que el contenido...
	{
		
		strcpy(aux,""); 									//Ingreso "vacio" a la cadena auxiliar.
		*largo = *largo - k;
		strncat(aux,s_aux->contenido,*largo);				//Sobre la cadena vacía solo se ingresará lo que contiene 'contenido' hasta k.
		strcpy(s_aux->contenido,aux);						//Se ingresa el contenido de la cadena aux antes vacia a contenido.
		
		s_aux = s;
		
		return s;
	}
	
	if(s_aux != NULL && s_aux->contiene_sn == true && k >= *largo ) // Si la cantidad de caracteres a borrar son mayores que el contenido...
	{
		strcpy(s_aux->contenido,""); //Si 'k' es mayor o igual a la cantidad de letras en contenido, quedará vacío.
		
	}
	
	s_aux = s;
	
	return s;
}

void Type(Sistema s, Cadena nombreArchivo)
{
	Sistema s_aux = new nodo;
	
	s_aux = buscador(s->hijo,nombreArchivo);	//Si lo encontró entra.
	
	if (s_aux != NULL)	//Si no está vacío...
	{
		
		if (strlen(s_aux->contenido) != 0) //Si no está vacio de contenido muestra
		{
			sp();
			cout << "\n" << s_aux->contenido << endl;
			sp();
		}
		else					//Si está vacío no muestra nada
		{
			sp();
			cout << "\n" << endl;
			sp();
		}
	}
}

Sistema Attrib(Sistema s,Cadena nombreArchivo,Cadena parametro)
{
	Sistema s_aux = s->hijo;	//Se crea puntero auxiliar y se ubica dentro del directorio.	

	Cadena cont = new char[3];
	Cadena cont2 = new char[3];
	strcpy(cont,"+W");
	strcpy(cont2,"-W");

	
	s_aux = buscador(s_aux,nombreArchivo);	//Se busca el archivo especificado dentro del directorio.
	
	if (s_aux != NULL)
	{
		if (strcmp(parametro,cont) == 0)
		{
			s_aux->wr = true;
		}
		else 
		{
			if (strcmp(parametro,cont2) == 0)
			{
				s_aux->wr = false;
			}
		}
	}
	
	s_aux = s;
	

	delete cont;
	delete cont2;
	
	return s;
}

Sistema liberarMemoria(Sistema s)
{	
	if(s != NULL)
	{
		liberarMemoria(s->hermano);
		liberarMemoria(s->hijo);
		delete s;
	}
	
	return NULL;
}

bool Search (Sistema s, Cadena nombreArchivo, Cadena texto)
{
	Sistema s_aux = new nodo;
	
	s_aux = buscador(s->hijo,nombreArchivo);
	
	if (s_aux != NULL )
	{
		if (strcmp(texto, s_aux->contenido) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

Sistema Replacer (Sistema s, Cadena nombreArchivo, Cadena texto1, Cadena texto2)
{	
	strcpy(s->contenido,texto2); 
	
	return s;
}

Sistema Deleteador (Sistema s, Cadena nombreArchivo)
{
	Sistema s_aux = s->hijo;
	Sistema s_aux2 = s->hijo;
	
	if(s_aux2->hermano != NULL) 	//Si no es el único nodo del directorio...
	{
		
		if(strcmp(s_aux->nombre,nombreArchivo) == 0 )	//Si es el primer elemento de los hijos.
		{
			
			s_aux = s_aux2->hermano;	//Aux se posiciona en el que será el nuevo primer elemento.
			
			s->hijo = s_aux;	//Segundo nodo asignado como primer hijo.
			
			delete s_aux2;		//Se borra el antiguo primer nodo.
			
			return s;
			
		}
		
		s_aux2 = buscador(s_aux2,nombreArchivo);	//Si es un nodo que no sea el primero lo busca.
		
		if (s_aux2->hermano != NULL) 	//Si no es el último nodo del directorio...
		{	
			s_aux = Puntero_anterior(s_aux->padre->hijo,nombreArchivo);		//Busco la direccion del nodo anterior al objetivo.
			
			s_aux->hermano = s_aux2->hermano;								//El nodo anterior apuntará al siguiente.
			
			delete s_aux2;													//Se libera el espacio de memoria del nodo borrado.
			
			return s;
		}
		else			//Si es el último nodo de del directorio
		{
			s_aux = Puntero_anterior(s_aux->padre->hijo,nombreArchivo);		//Se busca la direccion de memoria del nodo anterior a obj.
			
			s_aux->hermano = NULL;								//Ahora el nodo anterior será el ultimo.
			
			delete s_aux2;									//Nodo objetivo borrado.
			
			return s;
			
		}
	}
	else	//Caso que sea el unico nodo del directorio.
	{
		delete s_aux2;
		s->hijo = NULL;
		return s;
	}
	
	return s;
	
}

Sistema dc(Sistema s, Cadena nombreArchivo, int k)
{
	
	Sistema s_aux = new nodo;
	
	s_aux = buscador(s->hijo,nombreArchivo); 				//Busca la ubicacion de ese nodo exacto.
	
	int *largo = new int;
	
	*largo = strlen(s_aux->contenido);
	
	char aux[k-1];
	char aux2[*largo];
	
	int cont = 0;
	
	strcpy(aux2,s_aux->contenido);
	
	for (int ct = 0; ct < *largo; ct++)
	{
		if(s_aux->carpeta == false && s_aux->contiene_sn == true && k <= ct)
		{
			aux[cont] = aux2[ct];
			cont++;
		}
	}
	
	strcpy(s_aux->contenido,aux);
	
	return s;
}

Sistema Cambiar_directorio(Sistema S, Cadena nombreDirectorio)
{
	
	if(S != NULL)
	{
		if(strcmp(S->nombre,nombreDirectorio) == 0 && S->carpeta == true)
		{
			return S;
		}
		else
		{
			return Cambiar_directorio(S->hermano,nombreDirectorio);
			return Cambiar_directorio(S->hijo,nombreDirectorio);
		}
	}
	else
	{
		return S;
	}
	
}

void dir(Sistema s, Cadena parametro)
{	
	
	if (strlen(parametro) == 0) 
	{
		Sistema aux = s;								//Puntero auxiliar.
		bool vacio = false;
		
		if (s->hijo != NULL) 
		{
			s = s->hijo;	//Se ubica sobre el directorio.
			direccion(aux);	//Muestra la direccion del directorio desde la raíz.
			vacio = false;
		}
		else
		{
			direccion(aux);	//Muestra la direccion del directorio desde la raíz.
			vacio = true;
		}
		
		int cant;				//Tamaño del contenido del directorio.
		cout << "\n" << endl;
		
		
		if(vacio != true) 
		{
			//Parte de muestra de Archivos
			
			cant = contador_de_nodos(s,false); //False sólo contará archivos, True Directorios.
			imprime(cant,s,false);				//False sólo mostrará archivos, True Directorios.
			
			//	____________________________________________________________________ //
			
			//Parte de muestra de Directorios
			
			cant = contador_de_nodos(s,true); //False sólo contará archivos, True Directorios.
			imprime(cant,s,true);			//False sólo mostrará archivos, True Directorios.
			
		}
		else
		{
			cout << " (Directorio vacio)" << endl;
			
		}
	}
	else	//Si el parámetro existe al escribir "DIR"
	{
		//Si se escribió '\S'
		if (strcmp(parametro,"\\S") == 0)	//Si se pone una sola retrobarra da un 'warning' ya que el compilador lo malentiende.
		{
			Sistema aux = s;
			
			if (aux != NULL)
			{	
				cout << "\n";
				mostrar_ruta_ARC(aux);
				mostrar_ruta_DIR(aux);
			}
			else
			{
				cout << " (Directorio vacio)" << endl;
			}
		}
	}
	
}
void borradorDir(Sistema s,Cadena nombreDirectorio)
{
	Sistema aux = s->hijo;
	Sistema aux2;
	
	if (aux != NULL)
	{
		aux = buscadorII(aux,nombreDirectorio);
		aux2 = aux;
		
		if (s->hijo->nombre == aux2->nombre)//si es el primero hijo de la raiz 
		{	
			if (aux->hermano == NULL)
			{
				aux2->padre->hijo = NULL;
				aux = liberarMemoria(aux); //borro
			}
			else
			{
				aux2->padre->hijo = aux->hermano;//igualo el hijo del padre al siguiente
				aux->hermano = NULL;
				aux = liberarMemoria(aux); //borro
			}
		}
		else
		{
			aux2 = Puntero_anterior_DIR(aux2->padre->hijo,nombreDirectorio);
			if (aux->hermano == NULL)
			{
				aux2->hermano = NULL;
				aux->hermano = NULL;
				aux->padre = NULL;
				aux = liberarMemoria(aux);
			}
			else
			{
				aux2->hermano = aux->hermano;
				aux->hermano = NULL;
				aux->padre = NULL;
				aux = liberarMemoria(aux);
			}
		}
	}
}

//void mover(Sistema s,Cadena nombre,Cadena directorioDestino)
//{
//	Sistema dirNuevo = s;
//	Sistema nodo = s;
//	Cadena DC = new char [50];
//	Cadena DL = new char [200];
//	Cadena CO = new char [20];
//	strcpy(DL,directorioDestino);
//	strcpy(DC,directorioDestino);
//	
//
//	CO = strrchr(directorioDestino,'/');
//	CO = eliminar_primer_elemento(CO);
//
//	DL=acortador(DL);
//	DL = eliminar_primer_elemento(DL);
//	while(dirNuevo->nombre != CO) 	//Acá se consigue la dirección del directorio en el cual almacenar el nodo.
//	{
//		
//		DC = detector_D1(DL);
//		printf(" pasa1DC %s\n",DC);
//		DL = acortador(DL);
//		printf(" pasa2DL %s\n",DL);
//		if (DL!=NULL) {
//			DL = eliminar_primer_elemento(DL);
//		}
//		printf(" pasa4 elimina elemento %s\n",DL);
//		dirNuevo = buscar_FULL(s,DC);
//		printf(" pasa3BUSCAR \n");
//		printf("dir_actual: %s",dirNuevo->nombre);
//		
//	}
//
//	nodo = buscadorII(s->hijo,nombre);	//Acá se busca el nodo a mover.
//	
//	if(s != NULL && nodo != NULL)	//Se procede a mover.
//	{
//		
//		//Fase de desanclaje de nodo.
//		
//		if (nodo->padre->hijo == nodo) 
//		{
//			if(nodo->hermano != NULL) //Se busca la posibilidad de que el nodo a mover sea el primero de sus hermanos.
//			{
//				nodo->padre->hijo = nodo->hermano; 		//Ahora el nodo hermano será el nuevo nodo hijo primero.
//				
//			}
//			else //Si el nodo a mover es hoja.
//			{
//				nodo->padre->hijo = NULL;	//Ahora ese dir no tiene elementos. 
//			}
//		}
//		else	//Si es un nodo entre hermanos
//		{
//			
//			Sistema nodo_ant;
//			
//			nodo_ant = Puntero_anterior(nodo->padre->hijo,nombre);	//Busco el nodo anterior por si es archivo.
//			
//			if(nodo_ant == NULL) 	//Si no devuelve nada la función anterior, el archivo anterior es directorio
//			{
//				nodo_ant = Puntero_anterior_DIR(nodo->padre->hijo,nombre);	//Lo busca.
//			}
//			
//			if(nodo->hermano != NULL)	//Si es un nodo entre hermanos pero no es el ultimo.
//			{
//				nodo_ant->hermano = nodo->hermano;	//Ahora el elemento anterior su hermano será el siguiente.
//			}
//			else	//Si es el último nodo...
//			{
//				nodo_ant->hermano = NULL;		//Ahora el elemento anterior será el ultimo (NULL)
//			}
//			
//		}
//		
//		//Fase de Mover nodo.
//		
//		nodo->hermano = NULL;		//Se insertará al final, por lo cual será el último hermano.
//		
//		
//		if(dirNuevo->hijo == NULL)	//Si el directorio ya estaba vacío...
//		{
//			dirNuevo->hijo = nodo;	//Ahora su primer hijo será el nodo.
//			nodo->padre = dirNuevo;
//		}
//		else		//Si tiene hijos.
//		{
//			Sistema ant;
//			
//			ant = ultimo_hermano(dirNuevo);	//Se busca el último nodo de ese directorio.
//			ant->hermano = nodo;			//Ahora el hermano de el último nodo será el nodo movido.
//			
//		}
//	}
//	
//}
