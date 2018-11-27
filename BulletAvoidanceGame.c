#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> // Visual Studio 에서만 사용할 수 있는 getch 전용 함수

#define DEFAULT_LIFE 5 // 내 기본 목숨
#define BULLET_NUM_R1 30 // 첫번째 라운드의 bullet의 숫자들

/////////////////////////////

void select_1(); // 메인화면 첫번째 선택
void select_2(); // 메인화면 두번째 선택
void playGame(); // 게임을 실행하는 함수
void roundLoading(int num); // %d라운드 로딩하는 함수
void RemoveCursor(void);
void roundOne(); // 라운드 1의 게임 부분을 담당
int setScore(); // 스코어를 계산하는 함수
void setCursor(int x,int y); // Windows.h에 내장된 COORD 자료형을 통해 커서의 위치를 옮기는 함수
void printScore(int score,int life); // 스코어를 출력하는 함수
void clearScreen();

///////////////////////////

// rows= 27 cols=29

typedef struct enemyBullet // 절대 위치 x,y(처음 생성되는 위치), 상대위치 x,y(나중에 움직이는 좌표 필요) 
{
	double ab_x; // 절대 위치
	double ab_y; // 절대 위치
	double x;
	double y;
	double speed; ////
	char* shape;
}enemyBullet;

typedef struct myCh
{
	int x;
	int y;
	char* shape;
}myCh;

int myScore = 0; // 내 점수 전역변수로 만들기. (조금 아쉽)
int myLife = DEFAULT_LIFE; // 내 기본 목숨 갯수

/*참조
https://blog.naver.com/lyw94k/220842186941
콘솔 색상 바꾸기, 타이틀 넣기
https://m.blog.naver.com/PostView.nhn?blogId=sydneyman&logNo=50035878640&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
콘솔 커서의 깜빡임 없애기
https://m.blog.naver.com/PostView.nhn?blogId=skyvvv624&logNo=220774247361&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
기본 게임만드는 함수/테트리스 만들기 예제
*/

int main()
{
	// 메인 타이틀 선택
	system("title Bullet Avoidance Game");
	
	system("mode con: cols=80 lines=35");


	myCh mych = { 0,0,'山' };

	RemoveCursor();
	select_1(&myScore);
	

	return 0;
}

void setCursor(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RemoveCursor(void) //
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible 멤버 변경
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // 변경값 적용
}


