#include "CarRegistry.h"

shared_ptr<CarRegistry> CarRegistry::instance = nullptr;

shared_ptr<CarRegistry> CarRegistry::getInstance()
{
    if (!instance) {
        instance = shared_ptr<CarRegistry>(new CarRegistry());
    }
    return instance;
}

void CarRegistry::removeCar(const string& searchString)
{
    bool matchFound = false;
    cars_.erase(
        remove_if(cars_.begin(), cars_.end(), [&](auto& car)
        {
            if (car->searchMatches(searchString)) {
                matchFound = true;
                for (const auto& observer : carRemovalObservers) {
                    observer(*car);
                }
                return true;
            } else {
                return false;
            }
        }
    ), cars_.end());
    if (!matchFound) {
        cout << "Car not found" << endl;
    }
}

void CarRegistry::modifyCarInfo(const string& searchString, const CarInfo& fieldToUpdate, const string& updatedInfo)
{
    bool matchFound = false;
    for (const auto& car : cars_) {
        if (car->searchMatches(searchString)) {
            matchFound = true;
            car->updateInfo(fieldToUpdate, updatedInfo);
            for (const auto& observer : carModificationObservers) {
                observer(*car);
            }
        }
    }
    if (!matchFound) {
        cout << "Update failed. Possible reasons:" << endl;
        cout << " - No cars matching search criteria were found" << endl;
        cout << " - Tried updating registration information on an unregistered vehicle" << endl;
    }
}

void CarRegistry::searchCar(const string& searchString)
{
    bool matchFound = false;
    for (const auto& car : cars_) {
        if (car->searchMatches(searchString)) {
            matchFound = true;
            car->printInfo();
        }
    }
    if (!matchFound) {
        cout << "Car not found" << endl;
    }
}

void CarRegistry::printRegistry() const
{
    for (size_t i = 0; i < cars_.size(); i++) {
        cout << i+1 << "." << endl;
        cars_[i]->printInfo();
    }
}

void CarRegistry::printStatistics() const
{
    int totalCars = RegisteredCar::getTotalCars();
    int totalRegisteredCars = RegisteredCar::getTotalRegisteredCars();
    cout << "Registry statistics:" << endl;
    cout << "Registered cars: " << totalRegisteredCars << endl;
    cout << "Unregistered cars: " << totalCars - totalRegisteredCars << endl;
}

void CarRegistry::registerModificationListener(function<void(const Car&)> listener)
{
    carModificationObservers.push_back(listener);
}

void CarRegistry::registerRemovalListener(function<void(const Car&)> listener)
{
    carRemovalObservers.push_back(listener);
}
