// button.cpp
#include "buttons.h"

// Define the button instance (with pin and ID)
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

// void button_print_press(void){
//     if (buttonA.isPressed()) {
//         uBit.display.print("A");
//     } else if (buttonB.isPressed()) {
//         uBit.display.print("B");
//     }
// }
