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
#include <boost/optional.hpp>
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



    /*
    •	Set | Set: - returns a new set containing all unique elements from each input set.
•	Set & Set: - Returns a new set containing all elements common to both sets (Intersection)
  bool operator&&(const MySet& set1, const MySet set2) {


    }
    */




  
bool contains(T data){
    if (this->isEmpty() | ( this->getHead() == nullptr)) {
        return 0;
    }

else {
        int start = 0;
        int index = this->getIndex();

        while (start < index) {
            T valueAtHead = this->getHead()->getData();

            if (valueAtHead == data) {
                cout << valueAtHead << endl;
                return 1;
            } else {
                Item<T> *temp = this->getHead()->getNext();

               // cout << "valueAtHead" << endl;
                this->pHead = temp;

            }

            start++;
        }
        return 0;
    }
    }
    Item<T>* getTail()
    {

        return this->pTail;
    }
    Item<T>* getHead() {
        return this->pHead;
    }

    void setHead(Item<T>* h){
        this->pHead=h;

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

int  getIndex(){
        return this->index;
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

        else if (this->index == this->size | (this->contains(data )))
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
        return this->index;
    }

    void remove(int removeAtIndex) {
        //if no objects

        //really needs a CHEC
        if (this->isEmpty() | (this->getHead() == nullptr)) {
            return;
        } else {
            //compare the index of objects on the MEM stack with arg index
            int start = 0;
            int index = this->getIndex();

            while (start < index) {

                int indexAtHead = this->getHead()->getIndex();
                if (indexAtHead == removeAtIndex) {
                    this->setHead(this->getHead()->getNext());

                } else {
                    Item<T> *temp = this->getHead()->getNext();

                    cout << indexAtHead << endl;
                    this->pHead = temp;

                }


                start++;
            }
        }

    }




                //if found we remove , and copy to previous and  shift index







    T getElement(int elIndex) {
        if (this->isEmpty()) {
            return 0;
        } else {
            //compare the index of objects on the MEM stack with arg index
            int start = 0;
            int index = this->getIndex();

            while (start < index) {

                int indexAtHead = this->getHead()->getIndex();
                if (indexAtHead == elIndex) {
                    return this->getHead()->getData();

                } else {
                    Item<T> *temp = this->getHead()->getNext();


                    this->setHead(  temp);

                }


                start++;
            }
        }
        return 0;
        }







    void clear() {


    }



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




};

