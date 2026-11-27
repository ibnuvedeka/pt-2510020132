#include <iostream>
#include <string>

using namespace std;

const int MAKS_CUCIAN = 50;
const int HARGA_PER_KG = 7000;

// Prototipe fungsi sesuai Tabel Fungsi pada rancangan.md
int bacaBulat(string label, int bawah, int atas);
double bacaBerat(string label);
void tampilkanCucian(const string nama[], const double berat[], const int status[], int jumlah);
int cariIndeksTerberat(const double berat[], int jumlah);
void cetakRekap(const string nama[], const double berat[], const int status[], int jumlah);
void terimaCucian(string nama[], double berat[], int status[], int &jumlah);
void tandaiSelesai(const string nama[], const double berat[], int status[], int jumlah);
void ambilCucian(const string nama[], const double berat[], int status[], int jumlah);

int main() {
    string nama[MAKS_CUCIAN];
    double berat[MAKS_CUCIAN] = {};
    int status[MAKS_CUCIAN] = {};
    int jumlah = 0;
    int pilihan = 0;

    do {
        cout << "\n=== Kasir dan Pencatatan Laundry ===\n";
        cout << "1. Lihat daftar cucian\n";
        cout << "2. Terima cucian masuk\n";
        cout << "3. Tandai cucian selesai\n";
        cout << "4. Ambil cucian\n";
        cout << "5. Rekap harian\n";
        cout << "0. Selesai\n";
        pilihan = bacaBulat("Pilihan", 0, 5);

        switch (pilihan) {
            case 1:
                tampilkanCucian(nama, berat, status, jumlah);
                break;
            case 2:
                terimaCucian(nama, berat, status, jumlah);
                break;
            case 3:
                tandaiSelesai(nama, berat, status, jumlah);
                break;
            case 4:
                ambilCucian(nama, berat, status, jumlah);
                break;
            case 5:
                cetakRekap(nama, berat, status, jumlah);
                break;
            default:
                cout << "Kasir laundry ditutup. Terima kasih.\n";
        }
    } while (pilihan != 0);

    return 0;
}

// Stub Tahap 1: membaca angka menu tanpa validasi dulu (dirinci pada Tahap 2)
int bacaBulat(string label, int bawah, int atas) {
    int nilai = 0;
    cout << label << ": ";
    cin >> nilai;
    return nilai;
}

// Pengganti sementara (stub)
double bacaBerat(string label) {
    cout << "[belum dirinci] bacaBerat\n";
    return 0.0;
}

// Pengganti sementara (stub)
void tampilkanCucian(const string nama[], const double berat[], const int status[], int jumlah) {
    cout << "[belum dirinci] tampilkanCucian\n";
}

// Pengganti sementara (stub)
int cariIndeksTerberat(const double berat[], int jumlah) {
    cout << "[belum dirinci] cariIndeksTerberat\n";
    return 0;
}

// Pengganti sementara (stub)
void cetakRekap(const string nama[], const double berat[], const int status[], int jumlah) {
    cout << "[belum dirinci] cetakRekap\n";
}

// Pengganti sementara (stub)
void terimaCucian(string nama[], double berat[], int status[], int &jumlah) {
    cout << "[belum dirinci] terimaCucian\n";
}

// Pengganti sementara (stub)
void tandaiSelesai(const string nama[], const double berat[], int status[], int jumlah) {
    cout << "[belum dirinci] tandaiSelesai\n";
}

// Pengganti sementara (stub)
void ambilCucian(const string nama[], const double berat[], int status[], int jumlah) {
    cout << "[belum dirinci] ambilCucian\n";
}