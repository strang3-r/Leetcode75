#include <bits/stdc++.h>
using namespace std;
bool isValid(int screen[][8], int m, int n, int x, int y, int prevC, int newC)
{
	if(x < 0 || x >= m || y < 0 || y >= n || screen[x][y] != prevC
	|| screen[x][y]== newC)
		return false;
	return true;
}
void floodFill(int screen[][8], int m, int n, int x, int y, int prevC, int newC)
{
	vector<pair<int,int>> queue;
	pair<int,int> p(x,y);
	queue.push_back(p);
	screen[x][y] = newC;
	while(queue.size() > 0)
	{
		pair<int,int> currPixel = queue[queue.size() - 1];
		queue.pop_back();

		int posX = currPixel.first;
		int posY = currPixel.second;
		if(isValid(screen, m, n, posX + 1, posY, prevC, newC))
		{
			screen[posX + 1][posY] = newC;
			p.first = posX + 1;
			p.second = posY;
			queue.push_back(p);
		}

		if(isValid(screen, m, n, posX-1, posY, prevC, newC))
		{
			screen[posX-1][posY]= newC;
			p.first = posX-1;
			p.second = posY;
			queue.push_back(p);
		}

		if(isValid(screen, m, n, posX, posY + 1, prevC, newC))
		{
			screen[posX][posY + 1]= newC;
			p.first = posX;
			p.second = posY + 1;
			queue.push_back(p);
		}

		if(isValid(screen, m, n, posX, posY-1, prevC, newC))
		{
			screen[posX][posY-1]= newC;
			p.first = posX;
			p.second = posY-1;
			queue.push_back(p);
		}
	}
}
	
int main()
{
	int screen[][8] ={
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0},
	{1, 0, 0, 1, 1, 0, 1, 1},
	{1, 2, 2, 2, 2, 0, 1, 0},
	{1, 1, 1, 2, 2, 0, 1, 0},
	{1, 1, 1, 2, 2, 2, 2, 0},
	{1, 1, 1, 1, 1, 2, 1, 1},
	{1, 1, 1, 1, 1, 2, 2, 1}};
	int m = 8;
	int n = 8;
	int x = 4;
	int y = 4;
	int prevC = screen[x][y];
	int newC = 3;
	floodFill(screen, m, n, x, y, prevC, newC);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << screen[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
