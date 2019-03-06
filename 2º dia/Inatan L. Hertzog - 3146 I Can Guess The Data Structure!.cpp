#include <iostream>
#include <queue> 
#include <stack>

using namespace std;

int main()
{
    int n,j, i,op,data;
    bool qb,pqb,sb;
    while(cin >> n){  
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool qb=pqb=sb=true;
        for (i =0; i< n; i++){
            cin >> op >> data;
            if(!sb && !qb && !pqb)
                continue;
            else if(op==1){
                    q.push(data);
                    s.push(data);
                    pq.push(data);
            }
            else if(op ==2){
                if(qb){
                    if(!q.empty()  && q.front()==data)
                        q.pop();
                    else
                        qb=false;
                }
                if(sb){
                    if(!s.empty() && s.top()==data)
                        s.pop();
                    else
                        sb=false;
                }
                if(pqb){
                    if(!pq.empty() && pq.top()==data)
                        pq.pop();
                    else
                        pqb=false;
                }
            }
        }
        if(sb && !qb && !pqb)
            cout << "stack" << endl;
        else if (!sb && qb && !pqb)
            cout << "queue" << endl;
        else if (!sb && !qb && pqb)
            cout << "priority queue" << endl;
        else if(!sb && !qb && !pqb)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;   
    }
    return 0;
}