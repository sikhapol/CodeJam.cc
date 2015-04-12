#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define RICHARD "RICHARD"
#define GABRIEL "GABRIEL"

using namespace std;

struct Problem {
    vector<string> raw;
    int x, r, c;
};

string getline() {
    string line;
    getline(cin, line);
    return line;
}

vector<string> split() {
    vector<string> v;
    v.push_back(getline());
    return v;
}

Problem map(Problem p) {
    stringstream ss(p.raw[0]);
    string token;
    p.x = (getline(ss, token, ' '), stoi(token));
    p.r = (getline(ss, token, ' '), stoi(token));
    p.c = (getline(ss, token, ' '), stoi(token));
    if (p.r < p.c) {
        p.r = p.r ^ p.c;
        p.c = p.r ^ p.c;
        p.r = p.r ^ p.c;
    }
    return p;
}

string solve(Problem p) {
    int x = p.x;
    int r = p.r;
    int c = p.c;

    if (c == 0) {
        return RICHARD;
    }

    if (r*c < x) {
        return RICHARD;
    }

    if (x > r) {
        return RICHARD;
    }

    if ((r*c) % x != 0) {
        return RICHARD;
    }

    if (x <= 2) {
        return GABRIEL;
    }

    if (x == 3) {
        if (c == 1) {
            return RICHARD;
        }
        return GABRIEL;
    }

    if (x == 4) {
        if (c <= 2) {
            return RICHARD;
        }
        return GABRIEL;
    }

    return RICHARD;
}

int main (int argc, char **argv) {
    int num_prob = stoi(getline());
    for (int i = 0; i < num_prob; ++i) {
        Problem p;
        p.raw = split();
        p = map(p);
        cout << "Case #" << i+1 << ": " << solve(p) << endl;
    }
}
