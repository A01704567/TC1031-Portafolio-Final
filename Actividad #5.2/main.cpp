// =================================================================
//
// File: main.cpp
// Author: Sofia Blanco Prigmore 
// Date: 30 November, 2022 
//
// =================================================================
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {

    //Read file 
    if(argc != 3){
        cout << "Usage: " << argv[0] <<"<input_file> <output_file>"<<endl; 
        return -1; 
    }
    
    ifstream inputfile (argv[1], ios::in);
    if(!inputfile.is_open()){
        std::cout << "Error.... opening input file" << argv[1] <<endl; 
        return -1; 
    }
    ofstream outputfile (argv[2], ios::out);
    if(!outputfile.is_open()){
        cout <<"Error.... opening output file"<< argv[2] <<endl;
        return -1; 
    }

    int dictionary, num_descriptions; 
    inputfile>> dictionary >> num_descriptions; 

    map<string,int> jobs;


    for (int i=0; i < dictionary; i++){
        string occupation; 
        int money; 

        inputfile >> occupation >> money; 
        jobs[occupation] = money; 
    }

    for(int i=0; i < num_descriptions; i++){
        string occupation; 
        int salary = 0; 

        while (inputfile>>occupation){
            if(occupation == "."){
                break; 
            }

            salary += jobs[occupation]; 
        }

        outputfile << salary << endl; 
    }




	inputfile.close(); 
    outputfile.close();
}