#include <iostream>
using namespace std;

const int N = 10;
int arrA[N] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

// Fungsi cari nilai maksimum
int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

// Fungsi cari nilai minimum
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Prosedur hitung rata-rata
void hitungRataRata(int arr[], int n) {
    float jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    float rata = jumlah / n;
    cout << "Nilai rata-rata = " << rata << endl;
}

// Fungsi menampilkan isi array
void tampilkanArray(int arr[], int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                tampilkanArray(arrA, N);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, N) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, N) << endl;
                break;
            case 4:
                hitungRataRata(arrA, N);
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
