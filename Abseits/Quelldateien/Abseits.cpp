#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

HANDLE  hConsole;

bool isRunningProg = true;
bool isRunningGame = true;
bool isRunningMenu = true;
bool isRunning = true;
bool Optio = true;

// Wurfel
int Summe, wurfel, wurf, wurfelsumme;
// Schleie
int s;
// Spieler
int onFeld, gewinner;
char ply[10][15];
int plyer[10]; // DARF SPIELER NOCH SPIELEN = 1 / yes | 0 / no  - bsp = plyer[3][0] Darf nicht Spielen!
int points;
int x, p;
// MENU
int modus, menuloc, asciiValue, runningg;
int startmodus, startmenuloc, startrunning;
int optimodus, optiloc;

// Voids
void Game() {
	isRunningGame = true; // resete falls auf false ist!

	// RESET ALL NUMBERS
	for (s = 0; s < x; s++) {
		plyer[s] = 1;
	}
	// NAME
	for (s = 0; s < x; s++) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t      Name der Spieler!\n");
		printf("\t\t SPIELER [%d] \n\n", s + 1);
		printf("\t\t ");
		gets_s(ply[s]);
		ply[s][strlen(ply[s])] = '\0';
	}
	onFeld = x;
	points = 0;
	while (isRunningGame == true)
	{
		for (s = 0; s < x; s++)
		{
			system("cls");
			if (onFeld == 1)
			{
				onFeld = s;
				isRunningGame = false;
				break;
			}
			if (plyer[s] == 0)
			{
				s++;
			}
			if (plyer[s] == 1)
			{
				printf("Punkte : %d\n", points);
				printf("%s[%d]\n\n\n\n\n\n\n\n\n", ply[s], s + 1);
				printf("\t    \xFE Drucke eine Taste \xFE\n\n");
				_getch();

				time_t te;
				te = time(NULL);
				srand(te);
				wurf = rand() % 6;
				wurfelsumme = wurf + 1;

				points += wurfelsumme;
				gewinner = s;
				if (points >= p)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n");
					SetConsoleTextAttribute(hConsole, 12);
					printf("\t\t     %s\n", ply[s]);
					SetConsoleTextAttribute(hConsole, 15);
					printf("\t\t Fliegt raus");
					onFeld -= 1;
					points = 0;
					plyer[s] = 0;
					Sleep(1500);
					break;
				}

			} // if (plyer[s] = 1) ob der spieler spielen darf
			gewinner = s;
		} // forSchleifeGame
	} // while() == isRunningGame

	printf("Aktuelle Punkte : %d\n", points);
	printf("Gewinner ist %s !!", ply[gewinner]);
}

// MENU

void StartScreen() { // StartScreen
	system("mode 45, 21");
	startmenuloc = 1;
	startmodus = 0;
	do {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("\t          START [");
		SetConsoleTextAttribute(hConsole, 10);
		printf("X");
		SetConsoleTextAttribute(hConsole, 15);
		printf("]\n");
		printf("\t          INFOS [");
		SetConsoleTextAttribute(hConsole, 12);
		printf("B");
		SetConsoleTextAttribute(hConsole, 15);
		printf("]\n\n\n\n\n\n\n\n\n");
		asciiValue = _getch();
		if (asciiValue == 88 || asciiValue == 120) {
			startrunning = 1;
		}
		if (asciiValue == 66 || asciiValue == 98) {
			//info();
		}
	} while (startrunning == 0);
	system("cls");
}
void MenuSam() {
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute(hConsole, 10);
	printf("      \t\t\xFE SPIELEN \xFE   \n");
	SetConsoleTextAttribute(hConsole, 15);
	printf("      \t\t  OPTIONS     \n");
	printf("      \t\t  BEENDEN      \n");
	printf("\n\n\n\n\n\n\n\n");
}
void MenuLogic() {
	asciiValue = _getch();

	if (asciiValue == 87 || asciiValue == 119) // W & w
	{
		menuloc--;
		if (menuloc == 0) {
			menuloc = 1;
		}
	}
	if (asciiValue == 83 || asciiValue == 115) // S & s
	{
		menuloc++;
		if (menuloc == 4) {
			menuloc = 3;
		}
	}
	if (asciiValue == 88 || asciiValue == 120) // X & x
	//if (asciiValue == 32) // LEERTASTE (32)
	{
		isRunningProg = false;
	}
	if (menuloc == 1) { modus = 1; }
	if (menuloc == 2) { modus = 2; }
	if (menuloc == 3) { modus = 3; }
}
void MenuGrap() {
	if (menuloc == 1) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		SetConsoleTextAttribute(hConsole, 10);
		printf("      \t\t\xFE SPIELEN \xFE   \n");
		SetConsoleTextAttribute(hConsole, 15);
		printf("      \t\t  OPTIONS      \n");
		printf("      \t\t  BEENDEN      \n");
		printf("\n\n\n\n\n\n\n\n");


	}
	if (menuloc == 2) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("      \t\t  SPIELEN      \n");
		SetConsoleTextAttribute(hConsole, 10);
		printf("      \t\t\xFE OPTIONS \xFE   \n");
		SetConsoleTextAttribute(hConsole, 15);
		printf("      \t\t  BEENDEN      \n");
		printf("\n\n\n\n\n\n\n\n");

	}
	if (menuloc == 3) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("      \t\t  SPIELEN      \n");
		printf("      \t\t  OPTIONS      \n");
		SetConsoleTextAttribute(hConsole, 10);
		printf("      \t\t\xFE BEENDEN \xFE    \n");
		SetConsoleTextAttribute(hConsole, 15);
		printf("\n\n\n\n\n\n\n\n");

	}
}

