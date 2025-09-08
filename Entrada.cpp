#include "Entrada.hpp"
#include <algorithm> // std::min, std::max
#include <cctype>    // std::tolower

// Utilitário local para comparar "Direto"/"Reverso" sem diferenciar maiúsculas/minúsculas
static std::string toLower(std::string s) {
    for (auto &ch : s) ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    return s;
}

// Construtor
Entrada::Entrada(float bitola, float vazao, std::string sentido, float arPercentual)
    : bitola(bitola),
      vazao(vazao),
      sentido(std::move(sentido)),
      arPercentual(arPercentual) {}

// Configuração dos parâmetros
void Entrada::configurar(float bitola, float vazao, std::string sentido, float arPercentual) {
    this->bitola = bitola;
    this->vazao = vazao;
    this->sentido = std::move(sentido);
    this->arPercentual = arPercentual;
}

// Retorna o volume (em m³) para um intervalo de tempo (minutos)
// Regras: se sentido == "Reverso" => 0; aplica desconto por arPercentual; nunca negativo.
float Entrada::amostrarFluxo(float minutos) const {
    if (minutos <= 0.0f) return 0.0f;

    // Se está no reverso, não contabiliza
    const std::string s = toLower(sentido);
    if (s == "reverso") return 0.0f;

    // Volume bruto: vazão (m³/min) * tempo (min)
    float volume = vazao * minutos;

    // Aplica desconto de ar (0..100%)
    float desconto = arPercentual / 100.0f;
    desconto = std::clamp(desconto, 0.0f, 1.0f);
    volume *= (1.0f - desconto);

    // Garante não negativo
    if (volume < 0.0f) volume = 0.0f;
    return volume;
}

// Getters
float Entrada::getBitola() const { return bitola; }
float Entrada::getVazao() const { return vazao; }
std::string Entrada::getSentido() const { return sentido; }
float Entrada::getArPercentual() const { return arPercentual; }
