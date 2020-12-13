#include <conio.h> //getch
#include <fstream> // File handling
#include <iostream> // Input/Output stream
#define Line " ------------------------------------------ " //Macros
using namespace std;
////////////////////////////////////////////


class Carriage
{
protected:
	//identifires
	string carriageType, carriageID, carriagePlaces;
public:
	//setting data (name and tell)
	void setData(string carriageType, string carriageID, string carriagePlaces) {
		this->carriageType = carriageType;
		this->carriageID = carriageID;
		this->carriagePlaces = carriagePlaces;
	}
	//Get name and tell
	string getCarriageType() { return carriageType; }
	string getCarriageID() { return carriageID; }
	string getCarriagePlace() { return carriagePlaces;  }

	//Displaying name and tell
	void Display() {
		cout << Line << endl;
		cout << "  Carriage: " << carriageID << " " << carriageType << " " << carriagePlaces << endl;
	}
};


class Passenger
{
protected:
	//identifires
	string firstName, lastName, ticketType;
public:
	//setting data 
	void setData(string firstName, string lastName, string ticketType) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->ticketType = ticketType;
	}
	//Get name and tell
	string getFirstName() { return firstName; }
	string getFamilyName() { return lastName; }
	string getTicketType() { return ticketType; }

	//Displaying name and tell
	void Display() {
		cout << Line << endl;
		cout << "  Passenger: " << firstName <<" "<< lastName << " " << ticketType<< endl;
	}
};


// Linked List 
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
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}




////////////////////////////////////////////
int main() {
	//Identifires
	string firstName, lastName, ticketType, carriageType, carriageID, carriagePlaces;
	int Num = 1;
	//Objects
	Passenger Psg;
	Carriage Crg;

	//Start Program
	for (int i = 0; i < 1000; i++) { // loop for Menu
		system("cls");
		cout << "\n\t Menu " << endl;
		cout << "   1.Add Passenger -> File" << endl;
		cout << "   2.Read Passengers Info  -> File" << endl;
		cout << "   3.Add Carriage -> File" << endl;
		cout << "   4.Read Carriage Info  -> File" << endl;
		cout << "   5" << endl;
		cout << "    Your choice:";
		switch (_getch())
		{
		case 49: { // Write File
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
			cout << "\n Press any keyboard to continue program " << endl << endl;
			system("pause");
		}
			   break;
		case 50: { // Read File
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
			cout << "\n Press any keyboard to continue program " << endl << endl;
			system("pause");
		}
			   break;
		case 51: { // Write File
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
			cout << "\n Press any keyboard to continue program " << endl << endl;
			system("pause");
		}
			   break;
		case 52: { // Read File
			cout << endl;
			cout << "\n\t     File: " << endl;
			ifstream in;
			in.open("Carriages", ios::binary);
			while (in.read((char*)&Crg, sizeof(Carriage))) {
				cout << Num << "." << endl;
				Crg.Display();
				Num++;
			}
			cout << Line << endl;
			Num = 1;
			in.close();
			cout << "\n Press any keyboard to continue program " << endl << endl;
			system("pause");
		}
			   break;

		case 53: {
			LinkedList* list = new LinkedList();
			list->addNode(100);
			list->addNode(200);
			list->addNode(300);
			list->addNode(400);
			list->addNode(500);
			cout << "Linked List data" << endl;
			list->display();
			cout << "Reversed Linked List data" << endl;
			list->display();
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
