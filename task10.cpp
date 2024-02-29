//
// Created by mondayish on 3/29/21.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> fp_goblins;
    deque<int> sp_goblins;
    int n;
    cin >> n;
    vector<int> result;
    for(int i = 0; i < n; i++){
        char type;
        int goblin;
        cin >> type;
        if(type == '-'){
            result.push_back(fp_goblins.front());
            fp_goblins.pop_front();
        } else {
            cin >> goblin;
            if (type == '+') sp_goblins.push_back(goblin);
            else sp_goblins.push_front(goblin);
        }

        if(fp_goblins.size() < sp_goblins.size()){
            fp_goblins.push_back(sp_goblins.front());
            sp_goblins.pop_front();
        }
    }

    for(int goblin : result){
        cout << goblin << '\n';
    }
    return 0;
}