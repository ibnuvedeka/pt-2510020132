# Deklarasi AI

**Label AI 1**
* **Alat yang dipakai:** AI Gemini.
* **Untuk apa:** Membantu memvalidasi logika rentang percabangan `if-else` bertingkat dari batas nilai tertinggi hingga terendah, memastikan tipe data konversi `char` pada instruksi `switch (huruf_mutu[0])` ditangani dengan sintaks yang tepat, dan memastikan status kelulusan boolean dievaluasi secara langsung tanpa percabangan ganda.
* **Cara memeriksanya:** Saya telah membaca kode struktur kontrol percabangan untuk memastikan tidak ada kondisi yang tumpang tindih. Kemudian, saya mengompilasi program dengan flag `g++ -std=c++20 -Wall -Wextra -Wpedantic` hingga terbebas dari *warning* maupun *error*. Terakhir, saya telah menguji secara manual menggunakan ketujuh kasus batas nilai (seperti memasukkan angka 80, 79.9, 60, dan 59.9) guna memastikan keluaran huruf mutu, keterangan, dan status program seratus persen identik dengan tabel kasus uji di modul praktikum.