#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

vector<vii> adjMatrix;
vi dfs_num,order;  


void dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
  dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
  for (int j = 0; j <AdjList[u].size(); j++) {
    ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
      dfs(v.first);      // recursively visits unvisited neighbors v of vertex u
    order.push_back(u);
} }


int main()
{
    int m,n,i,j,t1,t2,maxI;
    while(cin >> n >> m>){
        map<int, int> mapper;
       // int adjMatrix[n][n];
        int importance[n];
        for(i=0;i<n;i++){
            importance[i]=0;
            for(j=0;j<n;j++)
                adjMatrix[i][j]=0;
        }
        for(i=0;i<m;i++){
            cin >> t1 >> t2;
            adjMatrix[t1][t2]= 1;
            adjMatrix[t2][t1]= -1;
        }
        for(i=0;i<n;i++)
            if(dfs_num[x] == DFS_WHITE)
                dfs(x);

    reverse(order.begin(), order.end());
    for(i=0;i<n;i++)
    {
           cout << answer[i]+1 << " ";
    }
    cout << endl;
    answer.clear();
        
    }
    return 0;
          
}   