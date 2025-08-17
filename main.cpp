#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

bool gameover;
const int width = 40, height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup();
void draw();
void input();
void logic();

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	setup();
	while(!gameover){
		draw();
		input();
		logic();
		_sleep(100);
	}
	return 0;
}

void setup(){
	gameover = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitX = rand()%width;
	fruitY = rand()%height;
	score = 0;
}
void draw(){
	system("cls");
	for (int i=0; i<width+2; i++) cout<<"#";
	cout<<endl;
	for (int i=1; i<height; i++){
		for (int j=0; j<width; j++){
			if(j == 0) cout<<"#";
			if (i == y and j == x) cout<<"O";
            else if (i == fruitY and j == fruitX) cout<<"*";
            else cout<<" ";
			if(j == width-1) cout<<"#";
		}
		cout<<endl;
	}
	for (int i=0; i<width+2; i++) cout<<"#";
	cout<<endl;
}
void input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}
void logic(){
    switch(dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if(x > width or x < -1 or y > height or y < 0) gameover = true;
    if (x == fruitX and y == fruitY){
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
    }
}
