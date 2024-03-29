#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int a[N][N],b[N][N];

int n,m,q;
void insert(int x1,int y1,int x2,int y2,int v){
    b[x1][y1] += v;
    b[x2+1][y1] -=v;
    b[x1][y2+1] -=v;
    b[x2+1][y2+1] +=v; 
}

int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            insert(i,j,i,j,a[i][j]);
        }
    }
    int x1,x2,y1,y2,v;

    for(int i=0;i<q;i++){
        cin>>x1>>y1>>x2>>y2>>v;
        insert(x1,y1,x2,y2,v);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
            //b[i][j] += b[i][j-1] + b[i-1][j] - b[i-1][j-1];;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}