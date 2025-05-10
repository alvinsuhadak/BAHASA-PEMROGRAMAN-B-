#include <iostream>
#include <cmath>
using namespace std;

bool Primakah(unsigned long long n) {
    if (n <= 1) return false; // 0 dan 1 bukan prima
    if (n == 2) return true; // 2 adalah prima
    if (n % 2 == 0) return false; // Bilangan genap > 2 bukan prima
    for (unsigned long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false; // Jika habis dibagi bilangan ganjil, bukan prima
    }
    return true; // Tidak ada pembagi, bilangan prima
}

int main() {
    unsigned long long anu;
    while (1) {
        cout << "Ketik Bilangan Bulat: ";
        cin >> anu;
        if (Primakah(anu)) {
            cout << anu << ": Bilangan prima\n";
        } else {
            cout << anu << ": Bukan bilangan prima\n";
        }
        string jawab;
        cout << "Lagi (y / t): ";
        cin >> jawab;
        if (jawab == "t") break;
    }
    return 0;
}
