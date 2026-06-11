// ZAIN AKBAR RIZKIA 202531091 C

#include <iostream> // i use vim btw
using namespace std;

// --- Tambahan: struct sederhana untuk data mahasiswa ---
struct Mahasiswa {
    char nama[100];
    char nim[20];
    char kelas[10];
};

Mahasiswa mhs;  // variabel global bertipe struct
// --------------------------------------------------------

void tampilkanIdentitas() {
    cout << "--- Data Diri ---" << endl;
    cout << "Nama  : " << mhs.nama << endl;
    cout << "NIM   : " << mhs.nim << endl;
    cout << "Kelas : " << mhs.kelas << endl;
    // cetak data diri yang diinput user
    cout << endl;
}

void tampilkanArray(int arr[], int n) {
    cout << "Isi elemen array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // loop isi elemen array 1 per satu
    cout << endl << endl;
}

void cariMinMax(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // bandingkan isi array buat cari min dan max

    cout << "Nilai Terkecil : " << min << endl;
    cout << "Nilai Terbesar : " << max << endl;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float avg = total / n;
    // total dibagi n buat cari average
    cout << "Nilai Rata-rata : " << avg << endl;
}

int main() {
    cout << "Masukkan Nama  : ";
    cin.getline(mhs.nama, 100);
    // simpan nama user ke variabel global struct
    cout << "Masukkan NIM   : ";
    cin.getline(mhs.nim, 20);
    cout << "Masukkan Kelas : ";
    cin.getline(mhs.kelas, 10);

    cout << endl;

    int n;
    cout << "Masukkan ukuran array (n): ";
    cin >> n;
    // input ukuran array

    int angka[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan angka ke-" << i + 1 << " : ";
        cin >> angka[i];
    }
    // input array n kali sesuai ukuran n

    cout << endl;

    tampilkanIdentitas();
    tampilkanArray(angka, n);
    cariMinMax(angka, n);
    hitungRataRata(angka, n);
    // panggil fungsi proses array dan identitas

    // --- Tambahan: array 2D sederhana ---
    int baris, kolom;
    cout << "\nMasukkan jumlah baris matriks: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom matriks: ";
    cin >> kolom;

    int matriks[baris][kolom];  // deklarasi array 2D (VLA)

    cout << "Masukkan elemen matriks:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }

    cout << "\nMatriks yang diinput:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    // ---------------------------------

    return 0;
}
