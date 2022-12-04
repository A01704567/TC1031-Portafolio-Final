//==============================================
// Author: Sofia Blanco Prigmore 
// Date: 30 November, 2022 
//==============================================

#include <iostream>
#include "heap.h"

//Private access methods 
template <class T>
uint Heap<T>::parent(uint pos) const{
    return (pos - 1)/2; 
}


template <class T>
uint Heap<T>::left_child(uint pos) const{
    return (pos * 2) + 1; 
}


template <class T>
uint Heap<T>::right_child(uint pos) const{
    return (pos * 2) + 2; 
}

//Access methods 
template <class T>
int Heap<T>::get_size() const{
    return data.size(); 
}

template <class T>
std::vector<T> Heap<T>::get_data() const{
    return data; 
}

//overload of << operator so we can print heap 
template <class ostream_t>
std::ostream &operator<<(std::ostream &os, const Heap<ostream_t> &_heap)
{
    for (auto &elem : _heap.data)
        os << elem << " ";

    return os;
} 


//Priv functions 
template <class T>
void Heap<T>::heapify(uint pos) {
	uint left = left_child(pos);
	uint right = right_child(pos);
	uint min = pos;

	if(left < data.size() && data[left] < data[min]){
		min = left;
	}
	if(right < data.size() && data[right] < data[min]){
		min = right;
	}

	if(pos != min){
		swap(pos, min);
		heapify(min);
	}
}


//swap 2 elements in heap
template <class T>
void Heap<T>::swap( T elem1, T elem2){
    T temp = data[elem1]; 
    data[elem1] = data[elem2]; 
    data[elem2] = temp; 
}

//insert element into heap 
// tree size = biggest element so place for new value is = size - 9
// while the new value is smaller than the parent the loop repeats 
// until the new value is sorted into place 
template <class T>
void Heap<T>::insert(T value){
    data.push_back(value); 
    uint place = data.size() -1; 

    while (place > 0 && value < data[parent(place)]){
        swap(place, parent(place)); 
        place = parent(place); 
    }
}

//remove element from heap 
template <class T>
T Heap<T>::remove(){
    T minimum = data[0]; 
    data[0] = data[data.size() - 1]; 
    data.pop_back(); 
    heapify(0); 

    return minimum; 
}

//Functions 
template <class T>
void Heap<T>::add(T element){
    insert(element); 
}

template <class T>
T Heap<T>::pop_front(){
    return remove(); 
}

template <class T>
bool Heap<T>::empty() const{
    return data.empty(); 
}

template <class T>
bool Heap<T>::full()const{
    return data.size() == data.max_size(); 
}

