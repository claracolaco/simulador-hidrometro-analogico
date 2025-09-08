#include "Controlador.hpp"

int main() {
    Controlador ctrl;
    if (ctrl.carregarConfig("config.txt")) {
        ctrl.executa();
    }
    return 0;
}
