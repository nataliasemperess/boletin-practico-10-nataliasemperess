#ifndef CUADRICULA_INCLUDED_
#define CUADRICULA_INCLUDED_

#include <vector>
#include <string>
#include <map>
#include <utility>

using Casilla = std::pair<int, int>;

enum class CC : char  { // Contenido de Casilla
    kLibre,
    kObstaculo,
    kPtoRecarga
};

const std::map<CC, char> kCcToChar = {{CC::kLibre, '.'},
                                      {CC::kObstaculo, '#'},
                                      {CC::kPtoRecarga, '@'}};

class Cuadricula {

    std::vector<std::vector<CC>> tablero_;
    int nfil_, ncol_;

public:
    Cuadricula(int nf, int nc);
    Cuadricula& Colocar(CC cc, const std::vector<Casilla>& v);
    std::string ACadena() const;
    std::vector<Casilla> Adyacentes(Casilla c) const;
    bool EsContenido(Casilla c, CC cc) const;

private:
    bool EsFilOK(int i) const;
    bool EsColOK(int j) const;

};

#endif
