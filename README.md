# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Vito Naryama Pramudito</p>

## Dasar Teori

Di pemrograman C++, kita bisa menyimpan dan mengatur data dengan beberapa cara, misalnya menggunakan array, pointer, dan reference. Array itu seperti rak tempat kita menaruh beberapa benda yang sejenis, jadi kita bisa mengakses setiap elemen dengan nomor urutnya. Pointer itu semacam penunjuk alamat, jadi kita bisa langsung mengubah atau membaca data dari lokasi memorinya. Reference mirip alias atau nama panggilan untuk variabel, jadi kalau kita ubah nilai lewat reference, variabel aslinya ikut berubah tanpa perlu tahu alamatnya. Untuk matriks, kita bisa menjumlahkan, mengurangi, atau mengalikan setiap elemen dengan bantuan array dua dimensi dan loop bersarang, sehingga semua elemen bisa terproses dengan rapi. Dengan pointer dan reference, kita jadi lebih fleksibel dalam mengatur data dan membuat kode lebih ringkas dan efisien.

## Guided 

### 1. [Array]

```C++
#include <iostream>
using namespace std;

int main()
{
    int arrID[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 Demensi : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "arr1D[" << i << "] = " << arrID[i] << endl;
    }
    cout << endl;

    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Array 2 Demensi : " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // ---Array Multi Demensi (3D)
    int arr3D[2][2][3] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };
    cout << "Array 3 Demensi : " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 3; k++){
                cout << "arr3D[" << i << "][" << j << "][" << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}

```
Kode ini menampilkan isi array satu dimensi, dua dimensi, dan tiga dimensi. Loop digunakan untuk menelusuri setiap elemen dan cout untuk mencetak nilainya, sehingga terlihat bagaimana data tersimpan dalam berbagai jenis array.

### 2. [Pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}

```
Memperkenalkan pointer yang menyimpan alamat variabel. Program menampilkan nilai dan alamat variabel, lalu menukar nilai dua variabel lewat alamatnya menggunakan function tukar. Ini menunjukkan manipulasi data secara langsung melalui memori.

### 3. [Reference]

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int &ref = a;

    cout << "Nilai a : " << a << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Nilai ref (alias a) : " << ref << endl;
    cout << "Alamat ref (&ref) : " << &ref << endl;

    // Mengubah nilai a lewat reference
    ref = 50;

    cout << "Setelah ref = 50" << endl;
    cout << "Nilai a : " << a << endl;
    cout << "Nilai ref : " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Menggunakan reference (alias untuk variabel) untuk menampilkan dan mengubah nilai variabel. Dengan reference, kita bisa menukar nilai dua variabel atau mengubah nilai variabel lewat aliasnya tanpa menggunakan pointer, sehingga kode lebih aman dan mudah dibaca.

## Unguided 

### 1. [Unguided1]

```C++
#include <iostream>
using namespace std;

const int Ukuran = 3; // Matriks berukuran 3x3

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
    for (int i = 0; i < Ukuran; i++)
        for (int j = 0; j < Ukuran; j++)
            Hasil[i][j] = X[i][j] + Y[i][j];
}

// Fungsi untuk mengurangkan dua matriks
void kurangkan(int X[Ukuran][Ukuran], int Y[Ukuran][Ukuran], int Hasil[Ukuran][Ukuran]) {
    for (int i = 0; i < Ukuran; i++)
        for (int j = 0; j < Ukuran; j++)
            Hasil[i][j] = X[i][j] - Y[i][j];
}

// Fungsi untuk mengalikan dua matriks
void kalikan(int X[Ukuran][Ukuran], int Y[Ukuran][Ukuran], int Hasil[Ukuran][Ukuran]) {
    for (int i = 0; i < Ukuran; i++) {
        for (int j = 0; j < Ukuran; j++) {
            Hasil[i][j] = 0;
            for (int k = 0; k < Ukuran; k++)
                Hasil[i][j] += X[i][k] * Y[k][j];
        }
    }
}

