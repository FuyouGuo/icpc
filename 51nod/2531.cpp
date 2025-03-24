#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<pii> intervals(q);
    for(int i=0;i<q;i++){
        cin>>intervals[i].first>>intervals[i].second;
    }
    vector<int> freq(n+2,0);
    for(auto interval:intervals){
        freq[interval.first]++;
        freq[interval.second+1]--;
    }
    for(int p=1;p<=n;p++){
        freq[p] += freq[p-1];
    }
    vector<int> coverage(n+1,0);
    vector<int> cnt1(n+1,0);
    vector<int> cnt2(n+1,0);
    for(int p=1;p<=n;p++){
        coverage[p]+=coverage[p-1] + (freq[p]>0?1:0);
        cnt1[p] += cnt1[p-1];
        cnt2[p] += cnt2[p-1];
        if(freq[p]==1){
            cnt1[p]++;
        }else if(freq[p]==2){
            cnt2[p]++;
        }
    }
    vector<int> u(q,0);
    for(int i=0;i<q;i++){
        int l=intervals[i].first;
        int r=intervals[i].second;
        u[i]=cnt1[r]-cnt1[l-1];
    }
    int total_coverage = coverage[n];
    int min_loss=INT_MAX;
    for(int i=0;i<q;i++){
        for(int j=i+1;j<q;j++){
            int intersection_l=max(intervals[i].first, intervals[j].first);
            int intersection_r=min(intervals[i].second, intervals[j].second);
            int clr=intersection_l<=intersection_r?cnt2[intersection_r]-cnt2[intersection_l-1]:0;
            int loss=u[i]+u[j]+clr;
            if(loss<min_loss){
                min_loss=loss;
            }
        }
    }
    cout<<total_coverage-min_loss<<endl;
    return 0;
}