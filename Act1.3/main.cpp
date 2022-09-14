// =================================================================
//
// File: main.cpp
// Author: Sofía Blanco Prigmore - A01704567 
//Alan Patricio González Bernal - A01067546
// Date: 13/09/2022
//
//
// g++ -std=c++11 main.cpp -o app
//
// ./app input1.txt mysolution1.txt diff mysolution1.txt output1.txt
// =================================================================
#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>

#include <sstream>
#include <string>
#include <cstdlib>
#include <string.h>


#include "header.h"
#include "exception.h"
#include "bubble.h"
#include "catch.h"


using namespace std;

//Registro barcos 
//<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>
//entrada: 
// (entero num barcos, string 3 caracteres)
//salida: 
//solo los que tienen UBI con el prefijo y ordenados por fecha 
//=======================================

int main(int argc, char *argv[]) {
  // main, <inputfile.txt> outputfile.txt
  ifstream inputfile;
  ofstream outputfile;

  if(argc != 3){
    cout<< "Invocación incorrecta !" << endl; 
  }
  
  inputfile.open(argv[1]); // entrada a array
  if(inputfile.fail()){

    cout << "No se pudo leer el archivo de entrada bro" << endl;
    return -1;
  
  }

  outputfile.open(argv[2]);
  if(inputfile.fail()){

    cout << "No se pudo abrir el archivo de salida bro" << endl;
    return -1;
  
  }

  //declaración variables 
  int num_ships; 
  string id, date, hour, port, prefix_UBI; 

  //clase Ship 
  class Ship{
  public: 
  int year, month, day;
  string dateS, hour, port, prefix_UBI; 
  };


    vector <Ship> portShips;     //creando vector de los barcos
  
  
  //Recorre el archivo 
  inputfile >> num_ships;             //Lee primera linea
  inputfile >> id; 
  

  for (int i = 0; i < num_ships; i++){
    //Recorre archivo, lee datos
    inputfile >> date >> hour >> port >> prefix_UBI; 

    //Formar el date string con los primeros datos de fecha 
    string day = date.substr(0, date.find("-")); 
    string month = date.substr(3, date.find("-"));
    string year = date.substr(6);

    //Encontrar los barcos con el prefijo del inputfile
    size_t found = prefix_UBI.rfind(id); 
    if(found != string::npos){
      portShips.push_back({stoi(year), stoi(month),stoi(day), date, hour, port, prefix_UBI}); 
      }
  }


  //Algoritmo de ordenamiento
  bubbleSortDay(portShips); 
  bubbleSortMonth(portShips); 
  

  //Escribe el archivo de salida 
  for(int i = 0; i<portShips.size(); i++){
    outputfile << portShips[i].dateS << " " << portShips[i].hour << " " << portShips[i].port << " " << portShips[i].prefix_UBI << endl;
  }


  //Cierra archivos 
  inputfile.close(); 
  outputfile.close(); 
  
	return 0;
}