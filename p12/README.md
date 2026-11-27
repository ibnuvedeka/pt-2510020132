# Pertemuan 12: Rekursi — Laboratorium Rekursi

- **Nama:** Ibnu Muhammad
- **NPM:** 2510020132
- **Kelas:** SI 3A Non Reg BJB

## Deklarasi Penggunaan AI (Label AI 1)
- **Alat yang digunakan:** Gemini
- **Untuk apa:** Memverifikasi perumusan *base case* dan *recursive case* pada keempat fungsi rekursif (`pangkat`, `palindrom`, `hanoi`, dan `cariBiner`) agar sesuai dengan diagram alir pada modul Pertemuan 12 serta bebas dari perulangan maupun *warning* kompilator.
- **Cara memeriksanya:** Mengompilasi `p12/lab_rekursi.cpp` menggunakan perintah `g++ -std=c++20 -Wall -Wextra -Wpedantic -g p12/lab_rekursi.cpp -o p12/lab_rekursi` hingga menghasilkan 0 *error* dan 0 *warning*, menjalankan pengujian otomatis dengan `./p12/lab_rekursi < p12/contoh_masukan.txt`, serta mencocokkan urutan langkah Menara Hanoi (`3 cakram = 7 langkah`) dan indeks pencarian biner (`27` di indeks `4`) dengan contoh keluaran pada modul dan `README` materi.