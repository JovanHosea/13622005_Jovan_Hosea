#include <iostream>
#include <fstream>
#include <string>

int main() {  
    // --- 1. PROSES MENULIS FILE (DIMATIKAN SEMENTARA) ---  
    /*
    std::ofstream fileTulis("data_sensor.txt"); 

    if (fileTulis.is_open()) {  
        fileTulis << "100.5\n";  
        fileTulis << "200.0\n";  
        fileTulis << "150.5\n";  
        fileTulis.close();  
        std::cout << "=> Data tersimpan di 'data_sensor.txt'\n";  
    } else {  
        std::cout << "Gagal membuat file.\n";  
    }
    */

    // --- 2. PROSES MEMBACA FILE (TETAP AKTIF) ---  
    std::ifstream fileBaca("data_sensor.txt");  
    std::string baris_teks;  
      
    std::cout << "\n--- Membaca isi file ---" << std::endl;  
    if (fileBaca.is_open()) {  
        while (std::getline(fileBaca, baris_teks)) {  
            std::cout << "Isi file: " << baris_teks << std::endl;  
        }  
        fileBaca.close();  
    } else {  
        std::cout << "File tidak ditemukan!\n";  
    }

    return 0;  
}
