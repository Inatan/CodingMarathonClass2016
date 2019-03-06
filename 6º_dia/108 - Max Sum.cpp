#include <iostream>
using namespace std;

int main()
{
    int n,i,j,k,l,m;
    while(cin >> n){
        int array[n][n];
        
        int maxsum=-128;
        for (i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin >> array[i][j];

        for (l=0;l<n;l++){
            for(k=0;k<n;k++){
                int sum[n][n];
                int sumcol[n][n];
                for (i=l;i<n;i++){
                    for(j=k;j<n;j++){
                        if(i==l&&j==k){
                             sum[i][j]=array[i][j];
                            sumcol[i][j]=array[i][j];
                        }
                        else if(i==l){
                            sum[i][j]=sum[i][j-1]  + array[i][j];
                            sumcol[i][j]=array[i][j];
                        }
                        else if(j==k){
                            sum[i][j]=sum[i-1][j]  + array[i][j];
                            sumcol[i][j]=array[i][j]+sumcol[i-1][j];
                        }
                        else{
                            sum[i][j]=sum[i][j-1]  + array[i][j]+sumcol[i-1][j];
                            sumcol[i][j]=array[i][j]+sumcol[i-1][j];
                        } 
                           
                        if(maxsum<sum[i][j])
                            maxsum=sum[i][j];
                    }
                }
            }
        }
    cout<<maxsum<<endl;            
    }
          
}   