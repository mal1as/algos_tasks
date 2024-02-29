//
// Created by mondayish on 3/27/21.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                            's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    unordered_map<char, int> weights;
    for (char letter : letters) {
        cin >> weights[letter];
    }
    unordered_map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    sort(letters.begin(), letters.end(), [&weights](char c1, char c2) {
        return weights[c1] > weights[c2] ? 1 : 0;
    });

    int index = 0;
    for (char letter : letters) {
        if (counts[letter] > 1) {
            s[index] = letter;
            s[s.length() - 1 - index] = letter;
            index++;
            counts[letter] -= 2;
        }
    }

    for (char letter : letters) {
        while (counts[letter] > 0) {
            s[index++] = letter;
            counts[letter]--;
        }
    }

    cout << s;

    return 0;
}