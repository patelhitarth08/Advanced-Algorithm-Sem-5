 #include<bits/stdc++.h>

using namespace std;
 

int n;


bool bfs(vector<vector<int>> &rgraph , int s ,int t , vector<int> &parent)
{
	vector<int> vis(n,0);
	queue<int> q;
	q.push(s);
	vis[s]=1;
	parent[s]=-1;

	while(q.size() !=0)
	{
    	int u = q.front();
    	q.pop();

    	for(int v= 0 ; v<n;v++)
    	{
        	if(vis[v]==0 && rgraph[u][v]>0)
        	{
            	if(v==t)
            	{
                	parent[v]=u;
                	return true;
            	}
            	q.push(v);
            	vis[v]=1;
            	parent[v]=u;
        	}
    	}
	}

	return false;
}


int ford(vector<vector<int>> &graph , int s,int t)
{
	vector<vector<int>> rgraph(n,vector<int> (n,0));

	for(int i=0;i<n;i++)
	{
    	for(int j=0;j<n;j++)
    	{
        	rgraph[i][j] = graph[i][j];
    	}
	}

	vector<int> parent(n,0);

	int max_flow =0;
	while(bfs(rgraph , s ,t ,parent))
	{
    	int path_flow = INT_MAX;


    	for(int v =t ; v!=s ; v = parent[v])
    	{
    
        	int u = parent [v];
        	path_flow = min(path_flow , rgraph[u][v]);

    	}

    	for(int v = t; v!=s ; v =parent[v])
    	{
        	int u = parent[v];
        	rgraph[u][v] -= path_flow;
        	rgraph[v][u] += path_flow;
    	}

    	max_flow+=path_flow;

	}

	return max_flow;

}

int main()
{
 
	n=6;
	vector<vector<int>> graph(n ,vector<int> (n ,0));
	graph[0][1] = 16;
	graph[0][2] = 13;
	graph[1][2] = 10;
	graph[1][3] = 12;
	graph[2][1] = 4;
	graph[2][4] = 14;
	graph[3][2] = 9;
	graph[3][5] = 20;
	graph[4][5] = 4;
	graph[4][3] = 7;
	cout<<"Max Flow is "<<ford(graph , 0,5)<<endl;

	return 0;
} 	
