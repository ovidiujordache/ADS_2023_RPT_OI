#include <iostream>
#include "OrderedArray.h";
#include "OrderedArrayAlloc.h";
#include "MySet.h";
#include "Box.h";
#include "Circle.h";
#include "ReadCSV.h";
#include "MySet.h"
#include "MySetAlloc.h"
	using namespace std;

	int main() {

		MySetAlloc<int>* set1 = new MySetAlloc<int>();
		int* a = new int(1);
		int* b = new int(2);
		set1->add(*a);
		set1->add(*b);
		MySetAlloc<int>* set2 = new MySetAlloc<int>();
		int* a1 = new int(21);
		int* b1 = new int(22);
		set2->add(*a1);
		set2->add(*b1);	set2->add(*b1);	set2->add(*b1);	set2->add(*b1);	set2->add(*b1);	set2->add(*b1);
		bool tr = set1->contains(1);
		//cout << tr << endl;
		/*

		MySetAlloc<int>* uni = &(*set1 | *set2);
		int* d =(int*)( uni->getData());
		uni->sort();
		int s = uni->getIndex();

	*/




}
