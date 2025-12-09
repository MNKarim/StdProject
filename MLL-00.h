#ifndef MLL-00_H_INCLUDED
#define MLL-00_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct Aktivitas *adrAktivitas;
typedef struct Relasi *adrRelasi;
typedef struct Anggota *adrAnggota;

struct Aktivitas {
    string idAktivitas;
    string namaAktivitas;
    string jenisAktivitas;
    adrAktivitas next;
};

struct Relasi {
    adrAktivitas infoAktivitas;
    adrRelasi next;
};

struct Anggota {
    string idAnggota;
    string namaAnggota;
    string email;
    adrRelasi firstAktivitas;
    adrAnggota next;
};

struct ListAnggota {
    adrAnggota first;
};

struct ListAktivitas {
    adrAktivitas first;
};

// ==================== DEKLARASI FUNGSI & PROSEDUR ====================

// Inisialisasi
void createListAnggota(ListAnggota &L);
void createListAktivitas(ListAktivitas &L);

// Alokasi
adrAnggota alokasiAnggota(string id, string nama, string email);
adrAktivitas alokasiAktivitas(string id, string nama, string jenis);
adrRelasi alokasiRelasi(adrAktivitas A);

// Insert
void insertAnggota(ListAnggota &L, adrAnggota P);
void insertAktivitas(ListAktivitas &L, adrAktivitas P);
void tambahAktivitasPadaAnggota(adrAnggota A, adrAktivitas Akt);

// Pencarian
adrAnggota cariAnggota(ListAnggota L, string id);
adrAktivitas cariAktivitas(ListAktivitas L, string id);

// Tampilan
void tampilkanSemuaAnggota(ListAnggota L);
void tampilkanSemuaAktivitas(ListAktivitas L);
void tampilkanAktivitasAnggota(adrAnggota A);
void tampilkanRingkasan(ListAnggota L);
void tampilkanAnggotaPalingAktif(ListAnggota L);

// Menu
void tampilkanMenu();



#endif // MLL-00_H_INCLUDED
