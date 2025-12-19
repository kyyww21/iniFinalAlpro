void peminjamanBuku() {
    char nama[50];
    char kelas[20];
    char kode[20];
    int ditemukan = 0;
    int jumlahPinjam;

    printf("\n--- Peminjaman Buku ---\n");

    printf("Masukkan Nama Peminjam : ");
    scanf(" %[^\n]", nama);

    printf("Masukkan Kelas         : ");
    scanf(" %[^\n]", kelas);

    printf("Masukkan Kode Buku     : ");
    scanf(" %[^\n]", kode);

    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;

            int tersedia = perpustakaan[i].jumlahTotal - perpustakaan[i].sedangDipinjam;

            printf("\n-- Buku Ditemukan --\n");
            printf("Judul Buku    : %s\n", perpustakaan[i].Judul);
            printf("Kode Buku     : %s\n", perpustakaan[i].Kode);
            printf("Stok Tersedia : %d\n", tersedia);

            if (tersedia > 0) {
                printf("\nMasukkan Jumlah yang Ingin Dipinjam : ");
                scanf("%d", &jumlahPinjam);

                if (jumlahPinjam <= 0) {
                    printf("\n-- Jumlah tidak valid! --\n");
                } else if (jumlahPinjam > tersedia) {
                    printf("\n-- Stok tidak mencukupi! --\n");
                    printf("Stok tersedia hanya %d buku\n", tersedia);
                } else {
                    strcpy(daftarPeminjaman[totalPeminjaman].NamaPeminjam, nama);
                    strcpy(daftarPeminjaman[totalPeminjaman].Kelas, kelas);
                    strcpy(daftarPeminjaman[totalPeminjaman].KodeBuku, kode);
                    strcpy(daftarPeminjaman[totalPeminjaman].JudulBuku, perpustakaan[i].Judul);
                    daftarPeminjaman[totalPeminjaman].jumlahPinjam = jumlahPinjam;
                    totalPeminjaman++;

                    perpustakaan[i].sedangDipinjam += jumlahPinjam;

                    printf("\n-- Peminjaman Berhasil! --\n");
                    printf("Nama Peminjam : %s\n", nama);
                    printf("Kelas / Guru  : %s\n", kelas);
                    printf("Nama Buku     : %s\n", perpustakaan[i].Judul);
                    printf("Jumlah Pinjam : %d\n", jumlahPinjam);
                }
            } else {
                printf("\n-- Maaf, stok buku habis dipinjam --\n");
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Buku dengan kode '%s' tidak ditemukan --\n", kode);
    }
}