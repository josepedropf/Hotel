#include "Fleet.h"

bool Vehicle::operator<(const Vehicle &v) const {
    if (mileage < v.getMileage()) {
        return true;
    }
    else return lugares < v.getLugares();
}

bool Vehicle::operator==(const Vehicle &v) const {
    return getPlate() == v.getPlate();
}

string Vehicle::getPlate() const {
    return plate;
}

double Vehicle::getMileage() const {
    return mileage;
}

int Vehicle::getLugares() const {
    return lugares;
}

BST<Vehicle> Fleet::getVehicles() const {
    return vehicles;
}

int Fleet::numVehicles() const {
    int result = 0;
    BSTItrIn<Vehicle> it(vehicles);
    for (; !it.isAtEnd();it.advance()) {
        result++;
    }
    return result;
}

void Fleet::addVehicle(Vehicle v1) {
    vehicles.insert(v1);
}

void Fleet::rentFleet(vector <Vehicle> rfleet) {
    vehicles.makeEmpty();
    for (auto & i : rfleet) {
        addVehicle(i);
    }
}
