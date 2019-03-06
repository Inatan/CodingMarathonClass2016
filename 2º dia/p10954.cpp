#include <iostream>
#include <queue> 

using namespace std;

int main()
{
    int n,i,sum,val,cost;
    
    while(cin >> n && n>0){  
        priority_queue<int, vector<int>, greater<int> > queue;
        cost = 0;  
        for(i=0;i<n;i++) {
            cin >> val; 
            queue.push(val);
        }
        
        while (queue.size() > 1) {
            sum = queue.top();  queue.pop();
            sum += queue.top();  queue.pop();
            cost += sum;
            queue.push(sum);
        }
        cout << cost << endl;
    }
    return 0;
}
