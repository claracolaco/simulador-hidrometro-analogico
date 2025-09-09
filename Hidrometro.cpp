#include "Hidrometro.hpp"

Hidrometro::Hidrometro(const Entrada& in, const Saida& out, const Display& disp, const Medicao& med)
    : input(in), output(out), display(disp), medicao(med) {}

void Hidrometro::medir(float minutos) {
    if (minutos <= 0.0f) return;
    float volume = input.amostrarFluxo(minutos); 
    if (volume > 0.0f) {
        medicao.contabilizar(static_cast<double>(volume));
    }
}

void Hidrometro::apresentacaoMedicao() {
    display.desenharMostrador(medicao);
    output.gerarJPEG(medicao, display);
}

const Medicao& Hidrometro::getMedicao() const { return medicao; }
Medicao& Hidrometro::getMedicao() { return medicao; }

const Entrada& Hidrometro::getEntrada() const { return input; }
Entrada& Hidrometro::getEntrada() { return input; }

const Saida& Hidrometro::getSaida() const { return output; }
Saida& Hidrometro::getSaida() { return output; }

const Display& Hidrometro::getDisplay() const { return display; }
Display& Hidrometro::getDisplay() { return display; }
