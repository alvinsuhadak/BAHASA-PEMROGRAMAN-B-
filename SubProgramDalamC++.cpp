#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Tugas 1: Metode Newton-Raphson
double f(double x) {
    return 3 * exp(-0.25 * x) * cos(2 * x) - 1; // Fungsi f(x) = 3e^(-0.25x)cos(2x) - 1
}

double f_prime(double x) {
    return 3 * exp(-0.25 * x) * (-0.25 * cos(2 * x) - 2 * sin(2 * x)); // Turunan f(x)
}

double newton_raphson(double x0, double tol = 1e-6, int max_iter = 100) {
    double x = x0; // Nilai awal
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x); // Nilai fungsi
        double fp = f_prime(x); // Nilai turunan
        if (fp == 0) {
            cout << "Turunan nol. Metode Newton-Raphson gagal.\n";
            return x;
        }
        double x_new = x - fx / fp; // Iterasi baru
        if (abs(x_new - x) < tol) {
            return x_new; // Konvergen
        }
        x = x_new; // Perbarui x
    }
    cout << "Metode Newton-Raphson tidak konvergen dalam " << max_iter << " iterasi.\n";
    return x;
}

// Tugas 2: Segitiga Umar Khayyam
void generate_pascal(int n, int c[][23]) {
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1; // Elemen pertama setiap baris
        c[i][i] = 1; // Elemen terakhir setiap baris
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i-1][j-1] + c[i-1][j]; // Hitung koefisien binomial
        }
    }
}

void print_pascal(int n, int c[][23]) {
    for (int i = 0; i <= n; i++) {
        // Cetak spasi awal untuk perataan
        for (int s = 0; s < n - i; s++) {
            cout << "     ";
        }
        // Cetak koefisien
        for (int j = 0; j <= i; j++) {
            cout << setw(5) << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Tugas 1: Mencari akar positif
    cout << "Tugas 1: Akar dari 3e^(-0.25x)cos(2x) - 1 = 0\n";
    double initial_guesses[] = {0.6155, 2.186, 3.757, 5.328}; // Tebakan awal
    int num_guesses = 4;
    for (int i = 0; i < num_guesses; i++) {
        double root = newton_raphson(initial_guesses[i]);
        if (root > 0) {
            cout << "Akar " << i+1 << ": x = " << fixed << setprecision(6) << root << endl;
        }
    }

    cout << "\nTugas 2: Segitiga Umar Khayyam (n = 11)\n";
    // Tugas 2: Membuat dan mencetak segitiga Pascal
    int n = 11;
    int c[23][23] = {0}; // Inisialisasi array
    generate_pascal(n, c);
    print_pascal(n, c);

    return 0;
}
