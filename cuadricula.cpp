#include "cuadricula.hpp"

#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <sstream>

const std::vector<std::pair<int, int>> kAdyacencias {
    std::make_pair(-1,  0), // N
    std::make_pair(+1,  0), // S
    std::make_pair( 0, +1), // E
    std::make_pair( 0, -1)  // O
};

Cuadricula::Cuadricula(int nf, int nc)
    : tablero_(), nfil_(nf), ncol_(nc) {
    if (nf < 1) {
        throw std::invalid_argument("nf no positivo");
    }
    if (nc < 1) {
        throw std::invalid_argument("nc no positivo");
    }
    tablero_ = std::vector<std::vector<CC>>(nf, std::vector<CC>(nc, CC::kLibre));
}

Cuadricula& Cuadricula::Colocar(CC cc, const std::vector<Casilla>& v) {
    for (Casilla c : v) {
        int i = c.first;
        int j = c.second;
        if(EsFilOK(i) and EsColOK(j)) {
            tablero_[i][j] = cc;
        }
    }
    return *this;
}

std::string Cuadricula::ACadena() const {
    std::ostringstream ss;
    ss << "  ";
    for (int j = 0; j < ncol_; ++j) {
        ss << j%10;
    }
    ss << std::endl;
    for (int i = 0; i < nfil_; ++i) {
        ss << i%10 << " ";
        for (int j = 0; j < ncol_; ++j) {
            ss << kCcToChar.at(tablero_[i][j]);
        }
        ss << std::endl;
    }
    return ss.str();
}

std::vector<Casilla> Cuadricula::Adyacentes(Casilla c) const {
    int i = c.first;
    int j = c.second;
    std::vector<Casilla> rdo;
    for (auto x : kAdyacencias) {
        int ia = i + x.first;
        int ja = j + x.second;
        if (EsFilOK(ia) and EsColOK(ja)) {
            if (tablero_[ia][ja] != CC::kObstaculo) {
                rdo.push_back(std::make_pair(ia, ja));
            }
        }
    }
    return rdo;
}

bool Cuadricula::EsContenido(Casilla c, CC cc) const {
    int i = c.first;
    int j = c.second;
    return EsFilOK(i) and EsColOK(j) and tablero_[i][j] == cc;
}

bool Cuadricula::EsFilOK(int i) const {
    return i >= 0 and i < nfil_;
}

bool Cuadricula::EsColOK(int j) const {
    return j >= 0 and j < ncol_;
}
