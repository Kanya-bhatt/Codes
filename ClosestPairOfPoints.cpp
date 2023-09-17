#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x;
    int y;
}P[3];
// Driver code
int main()
{
   
    for(int i = 0; i < 3; i++){
        cout << "enter the "<< i <<"th points" << endl;
        
        cin >> P[i].x >> P[i].y;
        
    }
    
    
    double d_min = INT_MAX;
    int ans_i, ans_j;
    
    for(int i = 0; i < 3 - 1; i++){
        for(int j = i+1; j < 3; j++){
            int x1 = P[i].x;
            int y1 = P[i].y;
            int x2 = P[j].x;
            int y2 = P[j].y;
            
            int d = sqrt(((x1 - x2)*(x1-x2)) + ((y1 - y2)*(y1-y2)));
            
            if(d_min > d){
                d_min = d;
                ans_i = i; 
                ans_j = j;
            }
            
        }
        
    }
    
    cout << "distance: " << d_min << "= i: " << ans_i << "= j: " << ans_j << endl; 
	return 0;
}
