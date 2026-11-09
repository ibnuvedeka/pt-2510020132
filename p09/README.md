# Deklarasi AI

**Label AI 1**
* **Alat yang dipakai:** AI Gemini.
* **Untuk apa:** AI hanya digunakan untuk mengklarifikasi konsep modul pemrograman modular (perbedaan mekanisme *pass by value* vs *pass by reference* `&`, aturan cakupan variabel lokal, serta penghindaran variabel global) dan melakukan tinjauan/kritik terhadap struktur pemecahan sembilan fungsi yang telah dirancang mandiri.
* **Cara memeriksanya:** Saya menyusun sendiri prototipe dan definisi sembilan fungsi sesuai spesifikasi modul, memastikan tidak ada penggunaan variabel global, lalu mengompilasi program secara ketat dengan `g++ -std=c++20 -Wall -Wextra -Wpedantic -g`. Pengujian verifikasi dilakukan dengan membandingkan luaran pengujian `contoh_masukan.txt` terhadap versi v0.6 (`diff keluaran_v06.txt keluaran_v07.txt`) untuk memastikan tidak ada perubahan perilaku atau nilai kalkulasi akhir selain baris judul versi.