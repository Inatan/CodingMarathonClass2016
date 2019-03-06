#include <iostream>
#include <cmath>

using namespace std;


bool isprime(int n)
{
    int i, squareroot;
    if (n >  1) {
        squareroot = (int) sqrt((double) n);
        for(i = 3; i <= squareroot; i = i + 2) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    } 
    else
    {
        return false;
    }
}

int main() {
    int i,num,testNumber,a,b;
    while(cin >> num && num > 0){
        i=1;
        do{
            i+=2;
            a=i;
            b=num-i;
        }
        while(!(isprime(b)&& isprime(a)));
        cout<< num<< " = " << a << " + " << b  << endl;
    }
}