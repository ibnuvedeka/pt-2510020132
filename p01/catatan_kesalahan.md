# Catatan Kesalahan (Praktikum 5)

| Berkas | Jenis kesalahan | Pesan yang muncul (salin baris pertamanya) | Cara kamu mengetahuinya |
|---|---|---|---|
| `k1_sintaks.cpp` | Sintaks | `error: expected ';' before 'std'` | Build gagal pada tahap compile, compiler menunjuk nomor baris yang kehilangan titik koma. |
| `k2_nama.cpp` | Compile lainnya | `error: 'Nilai' was not declared in this scope` | Build gagal karena nama variabel belum dikenal atau salah ketik huruf besar/kecil (C++ *case-sensitive*). |
| `k3_runtime.cpp` | Runtime | *(Program berhenti mendadak tanpa pesan / sistem operasi menghentikan program)* | Build sukses, tetapi saat dijalankan dan diberi input 0, program terhenti akibat pembagian dengan nol (*division by zero*). |
| `k4_logika.cpp` | Logika | *(Tidak ada pesan sama sekali)* | Build sukses dan program jalan mulus, hanya ketahuan dari hasil perbandingan angka di mana hasil cetaknya salah (81, bukan 81.67). |

**Kesalahan yang paling berbahaya:** 
Menurut saya, kesalahan jenis **Logika** adalah yang paling berbahaya karena tidak ada peringatan apa pun dari *compiler* maupun sistem operasi yang memberi tahu kita, sehingga kesalahan ini hanya bisa ketahuan jika kita benar-benar menguji dan membandingkan hasil keluarannya secara manual.