#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

void  union_of_segment(vector<pp>&arr){
    int n= arr.size();
    vector<pair<int,bool>>x(n*2);
    for(int i=0; i<n; i++){
        x[2*i]={arr[i].first, true};
        x[2*i +1]={arr[i].second,false};
    }
    sort(x.begin(), x.end());
    int res=0;
    int count=0;
    for(int i=0; i<x.size(); i++){
        if(i>0 and x[i].first >x[i-1].first and count>=0){
            res+= x[i].first-x[i-1].first;
        }
        if(x[i].second){
            count++;
        }
        if(!x[i].second)count--;
    }
    cout<<"length of union of segment is"<<res;
}
int main(){
    int n;
    cin>>n;
    vector<pp>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    union_of_segment(arr);
    return 0;
}