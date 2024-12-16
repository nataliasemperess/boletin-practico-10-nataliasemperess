#include "cuadricula.hpp"
#include "fesquemas.hpp"

#include <vector>
#include <iostream>

int main() {
    Cuadricula c(6, 13);
    c.Colocar(CC::kPtoRecarga, std::vector<Casilla> {std::make_pair(3, 1),
                                                     std::make_pair(5, 12)});
    c.Colocar(CC::kObstaculo, std::vector<Casilla> {std::make_pair(1, 2),
                                                    std::make_pair(4, 2),
                                                    std::make_pair(5, 2),
                                                    std::make_pair(3, 3),
                                                    std::make_pair(2, 4),
                                                    std::make_pair(2, 5),
                                                    std::make_pair(4, 5),
                                                    std::make_pair(5, 5),
                                                    std::make_pair(0, 7),
                                                    std::make_pair(1, 7),
                                                    std::make_pair(2, 7),
                                                    std::make_pair(3, 7),
                                                    std::make_pair(1, 9),
                                                    std::make_pair(2, 9),
                                                    std::make_pair(3, 9),
                                                    std::make_pair(4, 9),
                                                    std::make_pair(5, 9),
                                                    std::make_pair(2, 10),
                                                    std::make_pair(2, 11),
                                                    std::make_pair(4, 11),
                                                    std::make_pair(4, 12)});
    std::cout << c.ACadena() << std::endl;
    Casilla crobot = std::make_pair(5, 3);
    std::vector<Casilla> camino = misf::RecargarRobot(crobot, c);
    std::cout << "Con robot desde (" << crobot.first << ", "
              << crobot.second << "), camino de talla "
              << int(camino.size()) - 1 << std::endl;
    for (Casilla pto : camino) {
        std::cout << "    (" << pto.first << ", " << pto.second << ")" << std::endl;
    }
    return 0;
}
