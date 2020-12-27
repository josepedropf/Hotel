#ifndef HOTEL_FLEET_H
#define HOTEL_FLEET_H
#include "bst.h"

class Vehicle {
string plate;
double mileage;
int lugares;
//can add brand and date and more
public:
    Vehicle(string p) : plate(p) {}
    Vehicle(string p, double m, int l) : plate(p), mileage(m), lugares(l){}
    string getPlate() const;
    double getMileage() const;
    int getLugares() const;
    void setMileage(double m) {mileage = m;}
    void updateMileage(double m); //to be called at the end of a trip
    void returnVehicle(); //not implemented yet, devolve carro e remove da bst
    int info(ostream &o) const;
    bool operator < (const Vehicle & v) const;
    bool operator == (const Vehicle & v) const;
};

class Fleet {
    BST<Vehicle*> vehicles;
public:
    BST<Vehicle*> getVehicles() const;
    int numVehicles() const;
    void addVehicle(Vehicle *v1);
    void rentFleet(const vector<Vehicle*>& rfleet);
    Vehicle* searchForVehicle(string p);
    Vehicle* lowestM(); //to be called at the start or before a trip
};

class vehicleNotFound
{

};


#endif //HOTEL_FLEET_H
