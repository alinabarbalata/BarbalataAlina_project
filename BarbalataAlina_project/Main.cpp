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
	
	PersonInfo person1("Andreea");
	person1.setDateBirth(6, 10, 2003);
	cout << endl << person1.getName() << " birthday:" << person1.getDayBirth() << "." << person1.getMonthBirth() << "." << person1.getYearBirth();
	cout << endl<<"Id: "<<person1.getId();

	char namePerson[] = "Andreea";

	int seats[] = { 100, 100, 100 };
	float prices[] = { 200,250,300 };
	Event HorrorMovie(zones, 3, seats, prices);
	HorrorMovie.setType(Movie);

}