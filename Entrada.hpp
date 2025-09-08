#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include <string>

class Entrada {
private:
    float bitola;          // largura do cano (simbólico)
    float vazao;           // volume por minuto (0..100)
    std::string sentido;   // "Direto" ou "Reverso"
    float arPercentual;    // % de ar presente (0..100)

public:
    // Construtor
    Entrada(float bitola = 0.0f, float vazao = 0.0f,
            std::string sentido = "Direto", float arPercentual = 0.0f);

    // Configura os parâmetros de entrada
    void configurar(float bitola, float vazao, std::string sentido, float arPercentual);

    // Calcula o volume de água em m³ num intervalo de tempo (em minutos)
    float amostrarFluxo(float minutos) const;

    // Getters
    float getBitola() const;
    float getVazao() const;
    std::string getSentido() const;
    float getArPercentual() const;
};

#endif
