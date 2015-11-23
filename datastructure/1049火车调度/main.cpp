#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int t;
	int order[1001];
	int n,m;
	int stack1[1001]={-1};
	int stack2[1001]={-1};
	int position1,position2;
	int temp;
	int flag = 0;
	cin>>t;
	for(int time=0;time<t;time++){
		cin>>n>>m;
		//cout<<"n,m"<<n<<" "<<m<<" "<<endl;
		position1 = n-1;
		position2 = -1;
		for(int i=0;i<=n-1;i++){
			stack1[n-i-1] = i;
			stack2[i] = -1;
		}
		for(int i=0;i<=n-1;i++){
			cin>>temp;
			if(flag) continue;
			//cout<<"step "<<i<<": "<<position1<<" "<<stack1[position1]<<" "<<endl;
			if((position1!=-1)&&(stack1[position1] == temp)){
				position1--;
				//cout<<"the step(not in while) "<<i<<" --> "<<temp<<" :"<<"find in stack1"<<endl;
			}
			else{
				if(stack2[position2] == temp){
					position2--;
					//cout<<"the step "<<i<<" --> "<<temp<<" :"<<"find in stack2"<<endl;
				}
				else{
					//if(temp<stack2[position2]){flag = 1;}
					while(stack1[position1]!=temp){
						if(position1==0){
							flag = 1;
							break;
						}
						//cout<<"the step "<<i<<" -->can't find "<<temp<<" and put "<<stack1[position1]<<" into stack2"<<endl;
						stack2[++position2] = stack1[position1--];
						//cout<<"after insert position is:"<<position1<<endl;
						if(position2>(m-1)){flag = 1;}
					}
					//if(!flag) cout<<"the step "<<i<<" --> "<<temp<<" :find in stack1"<<endl;
					position1--;
				}
			}
			//if(position1<0) {flag=1;}
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		flag = 0;
	}
}
