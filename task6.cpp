//
// Created by mondayish on 2/22/21.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<string> numbers;
    string line;
    while (cin >> line) {
        numbers.push_back(line);
    }
    sort(numbers.begin(), numbers.end(), [](string s1, string s2) {
        if(s1+s2 > s2+s1) return 1;
        return 0;
    });
    for (string s : numbers) {
        cout << s;
    }
    cout << endl;
    return 0;
}
