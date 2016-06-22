#include <windows.h>

int main() {
	while (1) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0 ,0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0 ,0);
		Sleep(3000);
	}
	return 0;
}
