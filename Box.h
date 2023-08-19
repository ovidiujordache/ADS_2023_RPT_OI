#pragma once

#include <iostream>
using namespace std;



class Box {
private:
	int width, length;
public:
	Box() :width(0), length(0) {

	}
	Box(int w, int l) :width(w), length(l) {

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