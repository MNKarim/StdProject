#include <iostream>
#include "MLL-00.h"
using namespace std;

int main() {
    ListAnggota LA;
    ListAktivitas LAk;
    createListAnggota(LA);
    createListAktivitas(LAk);

    int pilihan;
    string id, nama, email, jenis, idAnggota, idAktivitas;

    tampilkanMenu();
    cin >> pilihan;
    while(pilihan != 0){

        switch(pilihan) {
            case 1: {
                cout << "\n--- TAMBAH ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin>>id;
                cout << "Nama Anggota: ";
                cin>>nama;
                cout << "Email: ";
                cin>>email;

                adrAnggota P = alokasiAnggota(id, nama, email);
                insertAnggota(LA, P);
                cout << "Anggota berhasil ditambahkan!\n";
                break;
            }

            case 2: {
                cout << "\n--- TAMBAH AKTIVITAS ---\n";
                cout << "ID Aktivitas: ";
                cin>>id;
                cout << "Nama Aktivitas: ";
                cin>>nama;
                cout << "Jenis (seminar/workshop/pertandingan): ";
                cin>>jenis;

                adrAktivitas P = alokasiAktivitas(id, nama, jenis);
                insertAktivitas(LAk, P);
                cout << "Aktivitas berhasil ditambahkan!\n";
                break;
            }

            case 3: {
                cout << "\n--- CARI ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin>>id;

                adrAnggota A = cariAnggota(LA, id);
                if (A != nullptr) {
                    cout << "\nAnggota ditemukan!\n";
                    cout << "ID: " << A->idAnggota << "\n";
                    cout << "Nama: " << A->namaAnggota << "\n";
                    cout << "Email: " << A->email << "\n";
                } else {
                    cout << "Anggota tidak ditemukan!\n";
                }
                break;
            }

            case 4: {
                cout << "\n--- TAMBAH AKTIVITAS PADA ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin>>idAnggota;
                cout << "ID Aktivitas: ";
                cin>>idAktivitas;

                adrAnggota A = cariAnggota(LA, idAnggota);
                adrAktivitas Akt = cariAktivitas(LAk, idAktivitas);

                if (A == nullptr) {
                    cout << "Anggota tidak ditemukan!\n";
                } else if (Akt == nullptr) {
                    cout << "Aktivitas tidak ditemukan!\n";
                } else {
                    tambahAktivitasPadaAnggota(A, Akt);
                    cout << "Aktivitas berhasil ditambahkan pada anggota!\n";
                }
                break;
            }

            case 5: {
                cout << "\n--- TAMPILKAN AKTIVITAS ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin>>id;

                adrAnggota A = cariAnggota(LA, id);
                if (A != nullptr) {
                    tampilkanAktivitasAnggota(A);
                } else {
                    cout << "Anggota tidak ditemukan!\n";
                }
                break;
            }

            case 6:
                tampilkanSemuaAnggota(LA);
                break;

            case 7:
                tampilkanSemuaAktivitas(LAk);
                break;

            case 8:
                tampilkanRingkasan(LA);
                break;

            case 9:
                tampilkanAnggotaPalingAktif(LA);
                break;

            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!\n";
                break;

            default:
                cout << "\nPilihan tidak valid!\n";
        }
        tampilkanMenu();
        cin >> pilihan;
}


    return 0;
}
