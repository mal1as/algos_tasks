//
// Created by impmb on 19.04.2021.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p, cur_pos = 0, count = 0;
    vector<int> cars;
    unordered_map<int, deque<int>> car_positions;
    unordered_set<int> cars_on_floor;
    cin >> n >> k >> p;

    for (int i = 0; i < p; i++) {
        int car;
        cin >> car;
        cars.push_back(car);
        auto positions = car_positions.find(car);
        if (positions == car_positions.end()) car_positions[car] = *new deque<int>({i});
        else positions->second.push_back(i);
    }

    while (cars_on_floor.size() < k && cur_pos < p) {
        int cur_car = cars[cur_pos];
        if (cars_on_floor.find(cur_car) == cars_on_floor.end()) {
            cars_on_floor.insert(cur_car);
            count++;
        }
        car_positions[cur_car].pop_front();
        cur_pos++;
    }

    while (cur_pos < p) {
        int cur_car = cars[cur_pos];
        if (cars_on_floor.find(cur_car) == cars_on_floor.end()) {
            int max_distant = 0, car_to_delete = 0;
            for(int c : cars_on_floor){
                if(car_positions[c].empty()){
                    car_to_delete = c;
                    break;
                }
                if(car_positions[c].front() - cur_pos > max_distant){
                    max_distant = car_positions[c].front() - cur_pos;
                    car_to_delete = c;
                }
            }

            cars_on_floor.erase(car_to_delete);
            cars_on_floor.insert(cur_car);
            count++;
        }
        car_positions[cur_car].pop_front();
        cur_pos++;
    }

    cout << count;

    return 0;
}