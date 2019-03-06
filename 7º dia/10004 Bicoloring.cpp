#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
    int n,vertex,edgesNumber,i,j,neighbor1pos,neighbor2pos;
    bool bicolor;
    while(cin >> n && n>0){
        cin >> edgesNumber;
        int color[n];
        queue<int> Qvertex;
        vector<int> neighbor[n];
        for(i=0;i<n;i++){
            color[i]=0;
        }

        bicolor=true;
        for(i=0;i<edgesNumber;i++){
            cin >> neighbor1pos >> neighbor2pos;
            neighbor[neighbor1pos].push_back(neighbor2pos);
            neighbor[neighbor2pos].push_back(neighbor1pos);
        }
        Qvertex.push(0);
        while(!Qvertex.empty() && bicolor){
            vertex=Qvertex.front();
            Qvertex.pop();
            edgesNumber=neighbor[vertex].size();
            for(i=0;i<edgesNumber && bicolor;i++)
            {
                if(color[neighbor[vertex][i]]==0)
                {
                    if(color[vertex]==1)
                        color[neighbor[vertex][i]]=2;
                    else
                        color[neighbor[vertex][i]]=1;
                    Qvertex.push(neighbor[vertex][i]);
                }
                else
                {
                    if(color[neighbor[vertex][i]]==color[vertex])
                    {
                        bicolor=false;
                    }
                }
            }
        }
        
     
        if(bicolor)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
          
}   

   /*for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                if(neighborhood[i][j]){
                    if(color[i]==0 && color[j]==0){
                        color[i]=1;
                        color[j]=2;
                    }else if(color[i]==0){
                        color[i] = color[j]==2? 1:2;
                    }else if(color[j]==0){
                        color[j] = color[i]==2? 1:2;
                    }else if(color[i] == color[j]){
                        bicolor=false;
                    }
                }
            }
            
        }*/