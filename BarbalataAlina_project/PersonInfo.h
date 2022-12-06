#pragma once
#include <iostream>
#include <string>
using namespace std;

class PersonInfo {
private:
	int idPerson;
	string name = "-";
	int dayBirth;
	int monthBirth;
	int yearBirth;
	int noTicketsBought = 0;

	const static int NO_DIGITS = 10;
	const static int NO_CHARACTERS_DATE = 8;
	static int COUNTER;
public:
	PersonInfo() {
		this->name = "-";
		this->dayBirth = 0;
		this->monthBirth = 0;
		this->yearBirth = 0;
	}
	PersonInfo(const string name) {
		this->name = name;
		PersonInfo::COUNTER++;
		cout << endl << "Person " << this->name << " was created";
	}

	string getName() {
		return this->name;
	}

	int getDayBirth() {
		return this->dayBirth;
	}

	int getMonthBirth() {
		return this->monthBirth;
	}

	int getYearBirth() {
		return this->yearBirth;
	}

	void setDateBirth(int day, int month, int year) {
		this->dayBirth = day;
		this->monthBirth = month;
		this->yearBirth = year;
	}

	int getId() {
		this->idPerson = PersonInfo::COUNTER;
		return this->idPerson;
	}

	int getNoTicketsBought() {
		return this->noTicketsBought;
	}

	void setNoTicketsBought(int noTickets) {
		this->noTicketsBought = noTickets;
	}
	~PersonInfo() {
		PersonInfo::COUNTER--;
	}
	friend istream& operator>>(istream& in, PersonInfo& person);

};


istream& operator>>(istream& in, PersonInfo& person) {
	cout << endl << "Name: ";
	in >> person.name;
	cout << endl << "Day of birth: ";
	in >> person.dayBirth;
	cout << endl << "Month of birth: ";
	in >> person.monthBirth;
	cout << endl << "Year of birth: ";
	in >> person.yearBirth;
	return in;
}
ostream& operator<<(ostream& out, PersonInfo& person) {
	out << endl << "Name: " << person.getName();
	out << endl << "Day of birth: " << person.getDayBirth();
	out << endl << "Month of birth: " << person.getMonthBirth();
	out << endl << "Year of birth: " << person.getYearBirth();
	return out;
}
int PersonInfo::COUNTER = 0;