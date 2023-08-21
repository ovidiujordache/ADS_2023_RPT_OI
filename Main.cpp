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
	oB->iterate();
	//ReadCSV* rF = new ReadCSV();
		
//	rF->readCSV();


}
