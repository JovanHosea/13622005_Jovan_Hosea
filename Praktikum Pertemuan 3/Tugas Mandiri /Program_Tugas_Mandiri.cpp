#include <iostream>
class RekeningBank {

    private:
    double saldo; 

public:
    RekeningBank(double saldoAwal) {
        saldo = saldoAwal;
        std::cout << "Rekening berhasil dibuat dengan saldo awal: " << saldo << std::endl;
    }

    void setor(double jumlah) {
        if (jumlah > 0) {
            saldo += jumlah;
            std::cout << "Setoran berhasil sebesar: " << jumlah 
                      << " | Saldo sekarang: " << saldo << std::endl;
        } else {
            std::cout << "Error: Jumlah setoran tidak valid!" << std::endl;
        }
    }

    void tarik(double jumlah) {
        if (jumlah > saldo) {
            std::cout << "Penarikan Gagal: Saldo Anda tidak mencukupi untuk menarik " 
                      << jumlah << " (Saldo: " << saldo << ")" << std::endl;
        } else if (jumlah > 0) {
            saldo -= jumlah;
            std::cout << "Penarikan berhasil sebesar: " << jumlah 
                      << " | Sisa saldo: " << saldo << std::endl;
        } else {
            std::cout << "Error: Jumlah penarikan tidak valid!" << std::endl;
        }
    }
};

int main() {
    double inputSaldoAwal;
    int pilihanMenu;
    double nominal;

    std::cout << "=== Selamat Datang di Sistem Perbankan ===" << std::endl;
    do {
        std::cout << "Masukkan nominal saldo awal Anda: ";
        std::cin >> inputSaldoAwal;

        if (inputSaldoAwal < 0) {
            std::cout << ">> Error: Saldo awal tidak boleh negatif. Silakan ulangi.\n" << std::endl;
        }
    } while (inputSaldoAwal < 0);

    RekeningBank rekeningJovan(inputSaldoAwal);

    do {
        std::cout << "\n--- Menu Transaksi ---" << std::endl;
        std::cout << "1. Setor Tunai" << std::endl;
        std::cout << "2. Tarik Tunai" << std::endl;
        std::cout << "3. Keluar" << std::endl;
        std::cout << "Pilih menu (1/2/3): ";
        std::cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            std::cout << "Masukkan nominal setoran: ";
            std::cin >> nominal;
            rekeningJovan.setor(nominal);
        } 
        else if (pilihanMenu == 2) {
            std::cout << "Masukkan nominal penarikan: ";
            std::cin >> nominal;
            rekeningJovan.tarik(nominal);
        } 
        else if (pilihanMenu == 3) {
            std::cout << "Terima kasih telah bertransaksi!" << std::endl;
        } 
        else {
            std::cout << "Pilihan tidak valid!" << std::endl;
        }

    } while (pilihanMenu != 3);

    return 0;
}
