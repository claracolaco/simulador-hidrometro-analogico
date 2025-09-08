#include "Medicao.hpp"
#include <iomanip>   // para std::setw e std::setfill
#include <sstream>   // para montar string formatada

// Construtor: inicia volume zerado
Medicao::Medicao(int limite) {
    volumeTotal_m3 = 0.0;
    mm = 0;
    limiteOdometro = limite;
}

// Soma volume ao total e atualiza mm + odômetro
void Medicao::contabilizar(double volume_m3) {
    // Atualiza volume total
    volumeTotal_m3 += volume_m3;

    // Atualiza mm (subunidades vermelhas)
    mm = static_cast<int>((volumeTotal_m3 - static_cast<int>(volumeTotal_m3)) * 1000);

    // Reseta se ultrapassar limite do odômetro
    if (volumeTotal_m3 >= limiteOdometro) {
        volumeTotal_m3 = 0.0;
        mm = 0;
    }
}

// Retorna string formatada da leitura (ex.: "01234 m³ | 067 mm")
std::string Medicao::leituraTexto() const {
    std::ostringstream oss;

    oss << std::setw(5) << std::setfill('0') << static_cast<int>(volumeTotal_m3)
        << " m³ | " 
        << std::setw(3) << std::setfill('0') << mm
        << " mm";

    return oss.str();
}

// Getters
double Medicao::getVolumeTotal_m3() const {
    return volumeTotal_m3;
}

int Medicao::getMM() const {
    return mm;
}
