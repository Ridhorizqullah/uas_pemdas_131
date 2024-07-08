#include <iostream>
using namespace std;
class MataKuliah
{
protected:
    float Presensi; 

public:
    MataKuliah()
    {
        int Presensi = 0.0;
        int Activity = 0.0;
        int Exercise = 0.0;
        int TugasAkhir = 0.0;
    }

    virtual void namaMatakuliah() {
        void setPresensi(float nilai) {
            Presensi = nilai;
        }

        float getPresensi() {
            return Presensi;
        }
    }
};

class Pemrograman : public MataKuliah
{
private:
    float activity;
    float exercise;
    float tugasAkhir;


public:

    void inputNilai(float presensi, float activity, float exercise, float tugasAkhir) {
        set.Presensi(presensi);
        set.Activity(activity);
        set.Exercise(exercise);
        set.TugasAkhir(tugasAkhir);
    }
    float hitungNilaiAkhir()  {
        return (Presensi * 0.1) + (activity * 0.2) + (exercise * 0.3) + (tugasAkhir * 0.4);
    }

    bool cekKelulusan()  {
        return hitungNilaiAkhir() >= 75.0;
    }
};

class Jaringan : public MataKuliah
{
private:
    float activity;
    float exercise;

public:
    virtual void namaMataKuliah() {
        void inputNilai(float activity, float exercise) {
            set.Activity(activity);
            set.Exercise(exercise);
        }

        float hitungNilaiAkhir() {
            return (activity * 0.4) + (exercise * 0.6);
        }

        bool cekKelulusan() {
            return hitungNilaiAkhir() >= 75.0;
        }

    }

};

int main() {
    char pilih = '0';
    MataKuliah* mataKuliah = nullptr;
    Pemrograman pemrograman;
    Jaringan jaringan;

    cout << "Program Pertama Kali Dijalankan" << endl;

    while (pilih != '3') {
        cout << "Pilih Mata Kuliah :" << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
        case '1': {
            float presensi, activity, exercise, tugasAkhir;
            cout << "Masukkan nilai presensi : ";
            cin >> presensi;
            cout << "Masukkan nilai activity : ";
            cin >> activity;
            cout << "Masukkan nilai exercise : ";
            cin >> exercise;
            cout << "Masukkan nilai tugas akhir : ";
            cin >> tugasAkhir;

            pemrograman.inputNilai(presensi, activity, exercise, tugasAkhir);
            mataKuliah = &pemrograman;
            break;
        }
        case '2': {
            float activity, exercise;
            cout << "Masukkan nilai activity : ";
            cin >> activity;
            cout << "Masukkan nilai exercise : ";
            cin >> exercise;

            jaringan.inputNilai(activity, exercise);
            mataKuliah = &jaringan;
            break;
        }
        case '3':
            cout << "Terima kasih." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }

        if (pilih == '1' || pilih == '2') {
            cout << "Nilai Akhir : " << mataKuliah->hitungNilaiAkhir() << endl;
            if (mataKuliah->cekKelulusan()) {
                cout << "Selamat Anda dinyatakan Lulus." << endl;
            }
            else {
                cout << "Anda dinyatakan Tidak Lulus." << endl;
            }
        }

        cout << endl;
    }

    return 0;
}