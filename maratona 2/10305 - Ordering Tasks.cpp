#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef vector<int> vi; 

vector<vi> adjMatrix;
vi dfsVal,order;  


void dfs(int u) {      
  dfsVal[u] = DFS_BLACK; 
  for (int j = 0; j <adjMatrix[u].size(); j++) {                    
    if (dfsVal[adjMatrix[u][j]] == DFS_WHITE)      
      dfs(adjMatrix[u][j]);  
    }
    order.push_back(u);
}


int main()
{
    int m,n,i,t1,t2;
    while(cin >> n >> m){
        adjMatrix.assign(n, vi());
        dfsVal.assign(n, DFS_WHITE);
        for(i=0;i<m;i++){
            cin >> t1 >> t2;
            t1--;
            t2--;
            adjMatrix[t1].push_back(t2);
        }
        for(i=0;i<n;i++){
            if(dfsVal[i] == DFS_WHITE){
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        for(i=0;i<order.size();i++)
        {
            cout << order[i]+1 << " ";
        }
        cout << endl;
        order.clear();
    }
    return 0;
          
}   