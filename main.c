void sortingNamaPeminjam() {
    struct Buku temp;

    for (int i = 0; i < totalPeminjaman - 1; i++) {
        for (int j = 0; j < totalPeminjaman - i - 1; j++) {
            if (strcmp(daftarPeminjaman[j].NamaPeminjam, daftarPeminjaman[j+1].NamaPeminjam) > 0) {
                temp = daftarPeminjaman[j];
                daftarPeminjaman[j] = daftarPeminjaman[j+1];
                daftarPeminjaman[j+1] = temp;
            }
        }
    }
}