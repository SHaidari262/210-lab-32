
#include <iostream>
#include <deque>
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

    return 0;
}
