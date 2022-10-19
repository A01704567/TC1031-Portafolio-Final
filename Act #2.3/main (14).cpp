// =================================================================
//
// File: main.cpp
// Author: Sofía Blanco Prigmore - A01704567 
//Alan Patricio González Bernal - A01067546
// Date: 18/10/2022
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


  //Algoritmo de ordenamiento y contadores
  bubbleSortDay(portShips); 
  bubbleSortMonth(portShips); 
  int contadorEneM = 0;
  int contadorEneR = 0;
  int contadorFebM = 0;
  int contadorFebR = 0;
  int contadorMarM = 0;
  int contadorMarR = 0;
  int contadorAbrM = 0;
  int contadorAbrR = 0;
  int contadorMayM = 0;
  int contadorMayR = 0;
  int contadorJunM = 0;
  int contadorJunR = 0;
  int contadorJulM = 0;
  int contadorJulR = 0;
  int contadorAgoM = 0;
  int contadorAgoR = 0;
  int contadorSepM = 0;
  int contadorSepR = 0;
  int contadorOctM = 0;
  int contadorOctR = 0;
  int contadorNovM = 0;
  int contadorNovR = 0;
  int contadorDicM = 0;
  int contadorDicR = 0;
  string M;
  string R;

  //Escribe el archivo de salida 
  outputfile << "jan\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 1 && portShips[i].port == "M"){

		contadorEneM++;

	 }
	 else if(portShips[i].month == 1 && portShips[i].port == "R"){

		contadorEneR++;

	 }
  }

	outputfile << "M " << contadorEneM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 1 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorEneR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 1 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

outputfile << "\n" << "feb\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 2 && portShips[i].port == "M"){

		contadorFebM++;

	 }
	 else if(portShips[i].month == 2 && portShips[i].port == "R"){

		contadorFebR++;

	 }
  }

	outputfile << "M " << contadorFebM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 2 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorFebR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 2 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

outputfile << "\nmar\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 3 && portShips[i].port == "M"){

		contadorMarM++;

	 }
	 else if(portShips[i].month == 3 && portShips[i].port == "R"){

		contadorMarR++;

	 }
  }

	outputfile << "M " << contadorMarM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 3 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorMarR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 3 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\napr\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 4 && portShips[i].port == "M"){

		contadorAbrM++;

	 }
	 else if(portShips[i].month == 4 && portShips[i].port == "R"){

		contadorAbrR++;

	 }
  }

	outputfile << "M " << contadorAbrM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 4 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorAbrR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 4 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

outputfile << "\nmay\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 5 && portShips[i].port == "M"){

		contadorMayM++;

	 }
	 else if(portShips[i].month == 5 && portShips[i].port == "R"){

		contadorMayR++;

	 }
  }

	outputfile << "M " << contadorMayM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 5 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorMayR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 5 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\njun\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 6 && portShips[i].port == "M"){

		contadorJunM++;

	 }
	 else if(portShips[i].month == 6 && portShips[i].port == "R"){

		contadorJunR++;

	 }
  }

	outputfile << "M " << contadorJunM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 6 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorJunR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 6 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\njul\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 7 && portShips[i].port == "M"){

		contadorJulM++;

	 }
	 else if(portShips[i].month == 7 && portShips[i].port == "R"){

		contadorJulR++;

	 }
  }

	outputfile << "M " << contadorJulM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 7 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorJulR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 7 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\nago\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 8 && portShips[i].port == "M"){

		contadorAgoM++;

	 }
	 else if(portShips[i].month == 8 && portShips[i].port == "R"){

		contadorAgoR++;

	 }
  }

	outputfile << "M " << contadorAgoM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 8 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorAgoR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 8 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\nsept\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 9 && portShips[i].port == "M"){

		contadorSepM++;

	 }
	 else if(portShips[i].month == 9 && portShips[i].port == "R"){

		contadorSepR++;

	 }
  }

	outputfile << "M " << contadorSepM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 9 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorSepR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 9 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\noct\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 10 && portShips[i].port == "M"){

		contadorOctM++;

	 }
	 else if(portShips[i].month == 10 && portShips[i].port == "R"){

		contadorOctR++;

	 }
  }

	outputfile << "M " << contadorOctM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 10 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorOctR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 10 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\nnov\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 11 && portShips[i].port == "M"){

		contadorNovM++;

	 }
	 else if(portShips[i].month == 11 && portShips[i].port == "R"){

		contadorNovR++;

	 }
  }

	outputfile << "M " << contadorNovM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 11 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorNovR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 11 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }

  outputfile << "\ndec\n";
  for (int i=0; i<portShips.size(); i++)
  {

	 if(portShips[i].month == 12 && portShips[i].port == "M"){

		contadorDicM++;

	 }
	 else if(portShips[i].month == 12 && portShips[i].port == "R"){

		contadorDicR++;

	 }
  }

	outputfile << "M " << contadorDicM << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 12 && portShips[i].port == "M"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }
	
	outputfile << "\n";

	outputfile << "R " << contadorDicR << ": ";

  for (int i=0; i<portShips.size(); i++){

	if(portShips[i].month == 12 && portShips[i].port == "R"){

		outputfile << portShips[i].prefix_UBI << " ";
	}

  }


  //Cierra archivos 
  inputfile.close(); 
  outputfile.close(); 
  
	return 0;
}