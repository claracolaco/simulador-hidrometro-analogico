#include "Hidrometro.hpp"

// Construtor completo
Hidrometro::Hidrometro(const Entrada& in, const Saida& out, const Display& disp, const Medicao& med)
    : input(in), output(out), display(disp), medicao(med) {}

// Passo de simulação: coleta volume da Entrada e contabiliza na Medicao
void Hidrometro::medir(float minutos) {
    if (minutos <= 0.0f) return;
    float volume = input.amostrarFluxo(minutos); // já considera sentido e ar
    if (volume > 0.0f) {
        medicao.contabilizar(static_cast<double>(volume));
    }
}

// Apresenta no display e persiste via Saida
void Hidrometro::apresentacaoMedicao() {
    display.desenharMostrador(medicao);
    output.gerarJPEG(medicao, display);
}

// Getters (estado)
const Medicao& Hidrometro::getMedicao() const { return medicao; }
Medicao& Hidrometro::getMedicao() { return medicao; }

// Getters (componentes)
const Entrada& Hidrometro::getEntrada() const { return input; }
Entrada& Hidrometro::getEntrada() { return input; }

const Saida& Hidrometro::getSaida() const { return output; }
Saida& Hidrometro::getSaida() { return output; }

const Display& Hidrometro::getDisplay() const { return display; }
Display& Hidrometro::getDisplay() { return display; }
