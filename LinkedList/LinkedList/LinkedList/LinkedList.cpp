#include<iostream>
using namespace std;

class node {
public:
	node(const int& data = 0, node* next = NULL) :data(data), next(next) { }
	int data;
	node* next;
};

class list {
private:
	node* root;
	node* tail;
	int length;

	node* findprevious(node* pos) {
		node* tmp = root;
		node* stop = end();
		while (tmp != stop && tmp->next != pos) {
			tmp = tmp->next;
		}
		return tmp;
	}
public:
	list() {
		root = new node();
		tail = root;
		tail->next = new node();
		length = 0;
	}
	node* begin()const { return root->next; }
	node* end()const { return tail->next; }

	bool isempty()const { return begin() == end(); }

	int size()const {
		return length;
	}

	void pushback(const int& value) {
		insert(end(), value);
	}

	void pushfront(const int& value) {
		insert(begin(), value);
	}

	void print()const {
		system("cls");
		node* tmp = begin();
		while (tmp != end()) {
			cout << tmp->data << "\t";
			tmp = tmp->next;
		}
		cout << "\n";
	}

	void insert(node* pos, const int value) {
		if (pos == end()) {
			tail->next = new node(value, end());
			tail = tail->next;
		}
		else {
			node* tmp = findprevious(pos);
			if (tmp == end()) {
				throw "Error";
			}
			tmp->next = new node(value, tmp->next);
		}
		length++;
	}

	void insert(node* pos, int n, const int& value) {
		for (int i = 0; i < n; i++) {
			insert(pos, value);
		}
	}

	void insert(node* pos, node* first, node* last) {
		while (first != last) {
			insert(pos, first->data);
			first = first->next;
		}
	}

	int front()const {
		if (isempty()) {
			throw" Error";
		}
		return begin()->data;
	}

	int back()const {
		if (isempty()) {
			throw "Error ";
		}
		return tail->data;
	}

	void remove(node* pos) {
		if (isempty()) {
			throw "";
		}
		node* prev = root;
		if (pos == end() || pos == tail) {
			pos = tail;
			prev = findprevious(pos);
			prev->next = pos->next;
			tail = prev;
		}
		else {
			prev = findprevious(pos);
			if (prev == end()) {
				throw "Error";
			}
			prev->next = pos->next;
		}
		delete pos;
		length--;
	}

	void remove(node* first, node* last) {
		node* tmp;
		while (first != last) {
			tmp = first;
			first = first->next;
			remove(tmp);
		}
	}

	void clear() {
		remove(begin(), end());
	}

	void popfront() {
		try { remove(begin()); }
		catch (const char* ex) { throw "Error"; }
	}

	void popback() {
		try { remove(end()); }
		catch (const char* ex) { throw "Error"; }
	}

	node* find(const int& value)const {
		node* tmp = begin();
		node* stop = end();
		while (tmp != stop && tmp->data != value) {
			tmp = tmp->next;
		}
		return tmp;
	}
};

int main() {
	list l; int value, secim;
	while (1) {
		cout << "1.size " << endl;
		cout << "2.last insertion " << endl;
		cout << "3.front insertion " << endl;
		cout << "4.Front " << endl;
		cout << "5.Back " << endl;
		cout << "6.front delete " << endl;
		cout << "7.last delete " << endl;
		cout << "8.find  " << endl;
		cout << "9.all delete " << endl;
		cout << "10.exit " << endl;
		cout << "your select => "; cin >> secim;
		switch (secim)
		{
		case 1:
		{
			cout << " Size : " << l.size() << endl;
			break;
		}
		case 2:
		{
			cout << " Enter value : "; cin >> value;
			l.pushback(value); l.print();
			break;
		}
		case 3:
		{
			cout << " Enter value : "; cin >> value;
			l.pushfront(value); l.print();
			break;
		}
		case 4:
		{
			cout << " Front : " << l.front() << endl;
			break;
		}
		case 5:
		{
			cout << " Back : " << l.back() << endl;
			break;
		}
		case 6:
		{
			l.popfront(); l.print();
			break;
		}
		case 7:
		{
			l.popback(); l.print();
			break;
		}
		case 8:
		{
			cout << "enter the value to search  : "; cin >> value;
			node* aranan = l.find(value);
			if (aranan == l.end()) {
				cout << "(" << value << ") not founnd on the list " << endl;
			}
			else {
				cout << "(" << value << ") found on the list " << endl;
			}
			break;
		}
		case 9:
		{
			cout << " all data deleted " << endl; l.clear(); l.print();
			cout << " size = " << l.size() << endl;
			break;
		}
		case 10:
		{
			return 0;
			break;
		}
		default:
		{
			system("cls");
			cout << "incorrect data entry" << endl;
			break;
		}
		}
	}
	return 0;
}