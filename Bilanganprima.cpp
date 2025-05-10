#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Fungsi untuk menyelidik bilangan prima
int SelidikPrima(unsigned long long n) {
    if (n % 2 == 0 && n != 2) {
        return 2;
    }

    unsigned long long b = sqrt(n);
    for (unsigned long long k = 3; k <= b; k += 2) {
        if (n % k == 0) {
            return k;
        }
    }

    return 1; // Bilangan prima
}

int main() {
    vector<unsigned long long> numbers = {
        17899999999111099591ULL,
        17899999999111099679ULL,
        17899999999111100447ULL,
        17899999999111100609ULL,
        17899999999111100891ULL,
        17899999999111101617ULL,
        17999999999111102191ULL,
        17999999999111128939ULL,
        17999999999111129749ULL
    };

    for (auto n : numbers) {
        int hasil = SelidikPrima(n);
        if (hasil == 1) {
            cout << n << " adalah bilangan prima." << endl;
        } else {
            cout << n << " bukan bilangan prima." << endl;
        }
    }

    return 0;
}
