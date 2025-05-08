# SISOP-3-2025-IT36

Anggota Kelompok
|     NRP    |                Nama              |
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
   - **soal_1:**
     - `image_client.c`
     - `image_server.c`
   - **soal_2:**
     - `dispatcher.c`
     - `delivery_agent.c`
   - **soal_3:**
     - `dungeon.c`
     - `shop.c/shop.h`
     - `player.c`
   - **soal_4:**
     - `system.c`
     - `hunter.c`
    
   - **assets**

Jika melanggar struktur repo akan dianggap sama dengan curang dan menerima konsekuensi sama dengan melakukan kecurangan. Folder assets bersifat opsional dan hanya diisi dengan dokumentasi pengerjaan yang akan diletakkan di readme. Tidak ada format khusus untuk penamaan file dalam assets.

5. Setelah pengerjaan selesai, semua script bash, awk, dan file yang berisi cron job ditaruh di github masing - masing kelompok, dan link github diletakkan pada form yang disediakan. Pastikan github di setting ke publik.
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

Karena anda adalah seorang professional programmer, anda mengikuti petunjuk yang anda dapatkan dari deep web untuk membuat sistem RPC server-client untuk mengubah text file sehingga bisa dilihat dalam bentuk file jpeg. Situs deep web yang anda baca terlihat sebagai berikut.

  a. Text file rahasia terdapat pada LINK BERIKUT (https://drive.google.com/file/d/15mnXpYUimVP1F5Df7qd_Ahbjor3o1cVw/view?usp=sharing), diperbolehkan untuk download/unzip secara manual. Contoh working directory setelah semuanya selesai akan terlihat sebagai berikut:

  ![Image](https://github.com/user-attachments/assets/771429ee-a541-49b8-b26e-efd5a5434742)

  b. Pada image_server.c, program yang dibuat harus berjalan secara daemon di background dan terhubung dengan image_client.c melalui socket RPC.
  
  c. Program image_client.c harus bisa terhubung dengan image_server.c dan bisa mengirimkan perintah untuk:
    - Decrypt text file yang dimasukkan dengan cara Reverse Text lalu Decode from Hex, untuk disimpan dalam folder database server dengan nama file berupa timestamp dalam bentuk angka, misalnya: database/1744401282.jpeg
    - Request download dari database server sesuai filename yang dimasukkan, misalnya: 1744401282.jpeg
    - Note: tidak diperbolehkan copy/pindah file, gunakan RPC untuk mengirim data.
    
  d. Program image_client.c harus disajikan dalam bentuk menu kreatif yang memperbolehkan pengguna untuk memasukkan perintah berkali-kali.
  
  Contoh:

  ![Image](https://github.com/user-attachments/assets/a71ad9ce-f72a-47a0-b3a7-f73ef3a81b2e)


  e. Program dianggap berhasil bila pengguna dapat mengirimkan text file dan menerima sebuah file jpeg yang dapat dilihat isinya. Apakah anda akan berhasil menemukan sosok sang legenda “rootkids”?
  
  f. Program image_server.c diharuskan untuk tidak keluar/terminate saat terjadi error dan client akan menerima error message sebagai response, yang meliputi minimal:
  - Dari Client:
    - Gagal connect ke server
    - Salah nama text file input
  - Dari Server:
    - Gagal menemukan file untuk dikirim ke client
   
  g. Server menyimpan log semua percakapan antara image_server.c dan image_client.c di dalam file server.log dengan format:

  ![Image](https://github.com/user-attachments/assets/e2b6421c-03d1-48f7-993b-3449966581ea)


2. Tahun 2025, di tengah era perdagangan serba cepat, berdirilah sebuah perusahaan ekspedisi baru bernama RushGo. RushGo ingin memberikan layanan ekspedisi terbaik dengan 2 pilihan, Express (super cepat) dan Reguler (standar). Namun, pesanan yang masuk sangat banyak! Mereka butuh sebuah sistem otomatisasi pengiriman, agar agen-agen mereka tidak kewalahan menangani pesanan yang terus berdatangan. Kamu ditantang untuk membangun Delivery Management System untuk RushGo.

Sistem ini terdiri dari dua bagian utama:

  - delivery_agent.c untuk agen otomatis pengantar Express
  - dispatcher.c untuk pengiriman dan monitoring pesanan oleh user

  a. Mengunduh File Order dan Menyimpannya ke Shared Memory.
  
Untuk memulai, Anda perlu mengelola semua orderan yang masuk dengan menggunakan shared memory.

  - Unduh file delivery_order.csv (https://drive.google.com/file/d/1OJfRuLgsBnIBWtdRXbRsD2sG6NhMKOg9/view?usp=sharing)
  - Setelah file CSV diunduh, program Anda harus membaca seluruh data dari CSV dan menyimpannya ke dalam shared memory.

  b. Pengiriman Bertipe Express

  - RushGo memiliki tiga agen pengiriman utama: AGENT A, AGENT B, dan AGENT C.
  - Setiap agen dijalankan sebagai thread terpisah.
  - Agen-agen ini akan secara otomatis:
    - Mencari order bertipe Express yang belum dikirim.
    - Mengambil dan mengirimkannya tanpa intervensi user.
  - Setelah sukses mengantar, program harus mencatat log di delivery.log dengan format:

  ![Image](https://github.com/user-attachments/assets/d5f6d3fc-52f0-47f8-b6ac-ebf48f85aae0)

  c. Pengiriman Bertipe Reguler

  Berbeda dengan Express, untuk order bertipe Reguler, pengiriman dilakukan secara manual oleh user.
  - User dapat mengirim permintaan untuk mengantar order Reguler dengan memberikan perintah deliver dari dispatcher. 
  Penggunaan:
  ./dispatcher -deliver [Nama]

  - Pengiriman dilakukan oleh agent baru yang namanya adalah nama user.
  - Setelah sukses mengantar, program harus mencatat log di delivery.log dengan format:

  ![Image](https://github.com/user-attachments/assets/e481d669-b7ea-42c0-9de7-61f212f1573e)

  d. Mengecek Status Pesanan
  
  Dispatcher juga harus bisa mengecek status setiap pesanan.
  Penggunaan:
  ./dispatcher -status [Nama]

  ![Image](https://github.com/user-attachments/assets/22893330-6ab4-4ac8-a820-3edb4d64ded1)

  e. Melihat Daftar Semua Pesanan
  
  Untuk memudahkan monitoring, program dispatcher bisa menjalankan perintah list untuk melihat semua order disertai nama dan statusnya.
  Penggunaan:
  ./dispatcher -list

3. The Lost Dungeon

Suatu pagi, anda menemukan jalan setapak yang ditumbuhi lumut dan hampir tertutup semak. Rasa penasaran membawamu mengikuti jalur itu, hingga akhirnya anda melihatnya: sebuah kastil tua, tertutup akar dan hampir runtuh, tersembunyi di tengah hutan. Gerbangnya terbuka seolah memanggilmu masuk.

Di dalam, anda menemukan pintu batu besar dengan simbol-simbol aneh yang terasa… hidup. Setelah mendorongnya dengan susah payah, anda pun menuruni tangga batu spiral yang dalam dan gelap. Di ujungnya, anda menemukan sebuah dunia baru: dungeon bawah tanah yang sudah tertinggal sangat lama.

Anda tidak tahu bagaimana anda dapat berada di situasi ini, tetapi didorong oleh rasa ingin tahu dan semangat, apa pun yang menunggumu di bawah sana, anda akan melawan.

  a. Entering the dungeon

dungeon.c akan bekerja sebagai server yang dimana client (player.c) dapat terhubung melalui RPC. dungeon.c akan memproses segala perintah yang dikirim oleh player.c. Lebih dari 1 client dapat mengakses server.

  b. Sightseeing 
  
Anda melihat disekitar dungeon dan menemukan beberapa hal yang menarik seperti toko senjata dan pintu dengan aura yang cukup seram. Ketika player.c dijalankan, ia akan terhubung ke dungeon.c dan menampilkan sebuah main menu seperti yang dicontohkan di bawah ini (tidak harus mirip, dikreasikan sesuai kreatifitas masing-masing praktikan).

  ![Image](https://github.com/user-attachments/assets/99fad34e-4b52-4b80-aeb5-840441e94916)

  c. Status Check
  
Melihat bahwa terdapat sebuah toko senjata, anda mengecek status diri anda dengan harapan anda masih memiliki sisa uang untuk membeli senjata. Jika opsi Show Player Stats dipilih, maka program akan menunjukan Uang yang dimiliki (Jumlah dibebaskan), senjata yang sedang digunakan, Base Damage, dan jumlah musuh yang telah dimusnahkan. 

  ![Image](https://github.com/user-attachments/assets/c8a13f92-cecb-4dbf-9ec8-a89309a14668)

  d. Weapon Shop
  
Ternyata anda memiliki sisa uang dan langsung pergi ke toko senjata tersebut untuk membeli senjata. Terdapat 5 pilihan senjata di toko tersebut dan beberapa dari mereka memiliki passive yang unik. Disaat opsi Shop dipilih, program akan menunjukan senjata apa saja yang dapat dibeli beserta harga, damage, dan juga passive (jika ada). List senjata yang ada dan dapat dibeli beserta logic/command untuk membeli senjata tersebut diletakan di code shop.c/shop.h yang nanti akan dipakai oleh dungeon.c.

  ![Image](https://github.com/user-attachments/assets/d9bf4395-754c-48af-99f1-1b937d083dee)

Notes: praktikan dibebaskan untuk penamaan, harga, damage, dan juga passive dari senjata-senjata yang ada. Yang penting harus terdapat 5 atau lebih senjata dengan minimal 2 senjata yang memiliki passive.

  e. Handy Inventory
  
Setelah membeli senjata di toko tadi, anda membuka ransel anda untuk memakai senjata tersebut. Jika opsi View Inventory dipilih, program akan menunjukan senjata apa saja yang dimiliki dan dapat dipakai (jika senjata memiliki passive, tunjukan juga passive tersebut).

  ![image](https://github.com/user-attachments/assets/01fa5005-4dec-4c05-ba42-b3451a7e93c4)

Lalu apabila opsi Show Player Stats dipilih saat menggunakan weapon maka Base Damage player akan berubah dan jika memiliki passive, maka akan ada status tambahan yaitu Passive.

  ![Image](https://github.com/user-attachments/assets/a18a1b1c-4ed3-4629-a4ad-8cd7718adfa1)

  f. Enemy Encounter
  
Anda sekarang sudah siap untuk melewati pintu yang seram tadi, disaat anda memasuki pintu tersebut, anda langsung ditemui oleh sebuah musuh yang bukan sebuah manusia. Dengan tekad yang bulat, anda melawan musuh tersebut. Saat opsi Battle Mode dipilih, program akan menunjukan health-bar musuh serta angka yang menunjukan berapa darah musuh tersebut dan menunggu input dengan opsi attack untuk melakukan sebuah serangan dan juga exit untuk keluar dari Battle Mode. Apabila darah musuh berkurang, maka health-bar musuh akan berkurang juga.

  ![Image](https://github.com/user-attachments/assets/fe5443ec-15e6-4511-a9f9-a1963546a4f9)

Jika darah musuh sudah 0, maka program akan menunjukan rewards berupa berapa banyak gold yang didapatkan lalu akan muncul musuh lagi.

  ![Image](https://github.com/user-attachments/assets/9de76e45-8e04-4682-9ce3-ea1655d999b3)

  g. Other Battle Logic
  
  - Health & Rewards
    
Untuk darah musuh, seberapa banyak darah yang mereka punya dibuat secara random, contoh: 50-200 HP. Lakukan hal yang sama untuk rewards. 

  - Damage Equation
    
Untuk damage, gunakan base damage sebagai kerangka awal dan tambahkan rumus damage apapun (dibebaskan, yang pasti perlu random number agar hasil damage bervariasi). Lalu buatlah logic agar setiap serangan memiliki kesempatan untuk Critical yang membuat damage anda 2x lebih besar.

![Image](https://github.com/user-attachments/assets/db5245f5-0a7f-4ab3-8fb5-84e2eca9e86e)

  - Passive
    
Jika senjata yang dipakai memiliki Passive setiap kali passive tersebut menyala, maka tunjukan bahwa passive tersebut aktif.

  ![Image](https://github.com/user-attachments/assets/98bd922b-d43b-4e63-897c-e6c921653ee0)

  h. Error Handling
  
Berikan error handling untuk opsi-opsi yang tidak ada.
Contoh:

  ![Image](https://github.com/user-attachments/assets/a27f4cc9-ce0e-4021-8d01-0f7806176d1b)









