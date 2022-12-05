#pragma once
#include <iostream>
#include <string>
using namespace std;

enum EventTicketType {VIP,A,B,C};
class EventTicket {
	int* id;
	int lengthId = 0;
	string date = "01.01.2022" ;
	string time = "00:00";
	char* namePerson = nullptr;
private:
	static int COUNTER;

	EventTicket(string date, string time, char* namePerson) {
		this->date = date;
		this->time = time;
		this->namePerson = new char[strlen(namePerson) + 1];
		for (int i = 0; i < strlen(namePerson) + 1; i++) {
			this->namePerson[i] = namePerson[i];
		}
		EventTicket::COUNTER++;
	}

	int* getId() {
		int* copy = new int[lengthId];
		for (int i = 0; i < lengthId; i++) {
			copy[i] = id[i];
		}
		return copy;
	}

	int getLengthId() {
		return this->lengthId;
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

	void idGenerator(int* idPerson, int lengthIdPerson, EventTicketType type) {
		int n = 0,index=0,i,j;
		int copy = EventTicket::COUNTER;
		int* array = nullptr;
		//no of digits of the EventTicket::COUNTER
		while (copy) {
			array[n] = copy % 10;
			n++;
			copy = copy / 10;
		}
		this->lengthId = n + lengthIdPerson+1;//+1 because we also add the code for the event type
		delete[] this->id;
		this->id = new int[this->lengthId];
		for (int i = 0; i < lengthIdPerson; i++) {
			this->id[i] = idPerson[i];
			index = i;
		}
		i = index;
		j = 0;
		while (i < this->lengthId && j<n) {
			this->id[i] = array[j];
			i++;
			j++;
		}
		this->id[this->lengthId] = type;//needs testing

	}

	/*static int counterLength(int counter) {
		int copy = counter,n=0;
		while (copy) {
			copy = copy / 10;
			n++;
		}
		return n;
	}*/
};

int EventTicket::COUNTER = 0;