void optioGrap() {
	if (optiloc == 1) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		SetConsoleTextAttribute(hConsole, 10);
		printf("      \t      \xFE SPIELER [%d/10] \xFE   \n", x);
		SetConsoleTextAttribute(hConsole, 15);
		printf("      \t        LAENGE [%d/50] \n", p);
		printf("\n\n\n\n\n\n\n\n");


	}
	if (optiloc == 2) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("      \t        SPIELER [%d/10]  \n", x);
		SetConsoleTextAttribute(hConsole, 10);
		printf("      \t      \xFE LAENGE [%d/50]\xFE \n", p);
		SetConsoleTextAttribute(hConsole, 15);
		printf("\n\n\n\n\n\n\n\n");

	}

}
void Optionen() {
	do
	{

		optioGrap();

		asciiValue = _getch();

		if (asciiValue == 87 || asciiValue == 119) // W & w
		{
			optiloc--;
			if (optiloc == 0)
			{
				optiloc = 1;
			}
		}

		if (asciiValue == 83 || asciiValue == 115) // S & s
		{
			optiloc++;
			if (optiloc == 3)
			{
				optiloc = 2;
			}
		}

		if (asciiValue == 65 || asciiValue == 97) {

			if (optiloc == 1)
			{
				x--;
				if (x == 1) {
					x = 2;
				}
			}
			if (optiloc == 2)
			{
				p--;
				if (p == 29)
				{
					p = 30;
				}
			}
		}
		if (asciiValue == 68 || asciiValue == 100) {

			if (optiloc == 1)
			{
				x++;
				if (x == 11)
				{
					x = 10;
				}
			}
			if (optiloc == 2)
			{
				p++;
				if (p == 51)
				{
					p = 50;
				}
			}
		}
		if (asciiValue == 88 || asciiValue == 120) // X & x
		{
			Optio = false;
			break;
		}
	} while (Optio == true);

}
void MenuModus() {
	if (modus == 1) {
		system("cls");
		isRunningProg = true;
		Game();
	}
	if (modus == 2) {
		system("cls");
		isRunningProg = true;
		Optionen();
	}
	if (modus == 3) {
		system("cls");
		exit(-1);
	}
}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	x = 3; // Spieler
	p = 30;
	optiloc = 1;
	StartScreen();
	MenuSam();
	while (isRunning == true)
	{
		// Initalisierung & Setze alles auf Standard.
		Optio = true;
		menuloc = 1; // Aktuelle auswahl des Menüs
		modus = 0; // Gibt nach dem Menü an Welcher Modus ausgewählt wurde.

		while (isRunningProg == true)
		{
			MenuLogic();
			MenuGrap();

		} // while() == isRunningProg
		MenuModus();
	}
} // int main()