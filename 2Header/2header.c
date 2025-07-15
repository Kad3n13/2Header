#include "2h.h"

int C_B = 8;

char SC_M = -128;
char SC_MX = 127;
unsigned char US_CX = 255;

char C_M = 0;  // Will be set in init_char_limits()
char C_MX = 0;

int MB_LM = 16;

short SH_M = -32768;
short SH_MX = 32767;
unsigned short USH_MX = 65535;

int I_M = -2147483648;
int I_MX = 2147483647;
unsigned int UI_MX = 4294967295U;

long L_M = -9223372036854775807L - 1;
long L_MX = 9223372036854775807L;
unsigned long UL_MX = 18446744073709551615UL;

void init_char_limits(void) {
    if (((char)-1) < 0) {
        C_M = SC_M;
        C_MX = SC_MX;
    } else {
        C_M = 0;
        C_MX = (char)US_CX;
    }
}

