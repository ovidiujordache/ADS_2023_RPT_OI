#pragma once

/*

To test template <class T> taking User defined Objects 
not only promitives

*/
class Circle {
private:
	int* radius;

public:
	void setRadius(  int& radius) {
		this->radius = &radius;
	}


	int& getRadius() {
		
		return *this->radius;
	}


};
