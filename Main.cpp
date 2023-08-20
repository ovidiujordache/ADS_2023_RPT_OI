#include <iostream>
#include "OrderedArray.h";
#include "Box.h";
#include "Circle.h";
#include "ReadCSV.h";

	using namespace std;

int main() {


	cout << "running main" << endl;
	/*
    OrderedArray<int> *oAI = new OrderedArray<int>();//address
	OrderedArray<float>* oAF = new OrderedArray<float>();//address
		*/
	OrderedArray<Box>* oAB = new OrderedArray<Box>();//address
	
	Box* b1 = new Box(3,5,3);
	Box* b2 = new Box(36, 5,5);
	Box* b3 = new Box(36, 5, 5);
	Box* b4 = new Box(36, 5, 5);
	Box* b5 = new Box(36, 5, 5);


	//
	oAB->push(*b1);
	oAB->push(*b2);
	oAB->push(*b3);
	oAB->push(*b4);
	oAB->push(*b5);
	cout<<oAB->length()<<endl;
	cout << oAB->getSize() << endl;
	
	cout<<"ending here" << endl;
	


	ReadCSV* rF = new ReadCSV();
		
//	rF->readCSV();


}
