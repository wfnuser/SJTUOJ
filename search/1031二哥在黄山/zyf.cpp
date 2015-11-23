#include <iostream>
#include <cstring>
#include <cstdio>
#include <utility>

using namespace std;
const int maxm = 15600;
const int maxn = 130;
const int d[4][2] = {{1,0} , {0,1} , {-1,0},{0,-1}};
int n, matrix[maxn][maxn];
bool visited[maxn][maxn];
bool check(int x , int _min , int _max){
   return (x >= _min && x <= _max);
}
bool in_line(int x)
{
   return x >= 0 && x < n;
}
int main(){
	cin >> n;
	int _max = 0 , _min = 110;
	for (int i = 0; i < n; ++ i)
	   for (int j = 0; j < n; ++ j) {
	   	cin >> matrix[i][j];
	   	_max = max(_max , matrix[i][j]);
		_min = min(_min , matrix[i][j]);
	   }
	int ans = _max - _min;
	for (int st = _min ; st <= _max ; ++ st)
	   for (int ed = st; ed <= _max ; ++ ed){
		memset(visited , true , sizeof visited);
		if (!check(matrix[0][0], st , ed)) continue;
		visited[0][0] = false;
		int head = 0 , tail = 1;
		pair<int , int> que[maxm];
		que[0].first = 0 , que[0].second = 0;
		while (head < tail)
		{
			int x = que[head].first;
			int y = que[head++].second;
			for (int i = 0; i < 4; ++ i){
				int _x = x + d[i][0];
				int _y = y + d[i][1];
				if (in_line(_x) && in_line(_y) && visited[_x][_y] && check(matrix[_x][_y] , st, ed)){
					que[tail].first = _x ;
					que[tail++].second = _y;
					visited[_x][_y] = false;
				}
			}
		}
		if (!visited[n-1][n-1]) ans = min(ans , ed - st);
	   }
	  cout << ans << endl; 
}
