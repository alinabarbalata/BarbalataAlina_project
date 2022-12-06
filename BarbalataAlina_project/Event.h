#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;

enum EventType { Movie, Football, Concert, Other };
class Event {
	int* noSeatsPerZone = nullptr;
	string* zones = nullptr;
	int noZones = 0;
	EventType type;
	char* location = nullptr;
	float* pricePerZone = nullptr;
public:
	const static int NO_MAX_SEATS = 300;
	const static int NO_MIN_ROWS = 3;
	const static int NO_MIN_CHAR_LOCATION = 3;
	const static int NO_MAX_CHAR = 100;
	const static int NO_MAX_ZONES = 5;
	const static int NO_MIN_ZONES = 1;
private:
	static int NO_EVENTS_CREATED;
public:
	Event() {
		this->noSeatsPerZone = nullptr;
		this->type = Other;
		this->zones = nullptr;
		this->noZones = 0;
		this->pricePerZone = nullptr;
		Event::NO_EVENTS_CREATED++;
	}
	Event(string* zones, int noZones, int* noSeatsPerZone, float* pricePerZone) {
		this->noZones = noZones;
		this->noSeatsPerZone = new int[this->noZones];
		this->zones = new string[this->noZones];
		this->pricePerZone = new float[noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->noSeatsPerZone[i] = noSeatsPerZone[i];
			this->zones[i] = zones[i];
			this->pricePerZone[i] = pricePerZone[i];
		}
		Event::NO_EVENTS_CREATED++;
	}

	int* getNoSeatsPerZone() {
		int* copy = new int[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			copy[i] = this->noSeatsPerZone[i];
		}
		return copy;
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
		char* copy = new char[strlen(this->location)+1];
		for (int i = 0; i < strlen(copy); i++) {
			copy[i] = location[i];
		}
		return copy;
	}

	float* getPricePerZone() {
		float* copy = new float[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			copy[i] = pricePerZone[i];
		}
		return copy;
	}

	string getType() {
		if (this->type == Movie)
			return "Movie";
		else if (this->type == Football)
			return "Football";
		else if (this->type == Concert)
			return "Concert";
		else
			return "Other";
	}

	void setType(EventType type) {
		this->type = type;
	}

	void setNoSeatsPerZone(int* noSeatsPerZone) {
		delete[] this->noSeatsPerZone;
		this->noSeatsPerZone = new int[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->noSeatsPerZone[i] = noSeatsPerZone[i];
		}
	}

	void setLocation(const char* location) {
		if (strlen(location) < Event::NO_MIN_CHAR_LOCATION || strlen(location) > Event::NO_MAX_CHAR) {
			throw "Invalid number of characters for location!";
		}
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		strcpy(this->location, location);
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
		this->zones = new string[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->zones[i] = zones[i];
		}
	}

	void setPricePerZone(float* pricePerZone) {
		delete[] this->pricePerZone;

		for (int i = 0; i < this->noZones; i++) {
			this->pricePerZone[i] = pricePerZone[i];
		}
	}

	static int lengthString(string word) {
		int count = 0;
		for (int i = 0; word[i] != '\0'; i++) {
			count++;
		}
		return count;
	}

	int getTotalNoSeats() {
		int S = 0;
		for (int i = 0; i < this->noZones; i++) {
			S =S+ this->noSeatsPerZone[i];
		}
		return S;
	}

	//COPY CONSTRUCTOR
	Event(const Event& object) {
		this->noZones = object.noZones;
		delete[] this->noSeatsPerZone, delete[] this->zones, delete[] pricePerZone;
		this->noSeatsPerZone = new int[this->noZones];
		this->zones = new string[this->noZones];
		this->pricePerZone = new float[noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->noSeatsPerZone[i] = object.noSeatsPerZone[i];
			this->zones[i] = object.zones[i];
			this->pricePerZone[i] = object.pricePerZone[i];
		}
		this->type = object.type;
	}
	
	//DESTRUCTOR
	~Event() {
		delete[] this->location;
		delete[] this->noSeatsPerZone;
		delete[] this->pricePerZone;
		delete[] this->zones;
		Event::NO_EVENTS_CREATED--;
	}

	int* operator+=(int value) {
		int* copy = new int[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->pricePerZone[i] += value;
			copy[i] = this->pricePerZone[i];
		}
		return copy;
	}

	bool operator>(Event& event) {
		if (this->getTotalNoSeats() > event.getTotalNoSeats())
			return true;
		return false;
	}
};


ostream& operator<<(ostream& out, Event& event) {
	out << endl<<"Type of event: "<<event.getType();
	out << endl << "Number of zones: " << event.getNoZones();
	int* seatsPerZone = event.getNoSeatsPerZone();
	string* zones = event.getZones();
	float* pricePerZone = event.getPricePerZone();
	out << endl<< "Zones: ";
	for (int i = 0; i < event.getNoZones(); i++) {
		out << zones[i] << " ";
	}
	out << endl<<"Number of seats per zone: ";
	for (int i = 0; i < event.getNoZones(); i++) {
		out << seatsPerZone[i] << " ";
	}
	out << endl<<"Prices per zone: ";
	for (int i = 0; i < event.getNoZones(); i++) {
		out << pricePerZone[i] << " ";
	}
	char* location = event.getLocation();
	out << endl << "Location: " << event.getLocation();
	return out;
}

int Event::NO_EVENTS_CREATED = 0;