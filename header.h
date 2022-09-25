#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct data{
    char nama[20];
    int jml, harga, tharga;
};
struct data brg;

FILE *pf; // Deklarasi variabel bertipe pointer ke file
int i, n, pilih;
char lagi;
char file[100];
void kasir();
void input();
void buka_file();
void hapus();
int main();

#endif // HEADER_H_INCLUDED
