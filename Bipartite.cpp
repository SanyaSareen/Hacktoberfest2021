#include<iostream>
#include <vector>
#include<queue>
using namespace std;

// void bfs(vector<vector<int> > g,int start,int n){

// queue<int> q;
// vector<bool> visited(n);
// for(int i=0;i<n;i++)
//     visited[i]=false;
// //cout<<"in f";
// q.push(start);
// visited[start]=true;
// while(!q.empty()){
//     int remove=q.front();
//     q.pop();
//     cout<<remove<<"->";
//     for(int i=0;i<g[remove].size();i++){
//         if(visited[g[remove][i]]==false)
//         {q.push(g[remove][i]);
//         visited[g[remove][i]]=true;
//         }
//     }
// }

// }

bool bipartite(vector<vector<int> >g,int n){

queue<int> q;
// int n=g.size();
vector<char> visited(n);
for(int i=0;i<n;i++)
    visited[i]='f';
//cout<<"in f";
char c='a';
int start;
for(int i=0;i<n;i++){
if(visited[i]=='f'){
start=i;
q.push(start);
visited[start]='a';
while(!q.empty()){
    int remove=q.front();
    q.pop();
    c=visited[remove];
    //cout<<remove<<"->";
    for(int i=0;i<g[remove].size();i++){
        if(visited[g[remove][i]]=='f')
        {q.push(g[remove][i]);
        if(c=='a')
        visited[g[remove][i]]='b';
        else
        visited[g[remove][i]]='a';
        
        }
        else if(visited[g[remove][i]]=='a' && c=='a'){
            return false;
        }
        else if (visited[g[remove][i]]=='b' && c=='b'){
            return false;
        }
    }
    //  if(c=='a')
    //     c='b';
    //     else
    //     c='a';

    
}
}
}

return true;
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

 bool t=bipartite(graph,n);
if(t)
cout<<"yes";
else
{
    cout<<"no";
}


    return 0;
}
