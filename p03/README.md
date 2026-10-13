# Deklarasi AI

**Label AI 1**
* **Alat yang dipakai:** AI Gemini.
* **Untuk apa:** AI digunakan sebagai pembimbing untuk mengimplementasikan variabel konstanta bobot secara benar, menyusun prioritas dan asosiativitas dalam perhitungan rumus akhir menggunakan tanda kurung (agar perhitungan perkalian dan penjumlahan tidak bentrok), serta mencegah jebakan pembagian bilangan bulat (integer division) dengan menggunakan `4.0` pada perhitungan rata-rata.
* **Cara memeriksa:** Saya telah membaca baris kode ekspresi perhitungan, memahami logika urutan evaluasi matematika di dalamnya, membangun program dari terminal tanpa pesan *error* maupun *warning*, dan mengujinya menggunakan `contoh_masukan.txt` untuk memastikan hasil `nilai_akhir` adalah 83.975 dan `rerata_polos` adalah 85.875, sesuai dengan ketentuan kriteria penilaian modul.