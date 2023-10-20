#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Fungsi untuk memformat angka dengan koma untuk ribuan
string formatWithCommas(int number) {
    stringstream ss;
    ss.imbue(std::locale(""));
    ss << number;
    return ss.str();
}

int main() {
  string namaKaryawan, pendidikan;
  int golongan;
  int jumlahJamKerja, tunjanganJabatan, tunjanganPendidikan, honorLembur;
  const int honorTetap = 300000, bonusLemburPerJam = 2500;
  
  map<int, double> bonusGolongan;
  map<string, double> bonusPendidikan;

  bonusGolongan[1] = 0.05;
  bonusGolongan[2] = 0.10;
  bonusGolongan[3] = 0.15;

  bonusPendidikan["SMU"] = 0.025;
  bonusPendidikan["D3"] = 0.05;
  bonusPendidikan["S1"] = 0.075;

  cout << "Program Hitung Honor Karyawan Kontrak PT. DINGIN DAMAI" << endl;

  cout << "Nama Karyawan \t\t: "; getline(cin, namaKaryawan);
  cout << "Golongan \t\t: "; cin >> golongan;
  cout << "Pendidikan (SMU/D3/S1) \t: "; cin >> pendidikan;
  cout << "Jumlah Jam Kerja \t: "; cin >> jumlahJamKerja;

  tunjanganJabatan = bonusGolongan[golongan] * honorTetap;
  tunjanganPendidikan = bonusPendidikan[pendidikan] * honorTetap;
  honorLembur = jumlahJamKerja > 8 ? (jumlahJamKerja - 8) * bonusLemburPerJam : 0;

  cout << endl << endl << "Karyawan yang bernama \t: " << namaKaryawan << endl;
  cout << "Honor yang diterima" << endl;
  cout << "\tHonor Tetap \t\tRp. " << formatWithCommas(honorTetap) << endl;
  cout << "\tTunjangan Jabatan \tRp. " << formatWithCommas(tunjanganJabatan) << endl;
  cout << "\tTunjangan Pendidikan \tRp. " << formatWithCommas(tunjanganPendidikan) << endl;
  cout << "\tHonor Lembur \t\tRp. " << formatWithCommas(honorLembur) << endl;
}
