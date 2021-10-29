#include<iostream>
#include<vector>
using namespace std;

void dfshelper(vector<vector<int> > & g,int start,vector<bool> &vis){
    vis[start]=true;
    cout<<start;

        for(int i=0;i<g[start].size();i++){
            
            if(vis[g[start][i]]==false)
            dfshelper(g,g[start][i],vis);
        }

}

void dfs(vector<vector<int> > &g,int start,int n){

    vector<bool> visited(n);
        for(int i=0;i<n;i++){
            visited[i]=false;
        }

        dfshelper(g,start,visited);


    
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int> > graphs(n);
    
    int e;
    cin>>e;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }
     
     dfs(graphs,0,n);
    return 0;
}
