#include<iostream>
#include<vector>
#include <fstream>
using namespace std;

typedef pair<int,int> pairInt;

int N, M;

int getMemory(vector<pairInt>& nodeList, int size){
    int retAddr = -1;
    for(int i = 0; i < nodeList.size();i++) {
        pairInt node = nodeList[i];
        if(node.second >= size){
            retAddr = node.first;
            int retSize = node.second - size;
            if (retSize > 0) {
                node.first += size;
                node.second = retSize;
                nodeList[i] = node;
            } else {
                nodeList.erase(nodeList.begin() + i);
            }
            return retAddr;
        }
    }
    return retAddr;
}

void releaseMemory(vector<pairInt>& nodeList, int start, int size) {
    for(int i = 0; i < nodeList.size();i++){
        pairInt node = nodeList[i];
        int maxMemory = min(start+size, N);
        if(node.first + node.second < start) continue;
        if(node.first > start) {
            if(start + size >= node.first) {
                node.second = max(node.first + node.second, maxMemory) - start;
                node.first = start;
                nodeList[i] = node;
            } else {
                nodeList.insert(nodeList.begin() + i, 1, pairInt(start, maxMemory-start));
            }
        } else if(start + size > nodeList[i].first + nodeList[i].second){
            nodeList[i].second = maxMemory - node.first;
        }
        while(i < nodeList.size() - 1) {
            // 合并区间
            int limit = nodeList[i].first + nodeList[i].second;
            if (limit > nodeList[i + 1].first){
                nodeList[i].second = max(limit, nodeList[i + 1].first + nodeList[i + 1].second) - nodeList[i].first;
                nodeList.erase(nodeList.begin() + i  + 1);
            } else {
                break;
            }
        }
        return;
    }
    nodeList.insert(nodeList.begin() + nodeList.size(), 1, pairInt(start, min(start + size, N) - start));
}

int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    vector<pairInt> nodeList = vector<pairInt>();
    cin>>N>>M;
    int op, start, size;
    nodeList.push_back(pairInt(0,N));
    for(int i=0; i<M;i++){
        cin>>op;
        switch(op){
            case 1:
                cin>>size;
                cout<<getMemory(nodeList, size)<<endl;
                // printNodeList(cout, nodeList);
                break;
            case 2:
                cin>>start>>size;
                releaseMemory(nodeList, start, size);
                // printNodeList(cout, nodeList);
                break;
        }
    }
}