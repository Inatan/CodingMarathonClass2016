#include <iostream>

using namespace std;

int main()
{
    int n,val,maximum=0,minimun=0,counter=0,,i;
    while(cin >> n && n>0){
        counter=0;
        for(i=0;i<n;i++){
            cin >> val;
            if(i==n)
                maximum=val;
                minimun=val;
                //counter++;
            }
            if(maximum<=val){
                maximum=val;
                counter++;
            }
            if(minimun>=val){
                maximum=val;
                counter++;
            }
            cout << counter << endl;
    }     
}      