#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int i,j,m,l,n,k,len,cost;
    while(cin >> l && l>0){ 
        cin >> n;
        int c[n+2];
        for(i=1;i<n+1;i++){
            cin >> c[i];
        }
        c[0]=0;
        c[n+1]=l;
        int cutcost[n+2][n+2];
        for(i=0;i<n+1;i++){
            cutcost[i][i+1]=0;
        }
        for(m=2;m<n+2;m++){
            for(i=0;i+m<n+2;i++){
                j=i+m;
                len=c[j]-c[i];
                cost=INT_MAX;
                for(k=i+1;k<j;k++){
                    cost=min(cutcost[i][k] + cutcost[k][j],cost);
                }
                cutcost[i][j]=cost+len;
            }            
        }
        cout << "The minimum cutting is " << cutcost[0][n+1] << "." << endl;
    }
    return 0;
}