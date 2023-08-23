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
	//very important !!! to return pointer for accessing
	//data.
	T* getData() {
		return this->bytesizeData;
	}
	void setData( T* d) {
		this->bytesizeData = d;
	}
	int getSize() {
		return this ->index;
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

	int getCapacity()
	{
		return this->capacity;
	}

	bool contains(T data) {
		if (this->isEmpty()) {
			return false;
		}
		for (int i = 0; i < this->index; i++) {
			if (bytesizeData[i] == data) {
				
				return true;
			}
			else {
				return false;
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
			if (!contains(data)) {
				bytesizeData[index] = data;
			}

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

	void copyInto(){
		T * copyData = (T*)calloc(sizeof(T), sizeof(capacity));
			for (int i = 0; i < this->index; i++) {
			copyData[i] = bytesizeData[i];

		}
			delete(bytesizeData);
			free(bytesizeData);
			bytesizeData = copyData;
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
			bytesizeData[removeAtIndex] = 0;
			this->copyInto();
		


		}

	}

	T getElement(int elIndex) {


		//pretty same as removing.only that is returning the Item /Element.
		if (this->isEmpty()) {

			return 0;
		}
		return bytesizeData[elIndex];


	}



	bool  search(T data) {
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

	MySetAlloc<T>& operator+(const MySetAlloc<T>& set2)const {
		T* data1 = bytesizeData;//this set
		T* data2 = nullptr;
		MySetAlloc<T>set2ptr;
		set2ptr = static_cast<MySetAlloc<T>>(set2);//arg set
		//very odd behaviour VS for converting
		MySetAlloc<T>* set2ptrr = &set2ptr;
		data2 = set2ptrr->getData();
		int size1 = this->index;
		int size2 = set2ptrr->getIndex();
		int coef = size1 + size2;
		MySetAlloc<T>* addedSet = new MySetAlloc<T>();//new union set
		T* newData = (T*)calloc(sizeof(T), sizeof((this->capacity) * coef));;//data size for new union set
		for (int i = 0; i < coef; i++) {

		}

		return addedSet;

	}
	MySetAlloc<T>	operator&(const MySetAlloc<T>& set1) {

		T* data1 = bytesizeData;
		T* data2 =  bytesizeData;
		T* newData = (T*)calloc(sizeof(T), sizeof(this->capacity));;

		int addingIndex = 0;
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

	 MySetAlloc<T>&	 operator|(const MySetAlloc<T>& set2)const {
		 /*
		 This method has the  meat of pointers /referencing
		 dereferencing and the lot...
		 */
		 T* data1 = bytesizeData;//this set
		 T* data2 = nullptr;
		 MySetAlloc<T>set2ptr;
		 set2ptr = static_cast<MySetAlloc<T>>(set2);//arg set
		//very odd behaviour VS for converting
		 MySetAlloc<T>* set2ptrr = &set2ptr;
		 data2 = set2ptrr->getData();
		 int size1 = this->index;
		 int size2 = set2ptrr->getIndex();
		 int coef = size1 + size2;
		 MySetAlloc<T>* uniSet = new MySetAlloc<T>();//new union set
		T*  newData = (T*)calloc(sizeof(T), sizeof((this->capacity)*coef));;//data size for new union set
	
		
		uniSet->setData(newData);//new data size byte alloc 2 times comparing sets
	
		//subscript requires array or pointer type
		T* uniSetData = uniSet->getData();//getting data to fill the mem bllocks;
		cout << "get data" << endl;
		
		int addingIndex = 0;

		for (int i = 0; i < this->index; i++) {
			for (int j = 0; j < this->index ; j++) {
			
			}

		}

		return *uniSet;

		
		
	}
	//if sets are same size , elements wise not capacity
	bool operator==(MySetAlloc<T>& set1) {
		return (this->index == set1->index);
	}



};

