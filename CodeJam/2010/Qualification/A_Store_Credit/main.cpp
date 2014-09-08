#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Problem {
    
    int credit;
    int items_count;
    std::vector<int> items;
    
    Problem(std::vector<std::string>::const_iterator &it);
};

std::vector<Problem> map(int n, std::vector<std::string> &lines);
std::string resolve(const Problem &problem);

int main (int argc, char const *argv[]) {
    
    std::vector<std::string> lines;
    std::string line;
    
    int problems_count = (std::getline(std::cin, line), std::stoi(line));
    
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    std::vector<Problem> mapped_problems = map(problems_count, lines);
    for (int i = 0; i < problems_count; ++i) {
        std::string solution = resolve(mapped_problems[i]);
        std::cout << "Case #" << i + 1 << ": " << solution << std::endl;
    }
     
    return 0;
}

std::vector<Problem> map(int problems_count, std::vector<std::string> &lines) {
    
    std::vector<Problem> problems;
    auto it = lines.cbegin();
    for (int i = 0; i < problems_count; ++i) {
        Problem problem(it);
        problems.push_back(problem);
    }
    
    return problems;
}

Problem::Problem(std::vector<std::string>::const_iterator &it) {
    
    this->credit = std::stoi(*it++);
    this->items_count = std::stoi(*it++);
    
    std::stringstream ss {*it++};

    std::string token;
    for (int i = 0; i < this->items_count; ++i) {
        this->items.push_back(std::stoi((std::getline(ss, token, ' '), token)));
    }
}

std::string resolve(const Problem &problem) {
    
    int credit = problem.credit;
    auto &items = problem.items;
    
    int i1 = -1, i2 = -1;
    bool found = false;
    
    for (int i = 0; i < problem.items_count - 1; ++i) {
        for (int j = i + 1; j < problem.items_count; ++j) {
            if (items[i] + items[j] == credit) {
                i1 = i + 1;
                i2 = j + 1;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    
    return std::to_string(i1) + " " + std::to_string(i2);
}