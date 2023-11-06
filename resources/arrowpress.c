#include <stdio.h>
#include <windows.h>

int main() {
    while (1) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            printf("Pressed: Up Arrow\n");
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            printf("Pressed: Down Arrow\n");
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            printf("Pressed: Left Arrow\n");
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            printf("Pressed: Right Arrow\n");
        }

        // Your other code here...

        Sleep(100); // Sleep for a short duration to reduce CPU usage
    }

    return 0;
}
