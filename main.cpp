#include "iostream"
#include "prototipos.h"
#include "prototipos_retorno.h"
#include "prototipos_b.h"
#include "struct.h"
#include "enum.h"
#include "string.h"
#include "constantes.h"

using namespace std;

int main (int argc, char *argv[]) 
{//<< >> 
	
	Sistema s = NULL;
	string comando;
	int k = 0;
	
	do 
	{
		Cadena ingreso = new char[100];
		Cadena nombreArchivo = new char[NOMBRE_MAX];
		Cadena nombreDirectorio = new char[NOMBRE_MAX];
		Cadena nombre = new char[NOMBRE_MAX];
		Cadena directorioDestino = new char[100];
		Cadena parametro = new char[5];
		Cadena texto = new char[TEXTO_MAX];
		Cadena texto1 = new char [TEXTO_MAX];
		Cadena texto2 = new char [TEXTO_MAX];
		
		direccion(s);
		cout << " > ";
		
		cin.getline(ingreso,100);		//Se almacena ingreso completo: comando, dir/archivo, texto1, texto2.
		
		comando = detectorI(ingreso);								//Separa el comando del resto del ingreso.
		nombreArchivo = detectorII(ingreso);						//Separa el nombre del archivo del resto del ingreso.	
		nombreDirectorio = detectorII(ingreso);
		texto2 = detectorVI(ingreso);
		texto = detectorV(ingreso,nombreArchivo);					//Separa el texto del resto del ingreso.
		texto1 = detectorV(ingreso,nombreArchivo);				
		parametro = detectorIII(ingreso,nombreArchivo);				//Separa el parametro +-W del ingreso.
		k = detectorIV(ingreso,nombreArchivo);						//Separa el int del ingreso.
		directorioDestino = detectorIII(ingreso,nombreArchivo);		//Obtiene el directorio de destino de MOVE
		nombre = detectorII(ingreso);								//Obtiene el nombre del elemento a mover.
		
		if(comando == "CREARSISTEMA")
		{
			Funcion(CREARSISTEMA(s));
		}
		if(comando == "CD")
		{
			Funcion(CD(s,nombreDirectorio));
		}
		if(comando == "MKDIR")
		{
			Funcion(MKDIR(s,nombreDirectorio));
		}
		if(comando == "RMDIR")
		{
			Funcion(RMDIR(s,nombreDirectorio));
		}
		if(comando == "MOVE")
		{
			Funcion(MOVE(s,nombre,directorioDestino));
		}
		if(comando == "DIR")
		{	
			Funcion(DIR(s,nombreArchivo));
		}
		if(comando == "CREATEFILE")
		{
			Funcion(CREATEFILE(s,nombreArchivo));
		}
		if(comando == "DELETE")
		{
			Funcion(DELETE(s,nombreArchivo));
		}
		if(comando == "ATTRIB")
		{
			Funcion(ATTRIB(s,nombreArchivo,parametro));
		}
		if(comando == "IC")
		{
			Funcion(IC(s,nombreArchivo,texto));
			
		}
		if(comando == "IF")
		{
			Funcion(IF(s,nombreArchivo,texto));
		}
		if(comando == "DF")
		{		
			Funcion(DF(s,nombreArchivo,k));
			
		}
		if(comando == "DC")
		{	
			Funcion(DC(s,nombreArchivo,k));
		}
		if(comando == "TYPE")
		{	
			Funcion(TYPE(s,nombreArchivo));
		}
		if(comando == "SEARCH")
		{
			Funcion(SEARCH(s,nombreArchivo,texto));
		}
		if(comando == "REPLACE")
		{		
			Funcion(REPLACE(s,nombreArchivo,texto1,texto2));
		}
		if(comando == "DESTRUIRSISTEMA")
		{
			Funcion(DESTRUIRSISTEMA(s));
		}
		
		compatibilidad('w','f'); // 'w' windows 'u' ubuntu (LINUX)!
		
		if(comando == "EXIT")	//Al salir se limpiará la memoria.
		{
			delete nombreArchivo;
			delete nombreDirectorio;
			delete parametro;
			delete ingreso;
			delete nombre;
			delete directorioDestino;
			delete texto;
			delete texto1;
			delete texto2;
			cout << "BYE!";
		}
		
		mensaje(comando);
		
	}
	while(comando != "EXIT");

	return 0;
}

