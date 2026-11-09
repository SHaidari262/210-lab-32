
#include <iostream>
#include <deque>
#include <cstdlib>
#include "Car.h"

using namespace std;

int main() {
    const int initial_cars = 2;
    const int num_lanes = 4;

    deque<Car> tollLanes[num_lanes];

 
    //milestone 3: add tow cars to each of the four toll lanes
    for (int i = 0; i < num_lanes; i++) {
        for (int j = 0; j < initial_cars; j++) {
            tollLanes[i].push_back(Car());
        }
    }

    cout << "Initial queue:" << endl;

    for (int i = 0; i < num_lanes; i++) {
        cout << "Lane " << i + 1 << ":" << endl;

    for (Car& car : tollLanes[i]) {
    car.print();
}
cout << endl;
} 

    // Test all four lanes
    for (int i = 0; i < num_lanes; i++) {
        cout << "Lane " << i + 1
             << " has " << tollLanes[i].size()
             << " car(s)." << endl;
    }
 
    //milestone 4: simulate 20 time periods
    const int time_periods = 20;

    for (int time =1; time <= time_periods; time++) {
        cout << "\nTime Period " << time << endl;
    
     for (int i = 0; i < num_lanes; i++) {
    int chance = rand() % 100;

    // Milestone 5: Handle empty lanes
    if (tollLanes[i].empty()) {
        if (rand() % 100 < 50) {
            tollLanes[i].push_back(Car());
            cout << "Lane " << i + 1
                 << ": New car joined empty lane." << endl;
        } else {
            cout << "Lane " << i + 1
                 << ": Empty lane, no action." << endl;
        }
        continue;
    }

    if (chance < 46 && !tollLanes[i].empty()) {
            tollLanes[i].pop_front();
            cout << "Lane " << i + 1
                 << ": Car paid and left the toll lane." << endl;
        } else if (chance < 85) {
            tollLanes[i].push_back(Car());
            cout << "Lane " << i + 1
                 << ": New car joined." << endl;

       } else {
           if (!tollLanes[i].empty()) {
               int newLane = rand() % num_lanes;

               while (newLane == i) {
                     newLane = rand() % num_lanes;
        }

        Car movingCar = tollLanes[i].back();
        tollLanes[i].pop_back();
        tollLanes[newLane].push_back(movingCar);

        cout << "Car switched from Lane " << i + 1
             << " to Lane " << newLane + 1 << endl;
    }
        }
    }  // End of lane loop
}      // End of time period loop

return 0;
}
  
