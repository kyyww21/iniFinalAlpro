void pengembalianBuku() {
    char nama[50];
    char kelas[20];
    char kode[20];
    int ditemukan = 0;
    int jumlahKembali;

    printf("\n--- Pengembalian Buku ---\n");

    printf("Masukkan Nama : ");
    scanf(" %[^\n]", nama);

    printf("Masukkan Kelas : ");
    scanf(" %[^\n]", kelas);

    printf("Masukkan Kode Buku : ");
    scanf(" %[^\n]", kode);
    // Cari data peminjaman yang sesuai
    for (int i = 0; i < totalPeminjaman; i++) {
        if (strcmp(daftarPeminjaman[i].NamaPeminjam, nama) == 0 &&
            strcmp(daftarPeminjaman[i].KodeBuku, kode) == 0 &&
            strcmp(daftarPeminjaman[i].Kelas, kelas) == 0) {
            ditemukan = 1;

            printf("\n-- Data Peminjaman Ditemukan --\n");
            printf("Nama Peminjam : %s\n", daftarPeminjaman[i].NamaPeminjam);
            printf("Kelas         : %s\n", daftarPeminjaman[i].Kelas);
            printf("Judul Buku    : %s\n", daftarPeminjaman[i].JudulBuku);
            printf("Jumlah Pinjam : %d\n", daftarPeminjaman[i].jumlahPinjam);

            printf("\nMasukkan Jumlah yang Ingin Dikembalikan : ");
            scanf("%d", &jumlahKembali);

            if (jumlahKembali <= 0) {
                printf("\n-- Jumlah tidak valid! --\n");
            } else if (jumlahKembali > daftarPeminjaman[i].jumlahPinjam) {
                printf("\n-- Jumlah pengembalian melebihi jumlah pinjaman! --\n");
                printf("Jumlah yang dipinjam hanya %d buku\n", daftarPeminjaman[i].jumlahPinjam);
            } else {
                // Update stok buku di perpustakaan
                for (int j = 0; j < totalBuku; j++) {
                    if (strcmp(perpustakaan[j].Kode, kode) == 0) {
                        // UPDATE: Kurangi status sedangDipinjam
                        perpustakaan[j].sedangDipinjam -= jumlahKembali;
                        break;
                    }
                }

                // Update jumlah pinjaman di struct Peminjaman
                daftarPeminjaman[i].jumlahPinjam -= jumlahKembali;

                printf("\n-- Pengembalian Berhasil! --\n");

                // Jika semua buku sudah dikembalikan, hapus data peminjaman
                if (daftarPeminjaman[i].jumlahPinjam == 0) {
                    printf("\n-- Semua buku telah dikembalikan! Data peminjaman dihapus. --\n");

                    // Geser data peminjaman
                    for (int k = i; k < totalPeminjaman - 1; k++) {
                        daftarPeminjaman[k] = daftarPeminjaman[k + 1];
                    }
                    totalPeminjaman--;
                    // Mundurkan index i karena array bergeser, agar tidak skip data
                    i--;
                } else {
                    printf("Sisa Pinjaman : %d buku\n", daftarPeminjaman[i].jumlahPinjam);
                }
            }
            break; // Keluar loop setelah ketemu
        }
    }

    if (!ditemukan) {
        printf("\n-- Data peminjaman tidak ditemukan! --\n");
    }
}