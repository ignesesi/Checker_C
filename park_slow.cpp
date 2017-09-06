#include<iostream>
#include<cstdio>
using namespace std;

long long vhod[1024][1024],lodki,hora,zloba[1024][1024];

long long nameriZloba(long long i,long long j){
    if(i>j){
        swap(i,j);
    }
    return (zloba[j][j]-zloba[i-1][j]-zloba[j][i-1]+zloba[i-1][i-1])/2;
}

long long  imaLiOtg(long long maxx){
    long long curr=1,l=1,i,otg=0;
    for(i=1;i<=hora;i++){
        if(nameriZloba(curr,i)>maxx){
            otg+=nameriZloba(curr,i-1);
            curr=i;
            l++;
            if(l==lodki){
                otg+=nameriZloba(curr,hora);
                return otg;
            }
        }
    }
    otg+=nameriZloba(curr,hora);
    return otg;
}

int main(){
    freopen("test.in","r",stdin);
    freopen("park_slow.out","w",stdout);
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    long long x,y,maxx=0,otg=-1,m,curr;
    cin>>hora>>lodki;
    for(x=1;x<=hora;x++){
        for(y=1;y<=hora;y++){
            cin>>vhod[x][y];
            zloba[x][y]=zloba[x-1][y]+vhod[x][y]+(zloba[x][y-1]-zloba[x-1][y-1]);
            maxx+=vhod[x][y];
        }
    }
    maxx/=2;
    for(m=0;m<=maxx;m++){
        curr=imaLiOtg(m);
        if(curr<otg or otg==-1){
            otg=curr;
        }
    }
    cout<<otg<<"\n";
    return 0;
}
