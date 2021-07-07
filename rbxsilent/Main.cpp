/*
----------------------------------------------
rbxsilent
Created July 2021
Author tostring#1337
----------------------------------------------
*/

#include <Windows.h>
#include <iostream>

using namespace std;

static BOOL CALLBACK windcallback(HWND hWnd, LPARAM lparam) {
    int length = GetWindowTextLength(hWnd) + 1;
    char* buffer = new char[length];
    GetWindowText(hWnd, buffer, length);
    std::string title(buffer);

    if (title == "Roblox" && IsWindowVisible(hWnd)) {
        ShowWindow(hWnd, SW_HIDE);
        PostMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0); //ensures that rendering is disabled
        cout << "Found roblox window " << hWnd << endl;
    }

    delete[] buffer;
    return true;
}

int main(int argc, char** argv) {
    cout << "All roblox clients that are open/opened will now be hidden." << endl;
    while (true) {
        EnumWindows(windcallback, 0);
        Sleep(1);
    }
    return 0;
}