#pragma once
#include <iostream>
#include <string>
using namespace std;

class PersonInfo {
private:
	int idPerson = 0;
	string name = "-";
	int dayBirth = 0;
	int monthBirth = 0;
	int yearBirth = 0;

	const static int NO_DIGITS = 10;
	const static int NO_CHARACTERS_DATE = 8;
public:
	PersonInfo(const string name) {
		this->name = name;
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
};