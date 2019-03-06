#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
    int test,n,peaple,j,i,maxc,sum,k;
    bool bicolor;
    cin >> test;
    while(test--){
        cin >> n;
        int p[n],w[n];
        maxc=0;
        for(i=0;i<n;i++)
            cin >> p[i] >> w[i];
        cin >> peaple;
        int pw[peaple];
        sum=0;
        for(i=0; i<peaple;i++){
            cin >> pw[i];
            if(maxc<pw[i])
                maxc=pw[i];
        }
        vector<int> cw(maxc+1,0), acw(maxc+1,0);
        vector<int> sp(maxc+1,0);


        for(i=0; i<n; i++){
            for(j=0; j <= maxc; j++)
            {   
                if(i==0){
                    if(w[i] <= j){
                        cw[j]=w[i];
                        sp[j]+=p[i];
                    }
                }
                else if(w[i] <= j){
                    cw[j] = max(acw[j], acw[j-w[i]] + w[i]);
                    if(acw[j]==cw[j])
                        sp[j]+=p[i];
                }
                cout << cw[j] << "  ";
            }
            cout << endl;
            for (j=0; j <= maxc; j++)
                acw[j]=cw[j];
        }
        for(i=0; i<peaple; i++)
            sum+=sp[pw[i]];
        cout << sum << endl;

    }
    return 0;
          
}