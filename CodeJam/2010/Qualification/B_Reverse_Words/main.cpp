#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Problem {
    
    std::string content;
    
    /* Problem object structure goes here */
    
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

/* Utilities functions */

std::vector<std::string> split(const std::string s, const char delimiter = ' ') {

    std::stringstream ss {s};
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

Problem::Problem(std::vector<std::string>::const_iterator &it) {
    
    /* Problem object construction goes here */
    
    this->content = *it++;
}

std::string resolve(const Problem &problem) {
    
    /* Solution goes here */
    auto tokens = split(problem.content);
    
    std::string reversed_words;
    for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
        reversed_words += *it + " ";
    }
    
    return reversed_words;
}