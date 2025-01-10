#include <iostream>

using namespace std;

class Node {
private:
    string data;
    Node* next; // 일단은 원시 포인터로 러프하게!

public:
    Node(string data) {  // data = "흑연"
        this->data = data;
        this->next = nullptr;  // 초기에는 다음 노드가 없으므로 nullptr로 초기화!
    }
    
    // LinkedList 클래스에서 Node의 private 멤버에 접근 가능하도록 친구로 설정!
    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;
    int nodeCount;  // 노드 개수를 추적하기 위한 변수

public:
    LinkedList(string value) {
        this->head = new Node(value);  // head에 시작하는 Node를 연결합니다.
        this->nodeCount = 1;
    }
    // 소멸자 생략!
    // ...

    void append(string value);
    void addNode(int index, string value);
    Node* getNode(int index);
};

void LinkedList::append(string value) {
		Node* curr = this->head;
		while (curr->next != nullptr) {  // curr의 다음이 끝에 갈 때까지 이동합니다.
				curr = curr->next;
		}
		// 이곳으로 왔다는 것은
		// while 루프를 탈출했다는 의미
		// 탈출을 하려면 curr->next != nullptr 이 조건이 지켜지지 않아야 함
		// curr->next == nullptr
		cout << "curr->next: " << curr->next << endl;
		curr->next = new Node(value);
		this->nodeCount++;
}

void LinkedList::addNode(int index, string value){
    if(index < 0 || index > nodeCount){
        throw out_of_range("유효하지 않은 인덱스입니다.");
    }

    Node* newNode = new Node(value);

    if(index == 0){
        newNode->next = this->head;
        this->head = newNode;
        this->nodeCount++;
        return;
    }

    Node* node = this->getNode(index - 1);
    Node* nextNode = node->next;
    node->next = newNode;
    newNode->next = nextNode;
    this->nodeCount++;

    return;
}

Node* LinkedList::getNode(int index){
    if(index < 0 || index >= nodeCount){
        throw out_of_range("유효하지 않은 인덱스입니다.");
    }

    Node* node = this->head;
    for(int i = 0; i < index; i++){
        node = node->next;
    }

    return node;
}

int main(){

}