#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a,b;
    int i,j,last;
    bool found;
    while(getline(cin,a) && getline(cin,b)){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        j=0;
        last=0;
        for(i=0;i<a.size() && last<b.size();i++){
            found=false;
            while(j<b.size() && !found){
                if(a[i]==b[j] && a[i]!=' '){
                    cout << a[i];
                    found=true;
                }
                j++;
            }
            if((j==b.size() && found)|| j<b.size()){
                last=j;
            }else
                j=last;
        }
        cout << endl;
    }

}