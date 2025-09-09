#ifndef HIDROMETRO_HPP
#define HIDROMETRO_HPP

#include "Entrada.hpp"
#include "Medicao.hpp"
#include "Display.hpp"
#include "Saida.hpp"

class Hidrometro {
private:
    Entrada input;   
    Saida output;   
    Display display; 
    Medicao medicao; 

public:
    Hidrometro() = default;
    Hidrometro(const Entrada& in, const Saida& out, const Display& disp, const Medicao& med = Medicao());

    void medir(float minutos = 1.0f);

    void apresentacaoMedicao();

    const Medicao& getMedicao() const;
    Medicao& getMedicao(); 

    const Entrada& getEntrada() const;
    Entrada& getEntrada();

    const Saida& getSaida() const;
    Saida& getSaida();

    const Display& getDisplay() const;
    Display& getDisplay();
};

#endif
