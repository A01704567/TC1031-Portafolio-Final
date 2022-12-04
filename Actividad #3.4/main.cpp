// =================================================================
//
// File: main.cpp
// Author: Sofía Blanco Prigmore 
// Date: 30/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string.h>

#include "heap.cpp"

//num comparaciones =   m + n -1
//primera línea = numListas 
//2nda lína  = tamlista 

int main(int argc, char* argv[]) {

    //Read file 
    if(argc != 3){
        std::cout << "Usage: " << argv[0] <<"<input_file> <output_file>"<< std::endl; 
        return -1; 
    }
    
    std::fstream inputfile (argv[1], std::ios::in);
    if(!inputfile.is_open()){
        std::cout << "Error: No se pudo abrir el archivo de entrada" << argv[1] <<std::endl; 
        return -1; 
    }
    std::fstream outputfile (argv[2], std::ios::out);
    if(!outputfile.is_open()){
        std::cout <<"Error: No se pudo abrir archivo de salida "<< argv[2] <<std::endl;
        return -1; 
    }


    int size; 
    inputfile >> size; 

    Heap<int> heap; 

    int val; 
    for(int i=0; i<size;i++){
        inputfile >> val; 
        heap.add(val);
    }

    int comparison{}, sum{};

    while (heap.get_size() > 1){
        sum = heap.pop_front() + heap.pop_front(); 
        heap.add(sum); 
        comparison += sum -1; // m + n - 1 
    } 


    outputfile << comparison << std::endl; 
	
}