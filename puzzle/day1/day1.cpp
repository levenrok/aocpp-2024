#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> left_col;
    std::vector<int> right_col;

    std::ifstream puzzle_input("input.txt");
    if (!puzzle_input) {
        std::cerr << "Error: file not found" << '\n';
        exit(1);
    }

    int left_num, right_num;
    while (puzzle_input >> left_num >> right_num) {
        left_col.push_back(left_num);
        right_col.push_back(right_num);
    }

    std::sort(left_col.begin(), left_col.end());
    std::sort(right_col.begin(), right_col.end());

    int total_distance = 0;
    for (int i = 0; i < left_col.size(); i++) {
        int distance = std::abs(left_col[i] - right_col[i]);
        total_distance += distance;
    }

    std::cout << "Total Distance: " << total_distance << '\n';

    puzzle_input.close();
    exit(0);
}
