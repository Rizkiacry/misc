// ZAIN AKBAR RIZKIA 202531091 C

#include "string.h" // termux g++ helper, remove on
                    // windows
#include <iostream>
#include <string.h> // i use vim btw
using namespace std;

void materi1()
{
    char input[100];
    char label[100];
    char temp[100];

    strcpy(label,
        "lab dasar"); // copy string "lab dasar" ke
                      // array label[]
    cout << label << endl;
    cout << "Input Karakter -> ";
    cin.getline(input, 100);

    int len
        = strlen(input); // hitung panjang input[]
                         // dan simpan ke len
    cout << "Karakter yang diinput : " << input
         << endl;
    cout << "Panjang Karakter : " << len << endl;

    strcpy(
        temp, input); // copy isi input[] ke temp[]
    cout << "Karakter dibalik : " << strrev(temp)
         << endl;
    // balik urutan karakter dalam string (pakai
    // helper string.h)

    strcpy(temp, input);
    cout << "Karakter diubah ke huruf besar : "
         << strupr(temp) << endl;
    // ubah semua huruf jadi kapital (pakai helper
    // string.h)

    strcpy(temp, input);
    cout << "Karakter diubah ke huruf kecil : "
         << strlwr(temp) << endl;
    // ubah semua huruf jadi huruf kecil

    if (strcmp(input, "lab dasar") == 0) {
        cout << "Input matches label 'lab dasar'."
             << endl;
        // strcmp == 0 artinya string sama persis;
        // cocok dengan label "lab dasar"
    }

    if (strstr(input, "lab") != NULL) {
        cout << "Substring 'lab' found in input."
             << endl;
        // strstr cari substring "lab" di dalam
        // input; jika ada, return pointer BUKAN
        // null
    }

    strcpy(temp, input);
    strcat(temp, "!");
    cout << "Concatenated with '!' : " << temp
         << endl;
    // gabungkan string input dengan tanda seru di
    // akhir

    cout << endl;

    strcpy(temp, input);
    strupr(temp);
    // ulangi cetak bertingkat baris naik
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            cout << temp[j];
        }
        cout << endl;
    }
    // cetak karakter 1 per satu dari awal hingga
    // ke-i tangga naik

    strcpy(temp, input);
    strlwr(temp);
    // ulangi cetak bertingkat baris turun
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << temp[j];
        }
        cout << endl;
    }
    // huruf dikurangi tiap barisnya tangga turun
}

int main() {
  materi1();
}
