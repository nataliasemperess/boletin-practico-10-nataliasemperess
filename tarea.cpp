#include "tarea.hpp"

#include <string>
#include <sstream>

Tarea::Tarea(std::string n, int hi, int hf)
    : nombre_(n), hini_(hi), hfin_(hf) {
    if (not (hi >= 0 and hi < hf and hf <= 24)) {
        Invalidar();
    }
}

int Tarea::HIni() const {
    return hini_;
}

int Tarea::HFin() const {
    return hfin_;
}

std::string Tarea::ACadena() const {
    if (hini_ < 0) {
        return "*** Tarea inválida ***";
    } else {
        std::ostringstream oss;
        oss << "[Tarea: " << nombre_
            << " (de " << hini_
            << " a " << hfin_ << ")]";
        return oss.str();
    }
}

void Tarea::Invalidar() {
    nombre_ = "";
    hini_ = -1;
    hfin_ = -1;
}
