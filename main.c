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