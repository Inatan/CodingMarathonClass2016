#include <iostream>
#include <string>
#include <cstdio>

#define WEST 1
#define SOUTH 2
#define EAST 3
#define NORTH 4

using namespace std;

int walkx(int player_x, int player_direction)
{
    if(player_direction==WEST)
        player_x--;
    else if(player_direction==EAST)
        player_x++;
    return player_x;
}

int walky(int player_y, int player_direction)
{
    if(player_direction==NORTH)
        player_y--;
    else if(player_direction==SOUTH)
        player_y++;
    return player_y;
}

int turnleft(int player_direction)
{
    if(player_direction==WEST)
        player_direction=SOUTH;
    else if(player_direction==SOUTH)
        player_direction=EAST;
    else if(player_direction==EAST)
        player_direction=NORTH;
    else if(player_direction==NORTH)
        player_direction=WEST;
    return player_direction;
}

int main()
{
    int b,w,i,j,robot,ztimes,otimes,ttimes,thtimes,ftimes,zeros,player_direction,player_x,player_y, source_x,source_y;
    bool eog,firsttime;
    char answer[3];
    while(cin >> b >> w && (b!=0 || w!=0)) {
        player_x=0;
        source_x=0;
        ztimes=0;
        otimes=0;
        ttimes=0;
        thtimes=0;
        ftimes=0;
        eog=false;
        firsttime=true;
        player_direction=EAST;
        player_y=b-1;
        source_y=b-1;
        int grid[b][w];
        char line[w];
        for(i=0;i<b;i++){
            cin >> line;
            for(j=0;j<w;j++){
                grid[i][j]= line[j] -'0';
            }
        }
        while(!eog){    
            if(player_direction==NORTH){
                if(player_y!=b-1 && player_x!=w-1 && grid[player_y+1][player_x+1]==1 &&  grid[player_y][player_x+1]!=1){
                    player_direction=EAST;
                    player_x=walkx(player_x,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else if( player_y!=0 && grid[player_y-1][player_x]!=1 && (player_x==0 || player_x==w-1 || grid[player_y][player_x+1]==1)){
                    player_y=walky(player_y,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else
                    player_direction= turnleft(player_direction);
            }
            else if(player_direction==SOUTH){
                if(player_y!=0 && player_x!=0 && grid[player_y-1][player_x-1]==1 && grid[player_y][player_x-1]!=1){
                    player_direction=WEST;
                    player_x=walkx(player_x,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else if( player_y!=b-1 && grid[player_y+1][player_x]!=1 && (player_x==0 || player_x==w-1 || grid[player_y][player_x-1]==1 )){
                    player_y=walky(player_y,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else
                    player_direction= turnleft(player_direction);
            }
            else if(player_direction==EAST){
                if (player_x!=0 && player_y!=b-1 && grid[player_y+1][player_x-1]==1 && grid[player_y+1][player_x]!=1){
                    player_direction=SOUTH;
                    player_y=walky(player_y,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else if( player_x!=w-1 && grid[player_y][player_x+1]!=1  && (player_y==0 || player_y==b-1 ||  grid[player_y+1][player_x]==1)){
                    player_x=walkx(player_x,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else
                    player_direction= turnleft(player_direction);
            }
            else if(player_direction==WEST){
                if (player_x!=w-1 && player_y!=0 && grid[player_y-1][player_x+1]==1 && grid[player_y-1][player_x]!=1){
                    player_direction=NORTH;
                    player_y=walky(player_y,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else if( player_x!=0 && grid[player_y][player_x-1]!=1 && (player_y==0 || player_y==b-1|| grid[player_y-1][player_x]==1)){
                    player_x=walkx(player_x,player_direction);
                    firsttime=false;
                    if(grid[player_y][player_x]==0)
                        grid[player_y][player_x]=2;
                    else
                        grid[player_y][player_x]++;
                }
                else
                    player_direction= turnleft(player_direction);
            }
            if(player_x==source_x && player_y==source_y && !firsttime)
                eog=true;
        }
        for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if(grid[i][j]==0)
                        ztimes++;
                    else if(grid[i][j]==2)
                        otimes++;
                    else if(grid[i][j]==3)
                        ttimes++;
                    else if(grid[i][j]==4)
                        thtimes++;
                    else if(grid[i][j]==5)
                        ftimes++;
                }
            }

        
        printf("%3d%3d%3d%3d%3d\n",ztimes,otimes,ttimes,thtimes,ftimes);
    }
    return 0;
}
