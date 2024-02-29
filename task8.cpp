//
// Created by mondayish on 3/27/21.
//

#include "bits/stdc++.h"

using namespace std;

int main(){
    int k, n;
    cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        prices.push_back(a);
    }
    sort(prices.begin(), prices.end());
    int sum = 0;
    for(int i = prices.size() - 1; i >= 0; i--){
        if((prices.size() - i) % k != 0) sum+=prices[i];
    }
    cout << sum;
    return 0;
}