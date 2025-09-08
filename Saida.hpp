#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <string>
#include "Medicao.hpp"
#include "Display.hpp"

class Saida {
private:
    std::string caminhoImagem; // caminho para salvar a saída
    float taxaImg_m3;          // intervalo em m³ para gerar saída

public:
    // Construtor
    Saida(std::string caminho = "saida.txt", float taxa = 1.0f);

    // Gera a "imagem" (nesta versão: salva em arquivo .txt)
    void gerarJPEG(const Medicao& m, const Display& d) const;

    // Getters
    std::string getCaminhoImagem() const;
    float getTaxaImg_m3() const;

    // Setters
    void setCaminhoImagem(const std::string& caminho);
    void setTaxaImg_m3(float taxa);
};

#endif
