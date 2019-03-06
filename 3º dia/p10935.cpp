#include <iostream>
#include <stack>
#include <queue> 

using namespace std;

int main()
{
    int n,toptobottom;
    while(cin >> n && n>0){
        stack<int> deck,auxdeck;
        queue<int> discarted;
            for(int i=n; i>0;i--)
                deck.push(i);
        while(deck.size()!=1){
            discarted.push(deck.top());
            deck.pop();
            if(deck.size()>1){
                toptobottom = deck.top();
                deck.pop();
                //cout << toptobottom << endl;
                while(!deck.empty())
                {
                    auxdeck.push(deck.top());
                    deck.pop();
                }
                deck.push(toptobottom);
                while(!auxdeck.empty())
                {
                    deck.push(auxdeck.top());
                    auxdeck.pop();
                }
            }

        }
        cout << "Discarded cards:";
        if(!discarted.empty()){
            cout << " "<<discarted.front();
            discarted.pop();
        }
        while(!discarted.empty())
        {              
            cout << ", " << discarted.front();
            discarted.pop();
        }
        cout << endl << "Remaining card: " << deck.top()<< endl;

    }
    return 0;
}

