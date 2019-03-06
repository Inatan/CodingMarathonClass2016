#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int testnumber,X,Y,i,j,C,M,N,A,result,casetest=0,count,currentNode;
    bool finish;
    cin >> testnumber;
    while(testnumber--){
        casetest++;
        count=0;
        result=-1;
        cin >> N >> M >> A;
        vector<vector<pair<int,int> > > locations(N,vector<pair<int,int> >());
        for(i=0;i<M;i++){
            cin >> X >> Y >> C ;
            if(C<A){
                locations[X-1].push_back(make_pair(Y-1,C));
                locations[Y-1].push_back(make_pair(X-1,C));
            }
        }  
        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
        vector<bool> vis(N);
        pair<int,int> p; 
        int v,w; 
        currentNode=0;
        result = 0;
        finish=false;
        while(!finish){
            q.push( make_pair(0,currentNode) );
            count++;
            while (!q.empty())
            {
                p = q.top(); 
                q.pop();
                v = p.second;
                w = p.first;

                if (vis[v]) 
                    continue;
                vis[v] = true;
                result += w;
                //cout << v << " - " << w << endl;
                for (i = 0; i < locations[v].size(); ++i){
                    if ( !vis[ locations[v][i].first ] ){
                       // cout << locations[v][i].second<<" - " <<locations[v][i].first << endl;
                        q.push( make_pair( locations[v][i].second, locations[v][i].first ) );
                    }
                }          
            }
            finish=true;
            for(i=0;i<N && finish;i++){
                if(!vis[i]){
                    finish=false;
                    currentNode=i;  
                }
            }
           // cout << count <<" - "<< result <<endl;
        }
        cout << "Case #"<<casetest <<": " << result+(A*count)<< " " << count << endl;
    }

}