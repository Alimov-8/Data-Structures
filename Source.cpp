#include <conio.h> // need to use getch()
#include <fstream> // file handling
#include <iostream> // input/output stream

#define Line " ------------------------------------------ " // macros

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

// function to add node to a list
void LinkedList::addNode(int val) {
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
			cout << temp->data <<endl;
			temp = temp->next;
		}
		cout << endl;
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
		cout << "Menu " << endl;
		cout << "1. Add passenger to file" << endl;
		cout << "2. Read passengers info from file" << endl;
		cout << "3. Add carriage to file" << endl;
		cout << "4. Read carriage info from file" << endl;
		cout << "5. Show linked list" << endl;
		cout << "Your choice:";

		switch (_getch()) {
		case 49: { // write to file
			cout << "\n" << Line << endl;
			ofstream out;
			out.open("Passengers", ios::binary | ios::app);
			cout << "       ADD Passenger" << endl;
			cout << "Enter First Name: "; cin >> firstName;
			cout << "Enter Last Name: "; cin >> lastName;
			cout << "Enter Ticket Type: "; cin >> ticketType;
			Psg.setData(firstName, lastName, ticketType);
			out.write((char*)&Psg, sizeof(Passenger));
			out.close();
			cout << "\nPress any keyboard to continue program " << endl << endl;
			system("pause");
		}
		break;

		case 50: { // read from file

			cout << endl;
			cout << "\n\t     File: " << endl;
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
			cout << "\nPress any keyboard to continue program " << endl << endl;
			system("pause");
		}
		break;

		case 51: { // write file
			cout << "\n" << Line << endl;
			ofstream out;
			out.open("Carriages", ios::binary | ios::app);
			cout << "       ADD Carriages" << endl;
			cout << "Enter ID: "; cin >> carriageID;
			cout << "Enter Type: "; cin >> carriageType;
			cout << "Enter Number of Places: "; cin >> carriagePlaces;
			Crg.setData(carriageID, carriageType, carriagePlaces);
			out.write((char*)&Crg, sizeof(Carriage));
			out.close();
			cout << "\nPress any keyboard to continue program " << endl << endl;
			system("pause");
		}
		break;

		case 52: { // read file
			cout << endl;
			cout << "\n\t     File: " << endl;
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
			cout << "\nPress any keyboard to continue program " << endl << endl;
			system("pause");
		}
		break;

		case 53: {
			///////////////////
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
			cout << Line << endl;
			Num = 1;
			in.close();
			//////////

			cout << "\nLinked List Business data" << endl;
			listBusiness->display();

			cout << "Linked List First data" << endl;
			listFirst->display();

			cout << "\nPress any keyboard to continue program " << endl << endl;
			system("pause");
		}
	    break;

		default: {
			cout << "\n\n Your choice is not available in Menu " << endl;
			cout << " Press any keyboard to continue program " << endl << endl;
			system("pause");
		}
    	break;

		} // end of switch
	} // end of loop

	system("pause");
	return 0;
}
