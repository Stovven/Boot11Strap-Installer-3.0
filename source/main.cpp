// This file works perfectly in the format of 'C'. Why is it a CPP file?
#include <string.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <sf2d.h>
#include <sfil.h>
#include <sys/stat.h>
#include <sys/types.h>
// headers
#include "commands.h"
// Data files
#include "bottom_png.h"
#include "top_png.h"
#include "changelog_png.h"
#include "error_png.h"
#include "idle_png.h"
#include "install_png.h"

int main(int argc, char **argv) {
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_vblank_wait(0);
	hidInit();
	
	sf2d_texture *tex1 = sfil_load_PNG_buffer(bottom_png, SF2D_PLACE_RAM);
	sf2d_texture *tex2 = sfil_load_PNG_buffer(top_png, SF2D_PLACE_RAM);
	sf2d_texture *tex3 = sfil_load_PNG_buffer(changelog_png, SF2D_PLACE_RAM);
	sf2d_texture *tex4 = sfil_load_PNG_buffer(error_png, SF2D_PLACE_RAM);
	sf2d_texture *tex5 = sfil_load_PNG_buffer(idle_png, SF2D_PLACE_RAM);
	sf2d_texture *tex6 = sfil_load_PNG_buffer(install_png, SF2D_PLACE_RAM);

	
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(tex2 , 0, 0);
		sf2d_end_frame();
		sf2d_swapbuffers();

		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_texture(tex5, 0, 0);
		sf2d_end_frame();
		sf2d_swapbuffers();
		
		while (aptMainLoop()) {
		gspWaitForVBlank();
		hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) {
			break;
			}
				
		if (kDown & KEY_A) {
			sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
			sf2d_draw_texture(tex1, 0, 0);
			sf2d_end_frame();
			sf2d_swapbuffers();
			
			sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sf2d_draw_texture(tex6, 0, 0);
			sf2d_end_frame();
			sf2d_swapbuffers();
			mkdir("/boot11strap", 0777);
			mkdir("/boot11strap/payloads", 0777);
			mkdir("/boot11strap/data", 0777);
			mkdir("/boot11strap/log", 0777);
			mkdir("/boot11strap/installer", 0777);
			FILE *fp;
			FILE *fp2;
			FILE *fp3;
			FILE *fp4;
			FILE *fp5;
			fp = fopen("/boot11strap/data/boot11status.txt", "w+");
			fprintf(fp, "boot11strap... READY!\n");
			fprintf(fp, "boot11strap has access to the SD!\n");
			fclose(fp);
			fp2 = fopen("/boot11strap/log/install_log.txt", "w+");
			fprintf(fp2, "Tests... Complete! \n");
			fprintf(fp2, "Permission Granted? Yes! \n");
			fprintf(fp2, "'make' returned with success code [0]! \n");
			fprintf(fp2, "[Success] Logged output! \n");
			fclose(fp2);
			fp3 = fopen("/boot.b11s", "w+");
			fprintf(fp3, "# Template b11s boot script. \n");
			fprintf(fp3, "[ENTRY] \n");
			fprintf(fp3, "NAME:= boot11CFW \n");
			fprintf(fp3, "TYPE:= NinFW \n");
			fprintf(fp3, "LOC1:= /boot11strap/CFW.pld \n");
			fprintf(fp3, "BCKUP:= /CFW.pld \n");
			fclose(fp3);
			fp4 = fopen("/boot11strap/CFW.pld", "w+");
			fprintf(fp4, "54 68 69 73 20 70 72 6f 67 72 61 6d 20 69 73 20 61 20 6a 6f 6b 65 2e 20 54 68 65 72 65 20 69 73 20 6e 6f 20 77 61 79 20 79 6f 75 20 63 61 6e 20 72 75 6e 20 57 69 6e 64 6f 77 73 20 31 30 20 61 70 70 6c 69 63 61 74 69 6f 6e 73 20 6f 6e 20 61 20 4e 69 6e 74 65 6e 64 6f 20 33 44 53 2e 20 49 74 20 72 65 61 6c 6c 79 20 69 73 6e 27 74 20 74 68 61 74 20 68 61 72 64 20 74 6f 20 66 69 6e 64 20 6f 75 74 2c 20 65 69 74 68 65 72 2e 20 49 74 20 77 61 73 20 66 75 6e 20 63 72 65 61 74 69 6e 67 20 74 68 69 73 2c 20 61 6e 64 20 6d 65 73 73 69 6e 67 20 77 69 74 68 20 79 27 61 6c 6c 21 20 54 68 61 6e 6b 73 20 66 6f 72 20 75 73 69 6e 67 20 62 6f 6f 74 31 31 73 74 72 61 70 20 2d 20 4b 69 6e 67 79 2e\n");
			fclose(fp4);
			fp5 = fopen("/boot11strap/installer/installerstatus.txt", "w+");
			fprintf(fp5, "# Boot11strap Installer Status \n");
			fprintf(fp5, "[UPDATE] \n");
			fprintf(fp5, "SERVER = Github1 \n");
			fprintf(fp5, "BUILD = STABLE \n");
			fclose(fp5);
			svcSleepThread(7000000000);
			reboot();
			}

		if (kDown & KEY_B) {
			sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
			sf2d_draw_texture(tex3, 0, 0);
			sf2d_end_frame();
			sf2d_swapbuffers();
		}

		if (kDown & KEY_X) {
			sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
			sf2d_draw_texture(tex4, 0, 0);
			sf2d_end_frame();
			sf2d_swapbuffers();
		}

		}

		
	sf2d_free_texture(tex1);
	sf2d_free_texture(tex2);
	sf2d_free_texture(tex3);
	sf2d_fini();
	return 0;
}
