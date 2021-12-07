#include "Car.h"

int Car::totalCars_{ 0 };

Car::Car()
	: manufacturer_{}, model_{}, manufacturingYear_{}
{
	totalCars_++;
}

Car::Car(const string& manufacturer, const string& model, int manufacturingYear)
	: manufacturer_{ manufacturer }, model_{ model }, manufacturingYear_{ manufacturingYear }
{
	totalCars_++;
}

Car::Car(const Car& car)
	: manufacturer_{ car.manufacturer_ }, model_{ car.model_ }, manufacturingYear_{ car.manufacturingYear_ }
{
	totalCars_++;
}

Car::~Car()
{
	totalCars_--;
}

string Car::getManufacturer() const
{
	return manufacturer_;
}

string Car::getModel() const
{
	return model_;
}

int Car::getManufacturingYear() const
{
	return manufacturingYear_;
}

int Car::getTotalCars()
{
	return totalCars_;
}

void Car::setManufacturer(const string& manufacturer)
{
	manufacturer_ = manufacturer;
}

void Car::setModel(int model)
{
	model_ = model;
}

void Car::setManufacturingYear(int manufacturingYear)
{
	manufacturingYear_ = manufacturingYear;
}

bool Car::searchMatches(const string& searchString) const
{
	if (searchString == manufacturer_
		|| searchString == model_
		|| searchString == manufacturer_ + " " + model_
		|| searchString == model_ + " " + manufacturer_) {
		return true;
	} else {
		return false;
	}
}

void Car::printInfo() const
{
	cout << manufacturer_ << " " << model_ << " " << manufacturingYear_ << endl;
}

// return boolean value depending on whether the update succeeds
void Car::updateInfo(const CarInfo& fieldToUpdate, const string& updatedInfo)
{
	switch (fieldToUpdate) {
	case(CarInfo::MANUFACTURER):
		manufacturer_ = updatedInfo;
		break;
	case(CarInfo::MODEL):
		model_ = updatedInfo;
		break;
	case(CarInfo::MANUFACTURING_YEAR):
		if (isNumeric(updatedInfo)) {
			manufacturingYear_ = stoi(updatedInfo);
		}
		break;
	}
}
