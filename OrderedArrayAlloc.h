#pragma once
#include <iostream>
#include <string>

#include "Item.h"

using namespace std;
template <typename T>

class OrderedArrayAlloc
{

private:



	int capacity = 200;
	T* bytesizeData = (T*)calloc(sizeof(T), sizeof(capacity));
	//how many elements.
	int index;

public:
	T getData() {
		return this->bytesizeData;
	}

	OrderedArrayAlloc()
	{
	

		index = 0;
	};
	OrderedArrayAlloc(int growSize)
	{
		/*easy way to do it is just */

		capacity += growSize;
		bytesizeData = (T*)calloc(sizeof(T), sizeof(capacity));
		index = 0;
		/*trivial . im sure its about copying elements of
		old Array into new Array.
		Can' t see it doing that in Constructor(as per requirements)

		*/
	};
	~OrderedArrayAlloc()
	{
		//deleting all objects on memory stack
		//if only one Object pHead doesnt have pNext reference
			//freeing the mem
	


	};

	bool isEmpty()
	{
		return (bytesizeData[0]);
	}
	int getSize() {
		return this->index;
	}
	int getCapacity()
	{
		return this->capacity;
	}





	void increaseIndex() {
		this->index++;

	}
	void decreaseIndex() {
		this->index--;
	}
	void push(const T& data)
	{
		T newData = data;
		//list is empty
		if (this->isEmpty())
		{
			cout << newData << endl;

			bytesizeData[index] = data;
			increaseIndex();

		}
		//list is not empty
		else if (this->index == this->capacity)
		{


			cout << "array full .Request increase size" << endl;
			//throw std::out_of_range;
		}
		else {
			bytesizeData[index] = data;

	
			this->increaseIndex();




		}

	}
	void sort() {
	


		for (int i = 0; i < index - 1; i++)
		{

			int min_idx = i;
			for (int j = i + 1; j < index; j++)
				if (bytesizeData[j] <= bytesizeData[min_idx])
					min_idx = j;

			T temp = bytesizeData[min_idx];
			bytesizeData[min_idx] = bytesizeData[i];
			bytesizeData[i] = temp;
			cout <<  temp  << endl;
		}
	}
	int length() {
		return this->index;
	}

	void remove(int removeAtIndex)
	{
		//if no objects 
		if (this->isEmpty()) {
			return;
		}
		else {
			// no idea.
			bytesizeData[removeAtIndex]->~T;

		}

	}

	T getElement(int elIndex) {


		//pretty same as removing.only that is returning the Item /Element.
		if (this->isEmpty()) {

			return 0;
		}
		//this returns where pointer is.
	
		return bytesizeData[elIndex];
		


	}

	void clear() {
/*
* 
* //clearing data in the mem block
		for (int i = 0; i < index; i++) {
			//fill with zeros
			bytesizeData[i] = nullptr;
		}
		*/
		//clearing all resources on the heap @runtime.
		bytesizeData = nullptr;
		//dealocating the memory dynamically.Calling destructor
		delete (bytesizeData);
	
	
	}

	int   search(T& data) {
			this->sort();
			for (int i =  0; i <index; i++) {
			if(bytesizeData[i]==data) {
				return i;
			}

			};
		return 0;//not found
	

	}


};

