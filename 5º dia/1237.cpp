#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,databaseSize,queryNumber,i,j;
    int counter,modelpos;
    cin >> n;
    while(n--){
        cin >> databaseSize;
        string M[databaseSize];
        int L[databaseSize],H[databaseSize];
        for(i=0; i<databaseSize; i++) {
            cin >> M[i] >> L[i] >> H[i];
        }
        cin >> queryNumber;
        int queryValue;
        for(i=0; i<queryNumber; i++){
        	cin >> queryValue;
        	counter=0;
        	for (j = 0; j < databaseSize && counter !=2; j++)
        	{
        		if(queryValue >= L[j]  && queryValue <= H[j]){
        			counter++;
        			modelpos=j;
        		}
        	}
        	if(counter==1)
        		cout << M[modelpos] <<endl;
        	else
        		cout << "UNDETERMINED" <<endl;
        }
        if(n)
        	cout <<endl;
    }
    return 0;    
}      