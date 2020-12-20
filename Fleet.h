//
// Created by jfred on 20/12/2020.
//

#ifndef HOTEL2_FLEET_H
#define HOTEL2_FLEET_H
#include "bst.h"

class Vehicle {
string plate;
double mileage;
int lugares;
public:
    Vehicle(string p) : plate(p) {}
    Vehicle(string p, double m, int l) : plate(p), mileage(m), lugares(l){}
    string getPlate() const;
    double getMileage() const;
    int getLugares() const;
    void setMileage(double m) {mileage = m;}
    void updateMileage(double m) {} //to do, maybe bool? return false if mileage > 5000?
    bool operator < (const Vehicle & v) const;
    bool operator == (const Vehicle & v) const;
};

class Fleet {
    BST<Vehicle> vehicles;
public:
    BST<Vehicle> getVehicles() const;
    int numVehicles() const;
    void addVehicle(Vehicle v1);
    void rentFleet(vector<Vehicle>& rfleet);
};


#endif //HOTEL2_FLEET_H
