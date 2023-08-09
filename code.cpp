#include <iostream>
#include <fstream> // untuk memberikan akses dan fungsionalitas yang diperlukan untuk berinteraksi dengan berkas atau file

using namespace std;

#define MAX_BUKU 100 // menyatakan bahwa setiap kali MAX_BUKU muncul dalam program, nilainya akan digantikan dengan 100 sebelum proses kompilasi.

// Struktur data buku
struct Buku
{
    string judul;
    string pengarang;
    int tahun_terbit;
    bool dipinjam;
};

struct Akun
{
    string username;
    string password;
    bool meminjam;
};

struct Pinjaman
{
    string judul_buku;
    string pengguna;
    bool pinjaman;
};

Buku buku_dipinjam;

// array untuk menyimpan detail
Pinjaman daftar_pinjaman[MAX_BUKU];
int jumlah_pinjaman = 0;

// Array untuk menyimpan daftar akun
Akun daftar_akun[MAX_BUKU];
int jumlah_akun = 0;

// Array untuk menyimpan daftar buku
Buku daftar_buku[MAX_BUKU];
int jumlah_buku = 0;

// Deklarasi fungsi
void tambahBuku();
void cariBuku();
void urutkanBuku();
void updateBuku();
void lihatBuku();
void lihatDetail();
void loginAdmin();
void pinjamBuku();
void kembalikanBuku();
void simpanDataBuku();
void simpanDataAkun();
void simpanDataPinjam();
void muatData();
void muatDataBuku();
void muatDataAkun();
void muatDataPinjam();

