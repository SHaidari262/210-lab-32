
#include <iostream>
#include <deque>
#include <cstdlib>
#include "Car.h"

using namespace std;

int main() {
    const int initial_cars = 2;

    deque<Car> tollLane;

    tollLane.push_back(Car());
    tollLane.push_back(Car());

    cout << "Initial queue:" << endl;
    for (Car& car : tollLane) {
        car.print();
}


// add this line here 
cout << "number of cars in the queue: " << tollLane.size() << endl;
    

    //add the new code here
   while (!tollLane.empty()) {
    int chance = rand() % 100; // Random number between 0 and 99

    if (chance < 55) {
        cout << "A car paid and left." << endl;
        tollLane.pop_front(); 
    }else {
        cout << "A new car arrived." << endl;
        tollLane.push_back(Car());
    }

    cout << "Cars waiting: " << tollLane.size() << endl;

    for (Car& car : tollLane) {
        car.print();
    }

}

return 0;
}
