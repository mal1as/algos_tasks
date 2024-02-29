//
// Created by mondayish on 2/14/21.
//

#include <iostream>
#include <stack>

using namespace std;

struct trap {
    char type;
    int animal_id;
};

int main() {
    string input;
    cin >> input;
    int animal_count = 0, result_count = 0;
    stack<struct trap> traps;
    int result[input.length() / 2];
    stack<int> indexes;
    for (char letter : input) {
        if (islower(letter)) {
            animal_count++;
            if (!traps.empty() && traps.top().type == toupper(letter)) {
                result[indexes.top()] = animal_count;
                indexes.pop();
                traps.pop();
            } else {
                traps.push(trap{.type = letter, .animal_id = animal_count});
            }
        } else {
            if (!traps.empty() && traps.top().type == tolower(letter)) {
                result[result_count++] = traps.top().animal_id;
                traps.pop();
            } else {
                traps.push(trap{.type = letter, .animal_id = -1});
                indexes.push(result_count++);
            }
        }
    }
    if (!traps.empty()) cout << "Impossible";
    else {
        cout << "Possible\n";
        for (int i = 0; i < input.size() / 2; i++) {
            cout << result[i] << " ";
        }
    }
    return 0;
}