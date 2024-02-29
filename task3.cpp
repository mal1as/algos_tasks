//
// Created by mondayish on 2/17/21.
//

#include "bits/stdc++.h"

using namespace std;

int solve();

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}

unordered_map<string, stack<int>> vars;

void process_file() {
    string str;
    unordered_set<string> args;
    while (cin >> str) {
        if (str == "{") {
            process_file();
            continue;
        }
        if (str == "}") {
            for (auto &it : args) {
                auto it2 = vars.find(it);
                it2->second.pop();
                if (it2->second.empty())
                    vars.erase(it2);
            }
            return;
        }
        string strcpy1, strcpy2;
        int i;
        for (i = 0; i < str.size() && str[i] != '='; ++i)
            strcpy1 += str[i];
        for (i += 1; i < str.size(); ++i)
            strcpy2 += str[i];

        auto it = args.find(strcpy1);
        if (it == args.end()) {
            args.insert(strcpy1);
            auto it2 = vars.find(strcpy1);
            if (it2 == vars.end()) {
                stack<int> tmp;
                vars.insert(make_pair(strcpy1, tmp));
                vars.find(strcpy1)->second.push(0);
            } else {
                if (strcpy1 == strcpy2) {
                    cout << it2->second.top() << '\n';
                    it2->second.push(it2->second.top());
                    continue;
                }
                it2->second.push(0);
            }
        }
        if (strcpy1 == strcpy2) {
            cout << vars.find(strcpy1)->second.top() << '\n';
            continue;
        }
        if (isdigit(strcpy2[0]) || strcpy2[0] == '-') {
            auto it3 = vars.find(strcpy1);
            it3->second.pop();
            it3->second.push(stoi(strcpy2));
        } else {
            auto it2 = vars.find(strcpy2);
            if (it2 == vars.end()) {
                args.insert(strcpy2);
                stack<int> tmp;
                vars.insert(make_pair(strcpy2, tmp));
                vars.find(strcpy2)->second.push(0);
            }
            it2 = vars.find(strcpy2);
            auto it3 = vars.find(strcpy1);
            it3->second.pop();
            it3->second.push(it2->second.top());
            cout << it3->second.top() << '\n';
        }
    }
}

int solve() {
    process_file();
    return 0;
}

