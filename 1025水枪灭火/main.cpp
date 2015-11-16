//
//  main.cpp
//  1025
//
//  Created by wfnuser on 15/10/19.
//  Copyright (c) 2015年 xunquweb. All rights reserved.
//

#include<iostream>
#include<cstdio>

using namespace std;

void quick_sort(int l, int r, int a[], int b[]){
    int left = l;
    int right = r;
    int flag = a[(l+r)/2];
    int flag2 = b[(l+r)/2];
    int temp = 0;
    int test = 0;
    while(left<=right){
        while((a[left]<flag||(a[left]==flag&&b[left]<flag2))&&left<=right){
            left++;
        }
        while((a[right]>flag||(a[right]==flag&&b[right]>flag2))&&left<=right){
            right--;
        }
        if(left <= right){
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            temp = b[left];
            b[left] = b[right];
            b[right] = temp;
            left++;
            right--;
        }
    }
    if(l<right)
        quick_sort(l,right,a,b);
    if(left<r)
        quick_sort(left,r,a,b);
}

int main(){
    int n;
    int a[20000];
    int b[20000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    quick_sort(0,n-1,a,b);
    int head;
    int tail;
    int length = 0;
    head = a[0];
    tail = b[0];
    for(int i=0;i<n;i++){
        //cout<<a[i]<<" "<<b[i]<<endl;
    }
    for(int i=0;i<n;i++){
        
        if((a[i]<tail)){
            if(tail<b[i]){
                tail = b[i];
            }
        }
        else{
            length = length + tail - head;
            head = a[i];
            tail = b[i];
        }
        //cout<<"length"<<i<<": "<<length<<endl;
        //cout<<"tail"<<i<<": "<<tail<<endl;
        
    }
    length =length + tail - head;
    cout<<length;
    
}
