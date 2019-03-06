#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
#include <queue> 
#include <stack>

#define STACK 1
#define QUEUE 2
#define PRIORITY_QUEUE 3
#define IMPOSSIBLE 4
#define NOT_SURE 5 

using namespace std;

int main()
{
    int n,j, i,type,typeaux,count,data,lastdata,num;
    bool qb,pqb,sb;

    while(cin >> n && n>0){  
        type=0,typeaux=0;;
        count=1;
        map <int,int> m;
        queue<int> q;
        priority_queue<int,int> pq
        num=1;
        lastdata=0;
        bool firsttime=false, priority=true;
        for (i =0; i< n; i++){
            vector<int> v(2);
            for(j=0;j<2;j++){
                cin >> v[j];
            }
            if(v[0]==1){
                m[v[1]]=count;
                count++;
                if(lastdata<v[1]){
                    lastdata=v[1]+1;
                }
            }
            else if(v[0]==2){
                q.push(v[1]);
                data=v[1];
                if(m[data]==0){
                    type=IMPOSSIBLE;
                } else if( m.size()!=1){                               
                    if(m[data]==num && type!=STACK){
                        type=QUEUE;
                        typeaux=QUEUE;
                    }
                    else if(m[data] == count-num){
                        type=STACK;
                        typeaux=STACK;
                        m.erase(data);
                        count--;
                        num--;
                    }
                    if( lastdata-1==data && priority ){
                        if((type==QUEUE || type==STACK || m.size()==1)  )
                            type=NOT_SURE;
                        else{
                            type=PRIORITY_QUEUE;
                        }
                        m.erase(data);
                        data=0;
                        for(map <int,int>::iterator  it=m.begin(); it!=m.end(); ++it){
                            if(it->first>=data)
                                data=it->first+1;
                        }
                    }
                    else
                    {
                        priority=false;
                        if(type==NOT_SURE)
                            type=typeaux;
                    }
                    num++;
                    lastdata=data;
                } else {
                        type=NOT_SURE;
                        m.erase(data);
                        count--;
                }
            }
        }
        if(type == STACK)
            cout << "stack" << endl;
        else if (type == QUEUE)
            cout << "queue" << endl;
        else if (type == PRIORITY_QUEUE)
            cout << "priority queue" << endl;
        else if(type == IMPOSSIBLE)
            cout << "impossible" << endl;
        else if(type == NOT_SURE)
            cout << "not sure" << endl;
        
    }


    return 0;
}

