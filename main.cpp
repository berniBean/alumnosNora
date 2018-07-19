/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: BerniMac
 *
 * Created on 22 de junio de 2018, 18:34
 */

#include <cstdlib>
#include<iostream>
#include<string.h>
#include<sstream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

/*
 * 
 */

struct registoAlumno{
	int matricula;
	char nombre[20];
	char fechaNacimiento[20];
	char carrera[20];
	int semestre;
}Alumno;

//////////////////seccion de menú////////////
bool menuPrincipal();
//////////////////seccion de menú////////////

////////////////Seccion de control//////////
void registrarAlta();
void realizaConsulta();
void realizaBusqudaId();
////////////////Seccion de control//////////


///////////////VALIDACION//////////////////
bool tipoIntValido(string);
int tomarInt();
bool tipoFloatValido(string);
float tomarFloat();

int main() {
	bool finalizar=false;
	system("cls");
	do{
		finalizar=menuPrincipal();
	}while(finalizar==false);
	
	
	return 0;

}

bool menuPrincipal(){
system("clear");
fflush(stdin);
int entrada;
	cout<<"usanndo git hub"<<endl;
	cout<<"Registro Escuela"<<endl;
	cout<<"1.-Altas"<<endl;
	cout<<"2.-Consultas"<<endl;
	cout<<"3.-Busquedas"<<endl;
	cout<<"4.-Salir"<<endl;
	cout<<"Escoge una opcion:";
	entrada=tomarInt();
	switch(entrada){
		case 1:{
                    registrarAlta();
			break;
		}
		case 2:{
			realizaConsulta();
			break;
		}
		case 3:{
                        realizaBusqudaId();
			break;
		}
		case 4:{
			exit(-1);
			break;
		}
		default:
			system("clear");
			cout<<"Opcion no valida presione una tecla "
                                "para regresar a 'Menu principal'"<<endl;
			system("pause");
			return false;
			break;
	} 
	
}

void registrarAlta(){
	char finaliza='N';
	char entrdada;

		FILE *a;

    		a=fopen("./registroAlumno.dat","a+b");
    		cout<<"Registra Alumno:"<<endl;
    		while(finaliza!=entrdada){
	    		cout<<"Matricula: ";
	    		fflush(stdin);
	    		Alumno.matricula=tomarInt();
	    		cin.getline(Alumno.carrera,20,'\n');
	    		cout<<"Nombre: ";
	    		fflush(stdin);
	    		cin.getline(Alumno.nombre,20,'\n');
	    		cout<<"Fecha nacimiento: ";
	    		fflush(stdin);
	    		cin.getline(Alumno.fechaNacimiento,20,'\n');		    		
				cout<<"carrera: ";
				fflush(stdin);
	    		cin.getline(Alumno.carrera,20,'\n');
	    		cout<<"semestre: ";
				fflush(stdin);
	    		Alumno.semestre=tomarInt();
	    		fwrite(&Alumno,sizeof(Alumno),1,a);
	    		cout<<endl;
	    		cout<<"****Registro almacenado****";   
				cout<<"Desea continuar:S/N";
				cin>>entrdada; 	
				entrdada=toupper(entrdada);
				system("clear");
				
			}
						
			fclose(a);
			main();
		
}
void realizaBusqudaId(){
system("clear");
	bool encontrado=false;
	char sBusca[10];
	char pBusca[10];
	
			cout<<"Ingrese la Matricula del Alumno:";
			fflush(stdin);
			gets(sBusca);
                        cout<<sBusca;
			FILE *a;
			 a=fopen("./registroAlumno.dat","a+b");
			while(fread(&Alumno,sizeof(Alumno),1,a)){
				stringstream ssP;
				ssP<<Alumno.matricula;
				ssP>>pBusca;
				
				 if(strstr(sBusca,pBusca)!=NULL){
				 	encontrado=true;
				 	cout<<endl;
		    		cout<<"Nombre: ";
		    		cout<<Alumno.nombre<<endl;
		    		cout<<"Fecha de Nacimiento: ";
		    		cout<<Alumno.fechaNacimiento<<endl;			    		
					cout<<"Carrera: ";
		    		cout<<Alumno.carrera<<endl; 
		    		cout<<"Semestre: ";
		    		cout<<Alumno.semestre<<endl;
					cout<<endl;
     			getchar();
     			if(encontrado==false){
     				cout<<"Valor no encontrado"<<endl;	
				 }
     			fclose(a);
     			getchar();
     			main();
}
}	
}
void realizaConsulta(){
    	system("clear");
            FILE *a;
		a=fopen("./registroAlumno.dat","a+b");
    			rewind(a);
    			while(fread(&Alumno,sizeof(registoAlumno),1,a)){
		         //fread(&Producto,sizeof(Producto),1,a);               
		    		cout<<"Matricula: ";
		    		cout<<Alumno.matricula<<endl;
		    		cout<<"Nombre: ";
		    		cout<<Alumno.nombre<<endl;
		    		cout<<"Fecha de nacimiento: ";
		    		cout<<Alumno.fechaNacimiento<<endl;			    		
				cout<<"Carrera: ";
		    		cout<<Alumno.carrera<<endl; 
                                cout<<"Semestre:";
				cout<<Alumno.semestre<<endl;	
                                cout<<endl;   
     			}
     			fclose(a);
     			cout<<"presione una tecla para continuar."<<endl;
                        getchar();
     			main();
		
}

int tomarInt(){
	string numero;
	bool esValido=false;
	
	while(!esValido){
		try{
			
			getline(cin,numero);
			esValido=tipoIntValido(numero);
			
			if(! esValido)
				throw numero;	
		}
		catch(string e){
			cout<<"\nsolo puede ser un numero"<<endl;
		}
	}
	return strtof((numero).c_str(),0);
}
bool tipoIntValido(string numero){
	int inicio=0;
		
	for(int i=inicio;i<numero.length();i++){
		if(!isdigit(numero[i])){
			return 0;	
		}	
	}
	return 1;
}
float tomarFloat(){
	string numero;
	bool esValido=false;
	
	while(!esValido){
		try{
			
			getline(cin,numero);
			esValido=tipoFloatValido(numero);
			
			if(! esValido)
				throw numero;	
		}
		catch(string e){
			cout<<"\nsolo puede ser un numero"<<endl;
		}
	}
	return strtof((numero).c_str(),0);
}
bool tipoFloatValido(string numero){
	int inicio=0;
		
	for(int i=inicio;i<numero.length();i++){
		if(!isdigit(numero[i]) and numero[i]!='.'){
			return 0;	
		}	
	}
	return 1;
}
