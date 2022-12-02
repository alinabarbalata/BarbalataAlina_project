#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

int main() {
	Event location1;
	string zones[] = { "A","B","C" };
	location1.setZonesAndNoZones(zones, 3);
	int* vector = nullptr;
	cout << endl << "The number of rows is: " << location1.getNoRowsPerZone() << endl;
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

}