//
// Created by mondayish on 2/15/21.
//

#include <iostream>

using namespace std;

long chaos_laboratory(int a, int b, int c, int d, long k) {
    int b_count;
    b_count = a;
    if (a * b - c == a) return a;
    int i = 0;
    while (i < k) {
        b_count *= b;
        b_count -= c;
        if (b_count > d && i > 0) return d;
        if (b_count <= 0) return 0;
        i++;
    }
    return b_count;
}

int main() {
    int a, b, c, d;
    long k;
    cin >> a >> b >> c >> d >> k;
    cout << chaos_laboratory(a, b, c, d, k);
    return 0;
}