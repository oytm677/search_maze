#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <queue>
#include <unistd.h>
// 0 = 
// 1 = stop
// 2 = start
// 3 = goal
// 4 = passed
using namespace std;
int dx[4] = {1,0,-1,0},dy[4]={0,1,0,-1};

typedef pair<int,int> P;
const int INF = 100;
int num[2];
int matrix[30][30];
int sx,sy;
int width=21;
int height=11;
int gx,gy;
int d[30][30];
int solve_problem();

int solve_problem(){
	
	for(int i= 0; i < height; i++){
		for(int j = 0; j < width; j++){
				scanf("%d", &matrix[i][j]);
		}
	}
	
	for(int i= 0; i < height; i++){
		for(int j = 0; j < width; j++){
				if(matrix[i][j] == 2){
					sx = j;
					sy = i;
				//	printf("\n%2d",sx);
				//	printf("%2d\n",sy);
				}
		}
	}
	for(int i= 0; i < height; i++){
		for(int j = 0; j < width; j++){
				if(matrix[i][j] == 3){
					gx = j;
					gy = i;
				}
		}
	}



	return 0;
}


int bfs(){
	queue<P> que;
	for(int i=0; i < height; i++){
		for(int j = 0; j < width; j++){
			d[i][j] = INF;
		}
	}

	for(int i=0; i < height; i++){
			printf("\n");
		for(int j = 0; j < width; j++){
			printf("%3d",d[i][j]);
		}
	}
	que.push(P(sx,sy));
	d[sx][sy] = 0;
	printf("%2d",d[sx][sy]);
	while(que.size()){

		P p = que.front(); que.pop();

		if(p.first == gx && p.second == gy) break;

		for(int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second + dy[i];

			if(0 <= nx && nx < width && 0 <= ny && ny < height && matrix[nx][ny] != 1 && d[nx][ny] == INF){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
				printf("%2d",d[nx][ny]);			
			}
		}
	}
	return d[gx][gy];
}

void dfs(int x,int y){
	sleep(1);
	if(x==gx && y==gy){
		system("clear");
		printf("FINISH!!!!!\n");
		for(int i= 0; i < height; i++){
			printf("\n");
			for(int j = 0; j < width; j++){
				if(j==x && i ==y){
					printf("\x1b[36m"); 
					printf("%2d",matrix[y][x]);
					printf("\x1b[39m");
				}
				else if(matrix[i][j] == 1){
					printf("\x1b[35m"); 
					printf("%2d",matrix[i][j]);
					printf("\x1b[39m");
				}
				else if(matrix[i][j] == 3){
					printf("\x1b[31m"); 
					printf("%2d",matrix[i][j]);
					printf("\x1b[39m");
				}
				else				
					printf("%2d", matrix[i][j]);
			}
			printf("\n");
		}
		
		sleep(10);
		return;
	}
		matrix[y][x] = 4;
		system("clear");

		for(int i= 0; i < height; i++){
			printf("\n");
			for(int j = 0; j < width; j++){
				if(j==x && i ==y){
					printf("\x1b[32m"); 
					printf("%2d",matrix[y][x]);
					printf("\x1b[39m");
				}
				else if(matrix[i][j] == 1){
					printf("\x1b[35m"); 
					printf("%2d",matrix[i][j]);
					printf("\x1b[39m");
				}
				else if(matrix[i][j] == 3){
					printf("\x1b[31m"); 
					printf("%2d",matrix[i][j]);
					printf("\x1b[39m");
				}
				else			
					printf("%2d", matrix[i][j]);
			}
			printf("\n");
		}	
		sleep(1);
		for(int i=0; i<4; i++){
			int nx = x + dx[i],ny = y + dy[i];
			if(0 <= nx && nx < width && 0 <= ny && ny < height && matrix[ny][nx] != 1 && matrix[ny][nx] != 4 ) dfs(nx,ny);
		}
	
	
	return;
}

int main(){
	solve_problem();
	system("clear");
	for(int i= 0; i < height; i++){
		printf("\n");
		for(int j = 0; j < width; j++){
			if(j==sx && i ==sy){
				printf("\x1b[37m"); 
				printf("%2d",matrix[i][j]);
				printf("\x1b[39m");
			}
			else
			printf("%2d", matrix[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
	sleep(1);
	dfs(sx,sy);

}
