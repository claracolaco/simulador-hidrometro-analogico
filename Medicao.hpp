#ifndef MEDICAO_HPP
#define MEDICAO_HPP

#include <string>

class Medicao {
private:
    double volumeTotal_m3;   
    int mm;                 
    int limiteOdometro;  

public:
    Medicao(int limite = 99999);

    void contabilizar(double volume_m3);   
    std::string leituraTexto() const;      

    double getVolumeTotal_m3() const;
    int getMM() const;
};

#endif
