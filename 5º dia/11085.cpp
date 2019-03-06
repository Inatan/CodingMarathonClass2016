#include <iostream>
#include <cmath>

#define SIZE 8

using namespace std;

bool valid(int row, int col, int *rowpos) {
    for(int j = 0; j < row; j++) {
        if(col == rowpos[j] || abs(row - j) == abs(col - rowpos[j])) 
            return false;
    }
    return true;
}
 
int search(int n , int* rowpos, int * queens) {
    if(n == SIZE) 
        return 0;
    int i,val, minMovesNumber = SIZE;
    for(i=0; i<SIZE; i++){
        if(valid(n, i,rowpos)) {
            rowpos[n] = i;
            val=search(n+1,rowpos,queens);
            if(i != queens[n]){
                val++;
            } 
            minMovesNumber=min(minMovesNumber, val);
        }
    }
    return minMovesNumber;
}

int main()
{
    int first,counter=0,i,casecounter=0;
    while(cin >> first){
        int queens[SIZE], rowpos[SIZE];
        counter=0;
        queens[0]= first-1; 
        rowpos[0] = queens[0];
        for(i=1; i<SIZE; i++) {
            cin >> queens[i];
            queens[i]--; 
            rowpos[i] = queens[i];
        }
        counter = search(0,rowpos,queens);
        casecounter++;
        cout << "Case " << casecounter <<": " << counter << endl;
    }
    return 0;    
}      