#include <iostream>
#include <stack>
#include <queue> 

using namespace std;

int main()
{
    int n,divisaX,divisaY,x,y;
    while(cin >> n && n>0){
        cin >> divisaX >> divisaY;
        while(n){
            cin >> x >> y;
            if(x==divisaX || y == divisaY){
                cout << "divisa" << endl;
            }else if(x>divisaX && y>divisaY){
                cout << "NE" << endl;
            }else if(x<divisaX && y<divisaY){
                cout << "SO" << endl;
            }
            else if(x<divisaX && y>divisaY){
                cout << "NO" << endl;
            }else{
                cout << "SE" << endl;
            }
            n--;
        } 
    }      
}
