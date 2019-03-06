#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int set,n,s,q,i,j,count,val,minutes;
    bool finished;
    cin >> set;
    while (set){
        minutes=0;;
        finished = false;
        cin >> n >> s >> q;
        vector<queue<int> > stations(n);
        vector<bool> clear(n,false);
        stack<int> carrier;

        for(i=0;i<n; i++){
            cin >> count;
            for(j=0;j<count;j++){
                cin >> val;
                stations[i].push(val);
            }
        }
        i=0;

        while (!finished){
            while (!carrier.empty()  && (carrier.top() == i+1 || stations[i].size() < q)) {
                if (carrier.top() != i+1) {
                    stations[i].push(carrier.top());
                }
                carrier.pop();
                minutes++;
            }
            while (!stations[i].empty() && carrier.size() < s) {
                carrier.push(stations[i].front());
                stations[i].pop();
                minutes++;
            }
            if(stations[i].empty())
                clear[i]=true;
            if(carrier.empty())
                finished=true;
            for (j = 0; j < n && finished; j++) {
                if(!finished || !clear[j])
                    finished=false;
            }
            if (!finished){
                i = (i+1) % n;
                minutes += 2;
            }
        } 

        cout << minutes << endl;
        set--;
    }
    return 0;
}
