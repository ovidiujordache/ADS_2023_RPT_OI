#include <iostream>
#include "OrderedArray.h";
#include "Box.h";
#include "Circle.h";
#include "ReadCSV.h";

	using namespace std;

int main() {
	cout << "running main" << endl;

    OrderedArray<int> *oAI = new OrderedArray<int>(2);//address
	OrderedArray<float>* oAF = new OrderedArray<float>(2);//address
	OrderedArray<Box>* oAB = new OrderedArray<Box>(6);//address
	Box* b = new Box(3,5,3);
	Box* b1 = new Box(36, 5,5);
	
	//dereferencing
	
	 bool areSame = (*b==*b1);

	//int length = b->getLength();
	cout << *b1 << endl;

	cout<<"Same or no Same:"<<areSame << endl;
	//printf("%i\n",length);

	//int size =oAB->length();
	//cout<<size<<endl;
	Circle* c1 = new Circle();
	int rad = 34;
	int* pRad = &rad;
	c1->setRadius(*pRad);
	int getR=c1 ->getRadius();
	printf("%d", getR);
	
	ReadCSV* rF = new ReadCSV();
		
	rF->readCSV();


}
