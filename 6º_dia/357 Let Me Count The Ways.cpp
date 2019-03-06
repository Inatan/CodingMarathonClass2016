#include <iostream>
#define SHORTLIMIT 32767
using namespace std;

int main()
{
    int n,cents[5] = {1,5,10,25,50};
    int i,j;
    long long int possibility[SHORTLIMIT];
    possibility[0] = 1;
    for (i=0; i<5; i++)
        for (j=cents[i]; j<SHORTLIMIT; j++)
            possibility[j] += possibility[j - cents[i]];
    while(cin >> n){
        if(possibility[n]>1)
            cout << "There are " << possibility[n] << " ways to produce " << n << " cents change." << endl;
        else
            cout << "There is only " << possibility[n] << " way to produce " << n << " cents change." << endl;
    }
    return 0;    
}      