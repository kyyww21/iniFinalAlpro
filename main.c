void daftarPeminjam(){

    if (totalPeminjaman == 0){
        printf("\n-- Belum ada data peminjaman --\n");
        return;
    }

    printf("\n=== DAFTAR PEMINJAM BUKU ===\n");
    printf("%-20s %-10s %-30s %-10s\n", "Nama Peminjam", "Kelas", "Judul Buku", "Jml Pinjam");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalPeminjaman; i++) {
        printf("%-20s %-10s %-30s %-10d\n",
               daftarPeminjaman[i].NamaPeminjam,
               daftarPeminjaman[i].Kelas,
               daftarPeminjaman[i].JudulBuku,
               daftarPeminjaman[i].jumlahPinjam);
    }
    printf("==============================================================================\n");
}