#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "fesquemas.hpp"


class Reto135Test : public CPPUNIT_NS::TestFixture {

    CPPUNIT_TEST_SUITE(Reto135Test);
    CPPUNIT_TEST(testPrueba1);
    CPPUNIT_TEST(testPrueba2);
    CPPUNIT_TEST(testPrueba3);
    CPPUNIT_TEST(testPrueba4);
    CPPUNIT_TEST(testPrueba5);
    CPPUNIT_TEST(testPrueba6);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testPrueba1() {
        int inicial = 4;
        int objetivo = 188;
        int esperada = 6;
        CPPUNIT_ASSERT_EQUAL(esperada, misf::DificultadReto(inicial, objetivo));
    }

    void testPrueba2() {
        int inicial = 1;
        int objetivo = -25;
        int esperada = 4;
        CPPUNIT_ASSERT_EQUAL(esperada, misf::DificultadReto(inicial, objetivo));
    }

    void testPrueba3() {
        int inicial = 1234;
        int objetivo = 1234;
        int esperada = 0;
        CPPUNIT_ASSERT_EQUAL(esperada, misf::DificultadReto(inicial, objetivo));
    }

    void testPrueba4() {
        int inicial = -10;
        int objetivo = 1024;
        int esperada = 13;
        CPPUNIT_ASSERT_EQUAL(esperada, misf::DificultadReto(inicial, objetivo));
    }

    void testPrueba5() {
        int inicial = 8;
        int objetivo = 40;
        int esperada = 1;
        CPPUNIT_ASSERT_EQUAL(esperada, misf::DificultadReto(inicial, objetivo));
    }

    void testPrueba6() {
        int inicial = 5;
        int objetivo = 125;
        int esperada = 2;
        CPPUNIT_ASSERT_EQUAL(esperada, misf::DificultadReto(inicial, objetivo));
    }
};

int main() {
    CPPUNIT_NS::TextUi::TestRunner runner;
    runner.addTest(Reto135Test::suite());
    bool wasSuccessful = runner.run();
    return (wasSuccessful ? EXIT_SUCCESS : EXIT_FAILURE);
}
