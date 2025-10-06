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
