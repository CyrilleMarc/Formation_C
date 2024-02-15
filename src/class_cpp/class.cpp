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

            cout << porshe.getMake() << '\n';
            cout << porshe.getModel() << '\n';
            cout << porshe.getYear() << '\n';
            cout << porshe.getMileage() << '\n';

        }
        
        return 0;
    }
