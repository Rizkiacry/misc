
// ZAIN AKBAR RIZKIA 202531091 C

#include <iostream> // i use vim btw
using namespace std;

// init gaji pokok berdasarkan kode golongan
// (1-4)
int tentukanGajiPokok(int kodeGolongan)
{
    // list gaji pokok per golongan
    int gajiPokok[4]
        = { 600000, 700000, 800000, 900000 };

    // validate kode golongan apakah berada di range
    // 1-4
    if (kodeGolongan >= 1 && kodeGolongan <= 4) {
        // return gaji sesuai indeks (kurangi 1
        // karena array mulai dari 0)
        return gajiPokok[kodeGolongan - 1];
    }
    return 0;
}

// input data nip, nama, dan golongan untuk jumlah
// karyawan
void inputData(char nip[][50], char nama[][50],
    int golongan[], int jumlahKaryawan)
{
    // loop pengambilan data setiap karyawan
    for (int i = 0; i < jumlahKaryawan; i++) {
        cout << "Masukkan NIP             : ";
        cin >> nip[i]; // input nip
        cout << "Masukkan Nama            : ";
        cin.ignore(); // flush buffer
        cin.getline(nama[i],
            50); // input nama lengkap dengan spasi
        cout << "Masukkan Kode Gol (1-4)  : ";
        cin >> golongan[i]; // input kode golongan
    }
}

// show tabel data karyawan beserta rincian gaji
void tampilData(char nip[][50], char nama[][50],
    int golongan[], int jumlahKaryawan)
{
    // header tabel output
    cout << "\nNIP\tNama\tGol\tGaji "
            "Pokok\tTunjangan\tNet Salary\n";

    // cetak data setiap karyawan
    for (int i = 0; i < jumlahKaryawan; i++) {
        // gaji pokok berdasarkan golongan
        int gp = tentukanGajiPokok(golongan[i]);
        // tunjangan (10% dari gaji pokok)
        int tj = (10 * gp) / 100;
        // gaji bersih (gaji pokok + tunjangan)
        int gb = gp + tj;

        // print
        cout << nip[i] << "\t" << nama[i] << "\t"
             << golongan[i] << "\t" << gp << "\t\t"
             << tj << "\t\t" << gb << endl;
    }
}

int main()
{
    int n;
    cout << "Masukkan jumlah karyawan: ";
    cin >> n; // input jumlah karyawan

    char nip[100][50];
    char nama[100][50];
    int golongan[100];

    // call function diatas
    inputData(nip, nama, golongan, n);
    tampilData(nip, nama, golongan, n);
}

