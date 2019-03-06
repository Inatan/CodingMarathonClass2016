#include <iostream>

using namespace std;

int main() {
    int i,j,N,K;
    unsigned int cases[100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if(j==0){
                cases[i][j]=1;
            }
            else if(i==0){
                cases[i][j]=j+1;
            }else
                cases[i][j] = (cases[i-1][j] + cases[i][j-1])% 1000000 ;
        }
    }
    while(cin >> N >> K && N>0 && K>0) 
        cout << cases[N-1][K-1] << endl;
    return 0;
}