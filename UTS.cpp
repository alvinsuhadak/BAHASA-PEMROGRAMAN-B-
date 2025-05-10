#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "Kanjeng Sinuwun Mukiyo Adalah Hukum";

    for (int i = 0; i <= 16; i++) {
        cout << i << "    " << str.substr(i) << "    " << 16 - i << endl;
    }

    return 0;
}
