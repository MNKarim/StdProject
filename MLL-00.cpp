#include "MLL-00.h"
void createListAnggota(ListAnggota &L) {
    L.first = nullptr;
}

void createListAktivitas(ListAktivitas &L) {
    L.first = nullptr;
}

adrAnggota alokasiAnggota(string id, string nama, string email) {
    adrAnggota P = new Anggota;
    P->idAnggota = id;
    P->namaAnggota = nama;
    P->email = email;
    P->firstAktivitas = nullptr;
    P->next = nullptr;
    return P;
}

adrAktivitas alokasiAktivitas(string id, string nama, string jenis) {
    adrAktivitas P = new Aktivitas;
    P->idAktivitas = id;
    P->namaAktivitas = nama;
    P->jenisAktivitas = jenis;
    P->next = nullptr;
    return P;
}

adrRelasi alokasiRelasi(adrAktivitas A) {
    adrRelasi R = new Relasi;
    R->infoAktivitas = A;
    R->next = nullptr;
    return R;
}

void insertAnggota(ListAnggota &L, adrAnggota P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrAnggota Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAktivitas(ListAktivitas &L, adrAktivitas P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrAktivitas Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrAnggota cariAnggota(ListAnggota L, string id) {
    adrAnggota P = L.first;
    while (P != nullptr) {
        if (P->idAnggota == id) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

adrAktivitas cariAktivitas(ListAktivitas L, string id) {
    adrAktivitas P = L.first;
    while (P != nullptr) {
        if (P->idAktivitas == id) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void tambahAktivitasPadaAnggota(adrAnggota A, adrAktivitas Akt) {
    adrRelasi R = alokasiRelasi(Akt);

    if (A->firstAktivitas == nullptr) {
        A->firstAktivitas = R;
    } else {
        adrRelasi Q = A->firstAktivitas;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

void tampilkanSemuaAnggota(ListAnggota L) {
    cout << "\n========================================\n";
    cout << "       DAFTAR SEMUA ANGGOTA\n";
    cout << "========================================\n";

    if (L.first == nullptr) {
        cout << "Belum ada anggota terdaftar.\n";
        return;
    }

    adrAnggota P = L.first;
    int no = 1;
    while (P != nullptr) {
        cout << no++ << ". ID: " << P->idAnggota << "\n";
        cout << "   Nama: " << P->namaAnggota << "\n";
        cout << "   Email: " << P->email << "\n";

        int count = 0;
        adrRelasi R = P->firstAktivitas;
        while (R != nullptr) {
            count++;
            R = R->next;
        }
        cout << "   Jumlah Aktivitas: " << count << "\n";
        cout << "----------------------------------------\n";

        P = P->next;
    }
}

void tampilkanSemuaAktivitas(ListAktivitas L) {
    cout << "\n========================================\n";
    cout << "       DAFTAR SEMUA AKTIVITAS\n";
    cout << "========================================\n";

    if (L.first == nullptr) {
        cout << "Belum ada aktivitas terdaftar.\n";
        return;
    }

    adrAktivitas P = L.first;
    int no = 1;
    while (P != nullptr) {
        cout << no++ << ". ID: " << P->idAktivitas << "\n";
        cout << "   Nama: " << P->namaAktivitas << "\n";
        cout << "   Jenis: " << P->jenisAktivitas << "\n";
        cout << "----------------------------------------\n";
        P = P->next;
    }
}

void tampilkanAktivitasAnggota(adrAnggota A) {
    cout << "\n========================================\n";
    cout << "  AKTIVITAS ANGGOTA: " << A->namaAnggota << "\n";
    cout << "========================================\n";

    if (A->firstAktivitas == nullptr) {
        cout << "Anggota ini belum mengikuti aktivitas apapun.\n";
        return;
    }

    adrRelasi R = A->firstAktivitas;
    int no = 1;
    while (R != nullptr) {
        cout << no++ << ". " << R->infoAktivitas->namaAktivitas << "\n";
        cout << "   Jenis: " << R->infoAktivitas->jenisAktivitas << "\n";
        cout << "   ID: " << R->infoAktivitas->idAktivitas << "\n";
        cout << "----------------------------------------\n";
        R = R->next;
    }
}

void tampilkanAnggotaPalingAktif(ListAnggota L) {
    if (L.first == nullptr) {
        cout << "\nBelum ada anggota terdaftar.\n";
        return;
    }

    adrAnggota palingAktif = L.first;
    int maxAktivitas = 0;

    adrAnggota P = L.first;
    while (P != nullptr) {
        int count = 0;
        adrRelasi R = P->firstAktivitas;
        while (R != nullptr) {
            count++;
            R = R->next;
        }

        if (count > maxAktivitas) {
            maxAktivitas = count;
            palingAktif = P;
        }

        P = P->next;
    }

    cout << "\n========================================\n";
    cout << "       ANGGOTA PALING AKTIF\n";
    cout << "========================================\n";
    cout << "Nama: " << palingAktif->namaAnggota << "\n";
    cout << "ID: " << palingAktif->idAnggota << "\n";
    cout << "Jumlah Aktivitas: " << maxAktivitas << "\n";
}

void tampilkanRingkasan(ListAnggota L) {
    cout << "\n========================================\n";
    cout << "    RINGKASAN AKTIVITAS PER ANGGOTA\n";
    cout << "========================================\n";

    if (L.first == nullptr) {
        cout << "Belum ada anggota terdaftar.\n";
        return;
    }

    adrAnggota P = L.first;
    while (P != nullptr) {
        int count = 0;
        adrRelasi R = P->firstAktivitas;
        while (R != nullptr) {
            count++;
            R = R->next;
        }

        cout << P->namaAnggota << " (" << P->idAnggota << "): "
             << count << " aktivitas\n";

        P = P->next;
    }
}

void tampilkanMenu() {
    cout << "\n========================================\n";
    cout << "   SISTEM DATA ANGGOTA KOMUNITAS\n";
    cout << "========================================\n";
    cout << "1. Tambah Anggota\n";
    cout << "2. Tambah Aktivitas\n";
    cout << "3. Cari Anggota\n";
    cout << "4. Tambahkan Aktivitas pada Anggota\n";
    cout << "5. Tampilkan Aktivitas Anggota Tertentu\n";
    cout << "6. Tampilkan Semua Anggota\n";
    cout << "7. Tampilkan Semua Aktivitas\n";
    cout << "8. Tampilkan Ringkasan\n";
    cout << "9. Tampilkan Anggota Paling Aktif\n";
    cout << "0. Keluar\n";
    cout << "========================================\n";
    cout << "Pilihan: ";
}
