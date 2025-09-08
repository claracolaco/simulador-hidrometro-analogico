#ifndef MEDICAO_HPP
#define MEDICAO_HPP

#include <string>

class Medicao {
private:
    double volumeTotal_m3;   // Volume total em metros cúbicos
    int mm;                  // Subunidades (dígitos vermelhos)
    int limiteOdometro;      // Limite máximo antes de voltar a zero

public:
    // Construtor
    Medicao(int limite = 99999);

    // Métodos principais
    void contabilizar(double volume_m3);   // Soma volume ao total
    std::string leituraTexto() const;      // Retorna string com leitura formatada

    // Getters
    double getVolumeTotal_m3() const;
    int getMM() const;
};

#endif
