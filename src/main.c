#include <unistd.h> /* usleep */
#include <stdio.h>
#include "gfx.h"

#define FMRT 25000
#define HGHT 450
#define WDTH 900

int main() {

    gfx_open(HGHT, WDTH, "Asteroides");
    gfx_color(0, 200, 100);
    gfx_clear();

    while (1) {
        
        gfx_flush();
        gfx_clear();
        usleep(FMRT);

        if (gfx_event_waiting())
            break;
    }

    printf("Asteroides\n");
	return 0;
}
