# PraktikumGTIA2
# Pertemuan 1
# Primitives OpenGL
Nama : Hadrian Shandhy Yudha
Nim : 24060124140207
Lab : GTI-A2

1. Primitive Drawing : merender sebagaimana penggunaan persamaan geometrik sederhana
Contoh primitif grafik dasar adalah Titik, Garis, Segiempat, Kurva, Lingkaran, Ellipse, Kurva Bezier, Text, Fill Area.  
<img width="866" height="703" alt="Screenshot 2026-03-03 122804" src="https://github.com/user-attachments/assets/93f6f76c-ee4c-4b72-8505-f94170be1315" />

2. Titik : GL_POINTS seranggkaian titik(vertex) secara terpisah di layar berdasarkan plotting titik-tiitk tunggal.
<img width="813" height="701" alt="Screenshot 2026-03-03 122850" src="https://github.com/user-attachments/assets/651727ab-f942-4670-a0c3-7e80455767b8" />

3. Garis : GL_LINES serangkaian 2 titik vertex secara terpisah dihubungkan secara berturut menjadi satu garis lurus yang terpisah. Lines memiliki Titik awal dan Titik akhir.
<img width="816" height="701" alt="Screenshot 2026-03-03 122959" src="https://github.com/user-attachments/assets/2b51dc90-e372-4568-ab5f-f3078448eb06" />

4. Segiitiga : GL_TRIANGLES serangkaian 3 titik vertex secara terpisah dihubungkan menjadi satu segitiga terpisah.
<img width="800" height="700" alt="Screenshot 2026-03-03 123814" src="https://github.com/user-attachments/assets/d86eee75-dfa0-4ffc-a670-d81c45b38f85" />

6. Segiempat Penuh : glrectf menggambar rectangle berdasarkan 2 titik sudut yang berlawanan hasil sama seperti memetakan 4 vertex.
<img width="806" height="701" alt="Screenshot 2026-03-03 123402" src="https://github.com/user-attachments/assets/677da94f-11fa-4e5a-996d-c9261a3a8254" />

7. GL Lines Strip : GL_LINES:STRIP menggambar rangkaian garis tersambung yang menghubungkan semua titik secara berurutar vertex1 - vertexKe-n.
<img width="803" height="699" alt="Screenshot 2026-03-10 005453" src="https://github.com/user-attachments/assets/2cd9003f-fdab-4013-8cf6-9b6e2b74fa0c" />

8. GL Line Loop : GL_LINE_LOOP menggambar rangkaian garis tersambung yang menghubungkan semua titik secara berurutar vertex1 - vertexKe-n dan dihungkan kembali terhadap vertex awal.
<img width="804" height="702" alt="Screenshot 2026-03-10 005500" src="https://github.com/user-attachments/assets/b134bff5-c5e7-4565-a531-72015d0c947b" />

9. GL Triangle Strip : GL_TRIANGLE_STRIP menghubungakan segitiga berbagi antar vertex, setiap 3 vertex membentuk satu segitiga mandiri. Penambahan vertex baru akan membentuk segitiga baru yang terhubung menggunakan 2 vertex sebelumnya.
<img width="807" height="704" alt="Screenshot 2026-03-10 011759" src="https://github.com/user-attachments/assets/06905caf-f18e-4e22-bbd2-c85ecd073354" />

10. GL Triangle Fan : GLL_TRIANGLE_FAN menggambarkan vertex awal sebagai titik pusat bersama yang digunakan untuk menghubungkan titik berikutnya mengitari hingga membentuk kipas.
<img width="814" height="704" alt="Screenshot 2026-03-10 011948" src="https://github.com/user-attachments/assets/17e788a3-4820-4f92-b2a5-8c09cbb3c3f1" />

11. GL Quads : GL_QUADS menggambar bentuk segi empat terisi berdasarkan 4 vertex. Mirip dengan Esgiempat Penuh namun menggunakan mode primitif langsung dari lbirary OpenGL.
<img width="805" height="701" alt="Screenshot 2026-03-10 013435" src="https://github.com/user-attachments/assets/1648d01a-69ac-42c5-a25a-1be1ec933f14" />

12. GL Quad Strip : GL_QUAD_STRIP menggambar rangkaian segi empat dimana setiap 2 vertex baru akan membentuk segi empat baru menggunakan 2 vertex sebelumnya.
<img width="803" height="696" alt="image" src="https://github.com/user-attachments/assets/a730c580-a7e1-422d-822d-1bb64c3f9dc5" />

REFERENCES : 
<img width="450" height="651" alt="image" src="https://github.com/user-attachments/assets/f9aa2a5d-e6bb-4f8e-9e6a-0051877ca376" />






































































