#ifndef MANAGEMENT_SYSTEM_H
#define MANAGEMENT_SYSTEM_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Book{
    public:
    int ID;
    string Name;
    string Author;
    int Available;
};

class Library{
    
    public:
    
    vector<Book> books;

    void Load_Books();

    void Add_Book();
    
    void Show_Books();

    void Borrow_Book();

    void Return_Book();

    void Search_Book();

    void Delete_Book();

    void Update_Book();

};

#endif 