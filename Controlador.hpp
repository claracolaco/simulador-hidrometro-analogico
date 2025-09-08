#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include <map>
#include <string>
#include "Hidrometro.hpp"

class Controlador {
private:
    std::map<std::string, std::string> configuracao; // pares CHAVE=valor do config.txt
    Hidrometro h1;

    // utilitário: remove espaços nas pontas
    static std::string trim(const std::string& s);

public:
    Controlador() = default;

    // Carrega o arquivo de configuração (ex.: TFS, VAM, PCT_AR, TAXA_IMG, CAMINHO)
    // Retorna true se carregou com sucesso
    bool carregarConfig(const std::string& arquivo);

    // Executa a simulação de acordo com a configuração lida
    void executa();

    // Acesso (útil para testes)
    const std::map<std::string, std::string>& getConfiguracao() const { return configuracao; }
    Hidrometro& getHidrometro() { return h1; }
    const Hidrometro& getHidrometro() const { return h1; }
};

#endif
