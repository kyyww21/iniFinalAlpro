#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Buku {
    char Judul[50];
    char Kode[20];
    int jumlahTotal;      
    int sedangDipinjam; 
};

struct Peminjaman {
    char NamaPeminjam[50];
    char Kelas[10];
    char KodeBuku[20];
    char JudulBuku[50];
    int jumlahPinjam;
};

struct Buku perpustakaan[100];
struct Peminjaman daftarPeminjaman[200];
int totalBuku = 0;
int totalPeminjaman = 0;


void penambahanBuku() {
    char kode[20];
    int jumlahTambah;
    int ditemukan = 0;

    printf("\n--- Tambah Buku ---\n");
    printf("Masukkan Kode Buku  : ");
    scanf(" %[^\n]", kode);

    
    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;

            printf("\n-- Buku ditemukan! --\n");
            printf("Judul: %s\n", perpustakaan[i].Judul);
            printf("Stok Total: %d\n", perpustakaan[i].jumlahTotal);
            printf("\nMasukkan jumlah yang ingin ditambahkan : ");
            scanf("%d", &jumlahTambah);

            perpustakaan[i].jumlahTotal += jumlahTambah;

            printf("\n-- Stok berhasil ditambahkan! --\n");
            printf("Stok baru: %d\n", perpustakaan[i].jumlahTotal);
            break;
        }
    }

    if (!ditemukan) {
        if (totalBuku >= 100) {
            printf("Penyimpanan penuh!\n");
            return;
        }

        printf("\n-- Buku baru, silakan lengkapi data --\n");

        strcpy(perpustakaan[totalBuku].Kode, kode);

        printf("Masukkan Judul Buku : ");
        scanf(" %[^\n]", perpustakaan[totalBuku].Judul);

        printf("Masukkan Jumlah     : ");
        scanf(" %d", &perpustakaan[totalBuku].jumlahTotal);

        
        perpustakaan[totalBuku].sedangDipinjam = 0;

        totalBuku++;
        printf("\n-- Buku baru berhasil ditambahkan --\n");
    }
}

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

void bubbleSortBuku() {
    struct Buku temp;

    for (int i = 0; i < totalBuku - 1; i++) {
        for (int j = 0; j < totalBuku - i - 1; j++) {
            if (strcmp(perpustakaan[j].Judul, perpustakaan[j+1].Judul) > 0) {
                temp = perpustakaan[j];
                perpustakaan[j] = perpustakaan[j+1];
                perpustakaan[j+1] = temp;
            }
        }
    }
}

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
