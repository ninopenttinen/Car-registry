#include "CarRegistry.h"

string askSearchDetails()
{
	string searchString;

	cout << " - Registration number" << endl;
	cout << " - Manufacturer" << endl;
	cout << " - Model" << endl;
	cout << " - Model and manufacturer" << endl;
	cout << ">> ";
	getline(cin, searchString);
	return searchString;
}

void addCar()
{
	string manufacturer, model, manufacturingYear, isRegistered;

	cout << "Provide the requested information" << endl;
	cout << "Manufacturer: ";
	getline(cin, manufacturer);
	cout << "Model: ";
	getline(cin, model);
	cout << "Manufacturing year: ";
	getline(cin, manufacturingYear);
	if (!isNumeric(manufacturingYear)) {
		manufacturingYear = "0";
	}

	cout << "Is car registered (Y/N)?: ";
	getline(cin, isRegistered);

	if (isRegistered == "Y" || isRegistered == "y") {
		string registrationNumber, registrationYear;
		cout << "Registration number: ";
		getline(cin, registrationNumber);
		cout << "Registration year: ";
		getline(cin, registrationYear);
		if (!isNumeric(registrationYear)) {
			registrationYear = "0";
		}
		CarRegistry::getInstance()->addCar(RegisteredCar{ manufacturer, model, stoi(manufacturingYear), registrationNumber, stoi(registrationYear) });
	}
	else if (isRegistered == "N" || isRegistered == "n") {
		CarRegistry::getInstance()->addCar(Car{ manufacturer, model, stoi(manufacturingYear) });
	}
	else {
		cout << "Invalid input: " << isRegistered << endl;
		cout << "Car was not added" << endl;
	}
}

void removeCar()
{
	cout << "Search car to remove by entering:" << endl;
	CarRegistry::getInstance()->removeCar(askSearchDetails());
}

void searchCar()
{
	cout << "Search car by entering:" << endl;
	CarRegistry::getInstance()->searchCar(askSearchDetails());
}

void modifyCarInfo()
{
	string searchString, infoToModify, updatedInfo;
	cout << "Search car to modify by entering:" << endl;
	searchString = askSearchDetails();

	cout << "Select info to modify:" << endl;
	cout << "1. manufacturer" << endl;
	cout << "2. model" << endl;
	cout << "3. manufacturing year" << endl;
	cout << "4. registration number" << endl;
	cout << "5. registration year" << endl;
	cout << "b. Back" << endl;
	cout << ">> ";
	getline(cin, infoToModify);

	CarInfo fieldToUpdate;
	switch (infoToModify[0]) {
	case '1':
		fieldToUpdate = CarInfo::MANUFACTURER;
		break;
	case '2':
		fieldToUpdate = CarInfo::MODEL;
		break;
	case '3':
		fieldToUpdate = CarInfo::MANUFACTURING_YEAR;
		break;
	case '4':
		fieldToUpdate = CarInfo::REGISTRATION_NUMBER;
		break;
	case '5':
		fieldToUpdate = CarInfo::REGISTRATION_YEAR;
		break;
	case 'b':
		return;
	}

	cout << "Enter new info: ";
	getline(cin, updatedInfo);

	CarRegistry::getInstance()->modifyCarInfo(searchString, fieldToUpdate, updatedInfo);
}

void menu()
{
	string input;

	cout << ">> Car registry service <<" << endl << endl;

	cout << "--------------------" << endl;
	cout << "1. Add car to registry" << endl;
	cout << "2. Search car" << endl;
	cout << "3. Remove car from registry" << endl;
	cout << "4. Modify car info" << endl;
	cout << "5. Sort car registry" << endl;
	cout << "6. Print registry" << endl;
	cout << "7. Print registered and unregistered amounts" << endl;
	cout << "q. Quit" << endl;
	cout << "--------------------" << endl;

	do {
		cout << endl << ">> ";
		getline(cin, input);

		switch (input[0]) {
		case '1':
			addCar();
			break;
		case '2':
			searchCar();
			break;
		case '3':
			removeCar();
			break;
		case '4':
			modifyCarInfo();
			break;
		case '5':
			break;
		case '6':
			CarRegistry::getInstance()->printRegistry();
			break;
		case '7':
			CarRegistry::getInstance()->printStatistics();
			break;
		case 'q':
			break;
		}
	} while (input[0] != 'q');

}


int main()
{
	auto listener = [](const string& msg, const Car& car) {
		cout << endl << msg << endl;
		car.printInfo();
	};
	CarRegistry::getInstance()->registerListener(listener);

	menu();
	return 0;
}
