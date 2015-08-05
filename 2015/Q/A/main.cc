#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int Smax;
        string S;
        cin >> Smax >> S;
        int r = 0, total = 0;
        for (int i = 0; i <= Smax; ++i) {
            int s = S[i] - '0';
            int add = i - total > 0 ? i - total : 0;
            r += add;
            total += s + add;
        }
        cout << "Case #" << t + 1 << ": " << r << endl;
    }
    return 0;
}
