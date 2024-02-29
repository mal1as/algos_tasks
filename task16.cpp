//
// Created by impmb on 07.05.2021.
//

#include "bits/stdc++.h"

using namespace std;

int graph[1000][1000];
bool g[1000][1000], used[1000];
int n;

void df_search(int v, bool direction) {
    used[v] = true;
    for (int i = 0; i < n; i++) {
        if ((direction ? g[i][v] : g[v][i]) && !used[i]) df_search(i, direction);
    }
}

bool is_all_visited() {
    for (int i = 0; i < n; i++) {
        if (!used[i]) return false;
    }
    return true;
}

void clear_used() {
    for (int i = 0; i < n; i++) used[i] = false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start = 0, finish = 1000000000;
    while (start < finish) {
        int middle = (start + finish) / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = graph[i][j] <= middle;
            }
        }
        clear_used();

        df_search(0, false);
        bool is_connectivity = false;
        if (is_all_visited()) {
            clear_used();
            df_search(0, true);
            if (!is_all_visited()) is_connectivity = true;
        } else is_connectivity = true;

        if (!is_connectivity) finish = middle;
        else start = middle + 1;
    }

    cout << start;
    return 0;
}

