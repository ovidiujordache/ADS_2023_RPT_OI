#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
template <typename T>
class OrderedArray
{

	/*

	Item vars :Data 
	Item*->pNext is where action is. Holds a pointer to address in memory.

	Hence all objects seem strung together as in an array.
	Methods : setNext, getNext,setData, getData.
	pTail ->next will point to itself.
	*/
	Item<T>* pHead;
	Item<T>* pTail;
	int size;
	//keeping track.
	int index;

	void initialize()
	{
	
	}
public:
	Item<T>* getHead() {
		return this->pHead;
	}

	OrderedArray()
	{
		pHead = pTail = nullptr;
		size = 100;
		index = 0;
	};
	~OrderedArray()
	{
		//deleting all objects on memory stack
		//if only one Object pHead doesnt have pNext reference
		while (pHead->getNext() != nullptr)
		{
			delete pHead;
		}
		delete size, index;
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
	void push(T& data)	
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

		}
		//list is not empty
		else if(this->index==this->size)
		{
			cout<<"array full .Request increase size" << endl;
		}
		else {
			//get last node and tag on the new node
			pTail->setNext(pNew);
			cout << pTail->getNext() << endl;

			pTail = pNew;
			cout << pTail << endl;
			pTail->setIndex(this->index);
			increaseIndex();
	
		
		
	
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
			//compare the index of objects on the MEM stack with arg index
			Item<T>* removingItem = pHead;
			if (removingItem == nullptr) {
				return;
			}
			
			//if found we remove , and copy to previous and  shift index
			else if(removingItem->getIndex() == removeAtIndex)
			{
				//loop till tail, and copy Objects to previous Item/Node.
				for (int rmv = removingItem->getIndex(); rmv < this->pTail->getIndex; ++rmv) {
					//now poiting to address of getNext()
					removingItem = removingItem->getNext();//new address .new object
					//they will all keep a reference of next object in order. HOPEFULLY.
					decreaseIndex();
					removingItem->setIndex(this->index);
				}
			}

			//continue to next untill found;
			else {
				remove(removingItem->getNext());
			}
		}
		
	}
	T getElement(int elIndex) {
		//pretty same as removing.only that is returning the Item /Element.
		if (this->isEmpty()) {
			return;
		}
		else {
			//compare the index of objects on the MEM stack with arg index
			Item<T>* returningItem = pHead;
			if (returningItem == nullptr) {
				return;
			}

			//if found we remove , and copy to previous and  shift index
			else if (returningItem->getIndex() == elIndex)
			{
				return returningItem->getData();
				//if we found Item we return 
				//if not we continue  recursively
			}

			//continue to next untill found;
			else {
				getElement(returningItem->getNext()->getIndex());
			}
		}
	}

	void clear() {
		
		
	}
	void search(T data) {

	}


};

