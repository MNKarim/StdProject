#include "MLL-00.h"

void createListAnggota(ListAnggota &L){
    L.first = nullptr;
}

bool isEmptyAnggota(ListAnggota L){
    return L.first == nullptr;
}

bool isEmptyAktivitas(adrAnggota p){
    return p->firstAktivitas == nullptr;
}

adrAnggota createElmAnggota(string id, string nama){
    adrAnggota p = new elmAnggota;
    p->info.id = id;
    p->info.nama = nama;
    p->next = nullptr;
    p->firstAktivitas = nullptr;
    return p;
}

adrAktivitas createElmAktivitas(string kode, string namaAktivitas, string jenis){
    adrAktivitas p = new elmAktivitas;
    p->info.kode = kode;
    p->info.namaAktivitas = namaAktivitas;
    p->info.jenis = jenis;
    p->next = nullptr;
    return p;
}

void addAnggota(ListAnggota &L, adrAnggota p){
    if(isEmptyAnggota(L)){
        L.first = p;
    }else{
        adrAnggota q = L.first;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = p;
    }
}

void addAktivitasKeAnggotaTertentu(adrAnggota &p, adrAktivitas q){
    q->next = p->firstAktivitas;
    p->firstAktivitas = q;
}

adrAnggota searchAnggota(ListAnggota L, string id){
    adrAnggota p = L.first;
    while(p != nullptr){
        if(p->info.id == id){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

adrAktivitas searchAktivitasDariAnggota(adrAnggota p, string kode){
    if(p == nullptr) return nullptr;

    adrAktivitas q = p->firstAktivitas;
    while(q != nullptr){
        if(q->info.kode == kode){
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void addAktivitasKeSemuaAnggota(ListAnggota &L, string namaAktivitas, string kodeAktivitas, string jenis){
    if(isEmptyAnggota(L)){
        cout << "Tidak ada anggota dalam list!\n";
        return;
    }

    adrAnggota p = L.first;
    int counter = 0;

    while(p != nullptr){
        adrAktivitas q = createElmAktivitas(kodeAktivitas, namaAktivitas, jenis);
        addAktivitasKeAnggotaTertentu(p, q);
        counter++;
        p = p->next;
    }

    cout << "Aktivitas \"" << namaAktivitas << "\" berhasil ditambahkan ke "
         << counter << " anggota.\n";
}

void tampilkanSemuaAnggota(ListAnggota L){
    if(isEmptyAnggota(L)){
        cout << "\n=== DAFTAR ANGGOTA ===\n";
        cout << "Belum ada anggota yang terdaftar.\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "        DAFTAR SEMUA ANGGOTA\n";
    cout << "========================================\n";

    adrAnggota p = L.first;
    int nomor = 1;

    while(p != nullptr){
        cout << nomor << ". ID: " << p->info.id << "\n";
        cout << "   Nama: " << p->info.nama << "\n";

        int jumlahAktivitas = 0;
       jumlahAktivitas = countAktivitasByAnggota(p);

        cout << "   Jumlah Aktivitas: " << jumlahAktivitas << "\n";
        cout << "----------------------------------------\n";

        nomor++;
        p = p->next;
    }

    cout << "Total Anggota: " << (nomor - 1) << "\n";
    cout << "========================================\n";
}

void tampilkanAktivitasAnggota(adrAnggota A){
    if(A == nullptr){
        cout << "Anggota tidak valid!\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "   AKTIVITAS ANGGOTA\n";
    cout << "========================================\n";
    cout << "ID: " << A->info.id << "\n";
    cout << "Nama: " << A->info.nama << "\n";
    cout << "----------------------------------------\n";

    if(isEmptyAktivitas(A)){
        cout << "Anggota ini belum mengikuti aktivitas apapun.\n";
    } else {
        adrAktivitas q = A->firstAktivitas;
        int nomor = 1;

        while(q != nullptr){
            cout << nomor << ". Kode: " << q->info.kode << "\n";
            cout << "   Nama: " << q->info.namaAktivitas << "\n";
            cout << "   Jenis: " << q->info.jenis << "\n";
            cout << "   ------------------------------------\n";

            nomor++;
            q = q->next;
        }

        cout << "Total Aktivitas: " << (nomor - 1) << "\n";
    }

    cout << "========================================\n";
}

void tampilkanAnggotaPalingAktif(ListAnggota L){
    if(isEmptyAnggota(L)){
        cout << "\n=== ANGGOTA PALING AKTIF ===\n";
        cout << "Belum ada anggota yang terdaftar.\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "      ANGGOTA PALING AKTIF\n";
    cout << "========================================\n";

    adrAnggota p = L.first;
    adrAnggota palingAktif = nullptr;
    int maxAktivitas = 0;

    while(p != nullptr){
        int jumlahAktivitas = 0;
        adrAktivitas q = p->firstAktivitas;

        while(q != nullptr){
            jumlahAktivitas++;
            q = q->next;
        }

        if(jumlahAktivitas > maxAktivitas){
            maxAktivitas = jumlahAktivitas;
            palingAktif = p;
        }

        p = p->next;
    }

    if(palingAktif == nullptr || maxAktivitas == 0){
        cout << "Belum ada anggota yang mengikuti aktivitas.\n";
    } else {
        cout << "ID: " << palingAktif->info.id << "\n";
        cout << "Nama: " << palingAktif->info.nama << "\n";
        cout << "Jumlah Aktivitas: " << maxAktivitas << "\n";
        cout << "----------------------------------------\n";
        cout << "Daftar Aktivitas:\n";

        adrAktivitas q = palingAktif->firstAktivitas;
        int nomor = 1;

        while(q != nullptr){
            cout << "  " << nomor << ". " << q->info.namaAktivitas
                 << " (" << q->info.jenis << ")\n";
            nomor++;
            q = q->next;
        }
    }

    cout << "========================================\n";
}

void tampilkanMenu() {
    cout << "\n========================================\n";
    cout << "   SISTEM DATA ANGGOTA KOMUNITAS\n";
    cout << "========================================\n";
    cout << "1. Tambah Anggota\n";
    cout << "2. Cari Anggota\n";
    cout << "3. Tambah Aktivitas pada Anggota Tertentu\n";
    cout << "4. Tambah Aktivitas ke Semua Anggota\n";
    cout << "5. Tampilkan Aktivitas Anggota Tertentu\n";
    cout << "6. Tampilkan Semua Anggota\n";
    cout << "7. Tampilkan Anggota Paling Aktif\n";
    cout << "8. Hapus Anggota dan Aktivitasnya\n";
    cout << "9. Hapus Aktivitas Anggota Tertentu\n";
    cout << "0. Keluar\n";
    cout << "========================================\n";
    cout << "Pilihan: ";
}

void delAnggotaAndAktivitas(ListAnggota &L, string id){
    adrAnggota p;
    adrAnggota prev = nullptr;

    if (isEmptyAnggota(L)) {
        cout << "List Anggota kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    p = searchAnggota(L, id);

    if (p == nullptr) {
        cout << "Anggota dengan ID " << id << " tidak ditemukan.\n";
        return;
    }

    if (p == L.first) {
        L.first = p->next;
    }else {
        prev->next = p->next;
    }

    cout << "Anggota \"" << p->info.nama << "\" (ID: " << id << ") berhasil dihapus.\n";

}

void delAktivitasByAnggota(adrAnggota p, string kode){
    if (p == nullptr) {
        cout << "Anggota tidak valid\n";
        return;
    }

    if (isEmptyAktivitas(p)) {
        cout << "Anggota " << p->info.nama << " tidak memiliki aktivitas.\n";
        return;
    }

    adrAktivitas q = p->firstAktivitas;
    adrAktivitas prev = nullptr;

    while (q != nullptr && q->info.kode != kode) {
        prev = q;
        q = q->next;
    }

    if (q == nullptr) {
        cout << "Aktivitas dengan kode " << kode << " tidak ditemukan pada anggota " << p->info.nama << ".\n";
        return;
    }

    if (q == p->firstAktivitas) {
        p->firstAktivitas = q->next;
    }else {
        prev->next = q->next;
    }

    cout << "Aktivitas \"" << q->info.namaAktivitas << "\" (Kode: " << kode << ") berhasil dihapus dari anggota " << p->info.nama << ".\n";
}

int countAktivitasByAnggota(adrAnggota p){
    adrAktivitas q;
    int total = 0;

    q = p->firstAktivitas;
    while(q != nullptr){
        total++;
        q = q->next;
    }
    return total;
}
