#include <bits/stdc++.h>
using namespace std;


bool bfs(int rgraph[6][6], int s, int t, int parent[6]){
	int visited[6] = {0};
// 	for(int i = 0; i < 6; i ++){
// 	visited[i] = 0;
// }
	queue<int> q1;
	q1.push(s);
	visited[s] = 1;
	parent[s] = -1;
	while(!q1.empty()){
    	int u = q1.front();
    	q1.pop();
    	for(int v = 0; v < 6; v++){
        	if(visited[v] == 0 && rgraph[u][v] > 0){
            	if(v == t){
                	parent[v] = u;
                	return true;
            	}
            	q1.push(v);
            	visited[v] = 1;
            	parent[v] = u;
        	}
    	}
	}
	return false;
    
}

int fordFulkersom(int G[6][6], int s, int t){
	int rgraph[6][6];//residual graph
	for(int i = 0; i < 6; i++){
    	for(int j = 0; j < 6; j++){
        	rgraph[i][j] = G[i][j];
    	}
	}
	int parent[6];
	int max_flow = 0;
	while(bfs(rgraph, s, t, parent)){
    	int u;
    	int path_flow = INT_MAX;
    	for(int v = t; v != s; v = parent[v]){
        	u = parent[v];
        	path_flow = min(path_flow, rgraph[u][v]);
    	}
    	for(int v = t; v!=s; v = parent[v]){
        	u = parent[v];
        	rgraph[u][v] -= path_flow;
        	rgraph[v][u] += path_flow;
       	 
       	 
    	}
     	max_flow += path_flow;
	}
   
	return max_flow;
    
}

int main()
{
	int G[6][6] = {{0, 16, 13, 0, 0, 0},{0, 0, 10, 12, 0, 0},{0, 4, 0, 0, 14, 0},{0, 0, 9, 0, 0, 20},{0, 0, 0, 7, 0, 4},{0, 0, 0, 0, 0, 0}};
	cout << fordFulkersom(G, 0, 5) << endl;

	return 0;
}
