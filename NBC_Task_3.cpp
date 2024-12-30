#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector{
protected:
    T* arr = nullptr;
    size_t iCurrentSize;
    size_t iCurrentCapacity;

    // 추가적으로 증가하는 캐퍼시티티
    const size_t add_capacity = 5;

    bool CheckValidIndex(const size_t index){   // 제거할 때 범위를 벗어났는지 체크크
        if(index >= 0 && index < this->iCurrentSize){
            return true;
        }
        else{
            throw printf("잘못된 접근입니다!!! 접근하려는 인덱스: %d, 배열의 크기 %d", index, this->iCurrentSize);
        }
    }

private:
    void resize(size_t capacity){
        if(iCurrentCapacity > capacity)
            return;

        T* temp = new T[capacity];
        iCurrentCapacity = capacity;

        if(iCurrentCapacity >= 1){
            for(size_t i = 0; i < iCurrentSize; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
        }

        arr = temp;
    }

public:
    SimpleVector() {    // 기본 생성자
        this->arr = nullptr;
        this->iCurrentSize = 0;
        this->iCurrentCapacity = 10;

        this->resize(iCurrentCapacity);
    }

    SimpleVector(int capacity){
        this->arr = nullptr;
        this->iCurrentSize = 0;
        this->iCurrentCapacity = capacity;

        this->resize(iCurrentCapacity);
    }

    SimpleVector(initializer_list<T> list){
        this->iCurrentCapacity = this->iCurrentSize = 0;
        this->resize(list.size());

        for(auto& element : list){
            this->arr[this->iCurrentSize++] = element;
        }
    }
    
    void push_back(const T& value){
        if(this->iCurrentSize == this->iCurrentCapacity){
            this->resize(this->iCurrentCapacity + this->add_capacity);
        }

        this->arr[iCurrentSize] = value;
        this->iCurrentSize++;
    }

    void pop_back(){
        const size_t last_index = this->iCurrentSize - 1;
        this->CheckValidIndex(last_index);

        T& data = this->arr[last_index];

        this->iCurrentSize--;
    }

    void sortData(){
        sort(this->arr, this->arr + iCurrentSize);
    }

    void show(){
        for(int i = 0; i < iCurrentSize; i++){
            cout << this->arr[i] << " ";
        }
        cout << endl;

        cout << this->size() << endl;
        cout << this->capacity() << endl;
    }

    int size(){
        return this->iCurrentSize;
    }

    int capacity(){
        return this->iCurrentCapacity;
    }

    ~SimpleVector() {
        if(this->arr){
            delete[] this->arr;
        }
    }
};

int main(){
    SimpleVector<int> sv;

    sv.push_back(5);
    sv.push_back(2);
    sv.push_back(3);
    sv.push_back(9);
    sv.push_back(1);
    sv.push_back(8);
    sv.show();
    sv.sortData();
    sv.show();

    sv.pop_back();
    sv.pop_back();
    sv.show();
}

/*
출력 결과
5 2 3 9 1 8 
6
10
1 2 3 5 8 9 
6
10
1 2 3 5 
4
10
*/