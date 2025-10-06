#include <iostream>
using namespace std;

const int Ukuran = 3;

// Prosedur untuk menampilkan isi matriks
void cetakMatriks(int M[Ukuran][Ukuran]) {
    for (int baris = 0; baris < Ukuran; baris++) {
        for (int kolom = 0; kolom < Ukuran; kolom++) {
            cout << M[baris][kolom] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menjumlahkan dua matriks
void jumlahkan(int X[Ukuran][Ukuran], int Y[Ukuran][Ukuran], int Hasil[Ukuran][Ukuran]) {
    for (int i = 0; i < Ukuran; i++) {
        for (int j = 0; j < Ukuran; j++) {
            Hasil[i][j] = X[i][j] + Y[i][j];
        }
    }
}

// Fungsi untuk mengurangkan dua matriks
void kurangkan(int X[Ukuran][Ukuran], int Y[Ukuran][Ukuran], int Hasil[Ukuran][Ukuran]) {
    for (int i = 0; i < Ukuran; i++) {
        for (int j = 0; j < Ukuran; j++) {
            Hasil[i][j] = X[i][j] - Y[i][j];
        }
    }
}

// Fungsi untuk mengalikan dua matriks
void kalikan(int X[Ukuran][Ukuran], int Y[Ukuran][Ukuran], int Hasil[Ukuran][Ukuran]) {
    for (int i = 0; i < Ukuran; i++) {
        for (int j = 0; j < Ukuran; j++) {
            Hasil[i][j] = 0;
            for (int k = 0; k < Ukuran; k++) {
                Hasil[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

int main() {
    int matriks1[Ukuran][Ukuran], matriks2[Ukuran][Ukuran], hasil[Ukuran][Ukuran];

    // Input data matriks pertama
    cout << "Masukkan elemen matriks pertama (3x3), tiap baris dipisah spasi:" << endl;
    for (int i = 0; i < Ukuran; i++) {
        cout << "Baris ke-" << i+1 << ": ";
        for (int j = 0; j < Ukuran; j++) {
            cin >> matriks1[i][j];
        }
    }

    // Input data matriks kedua
    cout << "\nMasukkan elemen matriks kedua (3x3), tiap baris dipisah spasi:" << endl;
    for (int i = 0; i < Ukuran; i++) {
        cout << "Baris ke-" << i+1 << ": ";
        for (int j = 0; j < Ukuran; j++) {
            cin >> matriks2[i][j];
        }
    }

    // Tampilkan kedua matriks
    cout << "\nMatriks Pertama:" << endl;
    cetakMatriks(matriks1);

    cout << "\nMatriks Kedua:" << endl;
    cetakMatriks(matriks2);

    // Operasi penjumlahan
    jumlahkan(matriks1, matriks2, hasil);
    cout << "\nHasil Penjumlahan:" << endl;
    cetakMatriks(hasil);

    // Operasi pengurangan
    kurangkan(matriks1, matriks2, hasil);
    cout << "\nHasil Pengurangan:" << endl;
    cetakMatriks(hasil);

    // Operasi perkalian
    kalikan(matriks1, matriks2, hasil);
    cout << "\nHasil Perkalian:" << endl;
    cetakMatriks(hasil);

    return 0;
}
