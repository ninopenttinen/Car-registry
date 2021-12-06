#pragma once
#include "utils.h"

class Car
{
public:
	Car();
	Car(const string& manufacturer, const string& model, int manufacturingYear);
	Car(const Car& car) = default;
	~Car();

	string getManufacturer() const;
	string getModel() const;
	int getManufacturingYear() const;
	static int getTotalCars();

	void setManufacturer(const string& manufacturer);
	void setModel(int model);
	void setManufacturingYear(int manufacturingYear);

	virtual bool searchMatches(const string& searchString) const;
	virtual void printInfo() const;
	virtual void updateInfo(const CarInfo& fieldToUpdate, const string& updatedInfo);

private:
	string manufacturer_;
	string model_;
	int manufacturingYear_;
	static int totalCars_;
};

