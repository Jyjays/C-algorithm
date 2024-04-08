// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #define int long long
// using namespace std;

// int g[20][21];
// int f[20][21];
// bool check(int h,int w,int i,int j){
//     int dx = i-h,dy = j-w;
//     int tx = dx,ty = dy;
//     while(dx<20&&dy<21){
//         if(f[h+dx][w+dy]){
//             return false;
//         }
//         f[h+dx][w+dy] = 1;
//         dx+=tx,dy+=ty;
//     }
//     return true;
// }
// int find(int h,int w){
//     int res =0;
//     memcpy(f,g,sizeof g);
//     for(int i=0;i<20;i++){
//         for(int j=0;j<21;j++){
//             if(!f[i][j]&&check(h,w,i,j)){

//                 res++;

//             }
//         }
//     }
//     return res;
// }
// signed main(){
//     int res=0;
//     for(int i=0;i<20;i++){
//         for(int j=0;j<20;j++){
//             g[i][j] = 1;
//             res+=find(i,j);
//         }
//     }
//     cout<<res;
//     return 0;
// }
#include <iostream>
#include <set>
using namespace std;

int main()
{
    double k,b;
    set<pair<double, double>> s;
    for (int x1 = 0; x1 < 20; x1++)
    {
        for (int y1 = 0; y1 < 21; y1++)
        {
            for (int x2 = x1+1; x2 < 20; x2++)
            {
                for (int y2 = 0; y2 < 21; y2++)
                {
                    //if (x1 != x2)
                    {
                        k=(double)(y1-y2)/(x1-x2);
                        b=(double)(x1*y2-x2*y1)/(x1-x2);
                        s.insert({k, b});
                    }
                }
            }
        }
    }
    cout<<s.size()+20;
    return 0;
}