void select_1()
{
	system("cls");

	int keycode = 0; // 메인 타이틀 바꾸기 위한 받기 전용 키코드

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
	
	for (int i = 0; i < 4; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}
	printf("■\t\t( ´'ω')つ──☆**\t\t\t■\n");
	printf("■\t\t  ☆탄막 피하기 게임☆\t\t\t■\n");
	printf("■\t\tPress Space to Continue\t\t\t■\n");

	for (int i = 0; i < 3; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}
	printf("■\t\t\t▶시작하기\t\t\t■\n");
	printf("■\t\t\t▷종료하기\t\t\t■\n");

	for (int i = 0; i < 15; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개

	keycode = _getch();

	if (keycode == 80 || keycode == 72)
	{
		select_2();
	}
	else if (keycode == 32)
	{
		playGame();
	}
	else
	{
		select_1();
	}
}

void select_2()
{
	system("cls");

	int keycode = 0; // 메인 타이틀 바꾸기 위한 받기 전용 키코드

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개

	for (int i = 0; i < 4; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}
	printf("■\t\t( ´'ω')つ──☆**\t\t\t■\n");
	printf("■\t\t  ☆탄막 피하기 게임☆\t\t\t■\n");
	printf("■\t\tPress Space to Continue\t\t\t■\n");

	for (int i = 0; i < 3; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}
	printf("■\t\t\t▷시작하기\t\t\t■\n");
	printf("■\t\t\t▶종료하기\t\t\t■\n");

	for (int i = 0; i < 15; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
	
	keycode = _getch();
	if (keycode == 80 || keycode == 72)
	{
		select_1();
	}
	else if (keycode == 32)
	{
		system("cls");
		printf("프로그램을 종료합니다...!");
		return;
	}
	else
	{
		select_2();
	}
}

void playGame()
{
	system("cls");
	roundLoading(1);
	clearScreen();
	roundOne();
}

void roundLoading(int num)
{
	
	for (int i = 0; i < 4; i++) {
		if (i == 0)
		{
			system("cls");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개

			for (int i = 0; i < 8; i++) {
				printf("■\t\t\t\t\t\t\t■\n");
			}
			printf("■\t\t\tRound %d!\t\t\t■\n■\t\t\tAre you Ready?\t\t\t■\n", num);
			for (int i = 0; i < 17; i++) {
				printf("■\t\t\t\t\t\t\t■\n");
			}
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
			Sleep(1500);
		}
		else
		{
			system("cls");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
			
			for (int i = 0; i < 8; i++) {
				printf("■\t\t\t\t\t\t\t■\n");
			}
			
			printf("■\t\t\t\t%d!\t\t\t■\n", 4-i);

			for (int i = 0; i < 18; i++) {
				printf("■\t\t\t\t\t\t\t■\n");
			}
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
			Sleep(1500);
		}
	}
	
}

void printScore(int score,int life)
{
	setCursor(61,8);
	printf("현재 점수: %d\n", score);
	setCursor(61, 9);
	printf("Life Remaining\n");
	setCursor(61, 10);
	for (int i = 1; i <= life; i++)
	{
		printf("♥");
	}
}

void roundOne() // 직선, 등속으로 떨어지는 패턴
{
	srand((unsigned int)time(NULL));
	printScore(myScore,myLife);
	enemyBullet enemybullet[BULLET_NUM_R1];
	
	// 떨어지는 bullet의 x절대 좌표는 랜덤으로, y 절대 좌표는 2 ( 맨위) 초기화 시키기
	for (int i = 0; i < BULLET_NUM_R1; i++)
	{
		enemybullet[i].ab_x = rand() % 25 + 1;
		enemybullet[i].ab_y = 2;
		enemybullet[i].speed = 0.5;
		enemybullet[i].x = enemybullet[i].ab_x;
		enemybullet[i].y = enemybullet[i].ab_y;
		
		int a = rand() % 3;
		switch (a)
		{
		case 0:
			enemybullet[i].shape = "♩";//
			break;
		case 1:
			enemybullet[i].shape = "♪";//
			break;
		case 2:
			enemybullet[i].shape = "♬";//
			break;
		default:
			continue;

		}

		// 좌표와 모양 초기화 완료!

	}

	// 초당 50프레임일시 1000/50=200
	// Sleep(200);기준

	clearScreen();
	for (int i = 0; i < 500; i++)
	{
		printScore(myScore, myLife);
		setCursor((int)enemybullet[0].x, (int)enemybullet[0].y);
		printf("%c", enemybullet[0].shape);
		Sleep(200);
		setCursor((int)enemybullet[0].x, (int)enemybullet[0].y);
		printf(" ");
		enemybullet[0].y += enemybullet[0].speed;
	}


	/*

	☆ 프레임 경과할때 마다 사용자에게서 키를 입력받고 사용자가 키를 입력하지 않으면 움직이지 않고
		키를 입력하면 좌 우로 제한선 안에서 이동하게 한다(제한선: 함수로 구현)
	0. 배경을 그린다
	1. [0]의 enemybullet과 점수를 그린다
	1-1. 프레임 경과
	2 이전에 그렸던 [0]의 enemybullet이 삭제된다 ( 원래 있었던 자리를 " "으로 채움)
	3. [0]의 enemybullet이 아래로 이동한다
	3-1. 출력하고 프레임 경과
	4. 0~3까지 반복하고 [0]이 3분의 1쯤 왔을때 [1]을 그린다
	5. 0이 다 도달했을 때 움직임 x 값변경 x

	*/
}

int setScore()
{

}

void clearScreen()
{
	system("cls");
	
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
	for (int i = 0; i < 27; i++) {
		printf("■\t\t\t\t\t\t\t■\n");
	}
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //27개
	
}
