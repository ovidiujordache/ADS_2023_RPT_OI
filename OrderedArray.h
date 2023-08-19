#pragma once

#include <iostream>

template <class T>
class OrderedArray{

private :
	int size;
	T* orderedArrayData=nullptr;
public :
	//constructor
	//@param noparam
	OrderedArray() {
		orderedArrayData = new T[0];
	};
	//overloaded constructor
	//@param int size
	OrderedArray(int size) :size(size) {
		this->orderedArrayData = new T[size];

		printf("%s", "overloaded constructor\n");
	}

	//@destructor
	~OrderedArray() {
		printf("%s", "Destructor is called\n");
	}
	

	//@function int length()
	int length() {

		//it should return the number of elements added to the array and not its capacity. 
		printf("%s", "get size called\n");
		return this->size;
	}

	//@function T getElement()
	T getElement() {
		printf("%s", "getElement is called\n");
	}

	//@function bool remove()
	bool remove(int index) {
		printf("%s", "remove(t) is called\n");
	
	}

	//@function int search(T& target)
	int search(T& target) {
		printf("%s", "search(t) is called\n");
	
	
	}

	//@function void clear()
	void clear() {
		printf("%s", "clear() is called\n");
	}



};