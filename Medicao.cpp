#include "Medicao.hpp"
#include <iomanip>   
#include <sstream>  

Medicao::Medicao(int limite) {
    volumeTotal_m3 = 0.0;
    mm = 0;
    limiteOdometro = limite;
}

void Medicao::contabilizar(double volume_m3) {
    volumeTotal_m3 += volume_m3;

    mm = static_cast<int>((volumeTotal_m3 - static_cast<int>(volumeTotal_m3)) * 1000);

    if (volumeTotal_m3 >= limiteOdometro) {
        volumeTotal_m3 = 0.0;
        mm = 0;
    }
}

std::string Medicao::leituraTexto() const {
    std::ostringstream oss;

    oss << std::setw(5) << std::setfill('0') << static_cast<int>(volumeTotal_m3)
        << " m³ | " 
        << std::setw(3) << std::setfill('0') << mm
        << " mm";

    return oss.str();
}

double Medicao::getVolumeTotal_m3() const {
    return volumeTotal_m3;
}

int Medicao::getMM() const {
    return mm;
}
