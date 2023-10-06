#include <iostream>
using namespace std;

class Stacknode {
public:
	int data;
	Stacknode* next;
	Stacknode(const int& data = 0, Stacknode* next = NULL) :data(data), next(next) { }
};

class Stack {
	Stacknode* root;
	int length;

	void MakeAllEmpty() {
		while (!IsEmpty()) {
			PopBack();
		}
	}
public:
	Stack() :root(NULL), length(0) {  }

	Stacknode* begin()const { return root; }
	Stacknode* end()const { return NULL; }

	~Stack() {
		MakeAllEmpty();
	}

	bool IsEmpty()const {
		return begin() == end();
	}

	void PushBack(const int& value) {					
		Stacknode* tmp = new Stacknode(value, root);
		root = tmp;									
		length++;
	}

	void PopBack() {
		if (IsEmpty()) {
			throw "Eror";
		}
		Stacknode* tmp = root;
		root = tmp->next;
		delete tmp;
		length--;
	}

	int Top()const {
		if (IsEmpty()) {
			throw "Error";
		}
		return begin()->data;
	}

	int Size() {
		return length;
	}

	void Print()const {
		Stacknode* tmp = begin();
		while (tmp != end()) {
			cout << tmp->data << "  ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};

int main() 
{
	Stack s;
	int sec, value;
	while (1) {
		cout << " 1-front insertion" << endl;
		cout << " 2-front delete" << endl;
		cout << " 3-print " << endl;
		cout << " 4-is empty ?" << endl;
		cout << " 5-size" << endl;
		cout << " 6-last value" << endl;
		cout << "your select => "; cin >> sec;
		switch (sec)
		{
		case 1:
		{
			system("cls");
			cout << "Enter a value : "; cin >> value;
			s.PushBack(value);
			break;
		}
		case 2:
		{
			system("cls");
			s.PopBack();
			break;
		}
		case 3:
		{
			system("cls");
			s.Print();
			break;
		}
		case 4:
		{
			system("cls");
			cout << "IsEmpty : " + s.IsEmpty() << endl;
			break;
		}
		case 5:
		{
			system("cls");
			cout << "Front Value : " + s.Size() << endl;
			break;
		}
		case 6:
		{
			system("cls");
			cout << "Last Value : " + s.Top() << endl;
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