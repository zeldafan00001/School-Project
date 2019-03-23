#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

//   map[y][x] 
char map[10][20] = {"\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1",
					"\xB1      \xB1\xB1         \xB1",
					"\xB1               \xB1\xB1\xB1",
					"\xB1  \xFE              \xB1",
					"\xB1        \xB1\xB1       \xB1",
					"\xB1                 \xB1",
					"\xB1 \xB1\xB1              \xB1",
					"\xB1      \xB1\xB1       \xB1\xB1\xB1",
					"\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" };

int y = 3;
int x = 3;

int pointY, pointX, point, pfield = 1, score = 0;

bool gameover = false;
int keyP;
char keyPC;
HANDLE  hConsole;

void draw() {
	for (int display = 0; display < 9; display++) {
		printf("%s\n", map[display]);
	}
	printf("CORDS : Y:%d | X:%d\nScore: %d\n\nSteuerung :\n", y+1, x+1, score);
	printf("W - HOCH  | A - RUNTER\n");
	printf("S - LINKS | D RECHTS\n");
	printf("X = EXIT");
}

void points() {
	time_t te;
	te = time(NULL);
	srand(te);

	pointY = rand() % 9;
	pointX = rand() % 19;

	while (map[pointY][pointX] == ' ' || map[pointY][pointX] == 'P')
	{
		if (map[pointY][pointX] == ' ' && pfield == 1) {
			map[pointY][pointX] = 'P';
			pfield = 0;
		}
		if (pfield == 0) {
			break;
		}
	}
			
}

void botEnemy() {

}
void input() {

	keyP = _getch();

	if (keyP == 'W' || keyP == 'w') {
		int y2 = y - 1;
		if (map[y2][x] == ' ' || map[y2][x] == 'P')
		{
			if (map[y2][x] == 'P') {
				map[y][x] = ' ';
				y--;
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y2][x] == ' ') {
				map[y][x] = ' ';
				y--;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'S' || keyP == 's') {
		int y2 = y + 1;
		if (map[y2][x] == ' ' || map[y2][x] == 'P')
		{
			if (map[y2][x] == 'P') {
				map[y][x] = ' ';
				y++;
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y2][x] == ' ') {
				map[y][x] = ' ';
				y++;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'A' || keyP == 'a') {
		int x2 = x - 1;
		if (map[y][x2] == ' ' || map[y][x2] == 'P')
		{
			if (map[y][x2] == 'P') {
				map[y][x] = ' ';
				x--;
				
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y][x2] == ' ') {
				map[y][x] = ' ';
				x--;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'D' || keyP == 'd') {
		int x2 = x + 1;
		if (map[y][x2] == ' ' || map[y][x2] == 'P')
		{
			if (map[y][x2] == 'P') {
				map[y][x] = ' ';
				x++;
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y][x2] == ' ') {
				map[y][x] = ' ';
				x++;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'X' || keyP == 'x') {
		exit(-1);
	}
}


int main()
{
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode 30, 17");
	while (!gameover) {
		system("cls");
		points();
		draw();
		input();


	}
}