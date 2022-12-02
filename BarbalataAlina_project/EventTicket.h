#pragma once
#include <iostream>
#include <string>
using namespace std;

enum EventTicketType {A,B,C,VIP};
class EventTicket {
	int* id;
	int length = 0;
	string date = { "01.01.2022" };
	string time = { "00:00" };
	char* namePerson = nullptr;

	EventTicket(string date, string time, char* namePerson) {
		this->date = date;
		this->time = time;
		delete[] namePerson;
		this->namePerson = new char[strlen(namePerson) + 1];
		for (int i = 0; i < strlen(namePerson) + 1; i++) {
			this->namePerson[i] = namePerson[i];
		}
	}

	int* getId() {
		int* copy = new int[length];
		for (int i = 0; i < length; i++) {
			copy[i] = id[i];
		}
		return copy;
	}

	int getNumberOfNumbersInId() {
		return this->length;
	}

	string getDate() {
		return this->date;
	}

	string getTime() {
		return this->time;
	}

	char* getNamePerson() {
		char* copy = new char[strlen(this->namePerson) + 1];
		for (int i = 0; i < strlen(this->namePerson) + 1;i++) {
			copy[i] = namePerson[i];
		}
		return copy;
	}
};