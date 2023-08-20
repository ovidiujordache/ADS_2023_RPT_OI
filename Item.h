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
	}
	~Item() {

	}
	T getData() const {
		return this->data;
	}

	void setNext(Item<T>* pNext) {
		this->pNext = pNext;
	}
	/*
	bool setNext(Item<T>* pNext) {
		if (pNext == nullptr)
			return false;
		this->pNext = pNext;
		return true;
	}
	*/
	Item* getNext() const { return this->pNext; }
	void setIndex(int i) {
		this->index = i;
	}
	int getIndex() {
		return this->index;
	}

};
