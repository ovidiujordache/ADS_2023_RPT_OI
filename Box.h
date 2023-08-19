#pragma once

#include <iostream>
using namespace std;


/*

To test template <class T> taking User defined Objects
not only promitives

*/
class Box {
private:
	int width, length,height;
	
public:
	Box() :width(0), length(0),height(0) {

	}
	Box(int w, int l,int h) :width(w), length(l) ,height(h){

	}
	void setWidth(int w) {
		this->width = w;
	}
	void setLength(int l) {
		this->length = l;
	}
	int  getWidth() {
		return this->width;
	}
	int  getLength() {
		return this->length;
	}

	//equlity for values not for Ref

	bool operator==(const  Box& box)const{
		//not modifying class.
		//very good case of lvalue AND rvalue
		//box.length is lvalue, this->length is rvalue;
		
		return (this->length == box.length && this->width==box.width);
	}
	void printBox(Box& b) {
		cout << b.getLength() << endl;

	}

	friend ostream& operator<<(ostream& stream , Box& box) {
	stream <<"Box address->: "<<&box <<"\n"
			<<"Box length->: " <<box.getLength()<<"\n"<<
				"Box width->: " <<box.getWidth()<<"\n" <<
				
				endl;
	return stream; 
	}

};