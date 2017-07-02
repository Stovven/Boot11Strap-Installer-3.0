#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <sf2d.h>
#include <stdlib.h>

//oh hey kingy, using this shit again, kbye


void clear() {
	printf("\e[1;1H\e[2J");
}

void ver() {
	printf("0.0.1");
}

void reboot() {
	APT_HardwareResetAsync();
}