#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int n,counter=0,pegsnumber,i;
    cin >> n;
    bool finish,pass;
    while(n--){
        counter=1;
        cin >> pegsnumber;
        finish=false;
        vector<int>v(pegsnumber,0);
        float val1, val2;
        
        while(!finish){
            pass=false;
            for(i=0; i<pegsnumber && !pass; i++)
            {
                val1=(float)counter;
                val2=(float)v[i];
                //cout << "Square value :" << sqrt(val1 + val2) <<  " " << val1 << " + " << val2  <<endl;
                if(v[i]==0 || round(sqrt(val1 + val2)) == sqrt(val1 + val2)){
                    
                    //cout << "counter value: "<< counter<< " last value: " << v[i] << " in peg: " << i+1<< endl;
                    v[i]=counter;
                    pass= true;
                    counter++;
                }
                if(counter == INT_MAX) {
                    finish=true;
                    counter = -1;
                }
                else if(!pass && i==(pegsnumber-1) )
                    finish=true;
                
            }
        }
        cout << counter-1 << endl;
    }     
}      