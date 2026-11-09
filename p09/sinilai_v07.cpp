#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// --- Prototipe 9 Fungsi ---
int bacaJumlah();
double bacaKomponen(string label);
string bacaNama();
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
string hurufMutu(double nilai_akhir);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void perbaruiPenghitung(char awal_huruf, int& jumlah_a, int& jumlah_b, int& jumlah_c, int& jumlah_d, int& jumlah_e);
void cetakSebaran(int jumlah_a, int jumlah_b, int jumlah_c, int jumlah_d, int jumlah_e);

int main() {
    cout << "=== SiNilai v0.7 ===\n";
    int jumlah_mahasiswa = bacaJumlah();

    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;

    double nilai_tertinggi = -1;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i << " dari " << jumlah_mahasiswa << " ---\n";
        bacaData(nama, npm, kehadiran, mingguan, uts, uas);

        double nilai_akhir = hitungNilaiAkhir(kehadiran, mingguan, uts, uas);
        string huruf = hurufMutu(nilai_akhir);
        bool lulus = (nilai_akhir >= 60);

        cetakBaris(nama, nilai_akhir, huruf, lulus);

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        perbaruiPenghitung(huruf[0], jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cetakSebaran(jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);

    return 0;
}

// --- Definisi Fungsi ---

// Membaca dan memvalidasi jumlah mahasiswa (paling sedikit 1)
int bacaJumlah() {
    int jumlah = 0;
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus berupa angka paling sedikit 1. Coba lagi: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');
    return jumlah;
}

// Membaca masukan komponen nilai numerik dengan validasi rentang 0-100
double bacaKomponen(string label) {
    double nilai = 0;
    cout << label << "  : ";
    cin >> nilai;
    while (cin.fail() || nilai < 0 || nilai > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus angka 0 sampai 100. Coba lagi: ";
        cin >> nilai;
    }
    return nilai;
}

// Membaca, memvalidasi, dan merapikan nama mahasiswa (Title Case)
string bacaNama() {
    string nama;
    bool sah = false;
    do {
        cout << "Nama       : ";
        getline(cin, nama);

        int panjang = static_cast<int>(nama.length());
        bool ada_huruf = false;
        bool ada_angka = false;

        for (int k = 0; k < panjang; k++) {
            if (nama[k] != ' ') {
                ada_huruf = true;
            }
            if (isdigit(nama[k])) {
                ada_angka = true;
            }
        }

        if (!ada_huruf) {
            cout << "Nama tidak boleh kosong.\n";
        } else if (ada_angka) {
            cout << "Nama tidak boleh mengandung angka.\n";
        } else {
            sah = true;
        }
    } while (!sah);

    int panjang = static_cast<int>(nama.length());
    bool awal_kata = true;
    for (int k = 0; k < panjang; k++) {
        if (nama[k] == ' ') {
            awal_kata = true;
        } else if (awal_kata) {
            nama[k] = static_cast<char>(toupper(nama[k]));
            awal_kata = false;
        } else {
            nama[k] = static_cast<char>(tolower(nama[k]));
        }
    }

    return nama;
}

// Membaca seluruh data satu mahasiswa (menggunakan 6 parameter referensi)
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas) {
    nama = bacaNama();
    cout << "NPM        : ";
    getline(cin, npm);

    kehadiran = bacaKomponen("Kehadiran");
    mingguan  = bacaKomponen("Mingguan");
    uts       = bacaKomponen("UTS");
    uas       = bacaKomponen("UAS");

    cin.ignore(1000, '\n');
}

// Menghitung Nilai Akhir berdasarkan bobot komponen
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas) {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN  = 0.45;
    const double BOBOT_UTS       = 0.25;
    const double BOBOT_UAS       = 0.20;

    return (kehadiran * BOBOT_KEHADIRAN) +
           (mingguan * BOBOT_MINGGUAN) +
           (uts * BOBOT_UTS) +
           (uas * BOBOT_UAS);
}

// Konversi nilai akhir ke huruf mutu
string hurufMutu(double nilai_akhir) {
    if (nilai_akhir >= 80) return "A";
    if (nilai_akhir >= 75) return "B+";
    if (nilai_akhir >= 70) return "B";
    if (nilai_akhir >= 65) return "C+";
    if (nilai_akhir >= 60) return "C";
    if (nilai_akhir >= 40) return "D";
    return "E";
}

// Mencetak satu baris ringkasan data mahasiswa
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus) {
    cout << "  " << left << setw(20) << nama
         << right << setw(7) << nilai_akhir
         << "  " << left << setw(3) << huruf
         << (lulus ? "Lulus" : "Belum lulus") << "\n";
}

// Memperbarui penghitung huruf mutu (menggunakan 5 parameter referensi)
void perbaruiPenghitung(char awal_huruf, int& jumlah_a, int& jumlah_b, int& jumlah_c, int& jumlah_d, int& jumlah_e) {
    switch (awal_huruf) {
        case 'A': jumlah_a++; break;
        case 'B': jumlah_b++; break;
        case 'C': jumlah_c++; break;
        case 'D': jumlah_d++; break;
        case 'E': jumlah_e++; break;
    }
}

// Mencetak grafik sebaran huruf mutu
void cetakSebaran(int jumlah_a, int jumlah_b, int jumlah_c, int jumlah_d, int jumlah_e) {
    cout << "\nSebaran huruf mutu\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') banyak = jumlah_a;
        else if (huruf == 'B') banyak = jumlah_b;
        else if (huruf == 'C') banyak = jumlah_c;
        else if (huruf == 'D') banyak = jumlah_d;
        else if (huruf == 'E') banyak = jumlah_e;

        cout << huruf << " ";
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
}