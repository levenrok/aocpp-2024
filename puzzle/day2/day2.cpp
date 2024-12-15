#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool is_safe_row(const std::vector<int>& row);

int main(void) {
    int num_safe_reports = 0;
    std::vector<std::vector<int>> reports;

    std::ifstream puzzle_input("input.txt");
    if (!puzzle_input.is_open()) {
        std::cerr << "Error: cannot open file" << '\n';
        exit(1);
    }

    std::string line;
    while (std::getline(puzzle_input, line)) {
        std::istringstream iss(line);

        std::vector<int> row;
        int num;

        while (iss >> num) {
            row.push_back(num);
        }
        reports.push_back(row);
    }

    for (const auto& row : reports) {
        if (is_safe_row(row)) {
            num_safe_reports++;
        }
    }

    std::cout << "Number of Safe Reports: " << num_safe_reports << '\n';

    puzzle_input.close();
    exit(0);
}

bool is_safe_row(const std::vector<int>& row) {
    for (size_t i = 1; i < row.size(); ++i) {
        int diff = row[i] - row[i - 1];

        if (std::abs(diff) > 3 || diff == 0) {
            return false;
        }
        if ((i > 1) && ((row[i - 1] - row[i - 2]) * diff < 0)) {
            return false;
        }
    }
    return true;
}
