# Rancangan Top-Down — Sistem Kasir dan Pencatatan Laundry

- **Nama / NPM:** IBNU MUHAMMAD / 2510020132
- **Pertemuan:** Pertemuan 11 (studi kasus mandiri)
- **Judul Program:** Sistem Kasir dan Pencatatan Laundry

---

## 1. Masalah dan Pengguna

Program ini membantu petugas kasir laundry mencatat transaksi cucian masuk beserta beratnya dalam satuan kilogram, memperbarui status pengerjaan cucian dari diproses menjadi selesai hingga diambil pelanggan, serta menampilkan daftar cucian dan rekapitulasi pendapatan harian. Program digunakan oleh satu orang petugas laundry pada satu komputer melalui antarmuka terminal berbasis teks. Program dianggap selesai apabila setiap penerimaan cucian baru tersimpan akurat pada daftar, perubahan status maupun pengambilan cucian tercatat tanpa kesalahan indeks, serta laporan total berat dan pendapatan harian tampil dengan benar.

---

## 2. Data yang Disimpan

Konstanta yang digunakan di dalam program:
- `const int MAKS_CUCIAN = 50;` (daya tampung maksimum transaksi cucian harian)
- `const int HARGA_PER_KG = 7000;` (tarif layanan cuci per kilogram)

| Larik / Variabel | Tipe | Isi | Berubah? |
| :--- | :--- | :--- | :--- |
| `nama` | `string` (`nama[MAKS_CUCIAN]`) | Nama pelanggan pemilik cucian | Ya (bertambah saat terima cucian; `const` pada fungsi baca/ubah status) |
| `berat` | `double` (`berat[MAKS_CUCIAN]`) | Berat cucian pelanggan dalam kilogram (kg) | Ya (bertambah saat terima cucian; `const` pada fungsi baca/ubah status) |
| `status` | `int` (`status[MAKS_CUCIAN]`) | Kode status cucian (`0` = Diproses, `1` = Selesai, `2` = Diambil) | Ya (berubah saat cucian diterima, selesai, maupun diambil) |
| `jumlah` | `int` | Banyak data cucian yang sedang tersimpan dalam larik | Ya (bertambah setiap ada cucian masuk baru) |
| `pilihan` | `int` | Nomor menu yang dipilih petugas pada perulangan `main` | Ya (berubah setiap siklus menu utama) |

Format satu baris berkas (tugas besar): `-` *(tidak dipakai pada Pertemuan 11)*

---

## 3. Bagan Hierarki

    main (Tingkat 0)
    ├── bacaBulat (Tingkat 1)
    ├── tampilkanCucian (Tingkat 1)
    ├── terimaCucian (Tingkat 1)
    │   └── bacaBerat (Tingkat 2)
    ├── tandaiSelesai (Tingkat 1)
    │   ├── tampilkanCucian (Tingkat 2 - dipanggil dari dua tempat)
    │   └── bacaBulat (Tingkat 2 - dipanggil dari dua tempat)
    ├── ambilCucian (Tingkat 1)
    │   ├── tampilkanCucian (Tingkat 2 - dipanggil dari dua tempat)
    │   └── bacaBulat (Tingkat 2 - dipanggil dari dua tempat)
    └── cetakRekap (Tingkat 1)
        └── cariIndeksTerberat (Tingkat 2)

---

## 4. Tabel Fungsi

