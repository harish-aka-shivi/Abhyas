template <typename K, typename V>
class Node {
	public:
	K key;
	V value;
	Node* next;
	
	Node(K key, V value) {
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};
