#include <iostream>

#include "class.h"

using namespace std;

    int main()
    {
        int kilometers = 0;
        {
            Car porshe;
            porshe.setMake("911");
            porshe.setModel("Turbo");
            porshe.setYear(1975);
            porshe.drive(kilometers);
            porshe.printDetails();
            porshe.getAge();

            cout << porshe.getMake() << '\n';
            cout << porshe.getModel() << '\n';
            cout << porshe.getYear() << '\n';
            cout << porshe.getMileage() << '\n';
            cout << "la voiture a " << porshe.getAge() << " ans\n";
        }
        
        return 0;
    }
