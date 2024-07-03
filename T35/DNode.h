#pragma once
template <typename T>

class DNode {
public:
	T info;
	DNode* prev;
	DNode* next;

	DNode(T a) { info = a; next = prev = nullptr; }
};

template <typename U>
class DList {
	DNode<U>* head;
	DNode<U>* current;
public:
	DList() { head = current = nullptr; }
	~DList() {
		while (head != nullptr) {
			DNode<U>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push_back(U value) {
		DNode<U>* newNode = new DNode<U>(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			DNode<U>* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}

	void show() {
		DNode<U>* temp = head;
		while (temp != nullptr) {
			std::cout << temp->info << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	DNode<U>* search(U value) {
		DNode<U>* temp = head;
		while (temp != nullptr) {
			if (temp->info == value) {
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}

	void push_front(U value) {
		DNode<U>* newNode = new DNode<U>(value);
		newNode->next = head;
		if (head != nullptr) {
			head->prev = newNode;
		}
		head = newNode;
	}

	void insertBefore(U before, U value) {
		DNode<U>* beforeNode = search(before);
		if (beforeNode != nullptr) {
			DNode<U>* newNode = new DNode<U>(value);
			newNode->prev = beforeNode->prev;
			newNode->next = beforeNode;
			if (beforeNode->prev != nullptr) {
				beforeNode->prev->next = newNode;
			}
			else {
				head = newNode;
			}
			beforeNode->prev = newNode;
		}
	}

	void insertAfter(U after, U value) {
		DNode<U>* afterNode = search(after);
		if (afterNode != nullptr) {
			DNode<U>* newNode = new DNode<U>(value);
			newNode->next = afterNode->next;
			newNode->prev = afterNode;
			if (afterNode->next != nullptr) {
				afterNode->next->prev = newNode;
			}
			afterNode->next = newNode;
		}
	}

	void erase(U value) {
		DNode<U>* deleteNode = search(value);
		if (deleteNode != nullptr) {
			if (deleteNode->prev != nullptr) {
				deleteNode->prev->next = deleteNode->next;
			}
			else {
				head = deleteNode->next;
			}
			if (deleteNode->next != nullptr) {
				deleteNode->next->prev = deleteNode->prev;
			}
			delete deleteNode;
		}
	}
};
