#include "RegisteredCar.h"

int RegisteredCar::totalRegisteredCars_{ 0 };

RegisteredCar::RegisteredCar()
	: Car{}, registrationNumber_{}, registrationYear_{}
{
	totalRegisteredCars_++;
}

RegisteredCar::RegisteredCar(const string& manufacturer, const string& model, int manufacturingYear, const string& registrationNumber, int registrationYear)
	: Car{ manufacturer, model, manufacturingYear }, registrationNumber_{ registrationNumber }, registrationYear_{ registrationYear }
{
	totalRegisteredCars_++;
}

RegisteredCar::~RegisteredCar()
{
	totalRegisteredCars_--;
}

string RegisteredCar::getRegistrationNumber() const
{
	return registrationNumber_;
}

int RegisteredCar::getRegistrationYear() const
{
	return registrationYear_;
}

int RegisteredCar::getTotalRegisteredCars()
{
	return totalRegisteredCars_;
}

void RegisteredCar::setRegistrationNumber(const string& registrationNumber)
{
	registrationNumber_ = registrationNumber;
}

void RegisteredCar::setRegistrationYear(int registrationYear)
{
	registrationYear_ = registrationYear;
}

bool RegisteredCar::searchMatches(const string& searchString) const
{
	if (Car::searchMatches(searchString)
		|| searchString == registrationNumber_) {
		return true;
	} else {
		return false;
	}
}

void RegisteredCar::printInfo() const
{
	Car::printInfo();
	cout << "Registration number: " << registrationNumber_ << endl;
	cout << "Registration year: " << registrationYear_ << endl;
}

// return boolean value depending on whether the update succeeds
void RegisteredCar::updateInfo(const CarInfo& fieldToUpdate, const string& updatedInfo)
{
	Car::updateInfo(fieldToUpdate, updatedInfo);

	switch (fieldToUpdate) {
	case(CarInfo::REGISTRATION_NUMBER):
		registrationNumber_ = updatedInfo;
		break;
	case(CarInfo::REGISTRATION_YEAR):
		if (isNumeric(updatedInfo)) {
			registrationYear_ = stoi(updatedInfo);
		}
		break;
	}
}
