#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

string a;
string b;

string mul(string a, string b){	
	int la = a.length();	
	int lb = b.length();
	int temp[20001]={0};
	int c = 0;
	int i=0;
	int j=0;
	for(i=lb-1;i>=0;i--){
		for(j=la-1;j>=0;j--){
			temp[la+lb-i-j-2] = temp[la+lb-i-j-2] + (b[i]-'0') * (a[j]-'0') + c;
			c = temp[la+lb-i-j-2]/10;
			temp[la+lb-i-j-2] = temp[la+lb-i-j-2]%10; 
			//cout<<"this turn:"<<" b is: "<<(lb-i-1)<<" "<<b[i]<<" a is: "<<(la-j-1)<<" "<<a[j]<<" c is: "<<c<<" t is:"<<(la+lb-i-j-2)<<" "<<temp[la+lb-i-j-2]<<endl;
		}
		if(c!=0){
			temp[la+lb-i-1] = temp[la+lb-i-1] + c;
		}	
		c = 0;
	}
	int flag = 0;
	string str = "";
	int len;
	j = 0;
	for(i=la+lb;i>=0;i--){
		if(temp[i]==0&&flag==0){
			continue;
		}
		else{
			flag = 1;	
		}
		char buff;
		buff = temp[i] + '0';
		str = str + buff;
		//cout<<temp[i];
		//cout<<str[j-1];
	}
	//cout<<str;
	return str;
	//cout<<endl;
}

int compare(string a, string b){
	int la = a.length();
	int lb = b.length();
	if(la>lb){
		return 1;
	}
	if(la<lb){
		return 0;
	}
	else{
		for(int i=0;i<=la-1;i++)
		{
			//cout<<a[i]<<" "<<b[i]<<endl;
			if(a[i]<b[i]){
				return 0;
			}
			if(a[i]>b[i]){
				return 1;
			}
		}
		return 1;
	}
}

string sub(string a, string b){
	string result = "";
	int lena = a.length();
	int lenb = b.length();
	int temp[500000];
	int c = 0;
	int flag = 0;
	if(compare(a,b)){
		for(int i=0;i<=lenb-1;i++){
			temp[lena-i-1] = a[lena-i-1] - b[lenb-i-1] + c;
			if(temp[lena-i-1]<0){
				c=-1;
				temp[lena-i-1] = temp[lena-i-1] + 10;
			}
			else{
				c=0;
			}
			//cout<<"this turn: temp is: "<<temp[lena-i-1]<<" position: "<<lena-i-1<<endl;
		}
		for(int i=lenb;i<=lena-1;i++){
			temp[lena-i-1] = a[lena-i-1] + c - '0';
			if(temp[lena-i-1]<0){
				c=-1;
				temp[lena-i-1] = temp[lena-i-1] + 10;
			}
			else{
				c=0;
			}
		}
		for(int i=0;i<=lena-1;i++){
			if(temp[i]==0&&flag==0){
				continue;
			}
			else{
				flag = 1;	
			}
			char buff;
			buff = temp[i] + '0';
			result = result + buff;
		}
		return result;
	}
	else{
		return result;
	}
}

void div(string a, string b){
	int lenb = b.length();
	int lena = a.length();
	string temp;
	string guess;
	string result;
	int pivot = lenb;
	int flag = 0;
	string chstr;
	temp = temp.append(a,0,pivot);
	if(!compare(a,b))
		cout<<0;
	else{
		for(pivot=lenb-1;pivot<=lena-1;){	
			//cout<<"---------startcompare----------"<<endl;
			int first = 0;
			while(!compare(temp,b)){
				//cout<<"the old temp:"<<temp<<" the divider:"<<b<<endl;
				temp = temp + a[++pivot];
				// cout<<"the pivot is on:"<<pivot<<endl;
				// cout<<"the pivot is on:"<<a[pivot]<<endl;
				// cout<<"the new temp is:"<<temp<<endl;
				// cout<<compare(temp,b)<<endl;
				if(first) result = result + "0";
				first = 1;
				if(pivot>lena-1){
					flag = 1;
					break;
				}
			}
			// cout<<"---------endcompare----------"<<endl;
			// cout<<"this turn is : "<<temp<<endl;
			if(flag){
				//cout<<"break"<<endl;
				break;
			}
			for(char ch='9';ch>='0';ch--){
				chstr = "";
				chstr.insert( chstr.begin(), ch );
				//cout<<"the guess number is:"<<chstr<<endl;
				guess = mul(b,chstr);
				//cout<<"the guess is :"<<guess<<endl;
				if(compare(temp,guess)){
					result = result + ch;
					temp = sub(temp,guess);	
					//cout<<"stop!"<<endl;
					//cout<<"the sub is:"<<temp<<endl;
					break;			
				}	
			}
		}
		for(int k=0;k<=result.length()-1;k++)
			cout<<result[k];
	}
	cout<<endl;
}

int main(){
	cin>>a;
	cin>>b;
	int la = a.length();	
	int lb = b.length();
	// cout<<mul(a,b);
	// cout<<la<<" "<<lb<<endl;
	// div(a,b);	
	// string test;
	// test = mul(a,b);
	// cout<<test;
	//cout<<compare(a,b);
	div(a,b);
}
