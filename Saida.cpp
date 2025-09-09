#include "Saida.hpp"
#include <fstream>  
#include <iostream>  
Saida::Saida(std::string caminho, float taxa)
    : caminhoImagem(std::move(caminho)), taxaImg_m3(taxa) {}

void Saida::gerarJPEG(const Medicao& m, const Display& d) const {
    std::ofstream arquivo(caminhoImagem);

    if (!arquivo.is_open()) {
        std::cerr << "[ERRO] Não foi possível criar o arquivo: " << caminhoImagem << std::endl;
        return;
    }

    arquivo << "Simulador de Hidrômetro Analógico\n";
    arquivo << "===============================\n";
    arquivo << "Leitura atual: " << m.leituraTexto() << "\n";
    arquivo << "Formato de saída: " << d.getFormato() << "\n";
    arquivo.close();

    std::cout << "[SAIDA] Arquivo gerado em: " << caminhoImagem << std::endl;
}

std::string Saida::getCaminhoImagem() const {
    return caminhoImagem;
}

float Saida::getTaxaImg_m3() const {
    return taxaImg_m3;
}

void Saida::setCaminhoImagem(const std::string& caminho) {
    caminhoImagem = caminho;
}

void Saida::setTaxaImg_m3(float taxa) {
    taxaImg_m3 = taxa;
}
