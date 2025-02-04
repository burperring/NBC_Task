#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int size, cnt, front, back;
    vector<int> v(size);

    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }

    cin >> cnt;
    while(cnt--){
        cin >> front;
        cin >> back;

        int sum = accumulate(v.begin() + (front - 1), v.begin() + back, 0);
        cout << sum << endl;
    }
}