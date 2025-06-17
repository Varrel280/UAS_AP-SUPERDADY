#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk memeriksa apakah array sudah urut naik
bool isSortedAscending(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

// Fungsi untuk melakukan rotasi kanan sekali
void rotateRight(vector<int>& arr) {
    int last = arr.back();
    for (int i = arr.size() - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan elemen array (dipisahkan spasi): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> original = arr; // Simpan versi asli
    int rotasi = 0;

    for (int i = 0; i < n; i++) {
        if (isSortedAscending(arr)) {
            cout << "Dilakukan operasi sebanyak: " << rotasi << " kali\n";
            return 0;
        }
        rotateRight(arr);
        rotasi++;
    }

    // Jika sudah dicoba sebanyak N kali tetapi tidak urut
    cout << "Tidak\n";
    return 0;
}
