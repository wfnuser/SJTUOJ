#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	freopen("date.out", "w", stdout);
	int n;
	int path;
	int i,j;
	int map[111][111]={0};
	int min,max;
	int s,e;
	int state[111][111]={0};
	int queue[20000]={0};
	int head,tail;
	int num;
	int row;
	int col;
	int visit[111][111] = {0};

	cin>>n;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			cin>>map[i][j];
			if(min>map[i][j]) min = map[i][j];
			if(max<map[i][j]) max = map[i][j];
		}
	}
	int flag = 0;
	int wave = 10000000;
	int father[20000]={0};
	for(s=min;s<=max;s++)
	{
		for(e=s;e<=max;e++){
			cout<<"---------------------------"<<endl;
			cout<<"start from "<<s<<" to "<<e<<endl;
			for(i=0;i<=n-1;i++){
				for(j=0;j<=n-1;j++){
					visit[i][j] = 0;
					queue[i*n+j] = 0;
					father[i*n+j] = 0;
					if(map[i][j]>=s&&map[i][j]<=e){state[i][j] = 1;}
					else {state[i][j] = 0;}
					cout<<state[i][j]<<" ";
				}
				cout<<endl;
			}
			tail = 0;
			head = 0;
			queue[head++] = 0*n + 0;
			visit[0][0] = 1;
			while(tail<head){
				row = queue[tail]/n;
				col = queue[tail] - n*row;
				if(queue[tail] == n*(n-1)+n-1){flag=1;if(wave>(e-s)){wave = e-s;};break;}
				if(row<n&&col+1<=n-1&&!visit[row][col+1]){
					visit[row][col+1] = 1;
					if(state[row][col+1] == 1){
						queue[head++] = n*(row) + col + 1;
						father[queue[head-1]] = queue[tail];
					}	
				}		
				if(row<n-1&&col<n&&!visit[row+1][col]){
					visit[row+1][col] = 1;
					if(state[row+1][col] == 1){
						queue[head++] = n*(row+1) + col;
						father[queue[head-1]] = queue[tail];
					}	
				}	
				if(col>0&&!visit[row][col-1]){
					visit[row][col-1] = 1;
					if(state[row][col-1] == 1){
						queue[head++] = n*(row) + col - 1;
						father[queue[head-1]] = queue[tail];
					}	
				}		
				if(row>0&&!visit[row-1][col]){
					visit[row-1][col] = 1;
					if(state[row-1][col] == 1){
						queue[head++] = n*(row-1) + col;
						father[queue[head-1]] = queue[tail];
					}	
				}	
				tail++;	
			}	
			if(flag){
				//cout<<"the path is:"<<endl;
				//path = queue[tail];
				//while(path!=0){
					//cout<<"("<<(path/n)<<","<<(path-(path/n)*(n))<<")"<<" ";
				//	path = father[path];
				//}
				cout<<endl;
				cout<<"wave is : "<<wave<<endl;
			}
			flag = 0;
			cout<<"-----------------------"<<endl;
			cout<<endl;
		}
	}
	cout<<wave;
	cout<<endl;
}
