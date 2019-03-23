#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>
//   map[y][x] 
char map[10][20] = { "#################",
					"#O              #",
					"#               #",
					"#               #",
					"#               #",
					"#               #",
					"#               #",
					"#               #",
					"#################" };

int y = 1;
int x = 1;

bool gameover = false;
int keyP;
void draw() {
	for (int display = 0; display < 9; display++) {
		printf("%s\n", map[display]);
	}
	printf("\n\n\n\nSteuerung :\n");
	printf("W - HOCH  | A - RUNTER\n");
	printf("S - LINKS | D RECHTS\n");
	printf("X = EXITsdsdsd");
}
void input() {

	keyP = _getch();

	if (keyP == 'W' || keyP == 'w') {
		int y2 = y - 1;
		if (map[y2][x] == ' ')
		{
			map[y][x] = ' ';
			y--;
			map[y][x] = 'O';
		}
	}
	if (keyP == 'S' || keyP == 's') {
		int y2 = y + 1;
		if (map[y2][x] == ' ')
		{
			map[y][x] = ' ';
			y++;
			map[y][x] = 'O';
		}
	}
	if (keyP == 'A' || keyP == 'a') {
		int x2 = x - 1;
		if (map[y][x2] == ' ')
		{
			map[y][x] = ' ';
			x--;
			map[y][x] = 'O';
		}
	}
	if (keyP == 'D' || keyP == 'd') {
		int x2 = x + 1;
		if (map[y][x2] == ' ')
		{
			map[y][x] = ' ';
			x++;
			map[y][x] = 'O';
		}
	}
	if (keyP == 'X' || keyP == 'x') {
		exit(-1);
	}
}


int main()
{
	system("mode 30, 17");
	while (!gameover) {
		system("cls");
		draw();
		input();


	}
}