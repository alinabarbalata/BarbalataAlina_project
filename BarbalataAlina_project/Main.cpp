#include <iostream>
#include <string>
#include "Event.h"
#include "EventTicket.h"
#include "PersonInfo.h"
using namespace std;

int main() {
	Event location1;
	string zones[] = { "A","B","C" };
	location1.setZonesAndNoZones(zones, 3);
	int* vector = nullptr;
	//does not work
	/*for(int i=0;i<location1.getNoZones();i++){
		cout << endl << "The number of seats for each zone is: " << location1.getNoSeatsPerZone()[i] << endl;
	}*/
	for (int i = 0; i < location1.getNoZones(); i++) {
		cout << endl << Event::lengthString(location1.getZones()[i]);
	}
	cout << endl;
	for (int i = 0; i < location1.getNoZones(); i++) {
		cout << location1.getZones()[i] << " ";
	}
	cout << endl;
	zones[2] = "VIP";
	location1.setZonesAndNoZones(zones, 3);
	for (int i = 0; i < location1.getNoZones(); i++) {
		cout << location1.getZones()[i] << " ";
	}
	for (int i = 0; i < location1.getNoZones(); i++) {
		cout << endl << Event::lengthString(location1.getZones()[i]);
	}

	cout << endl<<"**********************************";
	//char dateBirth[] = "02.03.2004";
	//char phoneNo[] = "0724440506";
	//PersonInfo person1("Andreea");//works
	//char dateBirth[] = "02.03.20045";
	//PersonInfo person1("Andreea", dateBirth, "0724440506");//throws error because the char length is larger than it's supposed to be
	//char dateBirth[] = "0.203.2004";
	//PersonInfo person1("Andreea", dateBirth, "0724440506");//throws error because the '.' character is on the wrong index
	//char dateBirth[] = "0A.03.2004";
	//PersonInfo person1("Andreea", dateBirth, "0724440506");//throws error because there is a char who is a letter
	//char dateBirth[] = "02.03.2004";
	//char phoneNo[] = "0724440506";
	//PersonInfo person1("Andreea", dateBirth, phoneNo);//works
	PersonInfo person1("Andreea");
	person1.setDateBirth(6, 10, 2003);
	cout << endl << person1.getName() << " birthday:" << person1.getDayBirth() << "." << person1.getMonthBirth() << "." << person1.getYearBirth();
}