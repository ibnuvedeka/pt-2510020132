// SiNilai v0.6: Laporan kelas dengan validasi masukan aman dan perapian nama.
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;

    // TODO 1: Pembacaan jumlah_mahasiswa dengan validasi input aman
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah_mahasiswa;
    while (cin.fail() || jumlah_mahasiswa < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus berupa angka paling sedikit 1. Coba lagi: ";
        cin >> jumlah_mahasiswa;
    }
    // Buang Enter tersisa setelah membaca angka agar getline nama tidak terlewati
    cin.ignore(1000, '\n');

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

    cout << "\n--- Data Mahasiswa ---\n";
    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        cout << "\n--- Mahasiswa ke-" << i << " dari " << jumlah_mahasiswa << " ---\n";

        string nama;
        bool sah_nama = false;

        // TODO 2: Validasi nama tidak boleh kosong, hanya spasi, atau mengandung angka
        do {
            cout << "Nama       : ";
            getline(cin, nama);

            int panjang_nama = static_cast<int>(nama.length());
            bool ada_huruf = false;
            bool ada_angka = false;

            for (int k = 0; k < panjang_nama; k++) {
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
                sah_nama = true;
            }
        } while (!sah_nama);

        // TODO 3: Rapikan nama (Huruf Besar Di Awal Kata)
        int panjang_nama = static_cast<int>(nama.length());
        bool awal_kata = true;
        for (int k = 0; k < panjang_nama; k++) {
            if (nama[k] == ' ') {
                awal_kata = true;
            } else if (awal_kata) {
                nama[k] = static_cast<char>(toupper(nama[k]));
                awal_kata = false;
            } else {
                nama[k] = static_cast<char>(tolower(nama[k]));
            }
        }

        string npm;
        cout << "NPM        : ";
        getline(cin, npm);

        // TODO 4 & 5: Pembacaan komponen nilai dengan validasi angka aman (0 - 100)
        double kehadiran = 0;
        cout << "Kehadiran  : ";
        cin >> kehadiran;
        while (cin.fail() || kehadiran < 0 || kehadiran > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. Coba lagi: ";
            cin >> kehadiran;
        }

        double mingguan = 0;
        cout << "Mingguan   : ";
        cin >> mingguan;
        while (cin.fail() || mingguan < 0 || mingguan > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. Coba lagi: ";
            cin >> mingguan;
        }

        double uts = 0;
        cout << "UTS        : ";
        cin >> uts;
        while (cin.fail() || uts < 0 || uts > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. Coba lagi: ";
            cin >> uts;
        }

        double uas = 0;
        cout << "UAS        : ";
        cin >> uas;
        while (cin.fail() || uas < 0 || uas > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. Coba lagi: ";
            cin >> uas;
        }

        // Buang sisa Enter setelah masukan UAS agar pembacaan nama mahasiswa berikutnya tidak terganggu
        cin.ignore(1000, '\n');

        // Perhitungan Nilai Akhir
        double nilai_akhir = (kehadiran * BOBOT_KEHADIRAN) +
                             (mingguan * BOBOT_MINGGUAN) +
                             (uts * BOBOT_UTS) +
                             (uas * BOBOT_UAS);

        string huruf_mutu;
        if (nilai_akhir >= 80) {
            huruf_mutu = "A";
        } else if (nilai_akhir >= 75) {
            huruf_mutu = "B+";
        } else if (nilai_akhir >= 70) {
            huruf_mutu = "B";
        } else if (nilai_akhir >= 65) {
            huruf_mutu = "C+";
        } else if (nilai_akhir >= 60) {
            huruf_mutu = "C";
        } else if (nilai_akhir >= 40) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        bool lulus = (nilai_akhir >= 60);

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }

        switch (huruf_mutu[0]) {
            case 'A': jumlah_a++; break;
            case 'B': jumlah_b++; break;
            case 'C': jumlah_c++; break;
            case 'D': jumlah_d++; break;
            case 'E': jumlah_e++; break;
        }

        cout << "  " << left << setw(20) << nama
             << right << setw(7) << nilai_akhir
             << "  " << left << setw(3) << huruf_mutu
             << (lulus ? "Lulus" : "Belum lulus") << "\n";

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }
    }

    // Laporan Kelas
    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

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

    return 0;
}