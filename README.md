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

4. Di dunia yang sedang kacau ini, muncul seorang hunter lemah bernama Sung Jin Woo😈yang bahkan tidak bisa mengangkat sebuah galon🛢️. Suatu hari, hunter ini tertabrak sebuah truk dan meninggal di tempat. Dia pun marah akan dirinya yang lemah dan berharap mendapat kesempatan kedua. Beruntungnya, Sung Jin Woo pun mengalami reinkarnasi dan sekarang bekerja sebagai seorang admin. Uniknya, pekerjaan ini mempunyai sebuah sistem yang bisa melakukan tracking pada seluruh aktivitas dan keadaan seseorang. Sayangnya, model yang diberikan oleh Bos-nya sudah sangat tua sehingga program tersebut harus dimodifikasi agar tidak ketinggalan zaman, dengan spesifikasi:

   a. Agar hunter lain tidak bingung, Sung Jin Woo memutuskan untuk membuat dua file, yaitu system.c dan hunter.c. Sung Jin Woo mendapat peringatan bahwa system.c merupakan shared memory utama yang mengelola shared memory hunter-hunter dari hunter.c. Untuk mempermudahkan pekerjaannya, Sung Jin Woo mendapat sebuah clue (https://drive.google.com/file/d/1E3tRDQ4xkSzs3sY3GT8gKb77iEfhOvZs/view?usp=sharing) yang dapat membuat pekerjaannya menjadi lebih mudah dan efisien. NOTE : Hunter bisa dijalankan ketika sistem sudah dijalankan.

   b. Untuk memastikan keteraturan sistem, Sung Jin Woo memutuskan untuk membuat fitur registrasi dan login di program hunter. Setiap hunter akan memiliki key unik dan stats awal (Level=1, EXP=0, ATK=10, HP=100, DEF=5). Data hunter disimpan dalam shared memory tersendiri yang terhubung dengan sistem.

   ![Image](https://github.com/user-attachments/assets/b0904b12-720e-44ea-adde-436a6ed02a5c)

   ![Image](https://github.com/user-attachments/assets/645ef148-9590-4865-bd91-b08836aaa68b)

   c. Agar dapat memantau perkembangan para hunter dengan mudah, Sung Jin Woo menambahkan fitur di sistem yang dapat menampilkan informasi semua hunter yang terdaftar, termasuk nama hunter, level, exp, atk, hp, def, dan status (banned atau tidak). Ini membuat dia dapat melihat siapa hunter terkuat dan siapa yang mungkin melakukan kecurangan.

   ![Image](https://github.com/user-attachments/assets/a39cb22f-ac9e-4726-8f19-21df4e870394)

   d. Setelah beberapa hari bekerja, Sung Jin Woo menyadari bahwa para hunter membutuhkan tempat untuk berlatih dan memperoleh pengalaman. Ia memutuskan untuk membuat fitur unik dalam sistem yang dapat menghasilkan dungeon secara random dengan nama, level minimal hunter, dan stat rewards dengan nilai:
   
  - 🏆Level Minimal : 1 - 5
  - ⚔️ATK : 100 - 150 Poin
  - ❤️HP  : 50 - 100 Poin
  - 🛡️DEF : 25 - 50 Poin
  - 🌟EXP : 150 - 300 Poin

Setiap dungeon akan disimpan dalam shared memory sendiri yang berbeda dan dapat diakses oleh hunter.

  ![Image](https://github.com/user-attachments/assets/39466575-a6fa-4841-b18d-e98142770f64)

  e. Untuk memudahkan admin dalam memantau dungeon yang muncul, Sung Jin Woo menambahkan fitur yang menampilkan informasi detail semua dungeon. Fitur ini menampilkan daftar lengkap dungeon beserta nama, level minimum, reward (EXP, ATK, HP, DEF), dan key unik untuk masing-masing dungeon.

  ![Image](https://github.com/user-attachments/assets/4572601b-42df-48f6-896d-e2e0ce28486d)

  f. Pada saat yang sama, dungeon yang dibuat oleh sistem juga harus dapat diakses oleh hunter. Sung Jin Woo menambahkan fitur yang menampilkan semua dungeon yang tersedia sesuai dengan level hunter. Disini, hunter hanya dapat menampilkan dungeon dengan level minimum yang sesuai dengan level mereka.

  ![Image](https://github.com/user-attachments/assets/d73dc642-fc22-4683-b8b5-e32485b98dd1)

  g. Setelah melihat beberapa hunter yang terlalu kuat, Sung Jin Woo memutuskan untuk menambahkan fitur untuk menguasai dungeon. Ketika hunter berhasil menaklukan sebuah dungeon, dungeon tersebut akan menghilang dari sistem dan hunter akan mendapatkan stat rewards dari dungeon. Jika exp hunter mencapai 500, mereka akan naik level dan exp kembali ke 0.

  ![Image](https://github.com/user-attachments/assets/9a44d27e-927b-4c4e-98bf-8de8a668a7f1)

  h. Karena persaingan antar hunter semakin ketat, Sung Jin Woo mengimplementasikan fitur dimana hunter dapat memilih untuk bertarung dengan hunter lain. Tingkat kekuatan seorang hunter bisa dihitung melalui total stats yang dimiliki hunter tersebut (ATK+HP+DEF). Jika hunter menang, maka hunter tersebut akan mendapatkan semua stats milik lawan dan lawannya akan terhapus dari sistem. Jika kalah, hunter tersebutlah yang akan dihapus dari sistem dan semua statsnya akan diberikan kepada hunter yang dilawannya.

  ![Image](https://github.com/user-attachments/assets/2c738396-662c-4c7c-b716-c584c92ecd76)

  i. Saat sedang memonitoring sistem, Sung Jin Woo melihat beberapa hunter melakukan kecurangan di dalam sistem. Ia menambahkan fitur di sistem yang membuat dia dapat melarang hunter tertentu untuk melakukan raid atau battle. Karena masa percobaan tak bisa berlangsung selamanya 😇, Sung Jin Woo pun juga menambahkan konfigurasi agar fiturnya dapat memperbolehkan hunter itu melakukan raid atau battle lagi. 

  j. Setelah beberapa pertimbangan, untuk memberikan kesempatan kedua bagi hunter yang ingin bertobat dan memulai dari awal, Sung Jin Woo juga menambahkan fitur di sistem yang membuat dia bisa mengembalikan stats hunter tertentu ke nilai awal.

  k. Untuk membuat sistem lebih menarik dan tidak membosankan, Sung Jin Woo menambahkan fitur notifikasi dungeon di setiap hunter. Saat diaktifkan, akan muncul informasi tentang semua dungeon yang terbuka dan akan terus berganti setiap 3 detik.

  ![Image](https://github.com/user-attachments/assets/99bb6523-8a40-4678-a5e0-59accb206325)

  l. Terakhir, untuk menambah keamanan sistem agar data hunter tidak bocor, Sung Jin Woo melakukan konfigurasi agar setiap kali sistem dimatikan, maka semua shared memory yang sedang berjalan juga akan ikut terhapus.


### Soal 1

  ## Script delivery_agent.c

a.) Fungsi Pengiriman Paket Express oleh Agen
```
void *agent_thread(void *arg) {
    char *agent_name = (char *) arg;

    while (1) {
        for (int i = 0; i < *order_count; ++i) {
            if (strcmp(orders[i].type, "Express") == 0 &&
                strcmp(orders[i].status, "Pending") == 0) {
                // tandai sebagai delivered
                snprintf(orders[i].status, sizeof(orders[i].status), "Agent %s", agent_name);
                write_log(agent_name, orders[i].name, orders[i].address);
                sleep(1);
            }
        }
        sleep(1);
    }

    return NULL;
}
```
  - Fungsi ini dijalankan sebagai thread oleh masing-masing agen pengantar.
    - agent_name: Nama agen (misal "A", "B", atau "C") yang diberikan sebagai argumen thread.
  - Melakukan looping terus-menerus untuk:
    - Memeriksa semua pesanan dalam shared memory.
    - Jika ada pesanan bertipe Express dan berstatus Pending, maka:
      - Status pesanan diubah menjadi "Agent X" (misal "Agent A").
      - Log pengiriman ditulis ke file delivery.log.
      - Menunggu selama 1 detik agar tidak memproses terlalu cepat.

  - Memberi delay 1 detik antar pemeriksaan ulang pesanan.
   
b.) Fungsi Logging Pengiriman
```
void write_log(const char *agent, const char *name, const char *address) {
    FILE *log = fopen("delivery.log", "a");
    if (!log) return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(log, "[%02d/%02d/%04d %02d:%02d:%02d] [%s] Express package delivered to %s in %s\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, agent, name, address);

    fclose(log);
}
```
  - Mencatat informasi pengiriman ke file delivery.log dalam format waktu dan detail pengiriman.
  - Format log:
    [DD/MM/YYYY HH:MM:SS] [Agent] Express package delivered to Nama in Alamat

c.) Struktur Data Pesanan
```
typedef struct {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char type[10];
    char status[64];
} Order;
```
  - Struktur untuk menyimpan satu data pesanan, meliputi:
    - name: Nama penerima.
    - address: Alamat tujuan.
    - type: Jenis pengiriman, seperti "Express".
    - status: Status pesanan ("Pending", atau nama agen yang mengantar).

d.) Fungsi Utama (main)
```
int main() {
    key_t key = ftok("sharedfile", 65);
    int shmid = shmget(key, sizeof(Order) * MAX_ORDER + sizeof(int), 0666);
    orders = (Order *) shmat(shmid, NULL, 0);
    order_count = (int *)(orders + MAX_ORDER);

    pthread_t tid[3];
    char *agents[] = {"A", "B", "C"};

    for (int i = 0; i < 3; ++i)
        pthread_create(&tid[i], NULL, agent_thread, agents[i]);

    for (int i = 0; i < 3; ++i)
        pthread_join(tid[i], NULL);

    shmdt(orders);
    return 0;
}
```
  - Mengakses shared memory untuk membaca data pesanan (orders) dan jumlah pesanan (order_count).
  - Membuat 3 thread agen ("A", "B", "C") yang akan menjalankan fungsi agent_thread.
  - Menunggu semua thread selesai (meskipun dalam kasus ini akan berjalan terus karena while(1)).
  - Melepas shared memory dengan shmdt.


### Soal 2 
a. Mengunduh file delivery_order.csv & menyimpan ke sherd memory 

   ---
   void load_orders_from_csv(const char *filename) {
    ...
    sscanf(line, "%[^,],%[^,],%[^\n]", orders[*order_count].name,      orders[*order_count].address, orders[*order_count].type);
    strcpy(orders[*order_count].status, "Pending");
    ...
}

if (argc == 2 && strcmp(argv[1], "-init") == 0) {
    load_orders_from_csv("delivery_order.csv");
}
   ---

![Screenshot 2025-05-08 223126](https://github.com/user-attachments/assets/5cf03c93-d9ec-484e-a9e0-e4fb33e9063e)

b. Pengiriman Bertipe Express (Otomatis oleh AGENT A/B/C)

   ---
   pthread_t tid[3];
char *agents[] = {"A", "B", "C"};
for (int i = 0; i < 3; ++i)
    pthread_create(&tid[i], NULL, agent_thread, agents[i]);

void *agent_thread(void *arg) {
    ...
    if (strcmp(orders[i].type, "Express") == 0 &&
        strcmp(orders[i].status, "Pending") == 0) {
        snprintf(orders[i].status, sizeof(orders[i].status), "Agent %s", agent_name);
        write_log(agent_name, orders[i].name, orders[i].address);
    }
}

   ---
![Screenshot 2025-05-08 223342](https://github.com/user-attachments/assets/175c27ab-7243-47e7-b9aa-397101b3c13c)

c.  Pengiriman Bertipe Reguler (Manual oleh User)

   ---
  } else if (argc == 3 && strcmp(argv[1], "-deliver") == 0) {
    ...
    if (strcmp(orders[i].type, "Reguler") == 0 &&
        strcmp(orders[i].status, "Pending") == 0) {
        char *username = getenv("USER");
        if (!username) username = "UnknownUser";
        snprintf(orders[i].status, sizeof(orders[i].status), "AGENT %s", username);
        write_log(username, orders[i].name, orders[i].address, "Reguler");
    }
}

   ---
![image](https://github.com/user-attachments/assets/7838d5a0-aee6-4665-8669-cf6c39745396)

d. Mengechek Setatus Pesanan

   ---
   } else if (argc == 2 && strcmp(argv[1], "-list") == 0) {
    for (int i = 0; i < *order_count; ++i) {
        printf("%s - %s\n", orders[i].name, orders[i].status);
    }
}

   ---
![image](https://github.com/user-attachments/assets/ae1920ed-33d4-4576-8dd5-ef29585134ac)

e. Format Log Pengiriman
   ---
  void write_log(...) {
    fprintf(log, "[%02d/%02d/%04d %02d:%02d:%02d] [%s] Express package delivered to %s in %s\n",
            ..., agent, name, address);
      
          
  id write_log(...) {
    if (strcmp(type, "Express") == 0)
        ...
    else
        fprintf(log, "[...][AGENT %s] Reguler package delivered to %s in %s\n", ...);
   ---

![image](https://github.com/user-attachments/assets/06495c33-d347-43c1-a410-e7dd45ef4c7d)

###Soal 3

  ## Script dungeon.c

a.) Fungsi get_player
```
Player* get_player(int sock) {
    for (int i = 0; i < player_count; i++) {
        if (players[i].socket == sock) return &players[i];
    }
    players[player_count].socket = sock;
    players[player_count].gold = 100;
    players[player_count].base_damage = 10;
    players[player_count].equipped = &weapon_list[0];
    players[player_count].inventory[0] = &weapon_list[0];
    players[player_count].inv_count = 1;
    players[player_count].enemies_defeated = 0;
    return &players[player_count++];
}
```
  - Mencari player berdasarkan socket.
  - Jika belum ada, data player baru dibuat:
    - Gold awal: 100
    - Senjata awal: weapon_list[0]
    - Damage dasar: 10
    - Inventory awal: 1 senjata
    - Musuh dikalahkan: 0

b.) Fungsi handle_client
```
void* handle_client(void* arg)
```
  - Fungsi ini dijalankan sebagai thread untuk menangani satu klien.

c.) Fungsi main
```
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    init_shop();

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 10);
    printf("Server started on port %d\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))) {
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &new_socket);
    }

    return 0;
```
  - Inisialisasi shop dengan init_shop().
  - Membuat socket TCP pada port 8080.
  - Mengikat socket ke alamat lokal dan mulai listening hingga 10 klien.
  - Untuk setiap koneksi masuk:
    - Membuat thread baru untuk handle_client.

  ## Script shop.c

a.) Fungsi init_shop
```
void init_shop() {
    strcpy(weapon_list[0].name, "Fists"); weapon_list[0].price = 0; weapon_list[0].damage = 5; weapon_list[0].has_passive = 0;
    strcpy(weapon_list[1].name, "Sword"); weapon_list[1].price = 50; weapon_list[1].damage = 15; weapon_list[1].has_passive = 0;
    strcpy(weapon_list[2].name, "Axe"); weapon_list[2].price = 80; weapon_list[2].damage = 20; weapon_list[2].has_passive = 1; strcpy(weapon_list[2].passive, "Extra 5 Gold per Kill");
    strcpy(weapon_list[3].name, "Dagger"); weapon_list[3].price = 30; weapon_list[3].damage = 10; weapon_list[3].has_passive = 1; strcpy(weapon_list[3].passive, "10%% Lifesteal");
    strcpy(weapon_list[4].name, "Hammer"); weapon_list[4].price = 100; weapon_list[4].damage = 25; weapon_list[4].has_passive = 0;
}
```
  - Menginisialisasi daftar senjata (weapon_list) sebanyak 5 jenis.

  - Setiap senjata memiliki:
    - name: Nama senjata
    - price: Harga dalam gold
    - damage: Tambahan damage senjata
    - has_passive: 1 jika punya efek tambahan
    - passive: Deskripsi efek pasif

b.) Fungsi get_shop_display
```
void get_shop_display(char* out) {
    strcpy(out, "Available Weapons:\n");
    for (int i = 0; i < MAX_WEAPONS; i++) {
        char line[200];
        sprintf(line, "%s - Price: %d, Damage: %d%s\n", weapon_list[i].name, weapon_list[i].price, weapon_list[i].damage,
                weapon_list[i].has_passive ? (char[100]) { sprintf((char[100]){}, ", Passive: %s", weapon_list[i].passive), (char[100]){} } : "");
        strcat(out, line);
    }
```
  - Mengisi string out dengan daftar senjata yang tersedia.

c.) Fungsi buy_weapon
```
Weapon* buy_weapon(const char* name, int* gold) {
    for (int i = 0; i < MAX_WEAPONS; i++) {
        if (strcmp(weapon_list[i].name, name) == 0 && *gold >= weapon_list[i].price) {
            *gold -= weapon_list[i].price;
            return &weapon_list[i];
        }
    }
    return NULL;
}
```
  - Fungsi pembelian senjata berdasarkan nama:
    - Mencari senjata yang namanya cocok
    - Memeriksa apakah gold pemain cukup
    - Jika cukup, gold dikurangi dan pointer ke senjata dikembalikan
    - Jika gagal (tidak cukup gold atau nama salah), mengembalikan NUL

  ## Script player.c
  
a.) Fungsi Menu
```
void menu(int sockfd) {
    char buffer[MAX];
    int choice;

    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Show Stats\n");
        printf("2. Shop\n");
        printf("3. Inventory\n");
        printf("4. Battle\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        sprintf(buffer, "%d", choice);
        send(sockfd, buffer, strlen(buffer), 0);

        if (choice == 5) break;

        int valread = recv(sockfd, buffer, sizeof(buffer), 0);
        buffer[valread] = '\0';
        printf("%s\n", buffer);
    }
}
```
  - Pemain memilih opsi (input disimpan dalam choice)
  - Pilihan dikirim ke server (send(sockfd, buffer, strlen(buffer), 0))
  - Jika pilihan bukan 5 (exit), maka client:
    - Menerima balasan dari server (recv)
    - Mencetak isi buffer sebagai respon dari server

b.) Fungsi Main
```
int main()
```
  - Membangun koneksi ke server:
    
```
sockfd = socket(AF_INET, SOCK_STREAM, 0);
```
  - Membuat socket TCP (SOCK_STREAM)
    
```
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);
serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
```
  - Mengatur informasi IP dan port ke localhost (127.0.0.1:8080)

```
connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))
```
  - Mencoba koneksi ke server. Jika gagal, program keluar dengan error.
  - Setelah terkoneksi:
    - Menjalankan menu(sockfd)
    - Menutup koneksi setelah selesai (close(sockfd))

###Soal 4

a.  Registrasi dan Login Hunter
    
  ---
  hunter_data->level = 1;
  hunter_data->exp = 0;
  hunter_data->atk = 10;
  hunter_data->hp = 100;
  hunter_data->def = 5;
  ---
  ![Screenshot 2025-05-08 225035](https://github.com/user-attachments/assets/27e65699-8b77-405f-b437-519a2ae88fe7)

b. Menampilkan Semua Data Hunter 
    Admin bisa melihat semua hunter yang terdaftar lengkap dengan stat dan status    banned.
    
  ---
  printf("Nama: %s | Level: %d | EXP: %d | ATK: %d | HP: %d | DEF: %d | Status: % s\n",
       data[i].name, data[i].level, data[i].exp,
       data[i].atk, data[i].hp, data[i].def,
       data[i].banned ? "Banned" : "Aktif");
  ---
  ![image](https://github.com/user-attachments/assets/cb53eaff-c409-4bff-9bdf-f70d5e5cebde)

c. Dungeon Generator (system.c).
    Dungeon di-generate acak dengan nilai sesuai rentang soal, dan disimpan dalam shared memory dungeon. 
    ---
    dungeons[i].min_level = (rand() % 5) + 1;
    dungeons[i].atk_reward = (rand() % 51) + 100;
    dungeons[i].hp_reward = (rand() % 51) + 50;
    dungeons[i].def_reward = (rand() % 26) + 25;
    dungeons[i].exp_reward = (rand() % 151) + 150;
    ---
![image](https://github.com/user-attachments/assets/32c8c88b-d2af-48e3-a375-31d1e35b9a66)

d. Menampilkan Semua Dungeon (Admin).
     Admin bisa lihat seluruh dungeon beserta reward dan key-nya.
    
    ---
  printf("Dungeon %d: Nama: %s | Level Min: %d | EXP: %d | ATK: %d | HP: %d |   DEF: %d\n",
  i + 1, dungeons[i].name, dungeons[i].min_level,
   dungeons[i].exp_reward, dungeons[i].atk_reward,
  dungeons[i].hp_reward, dungeons[i].def_reward);

    ---

e. Menampilkan Dungeon Sesuai Level Hunter.
    Hunter hanya bisa melihat dungeon dengan min_level <= level hunter.
    ---
    if (hunter_data->level >= dungeons[i].min_level)

   ---
f. Menaklukkan Dungeon (hunter.c).
   ---
  if (hunter_data->exp >= 500) {
    hunter_data->level++;
    hunter_data->exp = 0;
}
    ---


g. Hunter Battle (hunter.c).
    Hitung total stat, hunter kalah dihapus, hunter menang ambil semua stat lawan.

   ---
   stat_a = hunter_data->atk + hunter_data->hp + hunter_data->def;
   int stat_b = target->atk + target->hp + target->def;
   ---
   ![image](https://github.com/user-attachments/assets/2778e64c-9993-4f96-86e5-2a8ac8b235f2)

h. Ban / Unban Hunter (system.c),dan notifikasi Dungeon 3 Detik Sekali (hunter.c)
   ---
   sleep(3);

   ---
   ![image](https://github.com/user-attachments/assets/70366583-db26-4f48-9b2c-7154308f94e6)

i.Semua Shared Memory Terhapus Saat Sistem Dimatikan (system.c)
 ---
  shmctl(..., IPC_RMID, NULL);
 ---

![image](https://github.com/user-attachments/assets/adc738f4-e35e-421c-905f-05d5c0e92df9)


