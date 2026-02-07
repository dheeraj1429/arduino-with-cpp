#include <Arduino.h>
#include <MatrizLed.h>

MatrizLed matrix;

void heart() {
    // Heart pattern on 8x8 matrix
    // Row 0: . X X . . X X .
    matrix.setLed(0, 0, 1, true);
    matrix.setLed(0, 0, 2, true);
    matrix.setLed(0, 0, 5, true);
    matrix.setLed(0, 0, 6, true);

    // Row 1: X X X X X X X X
    matrix.setLed(0, 1, 0, true);
    matrix.setLed(0, 1, 1, true);
    matrix.setLed(0, 1, 2, true);
    matrix.setLed(0, 1, 3, true);
    matrix.setLed(0, 1, 4, true);
    matrix.setLed(0, 1, 5, true);
    matrix.setLed(0, 1, 6, true);
    matrix.setLed(0, 1, 7, true);

    // Row 2: X X X X X X X X
    matrix.setLed(0, 2, 0, true);
    matrix.setLed(0, 2, 1, true);
    matrix.setLed(0, 2, 2, true);
    matrix.setLed(0, 2, 3, true);
    matrix.setLed(0, 2, 4, true);
    matrix.setLed(0, 2, 5, true);
    matrix.setLed(0, 2, 6, true);
    matrix.setLed(0, 2, 7, true);

    // Row 3: X X X X X X X X
    matrix.setLed(0, 3, 0, true);
    matrix.setLed(0, 3, 1, true);
    matrix.setLed(0, 3, 2, true);
    matrix.setLed(0, 3, 3, true);
    matrix.setLed(0, 3, 4, true);
    matrix.setLed(0, 3, 5, true);
    matrix.setLed(0, 3, 6, true);
    matrix.setLed(0, 3, 7, true);

    // Row 4: . X X X X X X .
    matrix.setLed(0, 4, 1, true);
    matrix.setLed(0, 4, 2, true);
    matrix.setLed(0, 4, 3, true);
    matrix.setLed(0, 4, 4, true);
    matrix.setLed(0, 4, 5, true);
    matrix.setLed(0, 4, 6, true);

    // Row 5: . . X X X X . .
    matrix.setLed(0, 5, 2, true);
    matrix.setLed(0, 5, 3, true);
    matrix.setLed(0, 5, 4, true);
    matrix.setLed(0, 5, 5, true);

    // Row 6: . . . X X . . .
    matrix.setLed(0, 6, 3, true);
    matrix.setLed(0, 6, 4, true);
}

void setup() {
    matrix.begin(11, 13, 10, 4);
    matrix.borrar();
}

void loop() {
    // matrix.escribirCaracter('D', 0);
    // delay(500);
    // matrix.escribirCaracter('H', 0);
    // delay(500);
    // matrix.escribirCaracter('E', 0);
    // delay(500);
    // matrix.escribirCaracter('E', 0);
    // delay(500);
    // matrix.escribirCaracter('R', 0);
    // delay(500);
    // matrix.escribirCaracter('A', 0);
    // delay(500);
    // matrix.escribirCaracter('J', 0);
    // delay(500);

    matrix.escribirFraseScroll("Dheeraj", 100);
}