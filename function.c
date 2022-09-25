#include "header.h"

void tanggal()
{
    printf("  Masukkan Tanggal : "); scanf("%s", &file); fflush(stdin);
}

void kasir()
{
    do{
        puts("---------------------------------------------");
        puts("-               PROGRAM KASIR               -");
        puts("---------------------------------------------");
        puts("");
        puts("---------------------------------------------");
        puts("  Menu:");
        puts("    1. Kasir (Input)");
        puts("    2. Kasir (Output/Cek)");
        puts("    3. Hapus Data Kasir");
        puts("---------------------------------------------");
        printf("  Pilih : "); scanf("%d", &pilih);
        switch (pilih){
            case 1:
                input();
                break;
            case 2:
                buka_file();
                break;
            case 3:
                hapus();
                break;
            default:
                puts("---------------------------------------------");
                printf("  ERROR: Menu yang Dipilih Tidak Ada!!!\n");
        }
        fflush(stdin);
        puts("---------------------------------------------");
        printf("  Ingin Melanjutkan Program (y/t) ? ");
        lagi = getch();
        system("cls");
    }
    while(lagi=='y' | lagi=='Y');
    close();
    getch();
    exit (1);
};

void input()
{
    system("cls");
    puts("---------------------------------------------");
    puts("-               KASIR (INPUT)               -");
    puts("---------------------------------------------");
    puts("");
    puts("---------------------------------------------");
    tanggal();
    puts("---------------------------------------------");
    pf  = fopen(file, "a+");
    printf("  Jumlah Jenis Barang : "); scanf("%d", &n); fflush(stdin);
    puts("-                                           -");
    for(i=1; i<=n; i++){
        printf("  Jenis Barang ke-%d\n", i);
        printf("     Nama Barang\t: "); fflush(stdin); gets(brg.nama);
        printf("     Jumlah\t\t: ");    fflush(stdin); scanf("%d", &brg.jml);
        printf("     Harga\t\t: ");     fflush(stdin); scanf("%d", &brg.harga);
        brg.tharga=brg.jml*brg.harga;
        fprintf(pf, "%s\n", brg.nama);
        fprintf(pf, "%d\n", brg.jml);
        fprintf(pf, "%d\n", brg.harga);
        fprintf(pf, "%d\n", brg.tharga);
        }
    fclose(pf);
}

void buka_file()
{
    system("cls");
    puts("---------------------------------------------");
    puts("-              CEK DATA KASIR               -");
    puts("---------------------------------------------");
    puts("");
    puts("---------------------------------------------");
    tanggal();
    puts("---------------------------------------------");
    i=0;
    if ((pf = fopen(file, "r")) == NULL)
        printf("  ERROR: File Tidak Ada!!!\n");
    // Baca dari File -> Copy Data ke Variabel
    while(fscanf(pf, "%s %d %d %d", &brg.nama, &brg.jml, &brg.harga, &brg.tharga) != EOF){
        printf("  Jenis Barang ke-%d \n", ++i);
        printf("     Nama Barang\t: %s\n", brg.nama);
        printf("     Jumlah\t\t: %d\n", brg.jml);
        printf("     Harga\t\t: %d\n", brg.harga);
        printf("     Total Harga\t: %d\n", brg.tharga);
    }
    fclose(pf);
}

void hapus()
{
    system("cls");
    puts("---------------------------------------------");
    puts("-             HAPUS DATA KASIR              -");
    puts("---------------------------------------------");
    puts("");
    puts("---------------------------------------------");
    tanggal();
    puts("---------------------------------------------");
    if ((pf=fopen(file,"r"))!=NULL){
        fclose(pf);
        remove(file);
        printf("  File Data Kasir Telah Terhapus\n");
    }
    else{
        printf("  ERROR: File yang Anda Hapus Tidak Ada!!!\n");
    }
}

int close()
{
        puts("---------------------------------------------");
        puts("-               TERIMA KASIH                -");
        puts("-       TELAH MENGGUNAKAN PROGRAM ^_^       -");
        puts("---------------------------------------------\n");
}
