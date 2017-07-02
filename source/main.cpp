#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <sf2d.h>
#include <stdlib.h>
#include "commands.h"



int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);
	
	printf("Boot11strap Installer 3.0\n");
	printf("Ver.");
	ver();
	printf(".\n");

	consoleInit(GFX_TOP, NULL);
	printf("Press A to install\n");
	printf("Press Start to Quit\n");
	printf("Report anything to the github\n");


    while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) {
			break;
		}

		if (kDown & KEY_A) {
			clear();
			printf("currently in dev\n");
		}

        gfxFlushBuffers();
        gfxSwapBuffers();
    }

    gfxExit();
	fsExit();
    return 0;
}
