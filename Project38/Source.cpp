#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<ctime>
#include<iostream>
#include<math.h>
void sleep(unsigned int mseconds) { clock_t goal = mseconds + clock(); while (goal > clock()); }
void setTextColor(int textColor, int backColor = 0) { HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); int colorAttribute = backColor << 4 | textColor; SetConsoleTextAttribute(consoleHandle, colorAttribute); }
void clearScreen() { system("cls"); }
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); COORD cursorCoord; cursorCoord.X = y; cursorCoord.Y = x;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
int console_size_x=1920,console_size_y = 1080;
struct circlePosition
{
	int left, right, up, down;
}ellips;
struct Position
{
	int left, right, up, down;
}playerPosition;
struct mrectangles
{
	Position x;
	int tedad_x = 1, tadad_y = 1;
}moving_rectangels;
struct info
{
	int distinction = 0;
	int max_distinction = 0;
	char username[20];
};
int z, i = 3, zl, d, i_x = 0, i_y = 0;
float x = 2, y = 2;
int live_number = 0, score = 0;
int speed_changer;
int R_e = (ellips.down - ellips.up) / 2;
info users;
HWND a = GetConsoleWindow();
HDC hdc = GetDC(a);
static HBRUSH hbrash, hbrashold;
FILE *infofile;
void  movingRegtengle() {
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
		Rectangle(hdc, playerPosition.left, playerPosition.up, playerPosition.right, playerPosition.down);
		//daryaft vorodi
			if (GetKeyState(VK_RIGHT) & 0x800&&console_size_x>=playerPosition.right)
			{
				playerPosition.left += i;
				playerPosition.right += i;
			}
			else if (GetKeyState(VK_LEFT) & 0x800&&playerPosition.left>=0)
			{
				playerPosition.left -= i;
				playerPosition.right -= i;
			}
			else if (GetKeyState(VK_UP) & 0x800&&playerPosition.up>=console_size_y-70) {
				playerPosition.up -= i;
				playerPosition.down -= i;
			}
			else if (GetKeyState(VK_DOWN) & 0x800&&playerPosition.down<=console_size_y) {
				playerPosition.up += i;
				playerPosition.down += i;
			}
			SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
			Rectangle(hdc, playerPosition.left, playerPosition.up, playerPosition.right, playerPosition.down);
			//speed chenging
			if (live_number <= speed_changer)
				sleep(2);
			else
			    sleep(4);
}
void circle() {
	static bool endgame = true;
	if (ellips.down > playerPosition.down&&endgame) 
		endgame = false;
	if (live_number <= speed_changer)
		sleep(3);
	else
	    sleep(4);
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
		Ellipse(hdc, ellips.left, ellips.up, ellips.right, ellips.down);
			ellips.down += y;
			ellips.up += y;
			ellips.right += x;
			ellips.left += x;
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			Ellipse(hdc, ellips.left, ellips.up, ellips.right, ellips.down);
			z = (ellips.right + ellips.left) / 2;
			zl = (ellips.up + ellips.down) / 2;
			    if (ellips.down >= playerPosition.up&&z <= playerPosition.right&&z >= playerPosition.left&&endgame) {
					y = -2;
					if (GetKeyState(VK_UP) & 0x800&&playerPosition.up>console_size_y-70) 
						y = -4;
					if (GetKeyState(VK_DOWN) & 0x800&&playerPosition.down<console_size_y) 
						y = -1;
				}
				if (ellips.up < 1)
					y = 2;
				if (ellips.right > console_size_x) 
					x = -2;
				if (ellips.left < 1) 
					x = 2;
}
void toprectangels() {
	moving_rectangels.x.left = 0;
	moving_rectangels.x.right = console_size_x / moving_rectangels.tedad_x;
	moving_rectangels.x.up = 10;
	moving_rectangels.x.down = 40;
	static bool firstTime = true;
	static int center[200][3] = { 0 };
	if (firstTime){
		for (int i = 0; i < moving_rectangels.tadad_y*moving_rectangels.tedad_x; i++)
			center[i][2] = 1;
		firstTime = false;
	}
	static int d = (moving_rectangels.x.right - moving_rectangels.x.left);
	static int dl = (moving_rectangels.x.down - moving_rectangels.x.up);
	int gha = 0;
	while (i_y < moving_rectangels.tadad_y) {
		while (i_x < moving_rectangels.tedad_x+gha) {
			center[i_x][0] = (moving_rectangels.x.left + moving_rectangels.x.right) / 2;
			center[i_x][1] = (moving_rectangels.x.down + moving_rectangels.x.up) / 2;
			i_x++;
				hbrash = CreateSolidBrush(RGB(55, 100, 200));
				SelectObject(hdc, hbrash);
				Rectangle(hdc, moving_rectangels.x.left, moving_rectangels.x.up, moving_rectangels.x.right, moving_rectangels.x.down);
			moving_rectangels.x.left = moving_rectangels.x.right;	
			moving_rectangels.x.right += d;
		}
		gha+=moving_rectangels.tedad_x;
		moving_rectangels.x.left = 0;
		moving_rectangels.x.right = console_size_x / moving_rectangels.tedad_x;
		moving_rectangels.x.up += dl;
		moving_rectangels.x.down += dl;
		i_y++;
	}
	int i_z = 0;
	//physics code
	while (i_z < moving_rectangels.tadad_y*moving_rectangels.tedad_x) {
			if (center[i_z][2] != 0 && center[i_z + 1][2] != 0) {
				if (z == (center[i_z][0] + center[i_z + 1][0]) / 2&& abs(center[i_z][1] - zl) <= dl / 2 + R_e) {
					score += 2;
					gotoxy(0, 0);
					printf("%d\a", score);
					y *= -1;
					SelectObject(hdc, GetStockObject(BLACK_BRUSH));
					Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
					Rectangle(hdc, center[i_z + 1][0] - d / 2, center[i_z + 1][1] - dl / 2, center[i_z + 1][0] + d / 2, center[i_z + 1][1] + dl / 2);
					live_number -= 2;
					center[i_z][2] = 0;
					center[i_z + 1][2] = 0;
				}
			}
			if (abs(center[i_z][0] - z) <= R_e + d / 2 && abs(center[i_z][1] - zl) <= R_e + dl / 2 && center[i_z][2] != 0) {
				if (z > center[i_z][0] - d / 2 && z < center[i_z][0] + d / 2) {
					score ++;
					gotoxy(0, 0);
					printf("%d\a", score);
					SelectObject(hdc, GetStockObject(BLACK_BRUSH));
					Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
					y *= -1;
					center[i_z][2] = 0;
					live_number--;
				}
				else if (zl > center[i_z][1] - dl / 2 && zl < center[i_z][1] + dl / 2) {
					score ++;
					gotoxy(0, 0);
					printf("%d\a", score);
					SelectObject(hdc, GetStockObject(BLACK_BRUSH));
					Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
					x *= -1;
					center[i_z][2] = 0;
					live_number--;
				}
			}
		i_z++;
	}
	i_z = 0;
	users.distinction = score;
}
void menue() {
	int start, buck; bool back = true, tr = true;
	while (back) {
		system("cls");
		printf("1:start\n2:scors list\n");
		scanf_s("%d", &start);
		if (start == 1) {
			while (tr) {
				system("cls");
				printf("please enter username\n");
				gets_s(users.username);
				if (!users.username[0]) {
					gotoxy(0, 0);
					continue;
				}
				system("cls");
				tr = false;
			}
			tr = true;
			while (tr) {
				printf("please enter the number of rectangels_x\n");
				scanf_s("%d", &moving_rectangels.tedad_x); system("cls");
				if (moving_rectangels.tedad_x == 0) {
					printf("thats not possible!"); sleep(1000); system("cls");
					continue;
				}
				tr = false;
			}
			tr = true;
			while (tr) {
				printf("pleas enter the number of rectangels_y\n");
				scanf_s("%d", &moving_rectangels.tadad_y); system("cls");
				if (moving_rectangels.tadad_y == 0) {
					printf("thats not possible!"); sleep(1000); system("cls");
					continue;
				}
				tr = false;
			}
			live_number = moving_rectangels.tedad_x*moving_rectangels.tadad_y;
			speed_changer = live_number / 3;
			back = false;
		}
		else if (start == 2) {
			system("cls");
			infofile = fopen_s("H:\\game.project\\usersinfo.txt", "rt");
			printf("1:back\n");
			printf("user_name      score\n");
			fscanf_s(infofile, "%s%d", users.username, &users.distinction);
			printf("%s              %d\n", users.username, users.distinction);
			fclose(infofile);
			scanf_s("%d", &buck);
			if (buck == 1)
				back = true;
		}
	}
}
void position() {
	playerPosition.down = console_size_y;
	playerPosition.left = console_size_x / 2 - 60;
	playerPosition.right = console_size_x / 2 + 60;
	playerPosition.up = console_size_y - 20;
	ellips.left = (playerPosition.left + playerPosition.right) / 2 - 10;
	ellips.up = playerPosition.up - 21;
	ellips.right = (playerPosition.left + playerPosition.right) / 2 + 10;
	ellips.down = playerPosition.up - 1;
}
int main() {
	playerPosition.down = console_size_y;
	playerPosition.left = console_size_x/2-60;
	playerPosition.right = console_size_x/2+60;
	playerPosition.up = console_size_y-20;
	ellips.left = (playerPosition.left+playerPosition.right)/2-10;
	ellips.up = playerPosition.up-21;
	ellips.right = (playerPosition.left + playerPosition.right) / 2 + 10;
	ellips.down = playerPosition.up-1;
	moving_rectangels.x.left = 0;
	moving_rectangels.x.right = console_size_x / moving_rectangels.tedad_x;
	moving_rectangels.x.up = 10;
	moving_rectangels.x.down = 40;
	menue();
	printf("press Enter to start");
	getchar();
	system("cls");
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
	Rectangle(hdc, 0, 0, console_size_x, console_size_y);
	while (true)
	{
		toprectangels();
		circle();
		movingRegtengle();
		if (live_number == 0) {
			infofile = fopen_s("H:\\game.project\\usersinfo.txt", "wt");
			fprintf(infofile, "%s           %d\n", users.username,score);
			fclose(infofile);
			gotoxy(20, 20);
			printf("you win ");
			sleep(2000);
			system("cls");
			menue();
			position();
			continue;
			getchar();
			getchar();
			return 0;
		}
		if (ellips.up > console_size_y) {
			infofile = fopen_s("H:\\game.project\\usersinfo.txt", "wt");
			fprintf(infofile, "%s           %d\n", users.username, score);
			fclose(infofile);
			system("cls");
			gotoxy(20, 20);
			printf("game over ");
			sleep(2000);
			menue();
			position();
			continue;
			getchar();
			getchar();
			return 0;
		}
	}
	getchar();
	getchar();
	return 0;
}