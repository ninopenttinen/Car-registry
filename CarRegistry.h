#pragma once
#include "RegisteredCar.h"


class CarRegistry final
{
public:
	static shared_ptr<CarRegistry> getInstance();

	template <typename T>
	void addCar(const T& car) { 
		cars_.push_back(make_shared<T>(car)); 
		notifyObservers("Added:", car);
	}
	void removeCar(const string& searchString);
	void modifyCarInfo(const string& searchString, const CarInfo& fieldToUpdate, const string& updatedInfo);
	void searchCar(const string& searchString);
	void printRegistry() const;
	void printStatistics() const;
	void notifyObservers(const string& msg, const Car& car) const;

	void registerListener(function<void(const string&, const Car&)> listener);

private:
	static shared_ptr<CarRegistry> instance;

	CarRegistry() = default;
	CarRegistry(const CarRegistry& carRegistry) = delete;

	vector<shared_ptr<Car>> cars_;

	vector<function<void(const string&, const Car&)>> dataObservers_;
};

