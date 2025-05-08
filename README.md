# SISOP-1-2024-IT36

Anggota Kelompok
|     Nrp    |                Nama              |
|-----       | -----                            |
|5027241106  | Mohammad Abyan Ranuaji           |
|5027241078  | Naila Raniyah Hanan              |


- [Peraturan](#peraturan)
- [Soal](#soal)
  - [Soal 1](#soal-1)
  - [Soal 2](#soal-2)
  - [Soal 3](#soal-3)
  - [Soal 4](#soal-4)
 
---
## Peraturan
---
1. Waktu pengerjaan dimulai hari Senin (28 April 2025) setelah sesi lab hingga hari Sabtu (3 Mei 2025) pukul 23.59 WIB.
2. Praktikan diharapkan membuat laporan penjelasan dan penyelesaian soal dalam bentuk Readme (github).
3. Format nama repository github “Sisop-[Nomor Modul]-2025-[Nama Kelompok]” (contoh:Sisop-3-2025-IT01).
4. Struktur repository seperti berikut:
		—**soal_1:**
				—image_client.c
				—image_server.c
                                    
   —**soal_2:**
        —dispatcher.c
        — delivery_agent.c
			
  —**soal_3:**	
       — dungeon.c
	     — shop.c/shop.h
	     — player.c

  —**soal_4:**
      —system.c
      —hunter.c

  —**assets**

5. Jika melanggar struktur repo akan dianggap sama dengan curang dan menerima konsekuensi sama dengan melakukan kecurangan. Folder assets bersifat opsional dan hanya diisi dengan dokumentasi pengerjaan yang akan diletakkan di readme. Tidak ada format khusus untuk penamaan file dalam assets
Setelah pengerjaan selesai, semua script bash, awk, dan file yang berisi cron job ditaruh di github masing - masing kelompok, dan link github diletakkan pada form yang disediakan. Pastikan github di setting ke publik.
6. Commit terakhir maksimal 10 menit setelah waktu pengerjaan berakhir. Jika melewati maka akan dinilai berdasarkan commit terakhir.
7. Jika tidak ada pengumuman perubahan soal oleh asisten, maka soal dianggap dapat diselesaikan.
9. Jika ditemukan soal yang tidak dapat diselesaikan, harap menuliskannya pada Readme beserta permasalahan yang ditemukan.
10. Praktikan tidak diperbolehkan menanyakan jawaban dari soal yang diberikan kepada asisten maupun praktikan dari kelompok lainnya.
11. Jika ditemukan indikasi kecurangan dalam bentuk apapun di pengerjaan soal shift, maka nilai dianggap 0.
Pengerjaan soal shift sesuai dengan modul yang telah diajarkan.
12. Zip dari repository dikumpulkan di google form yang terdapat pada linktree.
13. Jika terdapat revisi soal akan dituliskan pada halaman terakhir.

 ---
## Soal
 ---  
 1. “The Legend of Rootkids” 
Sekarang tahun 2045, seluruh dunia mengalami kekacauan dalam segala infrastruktur siber. Sebagai seorang mahasiswa Departemen Teknologi Informasi ITS, anda memiliki ide untuk kembali ke masa lalu (tahun 2025) untuk memanggil hacker asal Semarang bernama “rootkids” yang mampu melawan segala hacker lain. Tetapi anda tidak tahu bagaimana cara mencapainya.
Hanya sedikit yang diketahui tentang hacker bernama “rootkids”. Beberapa informasi yang anda temukan dari deep web hanyalah berupa beberapa file text yang berisi tulisan aneh, beserta beberapa petunjuk untuk mengubah text tersebut menjadi sebuah file jpeg.
Karena anda adalah seorang professional programmer, anda mengikuti petunjuk yang anda dapatkan dari deep web untuk membuat sistem RPC server-client untuk mengubah text file sehingga bisa dilihat dalam bentuk file jpeg. Situs deep web yang anda baca terlihat sebagai berikut. (Author: Amoes / wintertia)
a. Text file rahasia terdapat pada LINK BERIKUT, diperbolehkan untuk download/unzip secara manual. Contoh working directory setelah semuanya selesai akan terlihat sebagai berikut:
.
├── client
│   ├── 1744403652.jpeg
│   ├── 1744403687.jpeg
│   ├── image_client
│   └── secrets
│       ├── input_1.txt
│       ├── input_2.txt
│       ├── input_3.txt
│       ├── input_4.txt
│       └── input_5.txt
├── image_client.c
├── image_server.c
└── server
    ├── database
    │   ├── 1744403652.jpeg
    │   └── 1744403687.jpeg
    ├── image_server
    └── server.log

Pada image_server.c, program yang dibuat harus berjalan secara daemon di background dan terhubung dengan image_client.c melalui socket RPC.
Program image_client.c harus bisa terhubung dengan image_server.c dan bisa mengirimkan perintah untuk:
Decrypt text file yang dimasukkan dengan cara Reverse Text lalu Decode from Hex, untuk disimpan dalam folder database server dengan nama file berupa timestamp dalam bentuk angka, misalnya: database/1744401282.jpeg
Request download dari database server sesuai filename yang dimasukkan, misalnya: 1744401282.jpeg
Note: tidak diperbolehkan copy/pindah file, gunakan RPC untuk mengirim data.
Program image_client.c harus disajikan dalam bentuk menu kreatif yang memperbolehkan pengguna untuk memasukkan perintah berkali-kali. Contoh:


Program dianggap berhasil bila pengguna dapat mengirimkan text file dan menerima sebuah file jpeg yang dapat dilihat isinya. Apakah anda akan berhasil menemukan sosok sang legenda “rootkids”?
Program image_server.c diharuskan untuk tidak keluar/terminate saat terjadi error dan client akan menerima error message sebagai response, yang meliputi minimal:
Dari Client:
Gagal connect ke server
Salah nama text file input
Dari Server:
Gagal menemukan file untuk dikirim ke client
Server menyimpan log semua percakapan antara image_server.c dan image_client.c di dalam file server.log dengan format:
[Source][YYYY-MM-DD hh:mm:ss]: [ACTION] [Info]
# Contoh:



