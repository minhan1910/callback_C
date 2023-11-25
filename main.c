#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  // for Sleep func
#define N_ACTORS 3

struct Actor;
typedef void (*fptr)(struct Actor* a);

// each actor’s fn will modify actor’s x,y diferrently because fn contains different function.
typedef struct Actor {
	int x, y;
	char* name;
	fptr fn;
} Actor;

Actor actors[N_ACTORS]; 
void move_rand(Actor*); 
void move_right(Actor*); 
void move_up(Actor*); 
void draw();
void main_loop(); 

int main(int argc, char *argv[]) {
	actors[0].x = 10; actors[0].y = 10; actors[0].name = "1"; actors[0].fn = move_rand; 
	actors[1].x = 10; actors[1].y = 10; actors[1].name = "2"; actors[1].fn = move_right; 
	actors[2].x = 10; actors[2].y = 10; actors[2].name = "3"; actors[2].fn = move_up; 
	
	while(1){main_loop();} 
	
	return 0;
}

void main_loop() {
	int i;
	for (i = N_ACTORS; --i >= 0;) {
		Actor* a = &actors[i];
		a->fn(a);
	}
	
	draw();
	
	Sleep(1000);
}

void move_rand(Actor* a) {
	a->x += (rand() % 4) - 1;
	a->y += (rand() % 4) - 1;
} 

void move_right(Actor* a) {
	a->x += 1;
}

void move_up(Actor* a) {
	a->y -= 1;	
}

void gotoxy(int x, int y) 
{ 
	COORD p = {x,y}; 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(h, p); 
} 

void draw() {
	system("cls");
	int i;
	for (i = N_ACTORS; --i >= 0;) {				
		Actor* a = &actors[i];		
		gotoxy(a->x, a->y);
		
		if (strcmp(a->name, "1") == 0) {
			printf("@");	
		} else if (strcmp(a->name, "2") == 0) {
			printf("*");
		} else {
			printf("->");
		}
	}
}


