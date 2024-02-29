//
// Created by mondayish on 3/28/21.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    set<pair<int, int>> sorted_window;
    for(int i = 0; i < k; i++){
        sorted_window.insert(make_pair(numbers[i], i));
    }

    for(int i = 0; i < n - k; i++){
        cout << sorted_window.begin()->first << ' ';
        sorted_window.erase(make_pair(numbers[i], i));
        sorted_window.insert(make_pair(numbers[i+k], i+k));
    }

    cout << sorted_window.begin()->first << endl;
    return 0;
}
























