#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int i,j,len1,len2;
    string s1, s2;
    bool found;
    while(getline(cin,s1)){
        getline(cin,s2);
        len1=s1.size();
        len2=s2.size();
        int subsequenceLen[len1+1][len2+1];
        for (i = 0; i <= len1; i++)
        {
            for (j = 0; j <= len2; j++)
            {
                if(j==0 || i==0){
                    subsequenceLen[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    subsequenceLen[i][j]=subsequenceLen[i-1][j-1]+1;
                }
                else{
                    subsequenceLen[i][j]=max(subsequenceLen[i][j-1],subsequenceLen[i-1][j]);
                }
            }
        }
        cout << subsequenceLen[len1][len2] << endl;
    }
    return 0;
}