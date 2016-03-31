#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "WinIo.h"

int main()
{
    unsigned short donnee;
    InitializeWinIo();
    donnee = _inp(0x37A);
    ShutdownWinIo();
    return 0;
}
