#include "Entrada.hpp"
#include <algorithm> // std::min, std::max
#include <cctype>    // std::tolower

static std::string toLower(std::string s) {
    for (auto &ch : s) ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    return s;
}

Entrada::Entrada(float bitola, float vazao, std::string sentido, float arPercentual)
    : bitola(bitola),
      vazao(vazao),
      sentido(std::move(sentido)),
      arPercentual(arPercentual) {}

void Entrada::configurar(float bitola, float vazao, std::string sentido, float arPercentual) {
    this->bitola = bitola;
    this->vazao = vazao;
    this->sentido = std::move(sentido);
    this->arPercentual = arPercentual;
}

// retorna o volume (em m³) para um intervalo de tempo (minutos)
// se sentido == "Reverso" => 0; aplica desconto por arPercentual; nunca negativo.
float Entrada::amostrarFluxo(float minutos) const {
    if (minutos <= 0.0f) return 0.0f;

    // se tá no reverso, não contabiliza
    const std::string s = toLower(sentido);
    if (s == "reverso") return 0.0f;

    // volume bruto: vazão (m³/min) * tempo (min)
    float volume = vazao * minutos;

    // aplica desconto de ar (0..100%)
    float desconto = arPercentual / 100.0f;
    desconto = std::clamp(desconto, 0.0f, 1.0f);
    volume *= (1.0f - desconto);

    if (volume < 0.0f) volume = 0.0f;
    return volume;
}

float Entrada::getBitola() const { return bitola; }
float Entrada::getVazao() const { return vazao; }
std::string Entrada::getSentido() const { return sentido; }
float Entrada::getArPercentual() const { return arPercentual; }
