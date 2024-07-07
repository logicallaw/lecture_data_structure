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
			cout << "-1\n";
		}
		else {
			cout << head->ele << endl;
		}
	}
	void showList() const {
		if (empty()) {
			cout << "-1\n";
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
		if (empty()) {
			head = tail = newNode;
			newNode->next = NULL;
			return;
		}
		newNode->next = head;
		tail->next = newNode;
		tail = newNode;
	}
	void deleteSize(int d) {
		IntNode* curNode = head;
		while (d--) {
			curNode = curNode->next;
		}
		if (curNode == head) {
			IntNode* tempNode = head;
			head = head->next;
			delete tempNode;
			tail->next = head;
		}
		else if (curNode == tail) {
			IntNode* tempNode = head;
			while (tempNode->next != tail) {
				tempNode = tempNode->next;
			}
			IntNode* old = tail;
			tempNode->next = head;
			tail = tempNode;
			delete old;
		}
		else {
			IntNode* tempNode = head;
			while (tempNode->next != curNode) {
				tempNode = tempNode->next;
			}
			tempNode->next = curNode->next;
		}
	}
};
int main(void) {
	int n;
	cin >> n;
	while (n--) {
		//��ũ�帮��Ʈ ����
		SLinkedList s;
		int cnt = 10;
		while (cnt--) {
			int x;
			cin >> x;
			s.addBack(x);
		}
		//Delete ��ɾ�
		cnt = 3;
		while (cnt--) {
			string userInput;
			int d;
			cin >> userInput >> d;
			s.deleteSize(d);
		}
		s.showList();

	}
}