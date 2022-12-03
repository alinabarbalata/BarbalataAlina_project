#pragma once
#include <iostream>
#include <string>
using namespace std;

class PersonInfo {
private:
	int idPerson = 0;
	string name="-";
	char* dateBirth = nullptr;
	string phoneNo;

	const static int NO_DIGITS = 10;
	const static int NO_CHARACTERS_DATE = 8;
public:
	PersonInfo(const string name, char* dateBirth, string phoneNo) {
		int ok = 1;
		this->name = name;
		if (strlen(dateBirth) == PersonInfo::NO_CHARACTERS_DATE) {
			if (dateBirth[2] = '.' && dateBirth[2] == dateBirth[5])
			{
				if (isDigit(dateBirth[0]) && isDigit(dateBirth[1]) && isDigit(dateBirth[3])
					&& isDigit(dateBirth[4]) && isDigit(dateBirth[6]) && isDigit(dateBirth[7])
					&& isDigit(dateBirth[8]))
					this->dateBirth = dateBirth;
			}
		}
		else
			throw "Invalid date of birth";
		if (Event::lengthString(phoneNo) == PersonInfo::NO_DIGITS)
					this->phoneNo = phoneNo;
		else
					throw "Invalid phone number";
				cout << endl << "Person " << this->name << " was created";
	}

	static bool isDigit(char character) {
		if (character >= 48 && character <= 57)
			return true;
		return false;
	}
};