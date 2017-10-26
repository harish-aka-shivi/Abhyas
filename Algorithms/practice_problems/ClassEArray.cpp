#include <iostream>
using namespace std;

template <typename T>
class EArray {
	T* storage;
	int capacity;
	int nextIndex;

	public:
	EArray() {
		nextIndex = 0;
		capacity = 5;
		storage = new T[capacity];
	}

	int size() {
		return nextIndex;
	}

	private:
	void expand() {
		T* temp = storage;
		capacity = capacity * 2;
		storage = new T[capacity];
		for (int i = 0; i < capacity/2; i++) {
			storage[i] = temp[i];
		}
		delete [] temp;
	}
	
	public:
	void add(T element) {
		if (nextIndex == capacity) {
			expand();
		}
		storage[nextIndex] = element;
		nextIndex++;
	}

	void set(int position, T element) {
		if (position > nextIndex) {
			return;
		}
		if (position < nextIndex) {
			storage[position] = element;
		} else {
			add(element);
		}
	}

	T get(int position) {
		if (position >= nextIndex) {
			return -1;
		}
		return storage[position];
	}

	bool isEmpty() {
		return size() == 0;
	}

	T remove(int position) {
		if (position >= nextIndex) {
			return -1;
		}

		T toBeRemoved = storage[position];
		for (int i = position; i < nextIndex - 1; i++) {
			storage[i] = storage[i + 1];
		}
		nextIndex--;
		return toBeRemoved;
	}

	T removeLast() {
		return remove(nextIndex - 1);
	}

	~EArray() {
		delete [] storage;
	}

};







