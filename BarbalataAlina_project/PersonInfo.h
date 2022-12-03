#pragma once
#include <iostream>
#include <string>
using namespace std;

class PersonInfo {
	int idPerson = 0;
	string name="-";
	string dateBirth = "-";
	int phoneNo[11] = { 0 };

	PersonInfo(const string name, const string dateBirth, int phoneNo[]) {
		this->name = name;
		this->dateBirth = dateBirth;
		for (int i = 0; i < 11; i++) {
			this->phoneNo[i] = phoneNo[i];
		}
	}
};
