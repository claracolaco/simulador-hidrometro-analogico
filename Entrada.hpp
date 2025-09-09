#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include <string>

class Entrada {
private:
    float bitola;          // largura do cano
    float vazao;           // volume por minuto (0..100)
    std::string sentido;   // "Direto" ou "Reverso"
    float arPercentual;    // % de ar presente (0..100)

public:
    Entrada(float bitola = 0.0f, float vazao = 0.0f,
            std::string sentido = "Direto", float arPercentual = 0.0f);

    void configurar(float bitola, float vazao, std::string sentido, float arPercentual);

    float amostrarFluxo(float minutos) const;

    float getBitola() const;
    float getVazao() const;
    std::string getSentido() const;
    float getArPercentual() const;
};

#endif
