#include <iostream>
using namespace std;

class Queuenode {
public:
	int data;
	Queuenode* next;
	Queuenode(const int& data = 0, Queuenode* next = NULL) :data(data), next(next) { }
};

class Queue {
private:
	Queuenode* tail;
	int length;

	void MakeAllEmpty() {
		while (!IsEmpty()) {
			PopFront();
		}
	}
public:
	Queuenode* root;

	Queue() :root(NULL), tail(NULL), length(0) { }

	~Queue() { MakeAllEmpty(); }

	bool IsEmpty()const { return root == NULL; }

	void PushFront(const int& value) {
		if (IsEmpty()) {
			root = new Queuenode(value);
			tail = root;
		}
		else {
			tail->next = new Queuenode(value);
			tail = tail->next;
		}
		length++;
	}

	void PopFront() {
		if (IsEmpty()) {
			throw "Error";
		}
		Queuenode* tmp = root;
		if (root == tail) {
			tail = tmp->next;
		}
		root = root->next;
		delete tmp;
		length--;
	}

	//int Size()const {
	//	Queuenode* tmp = root;
	//	return length;
	//}

	int Size()const {
		Queuenode* tmp = root;
		int counter = 0;
		while (tmp != NULL) {
			counter++;
			tmp = tmp->next;
		}
		return length;
	}

	int Front()const {
		if (IsEmpty()) {
			throw "Error ";
		}
		return root->data;
	}

	int Back()const {
		if (IsEmpty()) {
			throw "Error ";
		}
		return tail->data;
	}

	void Print()const {
		Queuenode* tmp = root;
		while (tmp != NULL) {
			cout << tmp->data << "  ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};

int main() {
	Queue q;
	int sec, value;
	while (1) {
		cout << " 1-front insertion" << endl;
		cout << " 2-front delete" << endl;
		cout << " 3-print " << endl;
		cout << " 4-is empty ?" << endl;
		cout << " 5-size" << endl;
		cout << " 6-front value" << endl;
		cout << " 7-last value" << endl;
		cout << "your select => "; cin >> sec;
		switch (sec)
		{
		case 1:
		{
			system("cls");
			cout << "Enter a value : "; cin >> value;
			q.PushFront(value);
			break;
		}
		case 2:
		{
			system("cls");
			q.PopFront();
			break;
		}
		case 3:
		{
			system("cls");
			q.Print();
			break;
		}
		case 4:
		{
			system("cls");
			cout << "IsEmpty : " + q.IsEmpty() << endl;
			break;
		}
		case 5:
		{
			system("cls");
			cout << "Front Value : " + q.Size() << endl;
			break;
		}
		case 6:
		{
			system("cls");
			cout << "Front Value : " + q.Front() << endl;
			break;
		}
		case 7:
		{
			system("cls");
			cout << "Last Value : " + q.Back() << endl;
			break;
		}
		default:
		{
			system("cls");
			cout << "Invalid data entry" << endl;
			break;
		}
		}
	}
	return 0;
}