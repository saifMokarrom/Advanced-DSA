#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void build(int node, int l,int h, vector<int> &seg, vector<int> &ara, bool isOr){

    if (l==h){
        seg[node] = ara[l];
        return;
    }

    int left = node*2+1;
    int right = node*2+2;

    int mid = (l+h)/2;

    build(left, l,mid,seg,ara,!isOr);
    build(right, mid+1,h,seg,ara,!isOr);

    if (isOr) seg[node] = seg[left] | seg[right];
    else seg[node] = seg[left] ^ seg[right];



}


void update(int node, int l,int h, vector<int> &seg,int idx,int value, bool isOr){

    if (l==h){
        seg[node] = value;
        return;
    }

    int left = node*2+1;
    int right = node*2+2;

    int mid = (l+h)/2;

    if (idx<=mid) update(left, l,mid,seg,idx,value,!isOr);
    else update(right, mid+1,h,seg,idx,value,!isOr);

    if (isOr) seg[node] = seg[left] | seg[right];
    else seg[node] = seg[left] ^ seg[right];



}

int main(){

    int n,m;
    cin>>n>>m;
    int s = pow(2,n);
    vector<int> ara(s,0);
    vector<int>seg(4 * s,0);
    for (int i=0;i<s;i++){
        cin>>ara[i];
    }

    if (n%2==0) build(0,0,s-1,seg,ara,0);
    else build(0,0,s-1,seg,ara,1);

    for (int i=0;i<m;i++){
        int idx,val;
        cin>>idx>>val;
        idx--;
        if (n%2==0) update(0,0,s-1,seg,idx,val,0);
        else update(0,0,s-1,seg,idx,val,1);

        cout<<seg[0]<<"\n";
    }

}
