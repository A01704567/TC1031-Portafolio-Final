// =================================================================
//
// File: main.cpp
// Author: Alan Patricio González Bernal 
//         Sofía Blanco Prigmore 
// Date: 17/11/2022
//
// =================================================================

#include <iostream>
#include <fstream>
#include <string.h>

#include "ugraph.h"
using namespace std;


int main(int argc, char *argv[]) {
  //Declare variables 
  int size, numQuery, MNP;
  string node1, node2, vertex, query; 
  
  //Read file 
  if(argc != 3){
    cout << "Usage: " << argv[0] <<"<input_file> <output_file>"<< endl; 
    return -1; 
  }
  
  ifstream inputfile (argv[1], ios::in);
  if(!inputfile.is_open()){
    cout << "Error: No se pudo abrir el archivo de entrada" <<endl; 
    return -1; 
  }
  ofstream outputfile (argv[2], ios::out);
  if(!outputfile.is_open()){
    cout <<"Error: No se pudo abrir archivo de salida "<< endl;
    return -1; 
  }

  //Begin code 
  inputfile >> size;
  UMatrixGraph<string> graph(size); 


  for(int i=0; i < size; i++){
    inputfile >> node1;
    inputfile >> node2;
    graph.addEdge(node1, node2);
  }

  cout << "graph" << endl; 
  inputfile >> numQuery;
  
  for(int i=0; i< numQuery; i++){
    inputfile >> vertex; 
    inputfile >> MNP; 

    outputfile << vertex << " " << MNP << endl; 
  }

  return 0; 
	 
}
