#pragma once

template <class T>
class Item {
private:


	T data;

	Item* pNext;
	//keeping track;
	int index;

public:
	Item(T data) {
		this->data = data;
		this->pNext = nullptr;
		index = 0;
	}
	~Item() {

	}
	T getData() const {
	
			return this->data;
	
	}
	void setData(T data)
	{
		this->data = data;
	}

	void setNext(Item<T>* pNext) {
		this->pNext = pNext;
	}

	Item* getNext() const {
		return this->pNext; }
	void setIndex(int i) {
		this->index = i;
	}
	int getIndex() {
	
			return this->index;
	
	}

};
