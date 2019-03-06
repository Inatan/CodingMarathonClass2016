#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,m,i,j,excess,sum,halfsum;
    bool check;
    cin >> n;
    while(n--){
        cin >> m;
        int vals[m];
        sum=0; 
        for (i=0;i<m;i++){
            cin >> vals[i];
            sum += vals[i];
        } 
        halfsum=sum/2;
        int valsSum[halfsum+1], lastVals[halfsum+1];
        for(i=0; i<m; i++){
            for(j=0; j <= halfsum; j++)
            {   
                if(i==0 ){
                    if(vals[i] <= j)
                        valsSum[j]=vals[i];
                    else
                        valsSum[j]=0;
                }
                else if(vals[i] <= j)
                    valsSum[j] = max(lastVals[j], lastVals[j-vals[i]] + vals[i]);
            }
            for (j=0; j <= halfsum; j++)
                lastVals[j]=valsSum[j];
        }
        excess= sum!=0? sum-(2*valsSum[halfsum]):0;
        cout << excess << endl;
    
    }
    return 0;    
}      