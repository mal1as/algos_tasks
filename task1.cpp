//
// Created by mondayish on 2/14/21.
//


#include <iostream>

void check_max_length(int *start_max, int *end_max, int start_cur, int end_cur) {
    if (*end_max - *start_max < end_cur - start_cur) {
        *start_max = start_cur;
        *end_max = end_cur;
    }
}

int main() {
    int n;
    std::cin >> n;
    int last_element = 0, count = 0, start_max = 0, end_max = 0, start_cur = 0, end_cur;
    for (int i = 0; i < n; i++) {
        int current;
        std::cin >> current;
        if (last_element != current) {
            count = 1;
            last_element = current;
        } else count++;
        if (count > 2) {
            end_cur = i - 1;
            check_max_length(&start_max, &end_max, start_cur, end_cur);
            start_cur = i - 1;
        }
    }
    end_cur = n - 1;
    check_max_length(&start_max, &end_max, start_cur, end_cur);
    std::cout << start_max + 1 << " " << end_max + 1 << std::endl;
    return 0;
}

