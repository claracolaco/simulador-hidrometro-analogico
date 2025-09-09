#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include <map>
#include <string>
#include "Hidrometro.hpp"

class Controlador {
private:
    std::map<std::string, std::string> configuracao; 
    Hidrometro h1;

    static std::string trim(const std::string& s);

public:
    Controlador() = default;

    bool carregarConfig(const std::string& arquivo);

    void executa();

    const std::map<std::string, std::string>& getConfiguracao() const { return configuracao; }
    Hidrometro& getHidrometro() { return h1; }
    const Hidrometro& getHidrometro() const { return h1; }
};

#endif
