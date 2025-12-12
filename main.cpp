#include <iostream>
#include "MLL-00.h"
using namespace std;

int main() {
    ListAnggota LA;
    createListAnggota(LA);

    int pilihan;
    string id, nama, jenis, kode, namaAktivitas;

    tampilkanMenu();
    cin >> pilihan;

    while(pilihan != 0){
        switch(pilihan) {
            case 1: {
                cout << "\n--- TAMBAH ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin >> id;
                cin.ignore();  // ✅ Penting untuk getline
                cout << "Nama Anggota: ";
                getline(cin, nama);

                adrAnggota P = createElmAnggota(id, nama);  // ✅ Fungsi yang benar
                addAnggota(LA, P);
                cout << "Anggota berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                cout << "\n--- CARI ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin >> id;

                adrAnggota A = searchAnggota(LA, id);  // ✅ Nama fungsi yang benar
                if (A != nullptr) {
                    cout << "\nAnggota ditemukan!\n";
                    cout << "ID: " << A->info.id << "\n";
                    cout << "Nama: " << A->info.nama << "\n";
                } else {
                    cout << "Anggota tidak ditemukan!\n";
                }
                break;
            }
            case 3: {
                cout << "\n--- TAMBAH AKTIVITAS PADA ANGGOTA TERTENTU ---\n";
                cout << "ID Anggota: ";
                cin >> id;

                adrAnggota A = searchAnggota(LA, id);  // ✅ searchAnggota
                if (A == nullptr) {
                    cout << "Anggota tidak ditemukan!\n";
                } else {
                    cin.ignore();
                    cout << "Kode Aktivitas: ";
                    getline(cin, kode);
                    cout << "Nama Aktivitas: ";
                    getline(cin, namaAktivitas);
                    cout << "Jenis (seminar/workshop/pertandingan): ";
                    getline(cin, jenis);

                    // ✅ Buat elemen aktivitas
                    adrAktivitas q = createElmAktivitas(kode, namaAktivitas, jenis);
                    // ✅ Tambahkan ke anggota
                    addAktivitasKeAnggotaTertentu(A, q);
                    cout << "Aktivitas berhasil ditambahkan pada anggota!\n";
                }
                break;
            }
            case 4: {
                cout << "\n--- TAMBAH AKTIVITAS KE SEMUA ANGGOTA ---\n";
                cin.ignore();
                cout << "Kode Aktivitas: ";
                getline(cin, kode);
                cout << "Nama Aktivitas: ";
                getline(cin, namaAktivitas);
                cout << "Jenis (seminar/workshop/pertandingan): ";
                getline(cin, jenis);

                addAktivitasKeSemuaAnggota(LA, namaAktivitas, kode, jenis);
                break;
            }
            case 5: {
                cout << "\n--- TAMPILKAN AKTIVITAS ANGGOTA ---\n";
                cout << "ID Anggota: ";
                cin >> id;

                adrAnggota A = searchAnggota(LA, id);
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
                tampilkanAnggotaPalingAktif(LA);
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }

        if(pilihan != 0){
            tampilkanMenu();
            cin >> pilihan;
        }
    }

    return 0;
}
