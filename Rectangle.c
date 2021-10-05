#include <Windows.h>
#include <stdio.h>

int main(void) {

	int ch;
	int width = 200, height = 200;
	HDC hdc = GetWindowDC(GetForegroundWindow());

	while (1) {
		Rectangle(hdc, 100, 100, width, height);//사각형을 그린다,
		ch = getch();//문자를 입력한다,
		Rectangle(hdc, 0, 0, 800, 600);//화면을 지운다.
		if (ch == 'b') {
			width += 10;
			height += 10;
		}
		else if (ch == 's') {
			width -= 10;
			height -= 10;
		}
		else if (ch == 'q') {
			return 0;
		}
	}

	return 0;
}