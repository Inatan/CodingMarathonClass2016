#include <iostream>

using namespace std;

int pow(int n,int mod){
    bool passed=false;
    long long FibMatrix[2][2]={1,1,1,0}, answer[2][2]={1,0,0,1};
    long long aux[2][2];
    if(n == 0) 
        return 0;
    if(n == 1) 
        return 1%mod;
    while(n != 0){
        if(n & 1){
            long long aux[2][2];
            passed=true;
            for(int i = 0;i < 2;i++)
                for(int j = 0;j < 2;j++){
                    aux[i][j]=answer[i][j];
                    answer[i][j]=0;
                }
            for(int i = 0;i < 2;i++)
                for(int j = 0;j < 2;j++)
                    for(int k = 0;k < 2;k++)
                        answer[i][k] = (answer[i][k] + aux[i][j] * FibMatrix[j][k]) % mod;
        }
        n >>= 1;
        for(int i = 0;i < 2;i++)
                for(int j = 0;j < 2;j++){
                    aux[i][j]=FibMatrix[i][j];
                    FibMatrix[i][j]=0;
                }
            for(int i = 0;i < 2;i++)
                for(int j = 0;j < 2;j++)
                    for(int k = 0;k < 2;k++)
                        FibMatrix[i][k] = (FibMatrix[i][k] + aux[i][j] * aux[j][k]) % mod;
    }
    if(passed)
        return answer[0][1];
    else
        return FibMatrix[0][1];
}

int main(){
    int n,m;
    while(cin >> n >> m){
        int mod = (1 << m);
        cout << pow(n,mod) << endl;
    }
    
    return 0;
}