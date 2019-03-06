#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int* initgrid(int* grid){
    for(int i =0;i<100;i++)
    {
        grid[i]=0;
    }
    return grid;
}

int main()
{
    int a,b,c, j,tests,bottomsl,topsl, grid[100],rolled,count=1;
    grid=initgrid(grid);
    while(cin >> tests){
        cin >> a >> b >> c;
        for(int i=0; i< b; i++)
        {
            cin >> bottomsl >> topsl;
            grid[bottomsl]=count;
            grid[topsl]=count+100;
            count++;
        } 
        for(i=0;i<c;i++)
        {
            cin >> rolled;
            if(grid[rolled]!=0)
            {
                j=rolled;
                while
            }
        }  

        
    }


}
