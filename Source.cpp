#include <conio.h> // need to use getch()
#include <fstream> // file handling
#include <iostream> // input/output handling

#define Line "------------------------------------------ " // macros

using namespace std;

class Carriage {
protected:
	// identifires
	string carriageType, carriageID, carriagePlaces;
public:
	// setting data (name and tell)
	void setData(string carriageType, string carriageID, string carriagePlaces) {
		this->carriageType = carriageType;
		this->carriageID = carriageID;
		this->carriagePlaces = carriagePlaces;
	}

	// get name and tell
	string getCarriageType() { return carriageType; }
	string getCarriageID() { return carriageID; }
	string getCarriagePlace() { return carriagePlaces; }

	// displaying name and tell
	void Display() {
		cout << Line << endl;
		cout << "  Carriage: " << carriageID << " " << carriageType << " " << carriagePlaces << endl;
	}
};


class Passenger {
protected:
	// identifires
	string firstName, lastName, ticketType;
public:
	// setting data 
	void setData(string firstName, string lastName, string ticketType) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->ticketType = ticketType;
	}

	// get name and tell
	string getFirstName() { return firstName; }
	string getFamilyName() { return lastName; }
	string getTicketType() { return ticketType; }

	// displaying name and tell
	void Display() {
		cout << Line << endl;
		cout << "  Passenger: " << firstName << " " << lastName << " " << ticketType << endl;
	}
};

// linked list
class Node {
public:
	int data;
	Node* next;
};

class LinkedList {
public:
	LinkedList() { // constructor
		head = NULL;
	}

	~LinkedList() {}; // destructor
	void addNode(int val);
	void display();

private:
	Node* head;
};


void LinkedList::addNode(int val) {
	// function to add node to a list
	Node* newnode = new Node();
	newnode->data = val;
	newnode->next = NULL;
	if (head == NULL) {
		head = newnode;
	}
	else {
		Node* temp = head; // head is not NULL
		while (temp->next != NULL) {
			temp = temp->next; // go to end of list
		}
		temp->next = newnode; // linking to newnode
	}
}

void LinkedList::display() {
	if (head == NULL) {
		cout << "List is empty!" << endl;
	}
	else {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << endl;
	}
}

class Stack {
	Node* front;  // points to the head of list
public:
	Stack() {
		front = NULL;
	}
	// push method to add data element
	void push(int);
	// pop method to remove data element
	void pop();
	// top method to return top data element
	int top();
};

// Inserting Data in Stack (Linked List)
void Stack::push(int d) {
	// creating a new node
	Node* temp;
	temp = new Node();
	// setting data to it
	temp->data = d;
	// add the node in front of list
	if (front == NULL)
		temp->next = NULL;
	else
		temp->next = front;
	front = temp;
}

// Removing Element from Stack (Linked List)
void Stack::pop() {
	// if empty
	if (front == NULL)
		cout << "UNDERFLOW\n";

	// delete the first element
	else {
		Node* temp = front;
		front = front->next;
		delete(temp);
	}
}

int main() {
	// identifires
	string firstName, lastName, ticketType, carriageType, carriageID, carriagePlaces;
	int Num = 1;
	int numOfBusiness = 0, numOfFirst = 0, businessSpace = 0, firstSpace = 0;

	// objects
	Passenger Psg;
	Carriage Crg;

	// start
	for (int i = 0; i < 1000; i++) { // loop for Menu
		system("cls");

		cout << "\t*** MENU *** " << endl;
		cout << "1. Add passenger to file" << endl;
		cout << "2. Read passengers info from file" << endl;
		cout << "3. Add carriage to file" << endl;
		cout << "4. Read carriage info from file" << endl;
		cout << "5. Show linked list" << endl;
		cout << "Your choice:";

		switch (_getch()) {
		case 49: { // write to file a passenger
			cout << "\n" << Line << endl;
			ofstream out;
			out.open("Passengers", ios::binary | ios::app);

			cout << "\t*** Add Passenger ***" << endl;
			cout << "Enter first name: "; cin >> firstName;
			cout << "Enter last name: "; cin >> lastName;
			cout << "Enter ticket type (Business/First): "; cin >> ticketType;

			Psg.setData(firstName, lastName, ticketType);
			out.write((char*)&Psg, sizeof(Passenger));
			out.close();

			cout << endl;
			system("pause");
		}
			   break;

		case 50: { // read from file passengers
			cout << "\n\t*** Passenger File *** " << endl;

			ifstream in;
			in.open("Passengers", ios::binary);
			while (in.read((char*)&Psg, sizeof(Passenger))) {
				cout << Num << "." << endl;
				Psg.Display();
				Num++;
			}
			cout << Line << endl;
			Num = 1;
			in.close();

			cout << endl;
			system("pause");
		}
			   break;

		case 51: { // write to file carriages
			cout << "\n" << Line << endl;
			ofstream out;
			out.open("Carriages", ios::binary | ios::app);

			cout << "\t*** Add Carriages ***" << endl;
			cout << "Enter ID: "; cin >> carriageID;
			cout << "Enter type (Business/First): "; cin >> carriageType;
			cout << "Enter number of seets: "; cin >> carriagePlaces;

			Crg.setData(carriageID, carriageType, carriagePlaces);
			out.write((char*)&Crg, sizeof(Carriage));
			out.close();

			cout << endl;
			system("pause");
		}
			   break;

		case 52: { // read from file carriages
			cout << endl;
			cout << "\n\t*** Carriage File ***" << endl;
			ifstream in;
			in.open("Carriages", ios::binary);
			while (in.read((char*)&Crg, sizeof(Carriage))) {
				cout << Num << "." << endl;
				Crg.Display();
				Num++;
				if (Crg.getCarriageType() == "Business")
					numOfBusiness++;
				else
					numOfFirst++;
			}
			cout << Line << endl;
			Num = 1;
			in.close();

			cout << endl;
			system("pause");
		}
			   break;

		case 53: {
			///////////
			LinkedList* listBusiness = new LinkedList();
			LinkedList* listFirst = new LinkedList();

			ifstream in;
			in.open("Passengers", ios::binary);
			while (in.read((char*)&Psg, sizeof(Passenger))) {
				if (Psg.getTicketType() == "Business")
					listBusiness->addNode(Num);
				else
					listFirst->addNode(Num);
				Num++;
			}
			cout << endl << Line << endl;
			Num = 1;
			in.close();
			//////////

			cout << "Linked List - 'Business class'" << endl;
			listBusiness->display();

			cout << "Linked List - 'First class'" << endl;
			listFirst->display();

			system("pause");
		}
			   break;

		default: {
			cout << "\n\nYour choice is not available in the menu!" << endl;
			cout << endl;
			system("pause");
		}
			   break;

		} // end of switch
	} // end of loop
	system("pause");
	return 0;
}
