#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int p, int q) {
    if (q > p) 
        return (gcd(q,p));
    if (q == 0) 
        return(p);
    return(gcd(q, p % q) );
}

int main() {
    int i,j,maxgcd,testNumber,m,aux;
    string vecNumber;
    cin >> testNumber;
    getline(cin,vecNumber);
    while(testNumber--){
        getline(cin,vecNumber);
        istringstream splitvec(vecNumber);
        vector<int> v;
        while(splitvec>>aux){
            v.push_back(aux);
        }
        maxgcd = 0;
        for(i = 0;i<v.size();i++)
            for(j = i+1;j<v.size();j++)
                maxgcd = max(maxgcd,gcd(v[i],v[j]));
        cout<< maxgcd  << endl;
    }

}