#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
using pii = std::pair<int, int>;
int n,m,s,t,w,ret = INT_MAX;
unordered_map<int, int> edges[501];
int nodes[501];
bool visited[501];
void dfs(int u){
    if(u==t){
        // 源点和目标点相同
        ret=0;
        return;
    }
    stack<pii*> ns; // 因为后续有修改元素，所以需要存成指针类型
    ns.push(new pii(u,0));
    nodes[u]=0;
    while(!ns.empty()){
        pii* cur=ns.top();
        visited[cur->first]=true;
        if(cur->second==-1){
            visited[cur->first]=false;
            ns.pop();
            continue;
        }
        for(auto &edge:edges[cur->first]){
            if(edge.first==t){
                ret=min(ret,cur->second+edge.second);
                continue;
            }
            if(!visited[edge.first]) {
                w = cur->second+edge.second;
                if(w<nodes[edge.first]){
                    nodes[edge.first] = w;
                    ns.push(new pii(edge.first, w));
                }
            }
        }
        cur->second=-1; // 因为可能有其他路径经过该节点，需要设置成-1，在访问结束后，从visited里删除 
    }
}
void bfs(int u){
    if(u==t){
        ret=0;
        return;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        edges[i]=unordered_map<int, int>();
        nodes[i]=INT_MAX;
    }
    for(int i=0;i<m;i++){
        cin>>s>>t>>w;
        if(s==t) continue;
        if(edges[s].find(t)!=edges[s].end()) w=min(w,edges[s][t]);
        edges[s][t]=w;
        edges[t][s]=w;
    }
    cin>>s>>t;
    dfs(s);
    cout<<ret<<endl;
    return 0;
}