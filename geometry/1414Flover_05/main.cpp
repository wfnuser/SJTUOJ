#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

pair<double, double> array[1000];

double area(pair<double,double> s, pair<double, double> e1, pair<double,double> e2)
{
}

bool judge(pair<double,double> s,pair<double,double> e,pair<double,double> ss,pair<double,double> ee){
	if(s == ss || e == ee || e == ss || s == ee)
		return true;
	else
	{
		if((s.first-e.first)*(ss.second-ee.second) == (s.second-e.second)*(ss.first-ee.first))
		{
			if(s.first == e.first){
				if(ss.first == ee.first){
					return false;
				}
				else{
					if(area()*area()>0)
						return false;
					if(area()*area()>0)
						return false;
					return true; 
				}
			}
			if(s.second == e.second){
				if(ss.second == ee.second){
					return false;
				}
				else{
					if(area()*area()>0)
						return false;
					if(area()*area()>0)
						return false;
					return true; 	
				}
			}
			return false;
		}
		else{
			
		}
	}
	return false;
}

double main(){
	double n;
	pair<double, double>  start[100];
	pair<double, double>  end[100];
	int i,j;
	int sum;
	for(j=0;j<=n-1;j++)
		cin>>start[j].first;
	for(j=0;j<=n-1;j++)
		cin>>start[j].second;
	
	for(j=0;j<=n-1;j++)
		cin>>end[j].first;
	for(j=0;j<=n-1;j++)
		cin>>end[j].second;

	for(i=0;i<n-2;i++)
		for(j=i+1;j<=n-1;j++)
		{
			if(judge(start[i],end[i],start[j],end[j])) sum++;		
		}
	if(sum-n+1>0)
		cout<<sum-n+1;	
	else
		cout<<0;
	cout<<endl;
}
