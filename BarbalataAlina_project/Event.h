#pragma once
#define _CRT_SECURE_NO_WARNINGS//to fix!!!!!!
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
	const static int NO_MAX_SEATS = 300;
	const static int NO_MIN_ROWS = 3;
	const static int NO_MIN_CHAR_LOCATION = 3;
	const static int NO_MAX_CHAR = 10;
	const static int NO_MAX_ZONES = 5;
	const static int NO_MIN_ZONES = 1;
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

	void setType(EventType type) {
		this->type = type;
	}

	void setNoRowsPerZone(int noRowsPerZone) {
		this->noRowsPerZone = noRowsPerZone;
	}

	void setNoSeatsPerRow(int noSeatsPerRow) {
		this->noSeatsPerRow = noSeatsPerRow;
	}

	void setLocation(const char* location) {
		if (strlen(location) < Event::NO_MIN_CHAR_LOCATION || strlen(location) > Event::NO_MAX_CHAR) {
			throw "Invalid number of characters for location!";
		}
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		//strcpy(this->location, location);//!!!!!!!!!!!!!!
	}

	void setZonesAndNoZones(const string* zones, const int noZones) {
		if (noZones<Event::NO_MIN_ZONES || noZones>Event::NO_MAX_ZONES)
			throw "Invalid number of zones!";
		this->noZones = noZones;
		for (int i = 0; i < this->noZones; i++) {
			if (lengthString(zones[i]) > Event::NO_MAX_CHAR) {
				throw "Invalid length of characters for zone " + i;
			}
		}
		delete[] this->zones;
		this->zones = new string[this->noZones + 1];
		for (int i = 0; i < this->noZones; i++) {
			this->zones[i] = zones[i];
		}
	}

	static int lengthString(string word) {
		int count = 0;
		for (int i = 0; word[i] != '\0'; i++) {
			count++;
		}
		return count;
	}
};