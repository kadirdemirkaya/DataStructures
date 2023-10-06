#include <iostream>
using namespace std;

class Student {
public:
	int number;
	string name;
	double ort;
	string state;
	Student* next;

	Student() {
		next = NULL;
	}

	Student(int number, string name, int ort) {
		this->name = name;
		this->number = number;
		this->ort = ort;
		this->state = ort < 50 ? "failed" : "successfully";
		next = NULL;
	}
};

class table {
public:
	Student* dizi;
	int size;
	table(int size) {
		this->size = size;
		dizi = new Student[size];
	}

	int CreateIndex(int number) {
		return number % size;
	}

	void Add(int number, string name, int ort) {
		int index = CreateIndex(number);
		Student* ogr = new Student(number, name, ort);
		Student* temp = (dizi + index);
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = ogr;
		cout << name << " registration received " << endl;
	}

	void Remove(int number) {
		int index = CreateIndex(number);
		Student* temp = (dizi + index);
		Student* tmp = (dizi + index);
		bool sonuc = false;

		if (temp->next == NULL) {
			sonuc = true;
			cout << number << " there is no person number " << endl;
		}
		else if (temp->next->next == NULL and temp->next->number == number) {
			sonuc = true;
			temp->next = NULL;
			cout << number << " The person with the number has been deleted " << endl;
		}
		else {
			while (temp->next != NULL) {
				tmp = temp;
				temp = temp->next;
				if (temp->number == number) {
					sonuc = true;
					tmp->next = temp->next;
					cout << number << " The person with the number has been deleted " << endl;
				}
			}
		}
		if (sonuc == false) {
			cout << number << " Contact number information could not be found." << endl;
		}
	}

	void Write() const {
		cout << " REGISTER INFOS " << endl;
		for (int i = 0; i < size; i++) {
			Student* temp = (dizi + i);
			while (temp->next != NULL) {
				cout << " number   : " << temp->next->number << endl;
				cout << " name     : " << temp->next->name << endl;
				cout << " average  : " << temp->next->ort << endl;
				cout << " state    : " << temp->next->state << endl;
				cout << endl;
				temp = temp->next;
			}
		}
	}

	void Find(int number) {
		bool sonuc = false;
		int index = CreateIndex(number);
		Student* temp = (dizi + index);
		while (temp->next != NULL) {
			if (temp->next->number == number) {
				sonuc = true;
				cout << number << " person number was found and informations " << endl;
				cout << " number   : " << temp->next->number << endl;
				cout << " name     : " << temp->next->name << endl;
				cout << " average  : " << temp->next->ort << endl;
				cout << " state    : " << temp->next->state << endl;
				cout << endl;
			}
			temp = temp->next;
		}
		if (sonuc == false) {
			cout << number << " person not found to register list " << endl;
		}
	}
};

int main() {
	int sec, number, ort; string name;
	table ht(5);
	while (1) {
		cout << " 1-Student Add " << endl;
		cout << " 2-Student Remove " << endl;
		cout << " 3-Student write " << endl;
		cout << " 4-Student find " << endl;
		cout << " 0-Exit " << endl;
		cout << " Your select : "; cin >> sec;
		switch (sec)
		{
		case 1:
		{
			system("cls");
			cout << " name of the person to be Added    = "; cin >> name;
			cout << " number of the person to be Added  = "; cin >> number;
			cout << " average of the person to be Added = "; cin >> ort;
			ht.Add(number, name, ort);
			break;
		}
		case 2:
		{
			system("cls");
			cout << " name of the person to be deleted  = "; cin >> number;
			ht.Remove(number);
			break;
		}
		case 3:
		{
			system("cls");
			ht.Write();
			break;
		}
		case 4:
		{
			system("cls");
			cout << " number of the person to be find  = "; cin >> number;
			ht.Find(number);
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		default:
		{
			system("cls");
			cout << " entry invalid data " << endl;
			break;
		}
		}
	}
	return 0;
}