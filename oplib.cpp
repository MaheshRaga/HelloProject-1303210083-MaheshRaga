#include "oplib.h"

int selectMenu() {
    cout << "========================= PROGRAM MULTI LINKED-LIST B: OPEN LIBRARY =========================="  << endl;
    cout << "===== Dirancang oleh: Mahesh Raga Nesta (1303210083) & Zaghi Haekal Nugraha (1303213001) =====" << endl;
    cout << "1. Tambah data mahasiswa." << endl;
    cout << "2. Tambah data buku." << endl;
    cout << "3. Cari data mahasiswa." << endl;
    cout << "4. Tambah relasi buku yang dipinjam oleh mahasiswa dan sebaliknya." << endl;
    cout << "5. Cari data yang dipinjam oleh mahasiswa tertentu." << endl;
    cout << "6. Hapus buku dan relasinya." << endl;
    cout << "7. Hapus data mahasiswa yang meminjam buku tertentu." << endl;
    cout << "8. Tampilkan seluruh data mahasiswa dan buku yang dipinjamnya." << endl;
    cout << "9. Tampilkan buku yang paling sering dipinjam (favorit) oleh mahasiswa." << endl;
    cout << "10. Tampilkan mahasiswa yang rajin membaca." << endl;
    cout << "0. Keluar program." << endl;
    cout << "==============================================================================================" << endl;
    cout << "Masukkan angka untuk mengakses menu yang ingin dipilih: ";

    int input = 0;
    cin >> input;

    return input;
}

void createListBuku(ListBuku &B) {
    firstB(B) = nil;
}

void createListRelasi(ListRelasi &R) {
    first(R) = nil;
    last(R) = nil;
}

void createListMhs(ListMhs &M) {
    firstM(M) = nil;
}

adrBuku createElmBuku(buku x) {
    adrBuku pB = new elmBuku;
    info(pB).judul = x.judul;
    info(pB).isbn = x.isbn;

    nextB(pB) = nil;

    return pB;
}

adrRelasi createElmRelasi() {
    adrRelasi pR = new elmRelasi;
    next(pR) = nil;
    prev(pR) = nil;
    edgeParent(pR) = nil;
    edgeChild(pR) = nil;

    return pR;
}

adrMhs createElmMhs(mhs y) {
    adrMhs pM = new elmMhs;
    info(pM) = y;
    info(pM).nama = y.nama;
    info(pM).nim = y.nim;
    nextM(pM) = nil;
    return pM;
}

void insertLastBuku(ListBuku &B, adrBuku pB) {
    adrBuku qB;
    if (firstB(B) == nil) {
        firstB(B) = pB;
    } else {
        qB = firstB(B);
        while (nextB(qB) != nil) {
            qB = nextB(qB);
        }
        nextB(qB) = pB;
    }
}

void insertLastMhs(ListMhs &M, adrMhs pM) {
    adrMhs qM;
    if (firstM(M) == nil) {
        firstM(M) = pM;
    } else {
        qM = firstM(M);
        while (nextM(qM) != nil) {
            qM = nextM(qM);
        }
        nextM(qM) = pM;
    }
}

adrBuku cariBuku(ListBuku B, string judul, int ISBN) {  // salah kondisi, buku match, isbn tidak match, output mengacu ke isbn
    adrBuku p = firstB(B);
    while (p != nil && (info(p).judul != judul || info(p).isbn != ISBN)) {
        p = nextB(p);
    }
    return p;
}

adrMhs cariMhs(ListMhs M, string nama, int nim) {       // salah kondisi, nama match, nim tidak match, output mengacu ke nim
    adrMhs p = firstM(M);
    while (p != nil && (info(p).nama != nama || info(p).nim != nim)) {
        p = nextM(p);
    }
    return p;
}

adrRelasi createRelasi(ListRelasi &R, ListBuku B, ListMhs M, string judul, string nama, int ISBN, int nim) {
    adrRelasi pR;
    adrBuku qB;
    adrMhs qM;

    qB = cariBuku(B, judul, ISBN);
    qM = cariMhs(M, nama, nim);

    pR = createElmRelasi();

    edgeParent(pR) = qM;
    edgeChild(pR) = qB;
    if(first(R) == NULL){
        first(R) = pR;
        last(R) = pR;
    }else{
        next(last(R)) = pR;
        prev(pR) = last(R);
        last(R) = pR;
    }
}

