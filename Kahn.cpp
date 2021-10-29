#include<iostream>
#include <vector>
#include <queue>
using namespace std;
void kahn(vector<vector<int> > g,int n,vector<int> in){

    queue<int> q;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(in[i]==0)
           {
                q.push(i);
                vis[i]=true;
           }
    }
    while (!q.empty()){
            int t=q.front();
            q.pop();
            cout<<t<<"->";
            for(int i=0;i<g[t].size();i++){
                //cout<<t<<"->child  "<<g[t][i]<<"  ";
                if(in[g[t][i]]>0)
                in[g[t][i]]-=1;
              //  cout<<in[g[t][i]]<<endl;
                if(in[g[t][i]]==0){
                    if(vis[g[t][i]]==false)
                    q.push(g[t][i]);
                }
            }
      
          queue<int> copy;
            copy=q;
           
        //    while(!copy.empty())
        //     {
        //         cout<<"q->"<<copy.front()<<endl;;
        //         copy.pop();
        //     }
        //     for(int i=0;i<n;i++)
        //     cout<<"IN "<<in[i]<<" "<<endl;
        //     }
    
    
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<vector<int> > g(n,vector<int> (0,0));
    int e;
    cin>>e;
    int u,v;
    vector<int> indegree(n,0);
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;

    }
    // for(int i=0;i<n;i++)
    // cout<<indegree[i]<<" ";
    kahn(g,n,indegree);
    return 0;
}
