#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// 사각형의 가로, 세로 길이
#define WIDTH	20
#define HEIGHT	20

// 그래픽을 위한 전역 변수(17장 참조)
HWND hwnd;
HDC hdc;

// 함수 원형 정의
void gotoxy(int x, int y);
void clear_screen(void);
int check_overlap(int x1, int y1, int x2, int y2);
void print_score(int s);
void draw_me(int x, int y);
void draw_enemy(int x, int y);

// 커서를(x, y) 좌표로 이동시킨다. 사용만 하자. 이해하지 않아도 된다.
void gotoxy(int x, int y)
{
	COORD coord = { 0, 0 };
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 큰 사각형을 그려서 화면을 지운다.
void clear_screen(void)
{
	Rectangle(hdc, 0, 0, 1000, 1000);
}

// 내 우주선을 그린다. 
void draw_me(int x, int y)
{
	Rectangle(hdc, x, y, x + WIDTH, y + HEIGHT);
}
// 적의 우주선을 그린다. 
void draw_enemy(int x, int y)
{
	Ellipse(hdc, x, y, x + WIDTH, y + HEIGHT);
}

// 현재 점수를 화면의 고정된 위치 (1, 1)에 출력한다. 
void print_score(int s)
{
	gotoxy(1, 1);
	printf("현재 점수=%d", s);
}

// 2개의 사각형이 서로 겹치면 1을 반환한다.  
int check_overlap(int x1, int y1, int x2, int y2)
{
	// 한 사각형이 다른 사각형의 왼쪽에 있으면 겹치치 않는다. 
	if ((x1 + WIDTH) < x2 || (x2 + WIDTH) < x1)
		return 0;

	// 한 사각형이 다른 사각형의 아래에 있으면 겹치치 않는다. 
	if ((y1 + HEIGHT) < y2 || (y2 + HEIGHT) < y1)
		return 0;

	return 1;
}

void enemy_run(int me_x, int me_y, int* enemy_x, int* enemy_y)
{
	if(me_x<*enemy_x) // 내 좌표가 enemy보다 왼쪽일 때 enemy가 오른쪽으로 느리게 움직임
	{
		*enemy_x += 5;
	}
	else if(me_y > *enemy_y) // 내 좌표가 enemy보다 오른쪽일 때 enemy가 왼쪽으로 느리게 움직임
	{
		*enemy_x -= 5;
	};

	if (me_y < *enemy_y) // 내 좌표가 enemy보다 위쪽일 때 enemy가 아래쪽으로 느리게 움직임
	{
		*enemy_y += 5;
	}
	else if(me_y > *enemy_y)// 내 좌표가 enemy보다 아래쪽일 때 enemy가 위쪽으로 느리게 움직임
	{
		*enemy_y -= 5;
	};

}

int main(void)
{
	int me_x, me_y;		// 나의 위치
	int enemy_x, enemy_y;	// 적의 위치
	int score = 0;			// 점수
	int keycode;			// 키보드에서 받은 문자

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	srand((unsigned)time(NULL)); // 시드 생성

	me_x = 100;		// 나의 초기 x 위치
	me_y = 100;		// 나의 초기 y 위치a
	enemy_x = rand() % 300;	// 적의 초기 x 위치
	enemy_y = rand() % 300; // 적의 초기 y 위치

	while (1)			// 무한 루프
	{

		clear_screen();	// 화면을 지운다. 
		print_score(score);
		draw_me(me_x, me_y);	// 나를 그린다. 
		draw_enemy(enemy_x, enemy_y);	// 적을 그린다. 
		if (check_overlap(me_x, me_y, enemy_x, enemy_y) == 1)
		{
			score++;
			enemy_x = rand() % 300;
			enemy_y = rand() % 300;
			continue;
		}

		enemy_run(me_x, me_y, &enemy_x, &enemy_y);//
		
		keycode = _getch();
		switch (keycode) {
		case 77:
			me_x += 20;
			break;
		case 75:
			me_x -= 20;
			break;
		case 80:
			me_y += 20;
			break;
		case 72:
			me_y -= 20;
			break;
		case 'q':
			return 0;
		}

		
		
	}
	return 0;
}


