# PraktikumGTIA2
# Pertemuan 4
# Camera
Nama : Hadrian Shandhy Yudha
Nim : 24060124140207
Lab : GTI-A2

1.Jelaskan apa saja yang harus dilakukan agar dapat menggerakkan objek dengan 
keyboard?
= Objek dapat digerakkan dengan membuat fungsi keyboard callback (glutKeyboardFunc()), mengubah nilai variabel transformasi (misalnya rotAngle), lalu memanggil glutPostRedisplay() agar objek digambar ulang sesuai perubahan.

2. Jelaskan Fungsi GluLookAt!
= gluLookAt() digunakan untuk mengatur posisi kamera, arah pandangan kamera ke objek, serta arah atas (up vector) sehingga menentukan sudut pandang pada scene 3D.

3. Dari kode di atas, terdapat dua proyeksi (Pojection, dan Model View), Jelaskan cara 
kerjanya. Mengapa keduanya digunakan?
Projection Matrix mengatur bagaimana objek diproyeksikan ke layar (misalnya perspektif), sedangkan ModelView Matrix mengatur posisi, orientasi kamera, dan transformasi objek. Keduanya digunakan agar pengaturan tampilan (proyeksi) terpisah dari pengaturan posisi objek dan kamera sehingga lebih mudah dikelola.
<img width="454" height="556" alt="image" src="https://github.com/user-attachments/assets/2d3e7a06-b083-4d8e-b60a-83756547f91a" />