int main() {
    int matriks1[Ukuran][Ukuran], matriks2[Ukuran][Ukuran], hasil[Ukuran][Ukuran];

    // Input matriks pertama
    cout << "Masukkan elemen matriks pertama (3x3), tiap baris dipisah spasi:" << endl;
    for (int i = 0; i < Ukuran; i++) {
        cout << "Baris ke-" << i+1 << ": ";
        for (int j = 0; j < Ukuran; j++) {
            cin >> matriks1[i][j];
        }
    }

    // Input matriks kedua
    cout << "\nMasukkan elemen matriks kedua (3x3), tiap baris dipisah spasi:" << endl;
    for (int i = 0; i < Ukuran; i++) {
        cout << "Baris ke-" << i+1 << ": ";
        for (int j = 0; j < Ukuran; j++) {
            cin >> matriks2[i][j];
        }
    }

    // Tampilkan matriks
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

```
#### Output:
<img width="1839" height="481" alt="image" src="https://github.com/user-attachments/assets/ed041b9e-c34e-4636-af79-6334f18a98ae" />
<img width="1907" height="720" alt="image" src="https://github.com/user-attachments/assets/407a014c-e897-4200-acf7-d65b7ea63ed0" />

Program ini meminta pengguna memasukkan elemen matriks 3x3, lalu melakukan penjumlahan, pengurangan, dan perkalian matriks. Loop bersarang digunakan untuk memproses setiap elemen, sehingga memberi pemahaman tentang manipulasi data dalam matriks dua dimensi.

#### Full code Screenshot:
<img width="694" height="962" alt="image" src="https://github.com/user-attachments/assets/e191a825-50ff-492e-9565-784adc9d6683" />

### 2. [Unguided2]

```C++
#include <iostream>
using namespace std;

void tukarReference(int &a, int &b, int &c) {
    int temp = a;   // simpan nilai a
    a = b;          // a diganti nilai b
    b = c;          // b diganti nilai c
    c = temp;       // c diganti nilai awal a
}

int main() {
    int x = 100, y = 200, z = 300;

    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarReference(x, y, z);

    cout << "Sesudah ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}

```
#### Output:
<img width="1830" height="469" alt="image" src="https://github.com/user-attachments/assets/3a7f5bbc-828c-4f51-877f-560c87aff162" />

Menunjukkan cara menukar nilai tiga variabel sekaligus menggunakan reference. Nilai pertama disimpan sementara, kemudian digeser ke variabel berikutnya hingga semua nilai tertukar.

#### Full code Screenshot:
<img width="1453" height="753" alt="image" src="https://github.com/user-attachments/assets/9e2b108f-9012-4caf-9c05-95bd6ed6d7ae" />


### 3. [Unguided3]

```C++
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

//Hitung rata-rata
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

```
#### Output:
<img width="1856" height="573" alt="image" src="https://github.com/user-attachments/assets/074b013d-51c6-4ff7-99c3-5b49d277c581" />

Membuat menu interaktif untuk menampilkan isi array, mencari nilai maksimum, minimum, dan menghitung rata-rata. Switch-case dan loop do-while digunakan agar pengguna bisa memilih opsi berulang kali hingga keluar dari program.

#### Full code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ca6d10ca-1e93-414b-a8cb-cd897cb30005" />



## Kesimpulan
Dari semua codingan yang dibuat, bisa disimpulkan bahwa C++ memberikan banyak cara untuk menyimpan dan mengatur data dengan efisien. Array membantu menyimpan elemen secara teratur, baik satu dimensi maupun lebih dari satu dimensi. Pointer dan reference memudahkan kita untuk mengubah atau mengakses nilai variabel secara langsung atau melalui aliasnya. Operasi seperti penjumlahan, pengurangan, dan perkalian matriks bisa dilakukan dengan loop bersarang untuk memastikan semua elemen terproses. Penggunaan menu interaktif dan fungsi-fungsi terpisah juga membuat program lebih terstruktur dan mudah dipakai. Secara keseluruhan, latihan ini membantu memahami cara kerja data, variabel, dan struktur program di C++ dengan lebih jelas dan praktis.

## Referensi
[1] Jensen, T. (2003). A tutorial on pointers and arrays in C.
[2] NTU. (2025). C++ pointers and references. Nanyang Technological University.
[3] Rayana, S. (2018). Arrays and pointers. Stony Brook University.
