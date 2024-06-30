#include <iostream>
using namespace std;
class SLinkedList;
class IntNode {
private:
	int ele;
	IntNode* next;
	friend class SLinkedList;
};
class SLinkedList {
private:
	IntNode* head;
	IntNode* tail;
public:
	SLinkedList() : head{ NULL }, tail{ NULL } {}
	~SLinkedList() {
		if (!empty()) {
			IntNode* temp = head;
			while (temp->next != tail) {
				IntNode* old = temp;
				temp = temp->next;
				delete old;
			}
			delete temp;
		}
	}
	bool empty() const { return (head == NULL); }
	void front() const {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << head->ele << endl;
		}
	}
	void addFront(int x) {
		IntNode* newNode = new IntNode;
		if (empty()) {
			tail = newNode;
		}
		newNode->ele = x;
		newNode->next = head;
		head = newNode;
	}
	void removeFront() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		IntNode* tempNode = head;
		head = head->next;
		cout << tempNode->ele << endl;
		delete tempNode;
		if (empty()) {
			tail = NULL;
		}
	}
	void showList() const {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		IntNode* tempNode = head;
		while (tempNode->next != tail) {
			cout << tempNode->ele << " ";
			tempNode = tempNode->next;
		}
		cout << tempNode->ele << " ";
		tempNode = tempNode->next;
		cout << tempNode->ele << endl;
	}
	void addBack(int x) {
		IntNode* newNode = new IntNode;
		newNode->ele = x;
		newNode->next = NULL;
		if (empty()) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}
};
int main(void) {
	int n;
	cin >> n;
	SLinkedList s;
	while (n--) {
		string userInput;
		cin >> userInput;
		if (userInput == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (userInput == "front") {
			s.front();
		}
		else if (userInput == "addFront") {
			int x;
			cin >> x;
			s.addFront(x);
		}
		else if (userInput == "removeFront") {
			s.removeFront();
		}
		else if (userInput == "showList") {
			s.showList();
		}
		else if (userInput == "addBack") {
			int x;
			cin >> x;
			s.addBack(x);
		}
	}

}