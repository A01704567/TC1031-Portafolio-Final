#include <iostream>
#include "heap.cpp"

using namespace std; 

int main(){

    Heap<int> heap; 
    Heap<int> empty_heap; 

    heap.add(1); 
    heap.add(2); 
    heap.add(3); 
    heap.add(4); 
    heap.add(5); 


    if (empty_heap.empty()){
        cout << "Heap structure is empty." <<endl; 
    }
    else{
        cout << "Heap is not empty." << endl; 
    }
    
    
}