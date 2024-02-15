#pragma once

#include <string>


class Car
{
public :
	std::string make;
	std::string model;
	int year;
	int mileage;

	//constructeur
	Car();
	Car(std::string amake, std::string amodel, int ayear, int aMileage);
	~Car();
	void setMake(std::string amake);
	void setModel(std::string amodel);
	void setYear(int ayear);
	void drive(int kilometers);
	void printDetails();
	std::string getMake();
	std::string getModel();
	int getYear();
	int getMileage();
	int getAge();
	
};