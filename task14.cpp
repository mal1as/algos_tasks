//
// Created by impmb on 23.05.2021.
//

#include "bits/stdc++.h"
using namespace std;

int notes[10001];

void fill_notes(int n){
    for (int i = 1; i < n+1; i++) {
        notes[i] = i;
    }
}

int get_head(int x) {
    if (notes[x] == x) return x;
    notes[x] = get_head(notes[x]);
    return notes[x];
}

int calculate_result(int n){
    int result = 0;
    for (int i = 1; i < n+1; i++) {
        if (notes[i] == i) result++;
    }
    return result;
}

int main() {
    int n, a;
    cin >> n;
    fill_notes(n);

    for (int i = 1; i < n+1; i++) {
        cin >> a;
        int start = get_head(i);
        int finish = get_head(a);
        if (start != finish) notes[finish] = start;
    }

    cout << calculate_result(n);
    return 0;
}