#include <iostream>
#include "OrderedArray.h";
#include "OrderedArrayAlloc.h";
#include "MySet.h";
#include "Box.h";
#include "Circle.h";
#include "ReadCSV.h";
#include "MySet.h"

	using namespace std;

int main() {

	OrderedArrayAlloc<int>* oAL = new OrderedArrayAlloc<int>();
	int* a = new int(5);
	int* b = new int(6);
	int* c = new int(67);
	int* d = new int(58);
	int* e = new int(9);
	oAL->push(*a); oAL->push(*b); oAL->push(*c); oAL->push(*d); oAL->push(*e);


}
