#include<iostream>
#include<cstdio>
#include <stack>

using namespace std;

int main(){
	//stack<int> elsestack;
	string temp;
	int flag=0;
	int error=0;
	int ifnum[100]={0};
	int beginnum[100]={0};
	int position = 0;
	while(cin>>temp){
		//error found
		//cout<<temp<<endl;
		if(flag)
			if(temp!="then"){ 
				error = 1; 
				break;
			}
		/////////////
		if(temp=="if"){
			flag = 1;
			ifnum[position]=1;
		}
		if(temp == "then"){
			if(flag == 0){
				error = 1; 
				break;
			}
			else flag = 0;
		}
		if(temp == "begin"){
			beginnum[++position]++;
		}
		if(temp == "end"){
			ifnum[position]=0;
			beginnum[position--]--;
			if(beginnum[position+1]<0){ error = 1; break;}
			if(position<0) {error=1;break;}
		}
		if(temp == "else"){
			ifnum[position]--;
			if(ifnum[position]<0) {error = 1; break;}
		}
	}
	if(flag||position){
		error = 1;	
	}	
	if(error)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}
