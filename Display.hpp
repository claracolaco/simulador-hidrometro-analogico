#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include "Medicao.hpp"

class Display {
private:
    std::string formato;   // ex.: "jpeg" (para futuras versões com imagem)

public:
    // Construtor
    Display(std::string formato = "texto");

    // Mostra a leitura no terminal
    void desenharMostrador(const Medicao& medicao) const;

    // Adiciona um texto extra sobreposto (ex.: "Simulação em andamento...")
    void sobreporTexto(const std::string& texto) const;

    // Getter
    std::string getFormato() const;
};

#endif
