#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
template <typename T>
class MySet
{

private:
	/*

	Item vars :Data
	Item*->pNext is where action is. Holds a pointer to address in memory.

	Hence all objects seem strung together as in an array.
	Methods : setNext, getNext,setData, getData.
	pTail ->next will point to itself.d
	*/
	Item<T>* pHead;
	Item<T>* pTail;


	int size = 200;


	//keeping track.
	int index;

public:
	Item<T>* getHead() {
		return this->pHead;
	}

	MySet()
	{
		pHead = pTail = nullptr;

		index = 0;
	};
	MySet(int growSize)
	{
		/*easy way to do it is just */
		pHead = pTail = nullptr;
		size += growSize;

		index = 0;
		/*trivial . im sure its about copying elements of
		old Array into new Array.
		Can' t see it doing that in Constructor(as per requirements)

		*/
	};
	~MySet()
	{
		//deleting all objects on memory stack
		//if only one Object pHead doesnt have pNext reference



	};

	bool isEmpty()
	{
		return (pHead == nullptr && pTail == nullptr);
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

	/*
	*
	* an attempt to sort by Node data.
	void sort() {
		/

		int ind = index - 1;
		for (int i = 0; i < ind; i++)
		{

			Item<T>* min = pHead;
			for (int j = i + 1; j < index; j++) {
				if (this->pHead->getNext()->getData() < this->pHead->getData())
				{
					min = pHead -> getNext();
				}
				Item<T>* temp = min;
				pHead->setNext(pHead)  ;
				pHead = temp;

			}
		}
		for (int i = 0; i < index; i++) {
			T t = getElement(i);
			cout << t << endl;
		}

	}

	*/
	
	int searchElement( T target)
	{
		//linear search
		for (int i = 0; i < index; i++) {
			if (target == getElement(i)) {
				T& t = getElement(i);
				cout <<t << endl;
				return 1;
			}
			
			
		}
		return -1;
		

	}
	
	bool add(const T& data)
	{
		Item<T>* pNew = new  Item<T>(data);

		//list is empty
		if (this->isEmpty())
		{
			//one object for start and end. 
			//have same index.
			pHead = pTail = pNew;


			pHead->setIndex(this->index);
			pTail->setIndex(this->index);
			increaseIndex();
			return true;

		}
		//list is not empty
		else if (this->index == this->size)
		{
			return false;

			cout << "array full .Request increase size" << endl;
			//throw std::out_of_range;
		}
		else {
		int res = searchElement(pNew->getData());
			if (res !=1) {


				pTail->setNext(pNew);
				//cout << pTail->getNext() << endl;

				pTail = pNew;
				//cout << pTail << endl;
				pTail->setIndex(this->index);
				//increaseIndex();
				return true;
			}
			
			



		}
		return false;

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
			//compare the index of objects on the MEM stack with arg index
			Item<T>* removingItem = pHead;
			if (removingItem == nullptr) {
				return;
			}

			//if found we remove , and copy to previous and  shift index
			else if (removingItem->getIndex() == removeAtIndex)
			{
				int tailIndex = pTail->getIndex();
				//loop till tail, and copy Objects to previous Item/Node.
				while (removingItem->getIndex() != tailIndex) {
					//now poiting to address of getNext()
					removingItem = removingItem->getNext();//new address .new object
					//they will all keep a reference of next object in order. HOPEFULLY.
					decreaseIndex();
					removingItem->setIndex(this->index);
					tailIndex++;
				}
			}

			//continue to next untill found;
			else {
				remove(removingItem->getNext()->getIndex());
			}
		}

	}

	void iterate() {
		for (int i = 0; i < index; i++) {
			
		}
	}
	T getElement(int elIndex) {


		//pretty same as removing.only that is returning the Item /Element.
		if (this->isEmpty()) {

			return 0;
		}
		else if (pHead->getIndex() == elIndex) {
			return pHead->getData();
		}
		else {
			while (pHead->getNext() != nullptr) {
				Item<T>* temp = pHead->getNext();
				pHead = temp;
				getElement(pHead->getNext()->getIndex());

			}
		}
	

	


	}

	void clear() {


	}
	int  search(T data) {
		//linear search starting at head
		Item<T>* searchHead = pHead;

		//pretty same as removing.only that is returning the Item /Element.
		if (this->isEmpty()) {
			return 0;
		}

		//compare the index of objects on the MEM stack with arg index

			//if found we remove , and copy to previous and  shift index
		else if (searchHead->getData() == data)
		{
			return searchHead->getIndex();
			//if we found Item we return 
			//if not we continue  recursively
		}

		//continue to next untill found;
		else {
			getElement(searchHead->getNext()->getData());
		}

	}


};

