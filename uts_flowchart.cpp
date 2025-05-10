#include <iostream>
#include <cmath>
using namespace std;

int SelidikPrima(int n) {
    if (n % 2 == 0 && n != 2) {
        return 2;
    }

    int b = sqrt(n);
    for (int k = 3; k <= b; k += 2) {
        if (n % k == 0) {
            return k; // Ditemukan faktor pembagi
        }
    }

    return 1; // Tidak ditemukan pembagi => bilangan prima
}

int main() {
    char lagi = 'y';
    while (lagi == 'y' || lagi == 'Y') {
        int n;
        cout << "Masukkan nilai n: ";
        cin >> n;

        int anu = SelidikPrima(n);

        if (anu == 1) {
            cout << n << " adalah Bilangan Prima" << endl;
        } else {
            int f = n / anu;
            cout << n << " = " << anu << " x " << f << endl;
        }

        cout << "Lagi? (y/t): ";
        cin >> lagi;
    }

    return 0;
}
