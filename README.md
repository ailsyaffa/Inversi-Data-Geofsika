Kelompok 15

Program Inversi Data Geofisika

Ailsa Syaffa Dynia (1806199871)

Anugrah Indah Lestari (1906324302)

## Program Inversi Data Geofisika
Umumnya, kegiatan eksplorasi geofisika dilakukan untuk membuat model bawah permukaan bumi berdasarkan pengukuran lapangan. Penghubung antara parameter fisis dan data observasi adalah berupa model matematika sehingga diperoleh parameter fisis bawah permukaan yang disebut sebagai proses inversi. Dalam program menggunakan bahasa C ini, terdapat empat jenis permasalah dalam bidang geofisika yang diselesaikan yakni:

1.	Seismik refleksi dengan asumsi bidang reflektor miring
 
 <img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/pic1.png" width="400">
 
(Sumber: Supriyanto, 2007)

2.	Seismik refleksi dengan asumsi bidang reflektor datar
  
 <img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/pic2.png" width="400">
 
(Sumber: GPG, 2017)

3.	Seismik refraksi
 
 <img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/pic3.jpg" width="400">
 
(Sumber: Elhaj, 2016)

4.	Model kurva temperatur sumur pemboran

Pengguna diminta untuk memasukan data lapangan untuk dapat memperoleh parameter fisis batuan di bawah permukaan bumi. Parameter fisis yang dapat diperoleh diantaranya kecepatan, kedalaman lapisan batuan, dan sudut kemiringan reflektor, serta model kurva temperatur terhadap kedalaman. Persamaan yang terdapat dalam keempat permasalahan tersebut memenuhi model matematika yang dinyatakan dalam operasi matriks:
     G m = d
dimana: 

     G adalah matriks kernel
     m adalah parameter model
     d adalah data lapangan 
     
Parameter model dapat diperoleh melalui manipulasi matriks melalui:

     m = inv(Gt*G)*Gt*d
dimana Gt merupakan transpose dari matriks kernel.

Parameter fisis batuan di bawah permukaan dapat diperoleh melalui nilai parameter model dan persamaan matematis yang terdapat pada permasalahan geofisika tersebut.

## Tampilan Program

1. Menu

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/menu.png" width="400">

2. Info

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/info.png" width="400">

3. Bantuan

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/bantuan.png" width="400">

4. Input Data

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/io.png" width="400">

5. Matriks G

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/g.png" width="400">

6. Matriks G Transpose

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/gt.png" width="400">

7. Matriks G*Gt

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/gtg.png" width="400">

8. Determinan

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/det.png" width="400">

9. Invers

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/inv.png" width="400">

10. Hasil

<img src="https://github.com/ailsyaffa/Inversi-Data-Geofsika/blob/master/picture/final.png" width="400">


Referensi:

Elhaj, K. 2016. Subsurface Delineation and Cavity Investigation Using Geophysical Methods in Gua Musang, Kelantan, Malaysia. *Master Thesis*. DOI: 10.13140/RG.2.2.33212.85129

Geophysics for Practicing Geoscientists (GPG). 2017. Travel times, https://gpg.geosci.xyz/content/seismic/traveltimes.html. Diakses pada 10 Oktober 2019

Supriyanto. 2007. *Analisis Data Geofisika: Memahami Teori Inversi*. Departemen Fisika-FMIPA Universitas Indonesia: Jakarta
