#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

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

Problem::Problem(std::vector<std::string>::const_iterator &it) {
    
    /* Problem object construction goes here */
    
    this->content = *it++;
}

int valueForSymbol(char c, std::map<char, int> &symbol_table) {
	
	int value = 0;
	
	auto it = symbol_table.find(c);
	
	if (it != symbol_table.end()) { // Found key
		value = symbol_table[c];
	} else { // Not found
		int size = symbol_table.size();
		if (size == 0) {
			value = 1;
		} else if (size == 1) {
			value = 0;
		} else {
			value = size;
		}
		symbol_table[c] = value;
	}
	
	return value;
}

std::string resolve(const Problem &problem) {
    
    /* Solution goes here */
	const std::string &line = problem.content;
	std::map<char, int> symbol_table;
	
	for (char c: problem.content) {
		valueForSymbol(c, symbol_table);
	}
	
	unsigned long result = 0, multiplier = 1;
	int base = std::max<int>(symbol_table.size(), 2); // They aren't using unary.
	for (auto it = problem.content.rbegin(); it != problem.content.rend(); ++it) {
		result += multiplier * symbol_table[*it];
		multiplier *= base;
	}
    
    return std::to_string(result);
}