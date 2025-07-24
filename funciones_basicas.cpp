#include<iostream>
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

using namespace std;

void compatibilidad(char so,char o)  
{
	//'so' es el sistema operativo u = linux, w= windows. 
	//'o' es la operación c = borrar pantalla, f = limpiar buffer.
	
	if(so == 'u' && o == 'c')
	{
		system("clear");
		
	}
	if(so == 'w' && o == 'c')
	{
		system("cls");
	}

	if(so == 'w' && o == 'f')	
	{
		fflush(stdin);
		
	}
	if(so == 'u' && o == 'f')
	{
		cin.clear();
		
	}
	
	
}
Sistema crear_sistema()
{
	Sistema nuevonodo = new nodo;
	strcpy(nuevonodo->nombre,"RAIZ");
	nuevonodo->contenido = NULL;			//Cambiar si no funciona como se esperaba.
	nuevonodo->contiene_sn = false;
	nuevonodo->padre = NULL;
	nuevonodo->hijo = NULL;
	nuevonodo->hermano = NULL;
	nuevonodo->wr = true;
	nuevonodo->carpeta = true;
	
	return nuevonodo;
}
void mostrar_temporal(Sistema s)
{
	
	if(s != NULL)
	{
		
		cout << "\n" << s->nombre << "\t";
		
		if(s->carpeta == true)
		{
			printf("Tipo: Directorio\t");
		}
		else
		{
			printf("Tipo: Archivo\t");
		}
		if(s->contiene_sn == true)
		{
			cout << "Contiene: Si\t";
		}
		else
		{
			printf("Contiene: No\t");
		}
		if(s->wr == true)
		{
			cout << "Lectura/Escritura\t";
		}
		else
		{
			cout << "Lectura\t";
		}
		
		printf("Size: 0KB\t");
		
		if (s->hermano != NULL) 
		{
			sp();
		}
		
		mostrar_temporal(s->hermano);
		mostrar_temporal(s->hijo);
	}
	
}

void sp()
{
	
	printf("\n__________________________________________________________________________\n");
	
}

