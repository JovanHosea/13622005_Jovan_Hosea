#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::vector<double> sensor;

    sensor.push_back(100.5);
    sensor.push_back(200.0);
    sensor.push_back(150.5);

    std::cout << "Memproses data sensor..." << std::endl;

    for (int i = 0; i < sensor.size(); i++) {
        sensor[i] = sensor[i] * 1.1;
    }

    std::ofstream fileOutput("hasil_kalibrasi.txt");

    if (!fileOutput.is_open()) {
        std::cerr << "Error: Gagal membuka atau membuat file output!" << std::endl;
        return 1;
    }

    for (int i = 0; i < sensor.size(); i++) {
        fileOutput << sensor[i] << "\n";
    }

    fileOutput.close();
    std::cout << "Proses selesai! Data telah diekspor ke 'hasil_kalibrasi.txt'." << std::endl;

    return 0;
}
