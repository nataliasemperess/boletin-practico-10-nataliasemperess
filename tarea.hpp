#ifndef TAREA_INCLUDED_
#define TAREA_INCLUDED_

#include <string>

class Tarea {

    std::string nombre_;
    int hini_, hfin_;

public:
    Tarea(std::string n, int hi, int hf);
    int HIni() const;
    int HFin() const;
    std::string ACadena() const;

private:
    void Invalidar();

};

// VISTO EN https://stackoverflow.com/questions/2999135
//
// Para utilizar PorHIni() o PorHFin() como
// tercer argumento de un std::sort...

struct PorHIni {
    bool operator()(Tarea const &a, Tarea const &b) const {
        return a.HIni() < b.HIni();
    }
};

struct PorHFin {
    bool operator()(Tarea const &a, Tarea const &b) const {
        return a.HFin() < b.HFin();
    }
};

struct PorDuracion {
    bool operator()(Tarea const &a, Tarea const &b) const {
        int dur_a = a.HFin() - a.HIni();
        int dur_b = b.HFin() - b.HIni();
        return dur_a < dur_b;
    }
};

#endif
