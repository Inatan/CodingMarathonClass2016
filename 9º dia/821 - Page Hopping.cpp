#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int distances[101][101];
    int sum,i,j,K,N,possibilities,casetest=0;;
    float result;
    while(cin >> N >> K && !(N == 0 && K==0)){
        sum=0;
        casetest++;
        for(i = 0; i < 101; i++)
            for(j = 0; j < 101; j++){
                if(i == j) 
                    distances[i][j] = 0;
                else 
                    distances[i][j] = 101;
            }
        vector<int> vec;
        vec.push_back(N);
        vec.push_back(K);
        distances[N][K] = 1;
        while(cin >> N >> K && !(N == 0 && K==0)){
            vec.push_back(N);
            vec.push_back(K);
            distances[N][K] = 1;
        }
        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        for (vector<int>::iterator kt = vec.begin() ; kt != vec.end(); ++kt){
            for (vector<int>::iterator it = vec.begin() ; it != vec.end(); ++it){
                for (vector<int>::iterator jt = vec.begin() ; jt != vec.end(); ++jt){
                    distances[*it][*jt] = min(distances[*it][*jt], distances[*it][*kt] + distances[*kt][*jt]);
                }
            }
        }
        for (vector<int>::iterator it = vec.begin() ; it != vec.end(); ++it){
            for (vector<int>::iterator jt = vec.begin() ; jt != vec.end(); ++jt){
                if(*it != *jt){
                    sum+=distances[*it][*jt];
                }
            }
        }
        possibilities= vec.size() * (vec.size()-1);
        result= (float)sum/possibilities;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(3);
        cout << "Case "<<casetest <<": average length between pages = " << result << " clicks" << endl;
    }

}