#include<iostream>
#include<vector>

using namespace std;

void belman(vector<vector<pair<int,int> > >g,int n ){
    vector<int > ans(n,INT_MAX);
    ans[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<g[j].size();k++){
                if(ans[j]+g[j][k].first<ans[g[j][k].second]){
                    ans[g[j][k].second]=ans[j]+g[j][k].first;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<pair<int,int> > > g(n);
    int e;
    cin>>e;
    int u,v,w;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(w,v));

    }

    belman(g,n);
    return 0;
}
