#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <string>
#include "Medicao.hpp"
#include "Display.hpp"

class Saida {
private:
    std::string caminhoImagem; 
    float taxaImg_m3;          
public:
    Saida(std::string caminho = "saida.txt", float taxa = 1.0f);

    // gera a "imagem" (nessa versão, salva em arquivo .txt)
    void gerarJPEG(const Medicao& m, const Display& d) const;

    std::string getCaminhoImagem() const;
    float getTaxaImg_m3() const;

    void setCaminhoImagem(const std::string& caminho);
    void setTaxaImg_m3(float taxa);
};

#endif
