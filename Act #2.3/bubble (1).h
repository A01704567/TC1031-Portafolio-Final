#ifndef BUBBLE_H
#define BUBBLE_H

#include "header.h"
#include <vector>


template <class T>
int bubbleSortDay(std::vector<T> &v) {
  int counter = 0; 
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].day > v[j + 1].day){
				swap(v, j, j + 1);
        counter+=1; 
			}
		}
	}
  return counter; 
}

template <class T>
int bubbleSortMonth(std::vector<T> &v) {
  int counter = 0; 
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].month > v[j + 1].month){
        counter+=1; 
				swap(v, j, j + 1);
			}
		}
	}
  return counter; 
}

#endif