#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Buku {
    char judulBuku[50];
    char kodeBuku[20];
    int jumlahTotal;      
    int sedangDipinjam; 
};

struct Peminjaman {
    char namaPeminjam[50];
    char kelasPinjam[10];
    char kodeBukuPinjam[20];
    char judulBukuPinjam[50];
    int jumlahPinjam;
};

struct Buku perpustakaan[500];
struct Peminjaman daftarPeminjaman[1000];
int totalBuku = 0;
int totalPeminjaman = 0;

void clear() {
    system("cls");
}

int inputInteger(const char* teks) {
    int isi;
    int hasil;

    while (1) {
        printf("%s", teks);
        hasil = scanf("%d", &isi);
        if (hasil == 1) {
            while(getchar() != '\n'); 
            return isi;
        } else {
            printf("\n-- Input tidak valid! Harap masukkan angka. --\n\n");
            while(getchar() != '\n'); 
        }
    }
}

void penambahanBuku() {
    char kode[20];
    int jumlahTambah;
    int ditemukan = 0;

    printf("\n--- Tambah Buku ---\n");
    printf("Masukkan Kode Buku  : ");
    scanf(" %[^\n]", kode);

    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].kodeBuku, kode) == 0) {
            ditemukan = 1;

            printf("\n-- Buku ditemukan --\n");
            printf("Judul: %s\n", perpustakaan[i].judulBuku);
            printf("Stok Total: %d\n", perpustakaan[i].jumlahTotal);
            jumlahTambah = inputInteger("Masukkan jumlah yang ingin ditambahkan : ");
            
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

        strcpy(perpustakaan[totalBuku].kodeBuku, kode);

        printf("Masukkan Judul Buku : ");   
        scanf(" %[^\n]", perpustakaan[totalBuku].judulBuku);
        perpustakaan[totalBuku].jumlahTotal = inputInteger("Masukkan Jumlah     : ");

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
        if (strcmp(perpustakaan[i].kodeBuku, kode) == 0) {
            ditemukan = 1;

            int tersedia = perpustakaan[i].jumlahTotal - perpustakaan[i].sedangDipinjam;

            printf("\n-- Buku Ditemukan --\n");
            printf("Judul Buku    : %s\n", perpustakaan[i].judulBuku);
            printf("Kode Buku     : %s\n", perpustakaan[i].kodeBuku);
            printf("Stok Tersedia : %d\n", tersedia);

            jumlahPinjam = inputInteger("\nMasukkan Jumlah yang Ingin Dipinjam : ");

            if (jumlahPinjam <= 0) {
                printf("\n-- Jumlah tidak valid! --\n");
            } else {
                strcpy(daftarPeminjaman[totalPeminjaman].namaPeminjam, nama);
                strcpy(daftarPeminjaman[totalPeminjaman].kelasPinjam, kelas);
                strcpy(daftarPeminjaman[totalPeminjaman].kodeBukuPinjam, kode);
                strcpy(daftarPeminjaman[totalPeminjaman].judulBukuPinjam, perpustakaan[i].judulBuku);
                daftarPeminjaman[totalPeminjaman].jumlahPinjam = jumlahPinjam;
                totalPeminjaman++;

                perpustakaan[i].sedangDipinjam += jumlahPinjam;

                printf("\n-- Peminjaman Berhasil! --\n");
                printf("Nama Peminjam : %s\n", nama);
                printf("Kelas / Guru  : %s\n", kelas);
                printf("Nama Buku     : %s\n", perpustakaan[i].judulBuku);
                printf("Jumlah Pinjam : %d\n", jumlahPinjam);
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Buku dengan kode '%s' tidak ditemukan --\n", kode);
    }
}

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

    for (int i = 0; i < totalPeminjaman; i++) {
        if (strcmp(daftarPeminjaman[i].namaPeminjam, nama) == 0 &&
            strcmp(daftarPeminjaman[i].kodeBukuPinjam, kode) == 0 &&
            strcmp(daftarPeminjaman[i].kelasPinjam, kelas) == 0) {
            ditemukan = 1;

            printf("\n-- Data Peminjaman Ditemukan --\n");
            printf("Nama Peminjam : %s\n", daftarPeminjaman[i].namaPeminjam);
            printf("Kelas         : %s\n", daftarPeminjaman[i].kelasPinjam);
            printf("Judul Buku    : %s\n", daftarPeminjaman[i].judulBukuPinjam);
            printf("Jumlah Pinjam : %d\n", daftarPeminjaman[i].jumlahPinjam);

            jumlahKembali = inputInteger("\nMasukkan Jumlah yang Ingin Dikembalikan : ");

            if (jumlahKembali <= 0) {
                printf("\n-- Jumlah tidak valid! --\n");
            } else if (jumlahKembali > daftarPeminjaman[i].jumlahPinjam) {
                printf("\n-- Jumlah pengembalian melebihi jumlah pinjaman! --\n");
                printf("Jumlah yang dipinjam hanya %d buku\n", daftarPeminjaman[i].jumlahPinjam);
            } else {

                for (int j = 0; j < totalBuku; j++) {
                    if (strcmp(perpustakaan[j].kodeBuku, kode) == 0) {
                        perpustakaan[j].sedangDipinjam -= jumlahKembali;
                        break;
                    }
                }

                daftarPeminjaman[i].jumlahPinjam -= jumlahKembali;
                printf("\n-- Pengembalian Berhasil! --\n");

                if (daftarPeminjaman[i].jumlahPinjam == 0) {
                    printf("\n-- Semua buku telah dikembalikan! Data peminjaman dihapus. --\n");
                    for (int k = i; k < totalPeminjaman - 1; k++) {
                        daftarPeminjaman[k] = daftarPeminjaman[k + 1];
                    }
                    totalPeminjaman--;
                    i--;
                } else {
                    printf("Sisa Pinjaman : %d buku\n", daftarPeminjaman[i].jumlahPinjam);
                }
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Data peminjaman tidak ditemukan! --\n");
    }
}

void bubbleSortBuku() {
    struct Buku temp;

    for (int i = 0; i < totalBuku - 1; i++) {
        for (int j = 0; j < totalBuku - i - 1; j++) {
            if (strcmp(perpustakaan[j].judulBuku, perpustakaan[j+1].judulBuku) > 0) {
                temp = perpustakaan[j];
                perpustakaan[j] = perpustakaan[j+1];
                perpustakaan[j+1] = temp;
            }
        }
    }
}

void sortingNamaPeminjam() {
    struct Peminjaman temp;

    for (int i = 0; i < totalPeminjaman - 1; i++) {
        for (int j = 0; j < totalPeminjaman - i - 1; j++) {
            if (strcmp(daftarPeminjaman[j].namaPeminjam, daftarPeminjaman[j+1].namaPeminjam) > 0) {
                temp = daftarPeminjaman[j];
                daftarPeminjaman[j] = daftarPeminjaman[j+1];
                daftarPeminjaman[j+1] = temp;
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
               perpustakaan[i].judulBuku,
               perpustakaan[i].kodeBuku,
               perpustakaan[i].jumlahTotal,
               dipinjam,
               tersedia);
    }
    printf("==================================================================================================\n");
}

void daftarPeminjam(){

    if (totalPeminjaman == 0){
        printf("\n-- Belum ada data peminjaman --\n");
        return;
    }

    printf("\n%-42s=== DAFTAR PEMINJAM ===%-42s\n", " ", " ");
    printf("============================================================================================================\n");
    printf("%-3s|%-30s|%-10s|%-50s|%-10s\n", "No.", "Nama Peminjam", "Kelas", "Judul Buku", "Jml Pinjam");
    printf("------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalPeminjaman; i++) {
        printf("%-3d|%-30s|%-10s|%-50s|%-10d\n",
               i+1,
               daftarPeminjaman[i].namaPeminjam,
               daftarPeminjaman[i].kelasPinjam,
               daftarPeminjaman[i].judulBukuPinjam,
               daftarPeminjaman[i].jumlahPinjam);
    }
    printf("============================================================================================================\n");
}

void hapusData() {
    char idBuku[20];
    int ditemukan = 0;

    if (totalBuku == 0) {
        printf("Data kosong, tidak ada yang dihapus.\n");
        return;
    }

    printf("Masukkan Kode Buku yang ingin dihapus: ");
    scanf(" %[^\n]", idBuku);

    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].kodeBuku, idBuku) == 0) {
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

void menu();

void selesai() {
    printf("Oke, Terimakasih ;)");
}

void selesaiPerubahan() {
    printf("Perubahan Telah Disimpan, Terimakasih ;)\n");
}

void subMenu1() {
    int subOpsi1;

    printf("\n");
    printf("+---------------------------------------------+\n");
    printf("|  No  |           OPSI OPERATOR              |\n");
    printf("+------+--------------------------------------+\n");
    printf("|  [1] |  Penambahan Buku                     |\n");
    printf("|  [2] |  Hapus Buku                          |\n");
    printf("|  [3] |  Daftar Peminjam                     |\n");
    printf("|  [4] |  Daftar Buku                         |\n");
    printf("|  [5] |  Kembali                             |\n");
    printf("|  [6] |  Selesai                             |\n");
    printf("+---------------------------------------------+\n");
    printf("\nMasukkan Pilihan Anda [1-6]: ");

    scanf("%d", &subOpsi1);

    if (subOpsi1 != 1) {
        while(getchar() != '\n');
    }

    switch(subOpsi1) {
        case 1:
            clear();
            penambahanBuku();
            bubbleSortBuku();
            selesaiPerubahan();
            subMenu1();
            break;
        case 2:
            clear();
            hapusData();
            subMenu1();
            break;
        case 3:
            clear();
            sortingNamaPeminjam();
            daftarPeminjam();
            subMenu1();
            break;
        case 4:
            clear();
            daftarBuku();
            subMenu1();
            break;
        case 5:
            clear();
            menu();
            break;
        case 6:
            clear();
            selesai();
            break;
        default:
            printf("\nInput tidak valid.\n");
            subMenu1();
            break;
    }
}

void subMenu2() {
    int subOpsi2;

    printf("\n");
    printf("+---------------------------------------------+\n");
    printf("|  No  |            OPSI PENGUNJUNG           |\n");
    printf("+------+--------------------------------------+\n");
    printf("|  [1] |  Peminjaman Buku                     |\n");
    printf("|  [2] |  Pengembalian Buku                   |\n");
    printf("|  [3] |  Kembali                             |\n");
    printf("|  [4] |  Selesai                             |\n");
    printf("+---------------------------------------------+\n");
    printf("\nMasukkan Pilihan Anda [1-5]: ");

    scanf("%d", &subOpsi2);

    if ( subOpsi2 != 1) {
        while(getchar() != '\n');
    }

    switch(subOpsi2) {
        case 1:
            clear();
            peminjamanBuku();
            selesaiPerubahan();
            subMenu2();
            break;
        case 2:
            clear();
            pengembalianBuku();
            selesaiPerubahan();
            subMenu2();
            break;
        case 3:
            clear();
            menu();
            break;
        case 4:
            clear();
            selesai();
            break;
        default:
            printf("\nInput tidak valid.\n");
            subMenu2();
            break;
    }
}

void menu() {
    int opsi;

    printf("\n");
    printf("+---------------------------------------------+\n");
    printf("|  No  |              MENU UTAMA              |\n");
    printf("+------+--------------------------------------+\n");
    printf("|  [1] |  Operator                            |\n");
    printf("|  [2] |  Pengunjung                          |\n");
    printf("|  [3] |  Selesai                             |\n");
    printf("+---------------------------------------------+\n");
    printf("\nMasukkan Pilihan Anda [1-3]: ");

    scanf("%d", &opsi);

    if (opsi != 1) {
        while(getchar() != '\n');
    }
    switch(opsi) {
        case 1:
            clear();
            subMenu1();
            break;
        case 2:
            clear();
            subMenu2();
            break;
        case 3:
            clear();
            selesai();
            break;
        default:
            printf("\nInput tidak valid.\n");
            menu();
            break;
    }
}

int main(){
    menu();
    return 0;
}
