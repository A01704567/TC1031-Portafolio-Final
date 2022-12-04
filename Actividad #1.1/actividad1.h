//================================================
//File: 
//Author: Sofía Blanco Prigmore - A01704567
//Date: 08/26/2022
//================================================
#ifndef ACTIVIDAD1_H
#define ACTIVIDAD1_H

#include <iostream>
using namespace std; 

unsigned int sumaIterativa(unsigned int n){
  int contador = 1; 
  int acum = 0; 
  if (n>=0){
    while (contador <= n){
    acum = acum + contador; 
    contador = contador + 1; 
  }
    return acum; 
  }
  return 0; 
}
//Complejidad de la iterativa = O(n)

unsigned int sumaRecursiva(unsigned int n){
  if (n <= 0){
    return 0; 
  }
  else{
    return sumaRecursiva(n-1) + n; 
  }
  return 0; 
}
// Complejidad de la recursiva = O(n)

unsigned int sumaDirecta(unsigned int n){
  int suma; 
  if(n>=0){
    suma = (n*(n+1))/2;
    return suma; 
    }
  return 0; 
}

// Complejidad de la directa = no es iterativa o recursiva. Pero si dijeramos que es iterativa por falta de recursión se podría decir que es de complejidad O(log n)

#endif

