//
// Created by ovi on 22/08/23.
//

#ifndef SEARCHDARNELEM_MYSET_H
#define SEARCHDARNELEM_MYSET_H

#endif //SEARCHDARNELEM_MYSET_H
#pragma once
#include <iostream>
#include "Item.h"


using namespace std;
template <typename T>
class OrderedArray
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

    void print() {



        int start = 0;
        int index = this->getIndex();

        while (start < index) {

            T valueAtHead = this->getHead()->getData();

            Item<T>* temp = this->getHead()->getNext();

            cout << valueAtHead << endl;
            this->pHead = temp;



            start++;
        }

    }
  
    Item<T>* getTail()
    {

        return this->pTail;
    }
    Item<T>* getHead() {
        return this->pHead;
    }

    void setHead(Item<T>* h) {
        this->pHead = h;

    }
    OrderedArray()
    {
        pHead = pTail = nullptr;

        index = 0;
    };
   OrderedArray(int growSize)
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
    ~OrderedArray()
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

    int  getIndex() {
        return this->index;
    }

    void increaseIndex() {
        this->index++;

    }
    void decreaseIndex() {
        this->index--;
    }






    bool push(const T& data)
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
            //


            pTail->setNext(pNew);
            //cout << pTail->getNext() << endl;

            pTail = pNew;
            increaseIndex();
            //cout << pTail << endl;
            pTail->setIndex(this->getIndex());
            //increaseIndex();
            return true;






        }
        return false;

    }
    int length() {
        return this->pTail->getIndex();
    }
   T search(T data) {
        if (this->isEmpty() | (this->getHead() == nullptr)) {
            return NULL ;
        }

        else {
            int start = 0;
            int index = this->getIndex();

            while (start < index) {
                T valueAtHead = this->getHead()->getData();

                if (valueAtHead == data) {
                    cout << valueAtHead << endl;
                    return this->getHead()->getData();
                }
                else {
                    Item<T>* temp = this->getHead()->getNext();

                    cout << "valueAtHead" << endl;
                    this->pHead = temp;

                }

                start++;
            }
            return 0;
        }
    }
    void remove(int removeAtIndex) {
        //if no objects

        //really needs a CHECK for pHEAD:
        if (this->isEmpty() | (this->getHead() == nullptr)) {
            return;
        }
        else {
            //compare the index of objects on the MEM stack with arg index
            int start = 0;
            int index = this->getIndex();

            while (start < index) {

                int indexAtHead = this->getHead()->getIndex();
                if (indexAtHead == removeAtIndex) {
                    this->setHead(this->getHead()->getNext());

                }
                else {
                    Item<T>* temp = this->getHead()->getNext();

                    cout << indexAtHead << endl;
                    this->pHead = temp;

                }


                start++;
            }
        }

    }




    //if found we remove , and copy to previous and  shift index








    T getElement(int elIndex) {
        if (this->isEmpty() ) {
            return NULL;
        }
        else {
            //compare the index of objects on the MEM stack with arg index
            int start = 0;
            int index = this->getIndex();

            while (start < index) {

                int indexAtHead = this->getHead()->getIndex();
                if (indexAtHead == elIndex) {
                   
                    
                    return this->getHead()->getData();

                }
                else {
                    Item<T>* temp = this->getHead()->getNext();


                    this->setHead(temp);

                }


                start++;
            }
        }


    }







    void clear() {


    }


};

