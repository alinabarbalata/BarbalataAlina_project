#pragma once
#include <iostream>
#include <string>
using namespace std;

enum EventType { Movie, Football, Concert, Other };
class Event {
	int noRowsPerZone = 0;
	string* zones = nullptr;
	int noZones = 0;
	int noSeatsPerRow = 0;
	EventType type;
	char* location = nullptr;
public:
	Event() {
		this->noRowsPerZone = 0;
		this->type = Other;
		this->zones = nullptr;
		this->noZones = 0;
		this->noSeatsPerRow = 0;
	}
	Event(EventType type, string* zones, int noZones, int noSeatsPerRow) {
		this->noRowsPerZone = 0;
		this->type = type;
		delete[] this->zones;
		this->zones = new string[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->zones[i] = zones[i];
		}
		this->noZones = noZones;
		this->noSeatsPerRow;
	}
	int getNoRowsPerZone() {
		return this->noRowsPerZone;
	}

	int getNoSeatsPerRow() {
		return this->noSeatsPerRow;
	}

	int getNoZones() {
		return this->noZones;
	}

	string* getZones() {
		string* copy = new string[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			copy[i] = this->zones[i];
		}
		return copy;
	}

	char* getLocation() {
		char* copy = new char[strlen(this->location) + 1];
		for (int i = 0; i < strlen(copy); i++) {
			copy[i] = location[i];
		}
		return copy;
	}
};