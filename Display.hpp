#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include "Medicao.hpp"

class Display {
private:
    std::string formato;   

public:
    Display(std::string formato = "texto");

    void desenharMostrador(const Medicao& medicao) const;

    void sobreporTexto(const std::string& texto) const;

    std::string getFormato() const;
};

#endif
