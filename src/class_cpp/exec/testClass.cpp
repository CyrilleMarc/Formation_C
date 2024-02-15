#include <iostream>
#include <ctime>

#include "class_cpp/class.h"

using namespace std;

    Car::Car()
    {
        make = "unknown";
        model = "unknown";
        year = 0;
        mileage = 0;
    }

    Car::Car(string amake, string amodel, int ayear, int aMileage)
    {
        make = amake;
        model = amodel;
        year = ayear;
        mileage = aMileage;
    }

    Car::~Car()
    {
        cout << "the car " << make << ' ' << model << " was destroyed\n";
    }

    void Car::setMake(string amake)
    {
        make = amake;
    }
    std::string Car::getMake()
    {
        return make;
    }

    void Car::setModel(string amodel)
    {
        model = amodel;
    }

    std::string Car::getModel()
    {
        return model;
    }

    void Car::setYear(int ayear)
    {
        year = ayear;
    }

    int Car::getYear()
    {
        return year;
    }

    int Car::getMileage()
    {
        return mileage;
    }

    int Car::getAge()
    {
       time_t t = time(0);
       struct tm* now = localtime(&t);
       return now->tm_year + 1900 - year;
    }

    void Car::printDetails()
    {
        cout << "Porshe " << make << " " << model << " was built in " << year << ".\n";
        cout << mileage << "kms au total\n";
    }

    void  Car::drive(int kilometers)
    {
        for (int i = 1; i <= 100; i++)
        {
            kilometers += i;
        }
        mileage = kilometers;
    }