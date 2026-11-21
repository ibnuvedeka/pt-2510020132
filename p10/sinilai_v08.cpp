// SiNilai v0.8: Menyimpan dan mengolah data mahasiswa dalam larik sejajar lewat fungsi.
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

const int MAKS = 50;

// --- Prototipe Fungsi v0.7 ---
int bacaJumlah();
double bacaKomponen(string label);
string bacaNama();
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
string hurufMutu(double nilai_akhir);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void perbaruiPenghitung(char awal_huruf, int& jumlah_a, int& jumlah_b, int& jumlah_c, int& jumlah_d, int& jumlah_e);
void cetakSebaran(int jumlah_a, int jumlah_b, int jumlah_c, int jumlah_d, int jumlah_e);

// --- Prototipe Fungsi Tukar & 6 Fungsi Baru v0.8 ---
void tukarAngka(double& a, double& b);
void tukarTeks(string& a, string& b);
double rerataKelas(const double nilai_akhir[], int jumlah);
int hitungLulus(const double nilai_akhir[], int jumlah);
int indeksTertinggi(const double nilai_akhir[], int mulai, int jumlah);
void urutkanMenurun(string nama[], string npm[], double nilai_akhir[], string huruf[], int jumlah);
void cetakPeringkat(const string nama[], const string npm[], const double nilai_akhir[], const string huruf[], int jumlah);
void hitungSebaran(const string huruf[], int jumlah, int& jumlah_a, int& jumlah_b, int& jumlah_c, int& jumlah_d, int& jumlah_e);

int main() {
    cout << "=== SiNilai v0.8 ===\n";
    int jumlah_mahasiswa = bacaJumlah();

    cout << fixed << setprecision(2);

    string nama[MAKS];
    string npm[MAKS];
    double nilai_akhir[MAKS] = {};
    string huruf[MAKS];

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i + 1 << " dari " << jumlah_mahasiswa << " ---\n";
        bacaData(nama[i], npm[i], kehadiran, mingguan, uts, uas);

        nilai_akhir[i] = hitungNilaiAkhir(kehadiran, mingguan, uts, uas);
        huruf[i] = hurufMutu(nilai_akhir[i]);

        cetakBaris(nama[i], nilai_akhir[i], huruf[i], nilai_akhir[i] >= 60);
    }

    urutkanMenurun(nama, npm, nilai_akhir, huruf, jumlah_mahasiswa);
    cetakPeringkat(nama, npm, nilai_akhir, huruf, jumlah_mahasiswa);

    int jumlah_lulus = hitungLulus(nilai_akhir, jumlah_mahasiswa);

    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;
    hitungSebaran(huruf, jumlah_mahasiswa, jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << rerataKelas(nilai_akhir, jumlah_mahasiswa) << "\n";
    cout << "Tertinggi        : " << nama[0] << " (" << nilai_akhir[0] << ")\n";

    cetakSebaran(jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);

    return 0;
}

// --- Definisi Fungsi v0.7 ---

// Membaca dan memvalidasi jumlah mahasiswa (1 sampai MAKS)
int bacaJumlah() {
    int jumlah = 0;
    cout << "Jumlah mahasiswa (1 sampai " << MAKS << "): ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1 || jumlah > MAKS) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus angka 1 sampai " << MAKS << ". Coba lagi: ";
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
    if (nilai_akhir >= 80) {
        return "A";
    }
    if (nilai_akhir >= 75) {
        return "B+";
    }
    if (nilai_akhir >= 70) {
        return "B";
    }
    if (nilai_akhir >= 65) {
        return "C+";
    }
    if (nilai_akhir >= 60) {
        return "C";
    }
    if (nilai_akhir >= 40) {
        return "D";
    }
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
        case 'A':
            jumlah_a++;
            break;
        case 'B':
            jumlah_b++;
            break;
        case 'C':
            jumlah_c++;
            break;
        case 'D':
            jumlah_d++;
            break;
        case 'E':
            jumlah_e++;
            break;
    }
}

// Mencetak grafik sebaran huruf mutu
void cetakSebaran(int jumlah_a, int jumlah_b, int jumlah_c, int jumlah_d, int jumlah_e) {
    cout << "\nSebaran huruf mutu\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else if (huruf == 'E') {
            banyak = jumlah_e;
        }

        cout << huruf << " ";
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
}

// --- Definisi Fungsi Tukar & 6 Fungsi Baru v0.8 ---

// Menukar dua nilai bertipe double
void tukarAngka(double& a, double& b) {
    double sementara = a;
    a = b;
    b = sementara;
}

// Menukar dua nilai bertipe string
void tukarTeks(string& a, string& b) {
    string sementara = a;
    a = b;
    b = sementara;
}

// Menghitung rata-rata nilai akhir kelas dari larik (hanya membaca)
double rerataKelas(const double nilai_akhir[], int jumlah) {
    if (jumlah <= 0) {
        return 0.0;
    }
    double total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += nilai_akhir[i];
    }
    return total / jumlah;
}

// Menghitung banyaknya mahasiswa yang lulus (nilai_akhir >= 60)
int hitungLulus(const double nilai_akhir[], int jumlah) {
    int lulus = 0;
    for (int i = 0; i < jumlah; i++) {
        if (nilai_akhir[i] >= 60) {
            lulus++;
        }
    }
    return lulus;
}

// Mencari indeks nilai tertinggi mulai dari kotak indeks 'mulai'
int indeksTertinggi(const double nilai_akhir[], int mulai, int jumlah) {
    int tertinggi = mulai;
    for (int i = mulai + 1; i < jumlah; i++) {
        if (nilai_akhir[i] > nilai_akhir[tertinggi]) {
            tertinggi = i;
        }
    }
    return tertinggi;
}

// Mengurutkan keempat larik sejajar secara menurun menggunakan selection sort
void urutkanMenurun(string nama[], string npm[], double nilai_akhir[], string huruf[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int t = indeksTertinggi(nilai_akhir, i, jumlah);
        if (t != i) {
            tukarAngka(nilai_akhir[i], nilai_akhir[t]);
            tukarTeks(nama[i], nama[t]);
            tukarTeks(npm[i], npm[t]);
            tukarTeks(huruf[i], huruf[t]);
        }
    }
}

// Mencetak daftar peringkat kelas terurut
void cetakPeringkat(const string nama[], const string npm[], const double nilai_akhir[], const string huruf[], int jumlah) {
    cout << "\n=== Peringkat Kelas ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << right << setw(2) << i + 1 << ". "
             << npm[i] << "  "
             << left << setw(20) << nama[i]
             << right << setw(7) << nilai_akhir[i] << "  "
             << huruf[i] << "\n";
    }
}

// Menghitung sebaran huruf mutu dari larik huruf ke lima penghitung referensi
void hitungSebaran(const string huruf[], int jumlah, int& jumlah_a, int& jumlah_b, int& jumlah_c, int& jumlah_d, int& jumlah_e) {
    for (int i = 0; i < jumlah; i++) {
        if (!huruf[i].empty()) {
            perbaruiPenghitung(huruf[i][0], jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);
        }
    }
}