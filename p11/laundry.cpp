#include <iomanip>
#include <iostream>
#include <limits>
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

// Membaca masukan bilangan bulat dalam rentang bawah..atas sampai valid
int bacaBulat(string label, int bawah, int atas) {
    int nilai = 0;
    while (true) {
        cout << label << ": ";
        if (cin >> nilai && nilai >= bawah && nilai <= atas) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
        if (cin.eof()) {
            return bawah;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Harus bilangan bulat " << bawah << " sampai " << atas << ". ";
    }
}

// Membaca masukan bilangan desimal positif untuk berat cucian sampai valid
double bacaBerat(string label) {
    double nilai = 0.0;
    while (true) {
        cout << label << ": ";
        if (cin >> nilai && nilai > 0.0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
        if (cin.eof()) {
            return 0.0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Harus bilangan desimal lebih dari 0. ";
    }
}

// Mencetak daftar seluruh cucian lengkap dengan nomor, nama, berat, dan status
void tampilkanCucian(const string nama[], const double berat[], const int status[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data cucian.\n";
        return;
    }

    cout << "\n--- Daftar Cucian ---\n";
    cout << left << setw(4) << "No"
         << setw(20) << "Pelanggan"
         << right << setw(10) << "Berat(kg)"
         << "  " << left << setw(12) << "Status" << "\n";

    cout << fixed << setprecision(1);
    for (int i = 0; i < jumlah; i++) {
        string teks_status = "Diproses";
        if (status[i] == 1) {
            teks_status = "Selesai";
        } else if (status[i] == 2) {
            teks_status = "Diambil";
        }

        cout << left << setw(4) << (i + 1)
             << setw(20) << nama[i]
             << right << setw(10) << berat[i]
             << "  " << left << setw(12) << teks_status << "\n";
    }
}

// Mengembalikan indeks cucian dengan bobot kilogram paling besar
int cariIndeksTerberat(const double berat[], int jumlah) {
    int indeks_maks = 0;
    for (int i = 1; i < jumlah; i++) {
        if (berat[i] > berat[indeks_maks]) {
            indeks_maks = i;
        }
    }
    return indeks_maks;
}

// Menampilkan ringkasan total berat, pendapatan harian, dan cucian terberat
void cetakRekap(const string nama[], const double berat[], const int status[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data cucian.\n";
        return;
    }

    double total_berat = 0.0;
    int selesai_atau_diambil = 0;
    for (int i = 0; i < jumlah; i++) {
        total_berat += berat[i];
        if (status[i] >= 1) {
            selesai_atau_diambil++;
        }
    }

    long long total_pendapatan = static_cast<long long>(total_berat * HARGA_PER_KG + 0.5);
    int terberat = cariIndeksTerberat(berat, jumlah);

    cout << "\n--- Rekap Harian Laundry ---\n";
    cout << fixed << setprecision(1);
    cout << "Jumlah transaksi : " << jumlah << " (" << selesai_atau_diambil << " selesai/diambil)\n";
    cout << "Total berat      : " << total_berat << " kg\n";
    cout << "Total pendapatan : Rp" << total_pendapatan << "\n";
    cout << "Cucian terberat  : " << nama[terberat] << " (" << berat[terberat] << " kg)\n";
}

// Menambahkan data cucian baru ke posisi terakhir larik sejajar jika kapasitas tersedia
void terimaCucian(string nama[], double berat[], int status[], int &jumlah) {
    if (jumlah >= MAKS_CUCIAN) {
        cout << "Kapasitas penyimpanan cucian harian sudah penuh (" << MAKS_CUCIAN << " data).\n";
        return;
    }

    string nama_pelanggan;
    while (true) {
        cout << "Nama pelanggan: ";
        if (!getline(cin, nama_pelanggan)) {
            return;
        }
        if (!nama_pelanggan.empty()) {
            break;
        }
        cout << "Nama pelanggan tidak boleh kosong. ";
    }

    double berat_cucian = bacaBerat("Berat cucian (kg)");
    if (berat_cucian <= 0.0) {
        return;
    }

    nama[jumlah] = nama_pelanggan;
    berat[jumlah] = berat_cucian;
    status[jumlah] = 0;
    jumlah++;

    long long estimasi_biaya = static_cast<long long>(berat_cucian * HARGA_PER_KG + 0.5);
    cout << fixed << setprecision(1);
    cout << "Cucian atas nama " << nama_pelanggan << " (" << berat_cucian
         << " kg) tercatat. Estimasi biaya: Rp" << estimasi_biaya << "\n";
}

// Mengubah status cucian yang dipilih petugas dari diproses menjadi selesai
void tandaiSelesai(const string nama[], const double berat[], int status[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data cucian.\n";
        return;
    }

    tampilkanCucian(nama, berat, status, jumlah);
    int nomor = bacaBulat("Nomor cucian selesai (0 batal)", 0, jumlah);
    if (nomor == 0) {
        return;
    }

    int i = nomor - 1;
    if (status[i] == 0) {
        status[i] = 1;
        cout << "Status cucian " << nama[i] << " diperbarui menjadi Selesai.\n";
    } else if (status[i] == 1) {
        cout << "Cucian " << nama[i] << " sudah berstatus Selesai.\n";
    } else {
        cout << "Cucian " << nama[i] << " sudah diambil pelanggan.\n";
    }
}

// Mengubah status cucian yang sudah selesai menjadi telah diambil oleh pelanggan
void ambilCucian(const string nama[], const double berat[], int status[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data cucian.\n";
        return;
    }

    tampilkanCucian(nama, berat, status, jumlah);
    int nomor = bacaBulat("Nomor cucian diambil (0 batal)", 0, jumlah);
    if (nomor == 0) {
        return;
    }

    int i = nomor - 1;
    if (status[i] == 1) {
        status[i] = 2;
        long long biaya = static_cast<long long>(berat[i] * HARGA_PER_KG + 0.5);
        cout << fixed << setprecision(1);
        cout << "Cucian " << nama[i] << " (" << berat[i]
             << " kg) telah diambil. Total bayar: Rp" << biaya << "\n";
    } else if (status[i] == 0) {
        cout << "Cucian " << nama[i] << " masih diproses, belum dapat diambil.\n";
    } else {
        cout << "Cucian " << nama[i] << " sudah diambil sebelumnya.\n";
    }
}