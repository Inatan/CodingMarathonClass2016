#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <typeinfo>

using namespace std;


int main()
{
    string t,lastword,text="",textaux="";
    bool partword;
    char lastchar;
    map<string,int, less<string> > dict;
    while(getline(cin,t)){
        text+=t+"\n";
    }
    for (string::iterator it=text.begin(); it!=text.end(); ++it)
        {
            if (((*it) >= 'a' && (*it) <= 'z' )|| ((*it) >= 'A' && (*it) <= 'Z') || (*it)=='-' ) {
                textaux+=tolower(*it);    
            }
            else
                textaux+=" ";
            lastchar=(*it);
        }

    istringstream iss(textaux);
    string word;
    lastword="";
    partword=false;
    while(iss >> word) {
        
        if(word[word.size()-1]=='-' && word.size()!=1){
            word.erase(word.size()-1);
            lastword +=word;

            partword=true;
        }
        else if(partword=true){
            if(word[0]=='-' && lastword.size()>0){ 
                dict[lastword+'-']++;
            }
            else{               
                word = lastword+word;
            }
            if(word!="-"){
                dict[word]++;
            }
            partword=false;
            lastword="";
            
        }
        else
            dict[word]++;

    }
    for (map <string,int>::iterator  it=dict.begin(); it!=dict.end(); ++it){
        cout << it->first << endl;
    }
}

