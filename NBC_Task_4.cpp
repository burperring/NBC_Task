#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}

    ~Book() {}
};

class BookManager{
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author){
        books.push_back(Book(title, author));
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    void displayAllBooks() const{
        if(books.empty()){
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록" << endl;
        for(size_t i = 0; i < books.size(); i++){
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    Book* findBookByTitle(string title){
        for(size_t i = 0; i < books.size(); i++){
            if(books[i].title == title){
                return &books[i];
            }
        }

        return nullptr;
    }

    Book* findBookByAuthor(string author){
        for(size_t i = 0; i < books.size(); i++){
            if(books[i].author == author)
                return &books[i];
        }

        return nullptr;
    }
    Book* getBookByTitle(string title);
    Book* getBookByAuthor(string author);
};

class BorrowManager{
protected:
    unordered_map<string, int> stock;

public:
    void initializeStock(Book book, int quantity){
        stock.insert({book.title, quantity});
    }

    void borrowBook(Book& book){
        if(stock[book.title] > 0)
            stock[book.title]--;

        cout << book.title << "을/를 대여했습니다." << endl;
        cout << book.title << "의 제고: " << stock[book.title] << endl;
    }

    void returnBook(string title){
        if(stock[title] < 3)
            stock[title]++;

        cout << title << "을/를 반납했습니다." << endl;
        cout << title << "의 재고: " << stock[title] << endl;
    }

    int bookStock(Book& book){
        return stock[book.title];
    }

    void displayStock(){
        for(auto iter : stock){
            cout << iter.first << "의 제고: " << iter.second << endl;
        }
    }
};

int main(){
    BookManager manager;
    BorrowManager borrowManager;

    while(1){
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;                          // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl;                     // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 전체 책 제고 확인하기" << endl;            // 모든 책 제고 확인하기기
        cout << "4. 책 제목으로 찾아서 빌리기" << endl;         // 현재 책 목록에서 제목으로 책 찾기
        cout << "5. 저자 이름으로 찾아서 빌리기기" << endl;     // 현재 책 목록에서 저자이름으로로 책 찾기
        cout << "6. 책 제목으로 반납하기" << endl;
        cout << "7. 종료" << endl;                             // 프로그램 종료
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {  // 1. 책 추가가
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            
            manager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initializeStock(Book(title, author), 3);
        } 
        else if (choice == 2) {  // 2. 모든 책 출력력
            manager.displayAllBooks();
        } 
        else if (choice == 3) {  // 3. 모든 책 제고 출력력
            borrowManager.displayStock();
        }
        else if (choice == 4) {  // 4. 책 제목으로 찾아서 빌리기
            string title;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)

            Book* nameBook = manager.findBookByTitle(title);

            if(nameBook != nullptr){
                int num = borrowManager.bookStock(*nameBook);
                cout << title << "의 제고가 " << num << "개 있습니다." << endl;

                if(num > 0){
                    cout << title << "책을 빌리겠습니까?" << endl;
                    cout << "0: 빌린다" << endl;

                    cin >> choice;

                    if(choice == 0){
                        borrowManager.borrowBook(*nameBook);
                    }
                    else{
                        cout << "책을 빌리지 않았습니다." << endl;
                        continue;
                    }
                }
            }
            else{
                cout << "해당 책은 존재하지 않습니다." << endl;
            }
        }
        else if (choice == 5) {  // 5. 책 저자로 찾아서 빌리기
            string author;
            cout << "책 저자자: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, author); // 제목 입력 (공백 포함)

            Book* bookAuthor = manager.findBookByAuthor(author);
            
            if(bookAuthor != nullptr){
                int num = borrowManager.bookStock(*bookAuthor);
                cout << bookAuthor->title << "의 제고가 " << num << "개 있습니다." << endl;
            
                if(num > 0){
                    cout << bookAuthor->title << "책을 빌리겠습니까?" << endl;
                    cout << "0: 빌린다" << endl;

                    cin >> choice;

                    if(choice == 0){
                        borrowManager.borrowBook(*bookAuthor);
                    }
                    else{
                        cout << "책을 빌리지 않았습니다." << endl;
                        continue;
                    }
                }
            }
            else{
                cout << "해당 책은 존재하지 않습니다." << endl;
            }
        }
        else if(choice == 6){
            string title;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)

            Book* nameBook = manager.findBookByTitle(title);

            if(nameBook != nullptr){
                int num = borrowManager.bookStock(*nameBook);

                if(num < 3){
                    borrowManager.returnBook(nameBook->title);
                }
                else{
                    cout << "해당 책을 빌리지 않았습니다." << endl;
                }
            }
            else{
                cout << "해당 책은 존재하지 않습니다." << endl;
            }
        } 
        else if (choice == 7) {  // 6. 종료
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        } 
        else {  // 잘못된 입력 처리 버퍼 제거
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }

    return 0;
}

