#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <typeinfo>

using namespace std;


int main()
{
    int caseNumber=1, n,i,j;
    bool found;
    string t,anwser,result,nospacet,nospaceans,space;
    bool outputerror,justspace;
    int numberofspacesT,numberofspacesAns;
    cin >> n;
    getline(cin,space);
    while(n){
            justspace=false;
            outputerror=false; 
            
            numberofspacesT=0;
            numberofspacesAns=0;
            getline(cin,anwser);
            getline(cin,t);
            nospacet=t;
            nospacet.erase(remove(nospacet.begin(),nospacet.end(),' '),nospacet.end());
            nospaceans=anwser;
            nospaceans.erase(remove(nospaceans.begin(),nospaceans.end(),' '),nospaceans.end());
            if(t==anwser){
                result="Yes";
            }
            else{
                
                if(anwser.find_first_not_of(' ') == string::npos || nospacet!=nospaceans){
                     result="Wrong Answer";
                }
                else{
                    if(anwser.length()>t.length())
                        result="Output Format Error";
                    else{
                        result="Wrong Answer";
                    }
                }
            }
            cout << "Case " <<caseNumber << ": " << result<< endl; 
            caseNumber++;
            n--;
       }
}