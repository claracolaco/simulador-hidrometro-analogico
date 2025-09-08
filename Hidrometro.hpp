#ifndef HIDROMETRO_HPP
#define HIDROMETRO_HPP

#include "Entrada.hpp"
#include "Medicao.hpp"
#include "Display.hpp"
#include "Saida.hpp"

class Hidrometro {
private:
    Entrada input;   // parâmetros de fluxo (vazão, sentido, ar)
    Saida output;    // geração de saída (nesta versão: .txt; futura: .jpg)
    Display display; // exibição (por ora, terminal / texto)
    Medicao medicao; // estado acumulado (m³ e mm)

public:
    // Construtores
    Hidrometro() = default;
    Hidrometro(const Entrada& in, const Saida& out, const Display& disp, const Medicao& med = Medicao());

    // Passo de simulação: amostra volume e contabiliza
    void medir(float minutos = 1.0f);

    // Apresenta e persiste a leitura atual
    void apresentacaoMedicao();

    // Acesso ao estado
    const Medicao& getMedicao() const;
    Medicao& getMedicao(); // versão não-const para ajustes em testes

    // Acesso aos componentes (se precisar ajustar depois)
    const Entrada& getEntrada() const;
    Entrada& getEntrada();

    const Saida& getSaida() const;
    Saida& getSaida();

    const Display& getDisplay() const;
    Display& getDisplay();
};

#endif
