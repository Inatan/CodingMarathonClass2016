#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

typedef vector<int> vi;

int main() {
    int namePos, caseNum = 1,i,j,N,M;
    string name, B1, B2;
    while (cin >> N) {
        namePos = 0;
        map<int, string> namesIndex;
        map<string, int> beverages;
        vector<vi> edges(N);
        vi alcoholicLevel(N,0);
        bool contains,done;
        for (i = 0; i < N; i++) {
            cin >> name;
            beverages[name] = namePos;
            namesIndex[namePos++] = name;
        }
        cin >> M;
        for (i = 0; i < M; i++) {
            cin >> B1 >> B2;
            edges[beverages[B1]].push_back(beverages[B2]);
            alcoholicLevel[beverages[B2]]++;
        }
        cout << "Case #"<< caseNum <<": Dilbert should drink beverages in this order:";
        caseNum++;
        i = 0;
        while(i < N) {
            if (alcoholicLevel[i] == 0) {
                alcoholicLevel[i]--;
                cout << " "<< namesIndex[i].data() ;
                for (j = 0; j < edges[i].size(); j++) {
                    alcoholicLevel[edges[i][j]]--;
                }
                i=0;
            } else 
                i++;
        }
        cout <<"." <<endl << endl;
    }
    return 0;
}