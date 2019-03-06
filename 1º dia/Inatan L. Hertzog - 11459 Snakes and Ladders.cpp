#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    int a,b,c,k,i,tests,bottomsl,topsl,rolled;
    bool endgame;
    while(cin >> tests) {
        for(k=0;k<tests;k++){
            cin >> a >> b >> c;
            vector<int> grid(101,0), players(a,1);
            for(i=0; i< b; i++)
            {
                cin >> bottomsl >> topsl;
                grid[bottomsl]=topsl;
            } 
            endgame=false;
            for(i=0;i<c;i++)
            {   
                cin >> rolled;
                if(!endgame)
                {
                    players[i%a] = min(100,rolled+players[i%a]);
                    if(grid[players[i%a]]>0)
                        players[i%a]=min(100,grid[players[i%a]]);
                    if(players[i%a]==100)
                        endgame=true;
                }
            }  
            for(i=0;i<a;i++)
                cout << "Position of player " << i+1 << " is " << players[i] <<".\n";
        }
    }
    return 0;
}
