#include <iostream>
#include "OrderedArray.h";
#include "OrderedArrayAlloc.h";
#include "Box.h";
#include "Circle.h";
#include "ReadCSV.h";

	using namespace std;

int main() {


 
	OrderedArray<Box>* oB = new OrderedArray<Box>(5);

	Box* b1 = new Box(3, 5, 3);
	Box* b2 = new Box(36, 5, 5);
	Box* b3 = new Box(36, 5, 5);
	Box* b4 = new Box(36, 5, 5);
	Box* b5 = new Box(36, 5, 5);


	oB->push(*b1);
	oB->push(*b2);
	oB->push(*b3);
	oB->push(*b4);
	oB->push(*b5);

	//ReadCSV* rF = new ReadCSV();
		
//	rF->readCSV();

	OrderedArrayAlloc<int>* oI = new OrderedArrayAlloc<int>(5);
	int* a =new int (245);
	int* b = new int(122);
	int* c = new int(652);
	int* d = new int (32);
	int* e = new int(2);

	oI->push( *a);
	oI->push(*b);
	oI->push(*c);
	oI->push(*d);
	oI->push(*e);

	/*

	OrderedArrayAlloc<Box>* oBA = new OrderedArrayAlloc<Box>(5);

	Box* b12 = new Box(3, 5, 3);
	Box* b23 = new Box(36, 5, 5);
	Box* b34 = new Box(36, 5, 5);
	Box* b45 = new Box(36, 5, 5);
	Box* b56 = new Box(36, 5, 5);


	oB->push(*b1);
	oB->push(*b2);
	oB->push(*b3);
	oB->push(*b4);
	oB->push(*b5);
	oBA->iterate();

	*/




}
