#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int n,b,h,w,p,a, price,beds, minprice;
    bool space,gohome=false;

    while (cin >> n >> b >> h >> w){
        minprice=b+1;
        for( int i= 0; i< h; i++)
        {
            cin >> p;
            price=p*n;
            space=false;
            for (int j=0; j<w; j++)
            {
                cin >> beds;
                if(beds>=n)
                {
                    space=true;
                }
            }
            if(minprice > price && space)
                minprice=price;
                gohome=false;
            if(!space){
                gohome=true;
            }
        }
        if(minprice > b)
        {
            gohome=true;
        }
        if(!gohome)
            cout << minprice << endl;
        else
            cout << "stay home" << endl;
    }
    return 0;
}
