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
        long long asdf=nameriZloba(curr,i);
        if(nameriZloba(curr,i)>maxx){
            otg+=nameriZloba(curr,i-1);
            curr=i;
            l++;
            if(l>lodki){
                return -1;
            }
        }
    }
    otg+=nameriZloba(curr,hora);
    return otg;
}

int main(){
    freopen("test.in","r",stdin);
    freopen("park_quick.out","w",stdout);
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    long long x,y,minn=10,maxx=0,otg=0;
    cin>>hora>>lodki;
    for(x=1;x<=hora;x++){
        for(y=1;y<=hora;y++){
            cin>>vhod[x][y];
            if(vhod[x][y]<minn and x!=y){
                minn=vhod[x][y];
            }
            /*if(x>y){
                vhod[x][y]=0;
            }*/
            zloba[x][y]=zloba[x-1][y]+vhod[x][y]+(zloba[x][y-1]-zloba[x-1][y-1]);
            maxx+=vhod[x][y];
        }
    }
    maxx/=2;
    while(minn+1<maxx){
        if(imaLiOtg((minn+maxx)/2)!=-1){
            maxx=(minn+maxx)/2;
        }else{
            minn=(minn+maxx)/2;
        }
    }
    otg=imaLiOtg(maxx);
    minn=imaLiOtg(minn);
    if(minn!=-1){
        otg=min(minn,otg);
    }
    //cout<<"-------\n";
    //imaLiOtg(3);
    cout<<otg<<"\n";
    return 0;
}