| Fungsi | Tugas (satu kalimat) | Parameter (`const`?) | Kembalian | Tahap |
| :--- | :--- | :--- | :--- | :--- |
| `bacaBulat` | Membaca masukan bilangan bulat dalam rentang batas bawah hingga batas atas sampai valid. | `string label, int bawah, int atas` | `int` | 2 |
| `bacaBerat` | Membaca masukan bilangan desimal positif untuk berat cucian sampai valid. | `string label` | `double` | 2 |
| `tampilkanCucian` | Mencetak daftar seluruh cucian lengkap dengan nomor urut, nama pelanggan, berat, serta status pengerjaannya. | `const string nama[], const double berat[], const int status[], int jumlah` | `void` | 2 |
| `cariIndeksTerberat` | Mengembalikan indeks cucian dengan bobot kilogram paling besar dari seluruh data yang tersimpan. | `const double berat[], int jumlah` | `int` | 2 |
| `cetakRekap` | Menampilkan ringkasan total berat, total pendapatan harian, serta pelanggan dengan cucian terberat. | `const string nama[], const double berat[], const int status[], int jumlah` | `void` | 2 |
| `terimaCucian` | Menambahkan data cucian baru ke posisi terakhir larik sejajar apabila kapasitas masih tersedia. | `string nama[], double berat[], int status[], int &jumlah` | `void` | 3 |
| `tandaiSelesai` | Mengubah status cucian yang dipilih petugas dari diproses menjadi selesai. | `const string nama[], const double berat[], int status[], int jumlah` | `void` | 3 |
| `ambilCucian` | Mengubah status cucian yang sudah selesai menjadi telah diambil oleh pelanggan. | `const string nama[], const double berat[], int status[], int jumlah` | `void` | 3 |

---

## 5. Rencana Tahap

| Tahap | Fungsi yang Dirinci | Yang Sudah Bisa Dicoba Setelah Tahap Ini |
| :--- | :--- | :--- |
| 1 | `main` dan semua *stub* (8 fungsi mencetak `[belum dirinci] <namaFungsi>`) | Menu berulang (`1`–`5` dan `0` selesai) dapat dipilih, setiap pilihan memanggil fungsi sesuai bagan dan mencetak nama fungsinya |
| 2 | `bacaBulat`, `bacaBerat`, `tampilkanCucian`, `cariIndeksTerberat`, `cetakRekap` | Validasi masukan angka bulat maupun desimal berjalan aman tanpa *infinite loop*, serta daftar cucian dan rekap harian tampil tanpa mengubah larik |
| 3 | `terimaCucian`, `tandaiSelesai`, `ambilCucian` | Seluruh transaksi penerimaan cucian baru, pembaruan status menjadi selesai, dan pengambilan cucian berjalan penuh serta mengubah isi larik sejajar |

---

## 6. Uji yang Direncanakan

1. **Jalan normal (terima cucian dan hitung rekap):** Memilih menu `2` (Terima cucian masuk) untuk menambahkan pelanggan `"Ibnu"` seberat `4.0` kg dan `"Muhammad"` seberat `6.5` kg. Saat menu `5` (Rekap harian) dipilih, program menampilkan jumlah transaksi `2`, total berat `10.5 kg`, total pendapatan `Rp73500`, dan cucian terberat `Muhammad (6.5 kg)`.
2. **Masukan salah tipe dan luar rentang:** Mengetik `"abc"` pada prompt pilihan menu utama, atau mengetik `"xyz"` maupun nomor urut `99` pada menu `3` (Tandai cucian selesai) saat data baru berjumlah `2`. Program tidak terjebak *infinite loop*, menampilkan peringatan validasi, dan meminta masukan ulang hingga valid.
3. **Kondisi batas (data kosong dan berat nol/negatif):** Saat program baru dijalankan (`jumlah = 0`), memilih menu `1` (Lihat daftar cucian) dan menu `5` (Rekap harian) menampilkan pesan `"Belum ada data cucian."` tanpa *crash*; saat memilih menu `2` dan memasukkan berat `0` atau `-2`, program menolak masukan dan meminta bilangan desimal lebih dari `0`.
4. **Pembuktian perubahan isi larik sejajar:** Memilih menu `3` (Tandai cucian selesai) untuk cucian nomor `1` (`"Ibnu"`), kemudian memilih menu `4` (Ambil cucian) untuk nomor `1` yang sama. Saat menu `1` (Lihat daftar cucian) dibuka kembali, status pada indeks `0` terbukti berubah bertahap dari `Diproses` menjadi `Selesai` lalu `Diambil` dengan tagihan `Rp28000`, sementara data `nama[0]` dan `berat[0]` tetap utuh.