#include <iostream>
using namespace std;

class Registration {
public:
	string name;
	int id;
	int salary;
	Registration* left;
	Registration* right;

	Registration(string name = "", int id = 0, int salary = 0, Registration* left = NULL, Registration* right = NULL)
		:name(name), id(id), salary(salary), left(left), right(right) { }

};

class RegistrationProcess {
private:
	Registration* root;
public:

	RegistrationProcess(Registration* root = NULL) { }
	Registration* NewRegistration(string name, int id, int salary) {
		root = new Registration(name, id, salary);
		return root;
	}

	Registration* RegistrationAdd(Registration* root, string name, int id, int salary) {
		if (root) {
			if (id < root->id) {
				root->left = RegistrationAdd(root->left, name, id, salary);
			}
			else {
				root->right = RegistrationAdd(root->right, name, id, salary);
			}
		}
		else {
			root = NewRegistration(name, id, salary);
		}
		return root;
	}
	void RegistrationAdd(string name, int id, int salary) {
		root = RegistrationAdd(root, name, id, salary);
	}

	void InOrder(Registration* root) {
		if (root) {
			InOrder(root->left);
			cout << " Name   : " << root->name << endl;
			cout << " Id     : " << root->id << endl;
			cout << " Salary : " << root->salary << endl << endl;
			InOrder(root->right);
		}
		else {
			cout << " There Are No Registration in The Tree Structure" << endl;
		}
	}
	void InOrder() {
		InOrder(root);
	}

	Registration* RegistrationSearch(Registration* root, int id) {
		if (root) {
			if (id < root->id) {
				return RegistrationSearch(root->left, id);
			}
			else if (id > root->id) {
				return RegistrationSearch(root->right, id);
			}
			else {
				cout << "(" << id << ") Found Inside The Tree " << endl;
				cout << " Name   : " << root->name << endl;
				cout << " Id     : " << root->id << endl;
				cout << " Salary : " << root->salary << endl;
			}
		}
		else {
			cout << "(" << id << ") Not Found The in Tree " << endl;
		}
		return root;
	}
	Registration* RegistrationSearch(int id) {
		return RegistrationSearch(root, id);
	}

	Registration* Find(Registration* root, int id) {
		if (root) {
			if (id < root->id) {
				return Find(root->left, id);
			}
			else if (id > root->id) {
				return Find(root->right, id);
			}
		}
		return root;
	}
	Registration* Find(int id) {
		return Find(root, id);
	}

	void GetMin(Registration* root) {
		while (root && root->left) {
			if (root->salary > root->left->salary) {
				root = root->left;
			}
		}
		cout << " The Smalist Salary Value                     : " << root->salary << endl;
		cout << " The Name Of The Person Get The Smalist Name  : " << root->name << endl << endl;
	}
	void GetMin() {
		GetMin(root);
	}

	void GetMax(Registration* root) {
		while (root and root->right) {
			if (root->salary < root->right->salary) {
				root = root->right;
			}
		}
		cout << " The Biggest Salary Value                      : " << root->salary << endl;
		cout << " The Name Of The Person Get The Highest Salary : " << root->name << endl;
	}
	void GetMax() {
		GetMax(root);
	}

	Registration* MaxId(Registration* root) {
		while (root && root->right) {
			root = root->right;
		}
		return root;
	}
	Registration* MaxId() {
		return MaxId(root);
	}

	Registration* MinId(Registration* root) {
		while (root and root->left) {
			root = root->left;
		}
		return root;
	}
	Registration* MinId() {
		return MinId(root);
	}

	Registration* RegistrationRemove(Registration* root, Registration* id) {
		if (root) {
			if (id->id < root->id) {
				root->left = RegistrationRemove(root->left, id);
			}
			else if (id->id > root->id) {
				root->right = RegistrationRemove(root->right, id);
			}
			else if (root == id) {
				Registration* temp = NULL;
				if (root->left && root->right) {
					temp = MinId(root->right);
					RegistrationRemove(root, temp);
					temp->left = root->left;
					temp->right = root->right;
				}
				else if (root->left) {
					temp = root->left;
				}
				else if (root->right) {
					temp = root->right;
				}
				return temp;
			}
			else {
				root->right = RegistrationRemove(root->right, id);
			}
		}
		return root;
	}
	void RegistrationRemove(Registration* id) {
		if (id) {
			root = RegistrationRemove(root, id);
			cout << "(" << id->id << ") NUmber '" << id->name << "' The Contact Has Been Deleted " << endl;
			delete id;
		}
	}
	void RegistrationRemove(int id) {
		RegistrationRemove(Find(id));
	}

};

int main() {
	int sec, id, salary; string name;
	RegistrationProcess rp;
	while (1) {
		cout << " 1-Add Register " << endl;
		cout << " 2-Delete REgister " << endl;
		cout << " 3-Find register " << endl;
		cout << " 4-Highest and lowest salary " << endl;
		cout << " 5-Write All Data " << endl;
		cout << " 6-Exit " << endl;
		cout << " Your Select : "; cin >> sec;
		switch (sec)
		{
		case 1:
		{
			system("cls");
			cout << " Enter a Name   : "; cin >> name;
			cout << " Enter a Id     : "; cin >> id;
			cout << " Enter a Salary : "; cin >> salary;
			rp.RegistrationAdd(name, id, salary);
			cout << name << " Added to The Tree " << endl;
			break;
		}
		case 2:
		{
			system("cls");
			cout << " The Number You Want To Delete : "; cin >> id;
			rp.RegistrationRemove(id);
			break;
		}
		case 3:
		{
			system("cls");
			cout << " Enter The Number Value : "; cin >> id;
			rp.RegistrationSearch(id);
			break;

		}
		case 4:
		{
			system("cls");
			rp.GetMin();
			rp.GetMax();
			break;
		}
		case 5:
		{
			system("cls");
			rp.InOrder();
			break;
		}
		case 6:
		{
			system("cls");
			return 0;
			break;
		}
		default:
		{
			system("cls");
			cout << " Yanlis Veri Girisi " << endl;
			break;
		}
		}
	}
	return 0;
}