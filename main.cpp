#include "oplib.h"

int main()
{
    int num1 = 0, num2 = 0;
    buku book;
    mhs mahasiswa;
    ListBuku B;
    ListMhs M;
    ListRelasi R;
    string pernyataan1, pernyataan2;
    int x, y, z;
    adrBuku pB;
    adrMhs pM, qM;
    adrRelasi pR, qS;
    int pilihan;
    createListMhs(M);
    createListBuku(B);
    createListRelasi(R);

    pilihan = selectMenu();

    while (pilihan != 0) {
        switch(pilihan) {
    case 1:
        cout << "Masukkan jumlah data yang ingin diinput: ";
        cin >> num1;
        x = 0;

        while (x < num1) {
            cout << "Masukkan nama mahasiswa: ";
            cin >> mahasiswa.nama;

            cout << "Masukkan NIM: ";
            cin >> mahasiswa.nim;

            pM = createElmMhs(mahasiswa);
            insertLastMhs(M, pM);
            cout << endl;
            x++;
        }

        showMhs(M);

        cout << "Kembali ke menu utama? (Ya/Tidak): " << endl;
        cin >> pernyataan1;
        system("CLS");
        if (pernyataan1 == "Tidak") {
            cout << "Keluar dari program..." << endl << endl;
            break;
        }

        break;

    case 2:
        cout << "Masukkan jumlah buku yang ingin diinput: ";
        cin >> num2;

        for (y = 0;y < num2; y++) {
            cout << "Masukkan judul buku: ";
            cin >> book.judul;

            cout << "Masukkan kode seri buku: ";
            cin >> book.isbn;

            pB = createElmBuku(book);
            insertLastBuku(B, pB);
            cout << endl;
        }

        showBuku(B);

        cout << "Kembali ke menu utama? (Ya/Tidak): ";
        cin >> pernyataan2;
        system("CLS");
        if (pernyataan2 == "Tidak") {
            cout << "Keluar dari sistem..." << endl << endl;
            break;
        }

        break;

    case 3:
        cout << "Input data mahasiswa yang ingin dicari: " << endl;
        cout << "Nama: ";
        cin >> mahasiswa.nama;
        cout << "NIM: ";
        cin >> mahasiswa.nim;

        qM = cariMhs(M, mahasiswa.nama, mahasiswa.nim);
        if (qM == nil) {
            cout << "Tidak ditemukan data mahasiswa!" << endl;
        } else {
            cout << "Ditemukan mahasiswa dengan data sebagai berikut: " << info(qM).nama << " (" << info(qM).nim << ")" << endl;
        }

        cout << "Kembali ke menu utama? (Ya/Tidak): ";
        cin >> pernyataan2;
        system("CLS");
        if (pernyataan2 == "Tidak") {
            cout << "Keluar dari sistem..." << endl << endl;
            break;
        }

        break;

    case 4:
        cout << "Masukkan nama dan NIM dari mahasiswa yang ingin meminjam buku: " << endl;
        cout << "Nama: ";
        cin >> mahasiswa.nama;
        cout << "NIM: ";
        cin >> mahasiswa.nim;

        cout << "Masukkan judul buku dan kode ISBN yang ingin dipinjam: " << endl;
        cout << "Judul Buku: ";
        cin >> book.judul;
        cout << "ISBN: ";
        cin >> book.isbn;

        createRelasi(R, B, M, book.judul, mahasiswa.nama, book.isbn, mahasiswa.nim);

        cout << "Kembali ke menu utama? (Ya/Tidak): ";
        cin >> pernyataan2;
        system("CLS");
        if (pernyataan2 == "Tidak") {
            cout << "Keluar dari sistem..." << endl << endl;
            break;
        }
        break;

    case 5:
        cout << "Masukkan nama dan NIM mahasiswa yang ingin ditampilkan: " << endl;
        cout << "Nama: ";
        cin >> mahasiswa.nama;
        cout << "NIM: ";
        cin >> mahasiswa.nim;

        showRelasiMhs(R, M, mahasiswa.nama, mahasiswa.nim);

        cout << "Kembali ke menu utama? (Ya/Tidak): ";
        cin >> pernyataan2;
        system("CLS");
        if (pernyataan2 == "Tidak") {
            cout << "Keluar dari sistem..." << endl << endl;
            break;
        }
    break;

    case 6:
        cout << "Masukkan judul dan ISBN dari buku yang akan dihapus: " << endl;
        cout << "Judul Buku: ";
        cin >> book.judul;
        cout << "ISBN: ";
        cin >> book.isbn;

        deleteElementRelasi(R, B, book.judul, book.isbn);

        cout << "Kembali ke menu utama? (Ya/Tidak): ";
        cin >> pernyataan2;
        system("CLS");
        if (pernyataan2 == "Tidak") {
            cout << "Keluar dari sistem..." << endl << endl;
            break;
        }
    break;

    case 7:
        showSeluruhRelasi(R);

        cout << "Kembali ke menu utama? (Ya/Tidak): ";
        cin >> pernyataan2;
        system("CLS");
        if (pernyataan2 == "Tidak") {
            cout << "Keluar dari sistem..." << endl << endl;
            break;
        }

    default:
        break;
        }
        pilihan = selectMenu();
    }

}

//ini perubahan
