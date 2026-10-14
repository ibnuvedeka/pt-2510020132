// SiNilai v0.5: Laporan kelas dengan keluaran berkolom, mahasiswa tertinggi, dan sebaran huruf mutu.
#include <iostream>
#include <string>
#include <iomanip> // Diperlukan untuk pengaturan format berkolom (setw, setprecision, dll.)

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;
    
    // Membaca jumlah mahasiswa dengan batas minimal 1
    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        cin >> jumlah_mahasiswa;
    } while (jumlah_mahasiswa < 1);

    // TODO 1: Atur cout agar semua angka pecahan tampil dengan dua angka di belakang koma
    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    // TODO 2: Deklarasikan lima penghitung huruf mutu (mulai dari 0)
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;

    // TODO 3: Deklarasikan penyimpan nilai tertinggi (dimulai -1) dan nama tertinggi
    double nilai_tertinggi = -1;
    string nama_tertinggi;

    cout << "\n--- Data Mahasiswa ---\n";
    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0, mingguan = 0, uts = 0, uas = 0;

        // Baca input data mahasiswa
        getline(cin >> ws, nama);
        cin >> npm >> kehadiran >> mingguan >> uts >> uas;

        // Perhitungan nilai akhir
        double nilai_akhir = (kehadiran * BOBOT_KEHADIRAN) + 
                             (mingguan * BOBOT_MINGGUAN) + 
                             (uts * BOBOT_UTS) + 
                             (uas * BOBOT_UAS);

        // if-else bertingkat huruf mutu
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

        bool lulus = nilai_akhir >= 60;

        // TODO 6: Pola "ingat yang terbesar sejauh ini"
        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }

        // TODO 5: switch untuk mengisi penghitung huruf
        switch (huruf_mutu[0]) {
            case 'A': jumlah_a++; break;
            case 'B': jumlah_b++; break; // B+ dan B sama-sama masuk ke 'B'
            case 'C': jumlah_c++; break; // C+ dan C sama-sama masuk ke 'C'
            case 'D': jumlah_d++; break;
            case 'E': jumlah_e++; break;
        }

        // TODO 4: Cetak satu baris berkolom untuk mahasiswa ini
        cout << "  " << left << setw(20) << nama 
             << right << setw(7) << nilai_akhir 
             << "  " << left << setw(3) << huruf_mutu 
             << (lulus ? "Lulus" : "Belum lulus") << "\n";

        // Akumulator
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
    
    // TODO 7: Cetak baris nilai tertinggi
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    // TODO 8 & 9: Perulangan bersarang untuk Sebaran huruf mutu
    cout << "\nSebaran huruf mutu\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        
        if (huruf == 'A') banyak = jumlah_a;
        else if (huruf == 'B') banyak = jumlah_b;
        else if (huruf == 'C') banyak = jumlah_c;
        else if (huruf == 'D') banyak = jumlah_d;
        else if (huruf == 'E') banyak = jumlah_e;

        cout << huruf << " ";
        
        // Perulangan dalam: cetak batang pagar '#' sebanyak variabel banyak
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        
        cout << " " << banyak << "\n";
    }

    return 0;
}