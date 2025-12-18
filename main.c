#include <stdio.h>
#include <stdio.h>

void selesaiPerubahan(){
    printf("Perubahan Telah Disimpan");
}

void selesai(){
    printf("Terimakasih");
}

void menu();

void subMenu1(){

    char subOpsi1;

    printf("\n=== OPSI ===\n1. Penambahan Buku\n2. Penghapusan Buku\n3. Daftar Peminjam\n4. Daftar Buku\n5. Clear Screen\n6. Kembali\nMasukkan Opsi Anda :");
    scanf(" %c", subOpsi1);

    switch(subOpsi1){
        case '1':
            selesaiPerubahan();
            break;
        case '2':
            selesaiPerubahan();
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        default:
            printf("Tidak ada opsi %c di dalam daftar opsi, Silahkan pilih kembali", subOpsi1);
            break;
    }
}

void subMenu2(){

    char subOpsi2;

    printf("\n=== OPSI ===\n1. Peminjaman Buku\n2. Pengembalian Buku\n3. Clear Screen\n4. Kembali\nMasukkan Opsi Anda :");
    scanf(" %c", subOpsi2);

    switch(subOpsi2){
        case '1':
            selesaiPerubahan();
            break;
        case '2':
            selesaiPerubahan();
            break;
        case '3':
            break;
        case '4':
            break;
        default:
            printf("Tidak ada opsi %c di dalam daftar opsi, Silahkan pilih kembali", subOpsi2);
            break;
    }
}

void menu(){

    char opsi;

    printf("\n=== OPSI ===\n1. Operator\n2. Pengunjung\n3. Clear Screen\n4. Selesai\nMasukkan Opsi Anda :");
    scanf(" %c", opsi);

    switch(opsi){
        case '1':
            subMenu1();
            break;
        case '2':
            subMenu2();
            break;
        case '3':
            break;
        case '4':
            selesai();
            break;
        default:
            printf("Tidak ada opsi %c di dalam daftar opsi, Silahkan pilih kembali", opsi);
            break;
    }
}

int main(){
    menu();
}