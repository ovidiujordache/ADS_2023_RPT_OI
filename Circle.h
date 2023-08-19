#pragma once
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
