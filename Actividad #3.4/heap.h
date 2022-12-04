//==============================================
// Author: Sofia Blanco Prigmore 
// Date: 30 November, 2022 
//==============================================
#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>
#include <sstream>

//Declare class Heap 

template <class T>
class Heap{

public: 
    //constructor 
    Heap() = default; 
    //destructor 
    ~Heap() = default; 

    //functions 
    T pop_front(); 

    void add(T); 
    void clear(); 

    bool empty() const; 
    bool full() const; 

    //access methods 
    int get_size() const; 
    std::vector<T> get_data() const; 

    //Operator overload + friend class
    // Operator Overload
    template <class ostream_t>
    friend std::ostream &operator<<(std::ostream &, const Heap<ostream_t> &);

private: 
    std::vector<T> data; 

    //access methods 
    uint parent(uint) const; 
    uint left_child(uint) const; 
    uint right_child(uint) const; 


    //functions 
    void swap(T,T); 
    void heapify(uint); 


    void insert(T); 
    T remove(); 
}; 



#endif 
