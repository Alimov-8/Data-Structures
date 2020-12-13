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
struct Node {
	int data;
	struct Node* next;
};

struct Node* head = NULL;

void insert(int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}
void display() {
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
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
			system("cls");
			insert(3);
			insert(1);
			insert(7);
			insert(2);
			insert(9);
			cout << "/n The linked list is: ";
			display();
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
