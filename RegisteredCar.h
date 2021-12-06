#pragma once
#include "Car.h"

class RegisteredCar final
	: public Car
{
public:
	RegisteredCar();
	RegisteredCar(const string & manufacturer, const string & model, int manufacturingYear, const string& registrationNumber, int registrationYear);
	RegisteredCar(const RegisteredCar & registeredCar) = default;
	~RegisteredCar();

	string getRegistrationNumber() const;
	int getRegistrationYear() const;
	static int getTotalRegisteredCars();

	void setRegistrationNumber(const string& registrationNumber);
	void setRegistrationYear(int registrationYear);

	virtual bool searchMatches(const string& searchString) const override;
	virtual void printInfo() const override;
	virtual void updateInfo(const CarInfo& fieldToUpdate, const string& updatedInfo) override;

private:
	string registrationNumber_;
	int registrationYear_;
	static int totalRegisteredCars_;
};

