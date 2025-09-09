#include "Display.hpp"
#include <iostream>

Display::Display(std::string formato)
    : formato(std::move(formato)) {}

void Display::desenharMostrador(const Medicao& medicao) const {
    // Vversão inicial: apenas imprime a leitura no terminal
    std::cout << "[DISPLAY] " << medicao.leituraTexto() << std::endl;
}

void Display::sobreporTexto(const std::string& texto) const {
    // versão inicial: só exibe a mensagem extra no terminal
    if (!texto.empty()) {
        std::cout << "[INFO] " << texto << std::endl;
    }
}

std::string Display::getFormato() const {
    return formato;
}