// Fungsi untuk menambahkan buku baru
void tambahBuku()
{
    system("cls");
    if (jumlah_buku == MAX_BUKU)
    {
        cout << "Maaf, kapasitas penuh. Tidak bisa menambah buku baru." << endl;
        cout << "--------------------" << endl;
        return;
    }

    Buku buku_baru;

    cout << "Judul: ";
    getline(cin, buku_baru.judul);

    cout << "Pengarang: ";
    getline(cin, buku_baru.pengarang);

    cout << "Tahun Terbit: ";
    cin >> buku_baru.tahun_terbit;

    buku_baru.dipinjam = false;

    cin.ignore(); // Membersihkan newline character dari input sebelumnya

    daftar_buku[jumlah_buku] = buku_baru;
    jumlah_buku++;

    cout << "Buku berhasil ditambahkan." << endl;
    cout << "--------------------" << endl;
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// Fungsi untuk mencari buku berdasarkan judul (SEQUENTIAL SEARCH)
void cariBukuJudul()
{
    system("cls");
    string judul_cari;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, judul_cari);

    bool ditemukan = false;
    for (int i = 0; i < jumlah_buku; i++)
    {
        if (daftar_buku[i].judul == judul_cari)
        {
            cout << "Buku ditemukan!" << endl;
            cout << "Judul: " << daftar_buku[i].judul << endl;
            cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
            cout << "Tahun Terbit: " << daftar_buku[i].tahun_terbit << endl;
            cout << "--------------------" << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan." << endl;
        cout << "--------------------" << endl;
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

void cariBukuPenerbit()
{
    system("cls");
    string pengarang_cari ;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, pengarang_cari);

    bool ditemukan = false;
    for (int i = 0; i < jumlah_buku; i++)
    {
        if (daftar_buku[i].pengarang == pengarang_cari)
        {
            cout << "Buku ditemukan!" << endl;
            cout << "Judul: " << daftar_buku[i].judul << endl;
            cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
            cout << "Tahun Terbit: " << daftar_buku[i].tahun_terbit << endl;
            cout << "--------------------" << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan." << endl;
        cout << "--------------------" << endl;
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// Fungsi untuk mengurutkan buku berdasarkan judul menggunakan algoritma bubble sort
void urutkanBuku()
{
    system("cls");
    for (int i = 0; i < jumlah_buku - 1; i++)
    {
        for (int j = 0; j < jumlah_buku - i - 1; j++)
        {
            if (daftar_buku[j].judul > daftar_buku[j + 1].judul)
            {
                swap(daftar_buku[j], daftar_buku[j + 1]);
            }
        }
    }
}

// BAGIAN PRADITUS EGI DANUARTA
// Fungsi untuk mengubah data buku berdasarkan judul
void updateBuku()
{
    system("cls");
    string judul_cari;
    cout << "Masukkan judul buku yang ingin diupdate: ";
    getline(cin, judul_cari);

    bool ditemukan = false;
    for (int i = 0; i < jumlah_buku; i++)
    {
        if (daftar_buku[i].judul == judul_cari)
        {
            cout << "Buku ditemukan!" << endl;

            Buku &buku = daftar_buku[i]; // Menggunakan reference untuk mengubah data buku

            cout << "Judul (sebelumnya): " << buku.judul << endl;
            cout << "Pengarang (sebelumnya): " << buku.pengarang << endl;
            cout << "Tahun Terbit (sebelumnya): " << buku.tahun_terbit << endl;

            cout << "Masukkan data buku yang baru : " << endl;
            cout << "Judul: ";
            getline(cin, buku.judul);

            cout << "Pengarang: ";
            getline(cin, buku.pengarang);

            cout << "Tahun Terbit: ";
            cin >> buku.tahun_terbit;

            cin.ignore(); // Membersihkan newline character dari input sebelumnya

            cout << "Buku berhasil diupdate." << endl;
            cout << "--------------------" << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan." << endl;
        cout << "--------------------" << endl;
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// Fungsi untuk menampilkan semua buku pada perpustakaan
void lihatBuku()
{
    system("cls");
    if (jumlah_buku == 0)
    {
        cout << "Tidak ada buku yang tersedia." << endl;
        cout << "--------------------" << endl;
        return;
    }

    cout << "Daftar buku yang tersedia:" << endl;
    for (int i = 0; i < jumlah_buku; i++)
    {
        cout << "Judul: " << daftar_buku[i].judul << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Tahun Terbit: " << daftar_buku[i].tahun_terbit << endl;
        cout << "Status : ";
        if (daftar_buku[i].dipinjam == true)
        {
            cout << "Sedang Dipinjam" << endl;
            cout << "--------------------" << endl;
        }
        else
        {
            cout << "Tersedia" << endl;
        }
        cout << "--------------------" << endl;
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

void lihatDetail()
{
    system("cls"); // clear screen
    muatDataPinjam();
    if (jumlah_pinjaman == 0)
    {
        cout << "Tidak ada yang meminjam" << endl;
        cout << "--------------------" << endl;
        return;
    }

    cout << "Daftar peminjam : " << endl;
    for (int i = 0; i < jumlah_pinjaman; i++)
    {
        if (daftar_pinjaman[i].pinjaman == true)
        {
            cout << "Judul: " << daftar_pinjaman[i].judul_buku << endl;
            cout << "Peminjam: " << daftar_pinjaman[i].pengguna << endl;
            cout << "Status : Dipinjam" << endl;
            cout << "--------------------" << endl;
        }
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// Fungsi untuk login admin
void loginAdmin()
{
    system("cls");
    string username;
    string password;
    cout << "\nMasukkan Username: ";
    cin >> username;
    cout << "\nMasukkan Password: ";
    cin >> password;

    if (username == "admin" && password == "admin")
    {
        cout << "Login berhasil." << endl;
        cout << "--------------------" << endl;
    }
    else
    {
        cout << "\nUsername atau password salah." << endl;
        cout << "--------------------" << endl;
        return loginAdmin();
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// BAGIAN NANDA PRATAMA

// Fungsi untuk meminjam buku

void pinjamBuku()
{
    system("cls");
    string username, password;
    cout << "\nMasukkan username: ";
    cin >> username;
    cout << "\nMasukkan password: ";
    cin >> password;

    int indeks_akun = -1;
    for (int i = 0; i < jumlah_akun; i++)
    {
        if (daftar_akun[i].username == username && daftar_akun[i].password == password)
        {
            indeks_akun = i;
            break;
        }
    }

    if (indeks_akun != -1)
    {
        if (daftar_akun[indeks_akun].meminjam == true)
        {
            cout << "Akun ini sudah meminjam buku." << endl;
            cout << "--------------------" << endl;
        }
        else
        {
            string judul_pinjam;
            cout << "Masukkan judul buku yang ingin dipinjam: ";
            cin.ignore();
            getline(cin, judul_pinjam);

            bool ditemukan = false;
            for (int i = 0; i < jumlah_buku; i++)
            {
                if (daftar_buku[i].judul == judul_pinjam)
                {
                    if (daftar_buku[i].dipinjam == true)
                    {
                        cout << "Buku sedang dipinjam oleh akun lain." << endl;
                        cout << "--------------------" << endl;
                    }
                    else
                    {
                        daftar_buku[i].dipinjam = true;
                        daftar_akun[indeks_akun].meminjam = true;
                        daftar_pinjaman[jumlah_pinjaman].judul_buku = judul_pinjam;
                        daftar_pinjaman[jumlah_pinjaman].pengguna = username;
                        daftar_pinjaman[jumlah_pinjaman].pinjaman = true;
                        daftar_pinjaman[indeks_akun].judul_buku = judul_pinjam;
                        daftar_pinjaman[indeks_akun].pengguna = username;
                        cout << "Buku berhasil dipinjam." << endl;
                        cout << "--------------------" << endl;
                        jumlah_pinjaman++;
                    }
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan)
            {
                cout << "Buku tidak ditemukan." << endl;
                cout << "--------------------" << endl;
            }
        }
    }
    else
    {
        cout << "Username atau password salah." << endl;
        cout << "--------------------" << endl;
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku()
{
    system("cls");
    string user, pass;
    cout << "\nMasukkan username: ";
    getline(cin, user);
    cout << "\nMasukkan password: ";
    getline(cin, pass);
    int index = -1;
    for (int i = 0; i < jumlah_akun; i++)
    {
        if (daftar_akun[i].username == user && daftar_akun[i].password == pass)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        if (daftar_akun[index].meminjam == true)
        {
            string judul_kembali;
            cout << "Masukkan judul buku yang ingin dikembalikan: ";
            getline(cin, judul_kembali);
            bool ditemukan = false;
            for (int i = 0; i < jumlah_buku; i++)
            {
                if (daftar_buku[i].judul == judul_kembali)
                {
                    if (daftar_buku[i].dipinjam == true)
                    {
                        for (int j = 0; j < jumlah_buku; j++)
                        {
                            if (daftar_pinjaman[j].judul_buku == judul_kembali)
                            {
                                daftar_buku[i].dipinjam = false;
                                daftar_akun[index].meminjam = false;
                                daftar_pinjaman[j].pinjaman = false;
                                cout << "Buku berhasil dikembalikan." << endl;
                                cout << "--------------------" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Buku belum dipinjam." << endl;
                        cout << "--------------------" << endl;
                    }

                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan)
            {
                cout << "Buku tidak ditemukan." << endl;
                cout << "--------------------" << endl;
            }
        }
        else
        {
            cout << "Akun ini tidak meminjam buku" << endl;
        }
    }
    else
    {
        cout << "Username atau password salah." << endl;
        cout << "--------------------" << endl;
    }
    cin.ignore();
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// BAGIAN HILAL

void simpanDataBuku()
{
    ofstream file("data_buku.txt");

    if (file.is_open())
    {
        for (int i = 0; i < jumlah_buku; i++)
        {
            file << daftar_buku[i].judul << "\n";
            file << daftar_buku[i].pengarang << "\n";
            file << daftar_buku[i].tahun_terbit << "\n";
            file << daftar_buku[i].dipinjam << "\n";
        }

        file.close();
        // cout << "Data buku berhasil disimpan." << endl;
    }
    else
    {
        cout << "Gagal membuka file." << endl;
    }
}

void simpanDataPinjam()
{
    ofstream file("data_pinjam.txt");

    if (file.is_open())
    {
        for (int i = 0; i < jumlah_pinjaman; i++)
        {
            file << daftar_pinjaman[i].judul_buku << "\n";
            file << daftar_pinjaman[i].pengguna << "\n";
            file << daftar_pinjaman[i].pinjaman << "\n";
        }

        file.close();
        // cout << "Data buku berhasil disimpan." << endl;
    }
    else
    {
        cout << "Gagal membuka file." << endl;
    }
}

void muatData()
{
    ifstream file("data_buku.txt");

    if (file.is_open())
    {
        string line;
        int i = 0;
        while (getline(file, line))
        {
            daftar_buku[i].judul = line;
            getline(file, line);
            daftar_buku[i].pengarang = line;
            getline(file, line);
            daftar_buku[i].tahun_terbit = stoi(line);
            getline(file, line);
            daftar_buku[i].dipinjam = (line == "1");

            i++;
            if (i >= MAX_BUKU)
                break;
        }

        jumlah_buku = i;

        file.close();
    }
    else
    {
        cout << "Gagal membuka berkas." << endl;
    }
}

void muatDataAkun()
{
    ifstream file("data_akun.txt");

    if (file.is_open())
    {
        string line;
        int i = 0;
        while (getline(file, line))
        {
            daftar_akun[i].username = line;
            getline(file, line);
            daftar_akun[i].password = line;
            getline(file, line);
            daftar_akun[i].meminjam = (line == "1");
            i++;
            if (i >= MAX_BUKU)
                break;
        }

        jumlah_akun = i;

        file.close();
    }
    else
    {
        cout << "Gagal membuka file." << endl;
    }
}

void muatDataPinjam()
{
    ifstream file("data_pinjam.txt");

    if (file.is_open())
    {
        string line;
        int i = 0;
        while (getline(file, line))
        {
            daftar_pinjaman[i].judul_buku = line;
            getline(file, line);
            daftar_pinjaman[i].pengguna = line;
            getline(file, line);
            daftar_pinjaman[i].pinjaman = (line == "1");
            i++;
            if (i >= MAX_BUKU)
                break;
        }

        jumlah_pinjaman = i;

        file.close();
    }
    else
    {
        cout << "Gagal membuka berkas." << endl;
    }
}

// BAGIAN ALFIN

void simpanDataAkunPinjam()
{
    ofstream file("data_akun.txt");

    if (file.is_open())
    {
        for (int i = 0; i < MAX_BUKU; i++)
        {
            file << daftar_akun[i].username << "\n";
            file << daftar_akun[i].password << "\n";
            file << daftar_akun[i].meminjam << "\n";
        }

        file.close();
        // cout << "Data akun berhasil disimpan." << endl;
    }
    else
    {
        cout << "Gagal membuka file." << endl;
    }
}

void redaksional()
{
    system("cls");
    cout << "\n========================================="
         << endl;
    cout << "KELOMPOK 6 - MANAJEMEN PERPUSTAKAAN VVIP"
         << endl;
    cout << "=========================================\n\n"
         << endl;
    cout << "22.11.4661 - AGUS HERYANTO" << endl;
    cout << "22.11.4634 - ANDI MUHAMAD BARIK ALFIN" << endl;
    cout << "22.11.4623 - NANDA PRATAMA" << endl;
    cout << "22.11.4638 - MUHAMMAD HILLAL ALHAMDI" << endl;
    cout << "22.11.4662 - PRADITUS EGI DANUARTA" << endl;
    cout << "\n\n=========================================\n\n"
         << endl;
    cout << "\n\nKlik Enter Untuk Melanjutkan\n\n"
         << endl;
    getchar();
}

// Fungsi utama
int main()
{
    redaksional();
    muatData();
    muatDataAkun;
    muatDataPinjam;
menu_login:
    int pilihan;
    system("cls");
    cout << "\n==== Manajemen Perpustakaan ====\n"
         << endl;
    cout << "\n1. Masuk" << endl;
    cout << "\n0. Keluar" << endl;
    cout << "\nPilih Menu: ";
    cin >> pilihan;
    cin.ignore(); // Membersihkan newline character dari input sebelumnya
    if (pilihan == 1)
    {
        loginAdmin();
        goto menu_admin;
    }
    else
    {
        return 0;
    }
menu_admin:
    do
    {
        system("cls");
        cout << "\n==== Menu Admin ====" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Cari Buku Berdasarkan Judul" << endl;
        cout << "3. Cari Buku Berdasarkan Penerbit" << endl;
        cout << "4. Update Buku" << endl;
        cout << "5. Lihat Buku" << endl;
        cout << "6. Pinjam Buku" << endl;
        cout << "7. Mengembalikan Buku" << endl;
        cout << "8. Detail Pinjaman Buku" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        cin.ignore(); // Membersihkan newline character dari input sebelumnya

        switch (pilihan)
        {
        case 1:
            muatData();
            tambahBuku();
            simpanDataBuku();
            urutkanBuku();
            simpanDataBuku();
            break;
        case 2:
            muatData();
            cariBukuJudul();
            break;
        case 3:
            muatData();
            cariBukuPenerbit();
            break;
        case 4:
            muatData();
            updateBuku();
            simpanDataBuku();
            break;
        case 5:
            muatData();
            lihatBuku();
            break;
        case 6:
            muatData();
            muatDataPinjam();
            muatDataAkun();
            pinjamBuku();
            simpanDataBuku();
            simpanDataPinjam();
            simpanDataAkunPinjam();
            break;
        case 7:
            muatData();
            muatDataPinjam();
            muatDataAkun();
            kembalikanBuku();
            simpanDataBuku();
            simpanDataPinjam();
            simpanDataAkunPinjam();
            break;
        case 8:
            muatData();
            muatDataAkun();
            muatDataPinjam();
            lihatDetail();
            simpanDataBuku();
            break;
        case 0:
            goto menu_login;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilihan != 0);
    {
        simpanDataAkunPinjam();
        simpanDataBuku();
        simpanDataPinjam();
        return 0;
    }
    simpanDataAkunPinjam();
    simpanDataBuku();
    simpanDataPinjam();
}