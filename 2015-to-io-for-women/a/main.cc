#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int num_case;
    cin >> num_case;
    for (int i = 0; i < num_case; ++i) {
        int num_char;
        string chars;
        cin >> num_char;
        cin >> chars;
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < num_char; ++j) {
           char c = 0;
           for (int k = 0; k < 8; ++k) {
               if (chars[j*8+k] == 'I') {
                   c |= 1 << (7-k);
               }
           } 
           cout << c;
        }
        cout << endl;
    }
    return 0;
}
