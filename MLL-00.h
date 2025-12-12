#ifndef MLL_00_H_INCLUDED
#define MLL_00_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmAnggota *adrAnggota;
typedef struct elmAktivitas *adrAktivitas;

struct Anggota {
    string id;
    string nama;
};

struct Aktivitas {
    string kode;
    string namaAktivitas;  // konsisten dengan ini
    string jenis;
};

struct elmAnggota {
    Anggota info;
    adrAnggota next;
    adrAktivitas firstAktivitas;
};

struct elmAktivitas {
    Aktivitas info;
    adrAktivitas next;
};

struct ListAnggota {
    adrAnggota first;
};

// Operasi dasar
void createListAnggota(ListAnggota &L);
bool isEmptyAnggota(ListAnggota L);
bool isEmptyAktivitas(adrAnggota p);

// Alokasi
adrAnggota createElmAnggota(string id, string nama);
adrAktivitas createElmAktivitas(string kode, string namaAktivitas, string jenis);

// Insert/Add
void addAnggota(ListAnggota &L, adrAnggota p);
void addAktivitasKeAnggotaTertentu(adrAnggota &p, adrAktivitas q);
void addAktivitasKeSemuaAnggota(ListAnggota &L, string namaAktivitas, string kodeAktivitas, string jenis);

// Pencarian
adrAnggota searchAnggota(ListAnggota L, string id);
adrAktivitas searchAktivitasDariAnggota(adrAnggota p, string kode);

// Tampilan
void tampilkanSemuaAnggota(ListAnggota L);
void tampilkanAktivitasAnggota(adrAnggota A);
void tampilkanAnggotaPalingAktif(ListAnggota L);

// Menu
void tampilkanMenu();

#endif // MLL_00_H_INCLUDED
