#include "MicroBit.h"
#include "samples/Tests.h"
#include "buttons.h"

MicroBit uBit;

int main()
{
    uBit.init();

    while (true) {
        if (buttonA.isPressed()) {
            uBit.display.print("A");
        } else if (buttonB.isPressed()) {
            uBit.display.print("B");
        }
        uBit.sleep(100);
        uBit.display.clear();
        uBit.sleep(100);
    }
}
