#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

// MAP
//		[y][x]
bool running = false;

int y = 2, y2;
int x = 2, x2;
int keyP;
int score = 0;
int wall = 250, wallR;
int Ry, Rx, pfield = 1;


char map[20][50] = {"#################################################",	
					"#                                               #",
					"# S                                             #",
					"#                                               #",
					"#                                               #",
					"#                                               #",
					"#                                               #",
					"#                                               #",
					"#                                               #",
					"#                                               #",
					"#                                               #",
					"#                                             Z #",
					"#                                               #",
					"#################################################"};	

void draw() {
	for (int display = 0; display < 15; display++) {
		printf("\t\t\t\t%s\n", map[display]);
	}
	printf("\t\t\t\tScore : %d %d ", score);
}


void points() {
	time_t te;
	te = time(NULL);
	srand(te);

	Ry = rand() % 15;
	Rx = rand() % 49;

	while (map[Ry][Rx] == ' ' || map[Ry][Rx] == 'P')
	{
		if (map[Ry][Rx] == ' ' && pfield == 1) {
			map[Ry][Rx] = 'P';
			pfield = 0;
		}
		if (pfield == 0) {
			break;
		}
	}

}

void input() 
{
	keyP = _getch();

	if (keyP == 'W' || keyP == 'w') {
		y2 = y - 1;
		if (map[y2][x] != '#')
		{
			if (map[y2][x] == '-') {
				map[y][x] = ' ';
				y--;
				score += 10;
				map[y][x] = 'S';
			}
			if (map[y2][x] == 'X') {
				map[y][x] = ' ';
				y--;
				map[y][x] = 'X';
				running = true;
			}
			if (map[y2][x] == ' ') {
				map[y][x] = ' ';
				y--;
				map[y][x] = 'S';
			}
		}
	}
	if (keyP == 'S' || keyP == 's') {
		y2 = y + 1;
		if (map[y2][x] != '#')
		{
			if (map[y2][x] == '-') {
				map[y][x] = ' ';
				y++;
				score += 10;
				map[y][x] = 'S';
			}
			if (map[y2][x] == 'X') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'X';
				running = true;
			}
			if (map[y2][x] == ' ') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'S';
			}
		}
	}
	if (keyP == 'A' || keyP == 'a') {
		x2 = x - 1;
		if (map[y][x2] != '#')
		{
			if (map[y][x2] == '-') {
				map[y][x] = ' ';
				x--;
				score += 10;
				map[y][x] = 'S';
			}
			if (map[y][x2] == 'X') {
				map[y][x] = ' ';
				x--;
				map[y][x] = 'X';
				running = true;
			}
			if (map[y][x2] == ' ') {
				map[y][x] = ' ';
				x--;
				map[y][x] = 'S';
			}
		}
	}
	if (keyP == 'D' || keyP == 'd') {
		x2 = x + 1;
		if (map[y][x2] != '#')
		{
			if (map[y][x2] == '-') {
				map[y][x] = ' ';
				x++;
				score += 10;
				map[y][x] = 'S';
			}
			if (map[y][x2] == 'X') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'X';
				running = true;
			}
			if (map[y][x2] == ' ') {
				map[y][x] = ' ';
				x++;
				map[y][x] = 'S';
			}
		}
	}
	if (keyP == 'X' || keyP == 'x') {
		exit(-1);
	}
}
int main()
{
	while (!running) {
		system("cls");
		points();
		draw();
		input();
	}
}

