#include <iostream>
#include <string>

using namespace std;

int bacaBulat(string label, int bawah, int atas);
int faktorial(int n);
int jumlahDeret(int n);
int pangkat(int basis, int n);
bool palindrom(string s, int kiri, int kanan);
void hanoi(int n, char dari, char ke, char bantu, int& langkah);
int cariBiner(const int a[], int kiri, int kanan, int dicari);

int main() {
    const int JUMLAH = 8;
    int terurut[JUMLAH] = {3, 8, 15, 21, 27, 34, 42, 50};

    int pilihan = 0;
    do {
        cout << "\n=== Laboratorium Rekursi ===\n";
        cout << "1. Faktorial dan deret\n";
        cout << "2. Pangkat\n";
        cout << "3. Palindrom\n";
        cout << "4. Menara Hanoi\n";
        cout << "5. Pencarian biner\n";
        cout << "0. Selesai\n";
        pilihan = bacaBulat("Pilihan", 0, 5);

        switch (pilihan) {
            case 1: {
                int n = bacaBulat("n (0 sampai 12)", 0, 12);
                cout << n << "! = " << faktorial(n) << ", 1 + ... + " << n << " = " << jumlahDeret(n) << "\n";
                break;
            }
            case 2: {
                int basis = bacaBulat("Basis (1 sampai 9)", 1, 9);
                int n = bacaBulat("Pangkat (0 sampai 9)", 0, 9);
                cout << basis << "^" << n << " = " << pangkat(basis, n) << "\n";
                break;
            }
            case 3: {
                string kata;
                cout << "Kata (tanpa spasi): ";
                cin >> kata;
                if (palindrom(kata, 0, kata.length() - 1)) {
                    cout << kata << " adalah palindrom\n";
                } else {
                    cout << kata << " bukan palindrom\n";
                }
                break;
            }
            case 4: {
                int n = bacaBulat("Banyak cakram (1 sampai 8)", 1, 8);
                int langkah = 0;
                hanoi(n, 'A', 'C', 'B', langkah);
                cout << "Total " << langkah << " langkah\n";
                break;
            }
            case 5: {
                cout << "Larik terurut: ";
                for (int i = 0; i < JUMLAH; i++) {
                    cout << terurut[i] << " ";
                }
                cout << "\n";
                int dicari = bacaBulat("Angka yang dicari", 0, 99);
                int posisi = cariBiner(terurut, 0, JUMLAH - 1, dicari);
                if (posisi == -1) {
                    cout << dicari << " tidak ada\n";
                } else {
                    cout << dicari << " ada di indeks " << posisi << "\n";
                }
                break;
            }
            default:
                cout << "Sampai jumpa.\n";
        }
    } while (pilihan != 0);
    return 0;
}

int bacaBulat(string label, int bawah, int atas) {
    int n = 0;
    cout << label << ": ";
    cin >> n;
    while (cin.fail() || n < bawah || n > atas) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat " << bawah << " sampai " << atas << ". " << label << ": ";
        cin >> n;
    }
    return n;
}

// Dua contoh yang sudah jadi: pola base case lalu recursive case.
int faktorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

int jumlahDeret(int n) {
    if (n == 0) {
        return 0;
    }
    return n + jumlahDeret(n - 1);
}

// TODO 1: basis^0 = 1 (base case); basis^n = basis * basis^(n-1) (recursive case).
int pangkat(int basis, int n) {
    if (n == 0) {
        return 1;
    }
    return basis * pangkat(basis, n - 1);
}

// TODO 2: kiri >= kanan berarti kosong atau satu huruf: palindrom. Kalau s[kiri] != s[kanan]:
// bukan. Selain itu, jawabannya sama dengan palindrom bagian tengah (kiri + 1, kanan - 1).
bool palindrom(string s, int kiri, int kanan) {
    if (kiri >= kanan) {
        return true;
    }
    if (s[kiri] != s[kanan]) {
        return false;
    }
    return palindrom(s, kiri + 1, kanan - 1);
}

// TODO 3: n == 0 tidak melakukan apa-apa. Selain itu: pindahkan n-1 cakram dari 'dari' ke
// 'bantu' (memakai 'ke' sebagai bantu), tambah langkah dan cetak "Langkah k: pindahkan cakram n
// dari X ke Y", lalu pindahkan n-1 cakram dari 'bantu' ke 'ke' (memakai 'dari' sebagai bantu).
void hanoi(int n, char dari, char ke, char bantu, int& langkah) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, dari, bantu, ke, langkah);
    langkah++;
    cout << "Langkah " << langkah << ": pindahkan cakram " << n
         << " dari " << dari << " ke " << ke << "\n";
    hanoi(n - 1, bantu, ke, dari, langkah);
}

// TODO 4: kiri > kanan berarti rentang kosong: kembalikan -1. Hitung tengah = (kiri + kanan) / 2.
// Sama: kembalikan tengah. Lebih kecil: cari di kiri..tengah-1. Lebih besar: tengah+1..kanan.
int cariBiner(const int a[], int kiri, int kanan, int dicari) {
    if (kiri > kanan) {
        return -1;
    }
    int tengah = (kiri + kanan) / 2;
    if (a[tengah] == dicari) {
        return tengah;
    }
    if (dicari < a[tengah]) {
        return cariBiner(a, kiri, tengah - 1, dicari);
    }
    return cariBiner(a, tengah + 1, kanan, dicari);
}