bool es_null(Sistema s)
{
	if(s == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
bool archivo_existe_modificable(Sistema s,Cadena nombreArchivo,char n)
{
	// 's' si se necesita saber si el archivo es editable, 'n' si no es necesario.	
	
	s = s->hijo; //Se posiciona el puntero sobre el contenido de ese directorio.
	
	if (n == 's') //Buscará si existe y es +w (modificable).
	{
		
		while(s != NULL)
		{
			if(strcmp(nombreArchivo,s->nombre) == 0 && s->wr == true && s->carpeta == false)
			{
				
				return true;
				
			}
			s = s->hermano;
		}
	}
	else	//En caso contrario solo buscará si existe.
	{
		while(s != NULL)
		{
			
			if(strcmp(nombreArchivo,s->nombre) == 0 && s->carpeta == false)
			{
				
				return true;
			}
			
			s = s->hermano;
		}
	}
	
	return false;
	
}
bool dir_existe(Sistema s, Cadena nombreDirectorio)
{
	s = s->hijo;
	
	while(s != NULL)
	{
		if(strcmp(nombreDirectorio,s->nombre) == 0 && s->carpeta == true)
		{
			return true;
		}
		s = s->hermano;
	}
	
	return false;
}

bool comprobador(Sistema S, Cadena nombreDirectorio)
{
	if(strcmp("..",nombreDirectorio) == 0 || dir_existe(S,nombreDirectorio) || strcmp("RAIZ",nombreDirectorio) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Sistema buscador(Sistema S, Cadena nombreArchivo)
{
	if(S != NULL)
	{
		if(strcmp(nombreArchivo,S->nombre) == 0 && S->carpeta == false)	//Si lo encuentra y no es carpeta.
		{
			return S;
		}
		
		return buscador(S->hermano,nombreArchivo);
	}
	
	return NULL;
	
}

int contador_de_nodos(Sistema s, bool carpeta)	//Debe recibir S->hijo para funcionar TRUE es para directorio FALSE para archivo.
{
	if(s != NULL)
	{
		if (s->carpeta == carpeta) 
		{
			return 1 + contador_de_nodos(s->hermano,carpeta);
		}
		else
		{
			return contador_de_nodos(s->hermano,carpeta);
		}
	}
	
	return 0;
}

Sistema Puntero_anterior(Sistema s, Cadena nombreArchivo) //Devuelve posicion anterior
{
	//Esta función requiere (s->padre->hijo) desde donde se utilice para funcionar adecuadamente!
	
	if(s != NULL)
	{
		
		if(strcmp(s->hermano->nombre,nombreArchivo) == 0 )	//Si son iguales
		{
			return s;
		}
		
		return Puntero_anterior(s->hermano,nombreArchivo);
		
	}
	
	return NULL;
}

bool verificador(Cadena nombreArchivo)	//Se asegura de que la extensión tenga el largo permitido.
{
	Cadena verific = new char[NOMBRE_MAX];	//Cadena donde guardo la extension
	Cadena aux2 = new char[NOMBRE_MAX];		//Cadena donde copio el nombreArchivo
	strcpy(aux2,nombreArchivo);
	
	if(strchr(aux2,'.') != 0)		// si no encuentra un punto devuelve false
	{
		verific = strchr(aux2,'.') + 1;	//me da la extension del archivo que sera de 1 a 3
	}
	else
	{
		return false;
	}
	
	int *largo = new int;
	
	*largo = strlen(nombreArchivo);
	
	if (*largo <= 19 && strstr(nombreArchivo,".") && strstr(nombreArchivo,verific) && strlen(verific) <= 3 && strlen(verific) > 0)//verifica que haya un punto y el tamaño de la extension sea de 3 o menos
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

Cadena detectorI(Cadena ingreso)			//Guarda n carácteres antes del primer espacio.
{
	Cadena resultado = new char [15]; 				//Nuevo almacen para comando.
	Cadena letra = new char [1];					//Filtro para espacio.
	
	strcpy(resultado,"");							//Se setea a vacío el almacén.
	strcpy(letra," ");								//Se ingresa objetivo.
	
	int *a = new int;
	
	*a = strcspn(ingreso,letra);					//Se obtiene el numero de la posicion del espacio.
	
	strncat(resultado,ingreso,*a);  				//Se ingresan en la cadena resultado todos los char antes del espacio.
	
	return resultado;								//Se devuelve el resultado.
	
}

Cadena detectorII(Cadena ingreso)				//Guarda n carácteres luego del primer espacio y antes del segundo.
{
	Cadena resultado = new char [70];			//Espacio de almacen.
	
	strcpy(resultado,"");						//Se vacía el almacen.
	
	if (strchr(ingreso,' ') != 0)					//Si realmente se ingresó algo luego del comando... 
	{
		resultado = strchr(ingreso,' ');			//Se obtiene todo luego del primer espacio.
		
		resultado = eliminar_primer_elemento(resultado);		//Esta funcion corrige la inconveniencia de strchr, ya que guarda también el espacio.
		
		resultado = detectorI(resultado);					//Se obtiene todo antes del segundo espacio.
		
		
		return resultado;						//retorna dir o archivo.
	}
	else
	{
		strcpy(resultado,"");					//Se agrega vacío a resultado. 
		
		return resultado;
	}
}



Cadena eliminar_primer_elemento(Cadena ingreso)
{
	Cadena almacen = new char[100];
	strcpy(almacen,"");
	int largo;
	int n_aux;
	largo = strlen(ingreso);
	
	for(int ct = 1; ct <= largo; ct++)
	{
		n_aux = ct - 1;
		almacen[n_aux] = ingreso[ct]; 
		
	}

	return almacen;
	
}

Cadena detectorIII(Cadena ingreso, Cadena t_anterior)
{
	Cadena resultado = new char [16]; 				//Nuevo almacen para comando.
	
	strcpy(resultado,"");							//Se setea a vacío el almacén.

	resultado = strstr(ingreso,t_anterior);			//Elimino la primer parte de la cadena asi puedo volver a aplicar las funciones creadas anteriormente.
	
	resultado = detectorII(resultado);
	
	return resultado;
}

int detectorIV(Cadena ingreso,Cadena t_anterior)
{
	Cadena resultado = new char [16]; 				//Nuevo almacen para comando.
	strcpy(resultado,"");							
	
	int *numero = new int;
	*resultado = 0;
	
	resultado = strstr(ingreso,t_anterior);
	resultado = detectorII(resultado);
	
	*numero = atoi(resultado);						//Pasa la cadena a int.
	
	return *numero;
	
}

Cadena detectorV(Cadena ingreso,Cadena t_anterior)
{
	
	Cadena resultado = new char [100];
	strcpy(resultado,"");

	if (strchr(ingreso,'\"') != 0)						//Si encuentra Comillas en el ingreso... 
	{
		resultado = strstr(ingreso,t_anterior); 		//Quita lo anterior 
		
		resultado = strchr(ingreso,'\"');				//Elimina todo antes de las comillas.
		
		resultado = strtok(resultado,"\"");				//Elimina todo luego de las comillas.
	}
	
	return resultado;
	
}

Cadena detectorVI(Cadena ingreso)
{

	Cadena resultado = new char [100];
	strcpy(resultado,"");
	
	if (strchr(ingreso,'\"') != 0)						//Si encuentra Comillas en el ingreso...
	{
		resultado = eliminar_ultima_comilla(ingreso);
		resultado = strrchr(resultado,'\"');
		resultado = eliminar_primer_elemento(resultado);
	}
	
	return resultado;
	
}

Cadena eliminar_ultima_comilla(Cadena ingreso)
{
	Cadena almacen = new char[100];
	strcpy(almacen,"");
	int largo;
	largo = strlen(ingreso);
	
	for(int ct = 0; ct < largo-1; ct++)
	{
		almacen[ct] = ingreso[ct]; 
	}
	
	
	return almacen;
	
}

Sistema ultimo_hermano(Sistema S)
{
	if(S->hermano == NULL)
	{
		return S;
	}
	else
	{
		return ultimo_hermano(S->hermano);
	}
	
}

Sistema root(Sistema S)
{
	while(S != NULL)
	{
		if(S->padre == NULL)
		{
			return S;
		}
		
		S = S->padre;
	}
	
	return NULL;
}

void direccion(Sistema D)
{	
	if (D != NULL) 
	{
		if(D->padre != NULL)	//Mientras que no esté en la raíz
		{
			direccion(D->padre);
			cout << D->nombre <<"/";
			
		}
		else	//Si ya está en la raíz o si estaba ahí desde el inicio
		{
			cout << D->nombre <<"/";
		}
	}
	else
	{
		cout << "(Sin-Sistema)";
	}
}


void imprime(int cant, Sistema s,bool C)
{
	Cadena nombreTempA = new char [NOMBRE_MAX];
	Cadena nombreTempD = new char [NOMBRE_MAX];
	
	Sistema aux = s;								//Punteros auxiliares.
	Sistema aux2 = s;
	
	int contador = 1;
	
	while(cant != 0) 	//Se repetirá cada vez por cada elemento del directorio.
	{
		aux2 = s;
		
		if (C == false) //Si es por archivos
		{
			while(aux2 != NULL) //Busca el primer elemento a comparar
			{
				if(aux2->asc == 0 && aux2->carpeta != true)
				{
					strcpy(nombreTempA,aux2->nombre);		//Guarda el primer elemento encontrado.
				}
				
				aux2 = aux2->hermano;
			}
		}
		else	//Si es por directorio
		{
			while(aux2 != NULL) //Busca el primer elemento a comparar
			{
				if(aux2->asc == 0 && aux2->carpeta == true)
				{
					strcpy(nombreTempD,aux2->nombre);		//Guarda el primer elemento encontrado.
				}
				
				aux2 = aux2->hermano;
			}
			
		}
		
		aux2 = s;
		
		aux = s;
		
		while(aux != NULL && C == false)	//Almacena nombre Archivos
		{
			//			1 		      -1 	//Si encuentra uno menor y no es directorio y no fué encontrado anteriormente o es el unico que queda.
			if((strcmp(aux->nombre,nombreTempA) == -1 && aux->carpeta == false && aux->asc == 0)  ||  (strcmp(aux->nombre,nombreTempA) == 0 && aux->carpeta == false && aux->asc == 0))	
			{
				strcpy(nombreTempA,aux->nombre);				//Lo guarda.
				aux2 = aux;
			}
			
			aux = aux->hermano;
		}
		
		while(aux != NULL && C == true)		//Almacena noombre Directorios
		{
			//			1 		      -1 	//Si encuentra uno menor y no es directorio y no fué encontrado anteriormente o es el unico que queda.
			if((strcmp(aux->nombre,nombreTempD) == -1 && aux->carpeta == true && aux->asc == 0)  ||  (strcmp(aux->nombre,nombreTempD) == 0 && aux->carpeta == true && aux->asc == 0))	
			{
				strcpy(nombreTempD,aux->nombre);				//Lo guarda.
				aux2 = aux;
			}
			
			aux = aux->hermano;
		}
		
		aux2->asc = contador;				//El elemento menor ahora será omitido.
		contador ++;
		
		if (C == false	&& aux2->asc != 0) 	//Si es archivo...
		{
			cout << nombreTempA << "     " ;		//Muestra en pantalla
			
			if(aux2->wr == true)
			{
				cout << "Lectura/Escritura\n" << endl; 
			}
			else
			{
				cout << "Lectura\n" << endl;
			}
			
		}
		
		if (C == true	&& aux2->asc != 0)	//Si es directorio...
		{
			cout << nombreTempD << "     " << "\n" << endl;		//Muestra en pantalla
		}
		
		
		cant --;						//Se reduce en 1 la cantidad de veces a repetir.
	}
	
	
	aux = s;
	
	while(aux != NULL)				//Reseteador (para volver a mostrar todo también la proxima vez).
	{
		aux->asc = 0;
		aux = aux->hermano;
	}
}

void mensaje(string comando)
{
	if(comando != "EXIT" && comando != "CREARSISTEMA" && comando != "DIR" && comando != "MOVE" && comando != "CD" && comando != "MKDIR" && comando != "RMDIR" && comando != "CREATEFILE" && comando != "DELETE" && comando != "ATTRIB" && comando != "IC" && comando != "IF" && comando != "DF" && comando != "DC" && comando != "TYPE" && comando != "SEARCH" && comando != "REPLACE" && comando != "DESTRUIRSISTEMA")
	{
		cout << "Comando invalido, intente nuevamente" << endl;
		
	}
	
}
void mostrar_ruta_ARC(Sistema s)
{
	if (s != NULL)
	{
		if (s->carpeta != true) 
		{
			direccion(s);
			cout << "\n";
			mostrar_ruta_ARC(s->hermano);
			mostrar_ruta_ARC(s->hijo);
		}
		else
		{
			mostrar_ruta_ARC(s->hermano);
			mostrar_ruta_ARC(s->hijo);
		}
	}
}
void mostrar_ruta_DIR(Sistema s)
{
	if (s != NULL)
	{
		if (s->carpeta == true && strcmp(s->nombre,"RAIZ") != 0 ) 
		{
			direccion(s);
			cout << "\n";
			mostrar_ruta_DIR(s->hermano);
			mostrar_ruta_DIR(s->hijo);
		}
		else
		{
			mostrar_ruta_DIR(s->hermano);
			mostrar_ruta_DIR(s->hijo);
		}
	}
}
Sistema buscadorII(Sistema s, Cadena elemento)
{
	if (s != NULL && strcmp(elemento,s->nombre) == 0)
	{
		return s;
	}
	else
	{		
		return buscadorII(s->hermano,elemento);
	}
	
}
Sistema Puntero_anterior_DIR(Sistema s, Cadena nombreDirectorio) //Devuelve posicion anterior
{
	s = s->padre->hijo;	//Se setea el primer elemento de ese directorio.
	
	Sistema aux;		//Puntero auxiliar.
	aux = s;
	
	while(s != NULL)
	{
		
		if(strcmp(nombreDirectorio,s->nombre) == 0 )
		{
			
			return aux;
			
		}
		
		aux = s;
		
		s = s->hermano;
		
	}
	
	return aux;
	
}
int tam_ext(Cadena ingreso)
{
	Cadena verific = new char[NOMBRE_MAX];	//Cadena donde guardo la extension
	Cadena aux2 = new char[NOMBRE_MAX];		//Cadena donde copio el nombreArchivo
	strcpy(aux2,ingreso);

	verific = strchr(aux2,'.');	//me da la extension del archivo que sera de 1 a 3
	return 3 - (strlen(verific) -1) ;
	
}

bool pase(Cadena nombreArchivo)
{
	int ext;
	
	ext = tam_ext(nombreArchivo);

	if( (ext == 0 && strlen(nombreArchivo) <= 19) || (ext == 1 && strlen(nombreArchivo) <= 18) || (ext == 2 && strlen(nombreArchivo) <= 17) )
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

Sistema buscar_FULL(Sistema S, Cadena nombre)
{
	if(S == NULL)
	{
		return NULL;
	}
	else
	{
		if(S->nombre == nombre && S->carpeta == true)
		{
			return S;
		}
		else
		{
			return buscar_FULL(S->hermano,nombre);
			return buscar_FULL(S->hijo,nombre);
		}
	}
	
}

Cadena acortador(Cadena direccion)
{
	Cadena nombre = new char[200];
	
	strcpy(nombre,direccion);
	
	return strchr(nombre,'/');

	
}

Cadena detector_D1(Cadena ingreso)			//Guarda n carácteres antes de la primer barra inclinada.
{
	Cadena resultado = new char [15]; 				//Nuevo almacen para comando.	
	strcpy(resultado,"");							//Se setea a vacío el almacén.
	
	int a = 0;
	int b = 0;
	
	b = strlen(ingreso);
	a = strcspn(ingreso,"/");						//Se obtiene el numero de la posicion de la barra inclinada.

	if (a != b) 	//Si no encuentra ningúna barra inclinada
	{
		strncat(resultado,ingreso,a);  				//Se ingresan en la cadena resultado todos los char antes del espacio.
		return resultado;							//Se devuelve el resultado.
	}
	
	return ingreso;
}
