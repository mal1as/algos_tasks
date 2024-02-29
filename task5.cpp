//
// Created by mondayish on 2/22/21.
//

#include <iostream>
#include <vector>

using namespace std;

int check_distance(int distance, vector<int> stalls) {
    int current_cows_count = 1, last_cow = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_cow >= distance) {
            last_cow = stalls[i];
            current_cows_count++;
        }
    }
    return current_cows_count;
}

int main() {
    int stalls_count, cows_count;
    cin >> stalls_count >> cows_count;
    vector<int> stalls(stalls_count);
    for (int i = 0; i < stalls_count; i++) {
        cin >> stalls[i];
    }

    int left = 0, right = stalls[stalls_count - 1] - stalls[0] + 1;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (check_distance(middle, stalls) >= cows_count) {
            left = middle;
        } else {
            right = middle;
        }
    }
    cout << left;
    return 0;
}

