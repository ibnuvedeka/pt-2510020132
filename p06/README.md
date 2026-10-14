# Deklarasi AI

**Label AI 1**
* **Alat yang dipakai:** AI Gemini.
* **Untuk apa:** Membantu memvalidasi implementasi pemformatan jarak kolom menggunakan library `<iomanip>`, memastikan peletakan inisialisasi awal variabel pencari nilai tertinggi berawal dari `-1`, serta menyusun kerangka logika *nested loop* (perulangan bersarang) untuk memetakan karakter jumlah karakter `#` pada bagian sebaran diagram batang huruf mutu.
* **Cara memeriksanya:** Saya memeriksa sintaks `left`, `right`, dan `setw()` pada baris cetak rekap untuk memastikan panjang kolom sudah proporsional untuk nama yang panjang. Setelah kompilasi berhasil tanpa peringatan `fall-through` di blok `switch`, program dieksekusi dengan `contoh_masukan.txt` untuk memastikan hasil angka pecahan tertulis `83.97` dan `90.00` dengan pembulatan dua presisi, serta diagram batangnya menghasilkan visual `A## 2`, `B# 1`, dll., identik dengan luaran yang diminta.