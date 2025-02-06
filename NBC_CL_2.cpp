#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    int cnt, prev, count, rank = 1;
    map<string, int> m;
    cin >> cnt;

    while(cnt--){
        string sf;
        cin >> sf;
        m[sf]++;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    prev = v[0].second;
    count = 0;

    for(auto x : v){
        if(prev != x.second){
            rank += count;
            count = 0;
            prev = x.second;
        }
        cout << x.first << " : " << rank << endl;
        count++;
    }
}