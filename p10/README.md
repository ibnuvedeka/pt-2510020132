# Deklarasi AI

**Label AI 1**
* **Alat yang dipakai:** AI Gemini.
* **Untuk apa:** AI digunakan untuk mengklarifikasi konsep pengiriman larik satu dimensi sebagai parameter fungsi (penggunaan pengubah `const` pada larik yang hanya dibaca, penjagaan batas indeks `0` hingga `jumlah - 1`, serta teknik pertukaran empat larik sejajar secara bersamaan pada *selection sort*) dan meninjau kelengkapan implementasi enam fungsi baru v0.8.
* **Cara memeriksanya:** Saya menyusun kode `sinilai_v08.cpp` dengan mempertahankan seluruh fungsi `sinilai_v07.cpp`, mengompilasinya secara ketat menggunakan `g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v08.cpp -o sinilai_v08` hingga nol *error* dan nol *warning*, menguji batas masukan jumlah mahasiswa (`0` dan `51` ditolak), serta membandingkan luaran pengujian `contoh_masukan.txt` terhadap versi v0.7 memakai perintah `diff` untuk memastikan seluruh angka laporan dan sebaran identik selain judul, batas prompt jumlah, dan blok peringkat kelas.