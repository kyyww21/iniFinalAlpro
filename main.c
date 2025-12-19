void daftarBuku() {
    if (totalBuku == 0) {
        printf("\n-- Belum ada buku di perpustakaan --\n");
        return;
    }
    printf("\n%-37s=== DAFTAR SEMUA BUKU ===%-37s\n", " ", " ");
    printf("==================================================================================================\n");
    printf("%-3s|%-50s|%-10s|%-10s|%-10s|%-10s\n","No.", "Judul", "Kode", "Total", "Dipinjam", "Tersedia");
    printf("--------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalBuku; i++) {
        int dipinjam = perpustakaan[i].sedangDipinjam;
        int tersedia = perpustakaan[i].jumlahTotal - dipinjam;

        printf("%-3d|%-50s|%-10s|%-10d|%-10d|%-10d\n",
               i+1,
               perpustakaan[i].Judul,
               perpustakaan[i].Kode,
               perpustakaan[i].jumlahTotal,
               dipinjam,
               tersedia);
    }
    printf("==================================================================================================\n");
}