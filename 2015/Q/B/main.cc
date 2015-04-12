#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

string solve();

int main(int argc, char *argv[]) {
    int num_prob;
    cin >> num_prob;
    for (int i = 0; i < num_prob; ++i) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}

string solve() {
    int num_plate;
    cin >> num_plate;

    vector<int> plates;
    for (int i = 0, temp; i < num_plate; ++i) {
        cin >> temp;
        plates.push_back(temp);
    }

    int max_plate = *max_element(plates.begin(), plates.end());
    int min_time = numeric_limits<int>::max();

    for (int i = max_plate; i > 0; --i) {
        int t = i;
        for (int j: plates) {
            t += (j-1)/i;
        }
        min_time = min(min_time, t);
    }

    return to_string(min_time);
}
