#ifndef OPLIB_H_INCLUDED
#define OPLIB_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;

#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(P) ((P).first)
#define last(P) ((P).last)
#define firstM(P) ((P).firstM)
#define firstB(P) ((P).firstB)
#define nextB(P) P->nextB
#define nextM(P) P->nextM
#define prevB(P) P->prevB
#define prevM(P) P->prevM
#define edgeParent(P) P->edgeParent
#define edgeChild(P) P->edgeChild

struct buku {
    string judul;
    int isbn;
};

struct mhs {
    string nama;
    int nim;
};

typedef buku infoBuku;
typedef mhs infoMhs;
typedef struct elmBuku *adrBuku;
typedef struct elmMhs *adrMhs;
typedef struct elmRelasi *adrRelasi;

struct elmBuku {
    buku info;
    adrBuku nextB;
};

struct elmRelasi {
    adrRelasi next;
    adrRelasi prev;
    adrMhs edgeParent;
    adrBuku edgeChild;
};

struct elmMhs {
    mhs info;
    adrMhs nextM;
    adrMhs edge;
};

struct ListBuku {
    adrBuku firstB;
};

struct ListRelasi {
    adrRelasi first;
    adrRelasi last;
};

struct ListMhs {
    adrMhs firstM;
};

void createListBuku(ListBuku &B);
void createListRelasi(ListRelasi &R);
void createListMhs(ListMhs &M);
adrBuku createElmBuku(buku x);
adrRelasi createElmRelasi();
adrMhs createElmMhs(mhs y);
adrRelasi createRelasi(ListRelasi &R, ListBuku B, ListMhs M, string judul, string nama, int ISBN, int nim);
adrMhs cariMhs(ListMhs M, string nama, int nim);
adrBuku cariBuku(ListBuku B, string judul, int ISBN);
void insertLastBuku(ListBuku &B, adrBuku pB);
void insertLastMhs(ListMhs &M, adrMhs pM);
void deleteElementRelasi(ListRelasi &R, ListBuku B, string judul, int isbn);
void deleteFirstRelasi(ListRelasi &R);
void deleteLastRelasi(ListRelasi &R);
adrMhs searchMhs(ListMhs M, string nama);
void showRelasiMhs(ListRelasi R, ListMhs M, string nama, int nim);
void showSeluruhRelasi(ListRelasi R);
void showFavBuku();
void showMhsRajin();
void showMhs(ListMhs &M);
void showBuku(ListBuku &B);
int selectMenu();

#endif // OPLIB_H_INCLUDED
