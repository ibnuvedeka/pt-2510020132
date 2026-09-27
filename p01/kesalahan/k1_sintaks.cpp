// Kesalahan 1: sintaks. Ada satu tanda titik koma yang hilang.
// Program ini gagal pada tahap compile, berkas .exe tidak terbentuk.
#include <iostream>

int main() {
    int nilai = 80; // <-- Menambahkan titik koma di sini
    std::cout << "Nilai: " << nilai << "\n";
    return 0;
}