#include "Controlador.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

static std::string to_lower(std::string s) {
    for (auto &ch : s) ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    return s;
}

std::string Controlador::trim(const std::string& s) {
    size_t b = 0, e = s.size();
    while (b < e && std::isspace(static_cast<unsigned char>(s[b]))) ++b;
    while (e > b && std::isspace(static_cast<unsigned char>(s[e-1]))) --e;
    return s.substr(b, e - b);
}

bool Controlador::carregarConfig(const std::string& arquivo) {
    std::ifstream in(arquivo);
    if (!in.is_open()) {
        std::cerr << "[ERRO] Não foi possível abrir o arquivo de configuração: " << arquivo << "\n";
        return false;
    }

    configuracao.clear();
    std::string linha;
    while (std::getline(in, linha)) {
        std::string raw = trim(linha);
        if (raw.empty()) continue;
        if (raw[0] == '#') continue;

        auto pos = raw.find('=');
        if (pos == std::string::npos) continue;

        std::string chave = trim(raw.substr(0, pos));
        std::string valor = trim(raw.substr(pos + 1));

        if (!chave.empty())
            configuracao[chave] = valor;
    }

    // TFS = tempo de funcionamento (minutos)
    int TFS = 10;
    if (auto it = configuracao.find("TFS"); it != configuracao.end()) {
        TFS = std::max(0, std::stoi(it->second));
    }

    // VAM = vazão por minuto (0..100)
    float VAM = 0.0f;
    if (auto it = configuracao.find("VAM"); it != configuracao.end()) {
        VAM = std::stof(it->second);
    }

    // PCT_AR = percentual de ar (0..100)
    float PCT_AR = 0.0f;
    if (auto it = configuracao.find("PCT_AR"); it != configuracao.end()) {
        PCT_AR = std::stof(it->second);
    }

    // BITOLA (opcional)
    float BITOLA = 0.0f;
    if (auto it = configuracao.find("BITOLA"); it != configuracao.end()) {
        BITOLA = std::stof(it->second);
    }

    // SENTIDO = "Direto" | "Reverso"  (default: Direto)
    std::string SENTIDO = "Direto";
    if (auto it = configuracao.find("SENTIDO"); it != configuracao.end()) {
        SENTIDO = it->second;
    }

    // TAXA_IMG = a cada X m3 gerar saída (default: 1.0)
    float TAXA_IMG = 1.0f;
    if (auto it = configuracao.find("TAXA_IMG"); it != configuracao.end()) {
        // permite "1m3" ou "1.0"
        std::string v = to_lower(it->second);
        for (char &c : v) {
            if (!std::isdigit(static_cast<unsigned char>(c)) && c != '.' && c != ',')
                c = ' ';
        }
        // substitui vírgula por ponto e extrai
        std::replace(v.begin(), v.end(), ',', '.');
        std::istringstream iss(v);
        iss >> TAXA_IMG;
        if (TAXA_IMG <= 0.0f) TAXA_IMG = 1.0f;
    }

    // CAMINHO = caminho do arquivo de saída (default: "saida.txt" nessa versão)
    std::string CAMINHO = "saida.txt";
    if (auto it = configuracao.find("CAMINHO"); it != configuracao.end()) {
        CAMINHO = it->second;
    }

    // FORMATO do display (texto/jpeg)
    std::string FORMATO = "texto";
    if (auto it = configuracao.find("FORMATO"); it != configuracao.end()) {
        FORMATO = to_lower(it->second);
    }

    
    // Entrada
    h1.getEntrada().configurar(BITOLA, VAM, SENTIDO, PCT_AR);

    // Saída
    h1.getSaida().setCaminhoImagem(CAMINHO);
    h1.getSaida().setTaxaImg_m3(TAXA_IMG);

    // Display
    // (por enquanto só guardamos o formato para futura evolução)
    // h1.getDisplay().setFormato(FORMATO); // (não existe ainda; apenas informativo)

    std::cout << "[CONFIG] TFS=" << TFS
              << " | VAM=" << VAM
              << " | PCT_AR=" << PCT_AR
              << " | BITOLA=" << BITOLA
              << " | SENTIDO=" << SENTIDO
              << " | TAXA_IMG=" << TAXA_IMG
              << " | CAMINHO=" << CAMINHO
              << " | FORMATO=" << FORMATO
              << std::endl;

    configuracao["TFS"] = std::to_string(TFS);
    return true;
}

// executa a simulação 
void Controlador::executa() {
    int TFS = 10;
    if (auto it = configuracao.find("TFS"); it != configuracao.end()) {
        TFS = std::max(0, std::stoi(it->second));
    }

    float taxaImg = h1.getSaida().getTaxaImg_m3();

    std::cout << "[EXECUCAO] Iniciando simulação por " << TFS << " minuto(s)...\n";

    double ultimoVolumeGerado = 0.0;

    h1.apresentacaoMedicao();
    ultimoVolumeGerado = h1.getMedicao().getVolumeTotal_m3();

    for (int minuto = 1; minuto <= TFS; ++minuto) {
        // avança 1 minuto de simulação
        h1.medir(1.0f);

        double volumeAtual = h1.getMedicao().getVolumeTotal_m3();
        if (taxaImg > 0.0f && (volumeAtual - ultimoVolumeGerado) >= static_cast<double>(taxaImg)) {
            h1.apresentacaoMedicao();
            ultimoVolumeGerado = volumeAtual;
        }
    }

    h1.apresentacaoMedicao();

    std::cout << "[EXECUCAO] Simulação concluída.\n";
}
