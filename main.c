void hapusData() {
    char id[20];
    int ditemukan = 0;

    if (totalBuku == 0) {
        printf("Data kosong, tidak ada yang dihapus.\n");
        return;
    }

    printf("Masukkan Kode Buku yang ingin dihapus: ");
    scanf(" %[^\n]", id);

    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, id) == 0) {
            ditemukan = 1;

            
            for (int j = i; j < totalBuku - 1; j++) {
                perpustakaan[j] = perpustakaan[j + 1];
            }

            totalBuku--;
            printf("Data berhasil dihapus!\n");
            break;
        }
    }

    if (!ditemukan) {
        printf("Data tidak ditemukan!\n");
    }
}