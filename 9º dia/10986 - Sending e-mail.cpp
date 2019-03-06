#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int testnumber,ms,md,i,j,w,m,n,S,T,result,casetest=0;
    bool finish;
    cin >> testnumber;
    while(testnumber--){
        casetest++;
        result=-1;
        cin >> n >> m >> S >> T;
        vector<vector<pair<int,int> > > latency(n,vector<pair<int,int> >());
        for(i=0;i<m;i++){
            cin >> ms >>md >> w ;
            //if(latency[ms][md].second == 0 || w < latency[ms][md].second){
                latency[ms].push_back(make_pair(md,w));
                latency[md].push_back(make_pair(ms,w));
        }
        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
        vector< int > d(n, -1);
        pair<int,int> p; 
        int v;
        finish = false;
        q.push( make_pair(0,S) );
        while (!q.empty() && !finish){
            p = q.top(); 
            q.pop();
            v = p.second;
            result = p.first;
            if ( d[v] != -1 ) {
                continue;
            }
            if (v != T) {                    
                d[v] = w;
                for (int i = 0; i <  latency[v].size(); i++){
                    if ( d[ latency[v][i].first ] == -1 || d[ latency[v][i].first ]  > result+latency[v][i].second){
                        q.push( make_pair(result+latency[v][i].second,latency[v][i].first) );
                    }
                }
            }
            else{
                finish=true;
            }
        }

        if(! finish)
            cout << "Case #"<<casetest <<": unreachable" << endl;
        else
            cout << "Case #"<<casetest <<": " << result << endl;
    }

}