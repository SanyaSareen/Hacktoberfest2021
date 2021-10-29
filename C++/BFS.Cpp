#include<iostream>
#include <vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> > g,int n){

queue<int> q;
vector<bool> visited(n);
for(int i=0;i<n;i++)
    visited[i]=false;
//cout<<"in f";
int start;
for(int i=0;i<n;i++){
    if(visited[i]==false){
        start=i;
q.push(start);
visited[start]=true;
while(!q.empty()){
    int remove=q.front();
    q.pop();
    cout<<remove<<"->";
    for(int i=0;i<g[remove].size();i++){
        if(visited[g[remove][i]]==false)
        {q.push(g[remove][i]);
        visited[g[remove][i]]=true;
        }
    }
}
    }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int> > graph(n);

int e;
cin>>e;
int u,v;
for(int i=0;i<e;i++){
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    //cout<<u<<"->"<<v;
}
 bfs(graph,n);


    return 0;
}
