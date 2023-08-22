#pragma once

#include <iostream>
#include <string>
using namespace std;


/*

To test template <class T> taking User defined Objects
not only promitives

*/
class Box {
private:
	int width, length,height;
	int volume;
	
public:
	Box() :width(0), length(0),height(0) {

	}
	Box(int w, int l,int h) :width(w), length(l) ,height(h){
		volume = width * height * length;
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


	int operator<(const Box& box)const {
		if (this->volume < box.volume)
		{
			return -1;
		}
		else if (this->volume == box.volume) {
			return 0;
		}
		else return 1;
	}

	 string to_string()
	{
		 int vol = this->volume;
		 return  std::to_string(vol);
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