#pragma once
#include <iostream>
#include <string>

#include "Item.h"

using namespace std;
template <typename T>

class MySetAlloc
{

private:



	int capacity = 200;
	T* bytesizeData = (T*)calloc(sizeof(T), sizeof(capacity));

	int index;

public:
	T getData() {
		return this->bytesizeData;
	}

	MySetAlloc()
	{


		index = 0;
	};
	MySetAlloc(int growSize)
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
	~MySetAlloc()
	{
		//deleting all objects on memory stack
		//if only one Object pHead doesnt have pNext reference



	};
	int getIndex() {
		return this->index;
	}
	bool isEmpty()
	{
		return (bytesizeData[0]);
	}

	int getSize()
	{
		return this->capacity;
	}

	bool contains(T data) {
		if (this->isEmpty()) {
			return 0;
		}
		for (int i = 0; i < this->index; i++) {
			if (bytesizeData[i] == data) {
				return true;
			}
		}

			
	}

	int search(T* bytedata, int size, int target)
	{
		int min = 0, max = size - 1, mid = 0;
		bool found = false;
		while (!found && min <= max)
		{
			mid = (min + max) / 2; // (integer div!)
			if (bytedata[mid] == target)
				found = true;
			else if (target < bytedata[mid])
				max = mid - 1;
			else min = mid + 1;
		}
		if (found) return mid;
		else return -1;
	}



	void increaseIndex() {
		this->index++;

	}
	void decreaseIndex() {
		this->index--;
	}
	void add(const T& data)
	{
		T newData = data;
		//list is empty
		if (this->isEmpty())
		{


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


			increaseIndex();




		}

	}


	void sort() {



		for (int i = 0; i < index - 1; i++)
		{

			int min = i;
			for (int j = i + 1; j < index; j++)
				if (bytesizeData[j] <= bytesizeData[min])
					min = j;

			T temp = bytesizeData[min];
			bytesizeData[min] = bytesizeData[i];
			bytesizeData[i] = temp;
			cout << temp << endl;
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
			this->index--;
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



	void   search(T data) {
		for (int i = 0; i < index; i++) {
			if (bytesizeData[i] == data) {
				return true;
			}

		};
		return false;//not found


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


	MySetAlloc<T>	operator&(const MySetAlloc<T>& set1) {

		T* data1 = bytesizeData;
		T* data2 =  bytesizeData;
		T newData = (T)calloc(sizeof(T), sizeof(this->capacity));;

		int* addingIndex = 0;
		for (int i = 0; i < this->index-1; i++) {
			for (int j = 0; j < this->index - 2; j++) {
				if (data1[i] == data2[j]) {
					cout << data1[i] << endl;
					cout << data1[j] << endl;
					//continue;
				}
				else {
					cout << data1[i] << endl;
					cout << data1[j] << endl;
				
					newData[addingIndex] = data1[i];
					addingIndex++;
					newData[addingIndex] = data2[j];
				}
			}

		}

		return newData;

	}

	MySetAlloc<T>	operator|( MySetAlloc<T> set1) {
	
		T* data1 = bytesizeData;
		T* data2 = bytesizeData;
		T newData = (T)calloc(sizeof(T), sizeof((this->capacity)*2));;
	
		int* addingIndex = 0;
		for (int i = 0; i < this->index; i++) {
			for (int j = 0; j < this->index ; j++) {
				if (data1[i] == data2[j]) {
					cout<<data1[i]<<endl;
					cout << data1[j] << endl;
					//continue;
				}
				else {
					cout << data1[i] << endl;
					cout << data1[j] << endl;
					newData[addingIndex++] = data1[i];
					
					newData[addingIndex++] = data2[j];
				
				}
			}

		}
	
		return newData;

	}
	//if sets are same size , elements wise not capacity
	bool operator==(MySetAlloc<T>& set1) {
		return (this->index == set1->index);
	}



};

