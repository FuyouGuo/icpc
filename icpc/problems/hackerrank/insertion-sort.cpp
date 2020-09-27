#include<iostream>
#include<vector>
using namespace std;

int insertionSort(vector<int> arr) {
    arr.insert(arr.begin(),0);
    int m = arr.size();
    int sum = 0;
    for(int i=2;i<m;i++){
        if(arr[i]<arr[i-1]){
            int val = arr[i];
            vector<int>::iterator iter = upper_bound(arr.begin(),arr.begin()+i-1,val);
            int step = arr.begin() + i - iter;
            arr.insert(iter,val);
            sum += step;
        }
    }
    return sum;
}

void fillInt(vector<int>&arr, int m){
    for(int i = 0; i < m; i++){
        arr.push_back(rand()%100000 + 1);
    }
}

int countTimes(vector<int>&arr){
    vector<int> tmpArr(arr.begin(), arr.end());
    tmpArr.insert(tmpArr.begin(), 0);
    int sum = 0;
    for(int i = 2; i < tmpArr.size(); i++){
        int j = i-1;
        while(tmpArr[i]  < tmpArr[j]) j--, sum++;
        tmpArr.insert(tmpArr.begin() + j + 1, tmpArr[i]);
        tmpArr.erase(tmpArr.begin() + i + 1);
    }
    return sum;
}

int main(){
    int n = 10;
    for (int i = 0; i  < 10000; i++) {
        vector<int> arr;
        fillInt(arr, n);
        vector<int> tmpArr(arr.begin(), arr.end());
        int cnt1 = countTimes(tmpArr);
        int cnt2 = insertionSort(tmpArr);
        if( cnt1 != cnt2){
            cout<<cnt1<<"  "<<cnt2<<endl;
            for(int i = 0; i < n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            break;
        }
    }
    return 0;
}