adrMhs searchMhs(ListMhs M, string nama) {
    adrMhs p;
    if (firstM(M) == nil) {
        return nil;
    } else {
        p = firstM(M);
        while (info(p).nama != nama && nextM(p) != firstM(M)) {
            p = nextM(p);
        }
        if (info(p).nama == nama) {
            return p;
        } else {
            return nil;
        }
    }
}

void showMhs(ListMhs &M) {
    int i = 1;
    adrMhs pM = firstM(M);
    if (pM != nil) {
        cout << "Daftar mahasiswa: " << endl;
        while (pM != nil) {
            cout << i << ". " << info(pM).nama << " (" << info(pM).nim << ")" << endl;
            i++;
            pM = nextM(pM);
        }
    } else {
        cout << "Tidak ada mahasiswa terdaftar!" << endl;
    }

}

void showBuku(ListBuku &B) {
    int i = 1;
    adrBuku pB = firstB(B);
    if (pB != nil) {
        cout << "Daftar buku: " << endl;
        while (pB != nil) {
            cout << i << ". " << info(pB).judul << "; " << info(pB).isbn << endl;
            i++;
            pB = nextB(pB);
        }
    } else {
        cout << "Tidak ada buku terdaftar!" << endl;
    }

}

void showRelasiMhs(ListRelasi R, ListMhs M, string nama, int nim) {
    adrRelasi pR = first(R);
    adrMhs pM = cariMhs(M, nama, nim);
    if (pM == nil) {
            cout << "Mahasiswa tidak terdaftar!" << endl;
    } else {
        cout << "Mahasiswa " << nama << " (" << nim << ") meminjam buku berikut: " << endl;
        while (pR != nil) {
            if (info(edgeParent(pR)).nama == nama && info(edgeParent(pR)).nim == nim){
                cout << "Judul Buku: " << info(edgeChild(pR)).judul << endl;
                cout << "ISBN: " << info(edgeChild(pR)).isbn << endl;
            }
            pR = next(pR);
        }
    }
}

void deleteFirstRelasi(ListRelasi &R) {
    adrRelasi pR;

    if (first(R) == nil) {
        cout << "Relasi kosong!" << endl;
    } else if (first(R) == last(R)) {
        first(R) = nil;
        last(R) = nil;
    } else {
        pR = first(R);
        next(pR) = nil;
        prev(first(R)) = nil;
    }
}

void deleteLastRelasi(ListRelasi &R) {

    adrRelasi pR;

    if (first(R) == nil) {
        cout << "Relasi kosong." << endl;
    } else if (first(R) == last(R)) {
        first(R) = nil;
        last(R) = nil;
    } else {
        pR = last(R);
        last(R) = prev(pR);
        next(last(R)) = nil;
        prev(pR) = nil;
    }
}

void deleteElementRelasi(ListRelasi &R, ListBuku B, string judul, int isbn) {
    adrRelasi pR;
    pR = first(R);

    if (cariBuku(B, judul, isbn) == nil) {
        cout << "Buku tidak ditemukan!" << endl;
    } else {
        while (pR != nil) {
            if (info(edgeChild(pR)).judul == judul && info(edgeChild(pR)).isbn == isbn) {
                if (pR == first(R)) {
                    deleteFirstRelasi(R);
                } else if (pR == last(R)) {
                    deleteLastRelasi(R);
                } else {
                    next(prev(pR)) = next(pR);
                    prev(next(pR)) = prev(pR);
                    next(pR) = nil;
                    prev(pR) = nil;
                }
            }
        }
    }
    pR = next(pR);
}

void showSeluruhRelasi(ListRelasi R) {
    adrRelasi pR;
    int i = 1;
    pR = first(R);

    if (pR == nil) {
        cout << "List relasi kosong!" << endl;
    } else {
        while (pR != nil) {
            cout << "Daftar relasi: " << endl;
            cout << i << ". " << info(edgeParent(pR)).nama << " (" << info(edgeParent(pR)).nim << "):" << endl;
            cout << info(edgeChild(pR)).judul << " (" << info(edgeChild(pR)).isbn << ")" << endl;
            i++;
        }
    }
}


