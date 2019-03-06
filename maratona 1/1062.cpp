#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <typeinfo>
#include <stack>

using namespace std;


int main()
{
    int caseNumber=1, counter=0,i;
    bool found;
    string t;
    while(getline(cin,t)){
        if(t!="end"){
            stack<char> stacks[1000];
            counter=0;
            reverse(t.begin(),t.end());

            for (string::iterator it=t.begin(); it!=t.end(); ++it)
            {
                found=false;
                if (((*it) >= 'a' && (*it) <= 'z' )|| ((*it) >= 'A' && (*it) <= 'Z')) {
                    //cout << (*it);
                    for(i=0;i<1000 && !found; i++)
                    {
                        if(stacks[i].empty())
                        {
                            stacks[i].push(*it);
                            counter++;
                            found=true;
                        }
                        if(stacks[i].top() <= (*it)){
                            stacks[i].push(*it);
                            found=true;
                        }
                    }

                }
            }
            cout << "Case " <<caseNumber << ": " << counter<< endl; 
            caseNumber++;
        }
    }
}