#pragma once
#include <iostream>
#include <string>

#include "Item.h"

using namespace std;
template <typename T>

class OrderedArrayAlloc
{

private:



	int size = 200;
	T* bytesizeData = (T*)calloc(sizeof(T), sizeof(size));

	int index;

public:
	T getData() {
		return this->bytes;
	}

	OrderedArrayAlloc()
	{
	

		index = 0;
	};
	OrderedArrayAlloc(int growSize)
	{
		/*easy way to do it is just */

		size += growSize;
		bytesizeData = (T*)calloc(sizeof(T), sizeof(size));
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



	};

	bool isEmpty()
	{
		return (bytesizeData[0]);
	}

	int getSize()
	{
		return this->size;
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
		

			bytesizeData[index] = data;
			increaseIndex();

		}
		//list is not empty
		else if (this->index == this->size)
		{


			cout << "array full .Request increase size" << endl;
			//throw std::out_of_range;
		}
		else {
			bytesizeData[index] = data;

	
			increaseIndex();




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
		return bytesizeData[elIndex];


	}

	void clear() {

		for (int i = 0; i < index;i++) {
			bytesizeData[i]=nullptr;//calling destructor
		};
	}

	void   search(T data) {
		for (int i = 0; i < index; i++) {
			if(bytesizeData[i]=data) {
				return true;
			}

			};
		return false;//not found
	

	}


};

