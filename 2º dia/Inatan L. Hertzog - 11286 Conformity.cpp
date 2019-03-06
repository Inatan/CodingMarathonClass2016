#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>


using namespace std;

int main()
{
    int n,j, i,maxqnt,qnt;
    
    while(cin >> n && n>0){  
        map <vector<int>,int> m;
        for (i =0; i< n; i++){
            vector<int> v(5);
            for(j=0;j<5;j++){
                cin >> v[j];
            }
            sort(v.begin(),v.end());
            m[v]++;
        }
        maxqnt=0;
        qnt=0;
        for (map <vector<int>,int>::iterator  it=m.begin(); it!=m.end(); ++it){
        	if(it->second == maxqnt )
        	{
        		qnt++;
        	}
        	else if(it->second > maxqnt){
        		qnt=1;
        		maxqnt = it->second;
        	}
        	
        }
        //cout  << endl;
        cout << maxqnt*qnt << endl;
    }
    return 0;
}

