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

```text
main (Tingkat 0)
├── bacaBulat (Tingkat 1)
├── tampilkanCucian (Tingkat 1)
├── terimaCucian (Tingkat 1)
│   └── bacaBerat (Tingkat 2)
├── tandai