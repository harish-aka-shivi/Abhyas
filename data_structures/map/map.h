#include "Node.h"
#include <cstring>

template <typename V>
class map {
	private:
	Node<char*, V>** buckets;
	int num;
	int capacity;

	public:
	map() {
		capacity = 7;
		buckets = new Node<char*, V>*[capacity];
		for (int i = 0; i < capacity; i++) {
			buckets[i] = NULL;
		}
		num = 0;
	}

	~map() {
		for (int i = 0; i < capacity; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return num;
	}

	bool isEmpty() {
		return size() == 0;
	}

	int getBucketIndex(char* key) {
		int sum = 0;
		int currentPower = 1;
		for (int i = 0; key[i] != '\0'; i++) {
			sum = sum + ((key[i] * currentPower) % capacity);
			sum = sum % capacity;
			currentPower = (currentPower * 37) % capacity;
		}
		return sum % capacity;
	}

	void set(char* key, V value) {
		int b = getBucketIndex(key);
		Node<char*, V>* currentHead = buckets[b];
		Node<char*, V>* current = currentHead;
		while (current != NULL) {
			if (strcmp(current->key, key) == 0) {
				current->value = value;
				return;
			}
			current = current->next;
		}

		// delete these?
		char * temp = new char[strlen(key) + 1];
		strcpy(temp, key);
		Node<char*, V>* node = new Node<char*, V>(temp, value);
		node->next = currentHead;
		buckets[b] = node;
	}

	V get(char* key) {
		int b = getBucketIndex(key);
		Node<char*, V>* currentHead = buckets[b];
		Node<char*, V>* current = currentHead;
		while (current != NULL) {
			if (strcmp(current->key, key) == 0) {
				return current->value;
			}
			current = current->next;
		}
		return 0;
	}

	V remove(char* key) {
		int b = getBucketIndex(key);
		Node<char*, V>* currentHead = buckets[b];
		Node<char*, V>* current = currentHead;
		Node<char*, V>* prev = NULL;

		while (current != NULL) {
			if (strcmp(current->key, key) == 0) {
				if (prev == NULL) {
					buckets[b] = current->next;
				} else {
					prev->next = current->next;
				}
				V val = current->value;
				current->next = NULL;
				delete current;
				return val;
			}
			prev = current;
			current = current->next;
		}
		return 0;
	}

};
