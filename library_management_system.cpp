#include <iostream>
#include "library_management_system.h"
using namespace std;



void Library::Add_Book()
{   

    Book b;
    cout<<"Enter Book ID:";
    cin>>b.ID;
    cout<<"Enter Book Name:";
    cin.ignore();
    getline(cin, b.Name);
    cout<<"Enter Author Name:";
    getline(cin, b.Author);
    cout<<"Enter Quantity:";
    cin>>b.Available;
    
    ofstream My_file("books_list.txt", std::ios::app);
    My_file<<"Book ID:"<<b.ID<<" Book Name:"<<b.Name<<" Author Name:"<<b.Author<<"Quantity:"<<b.Available<<"\n";
    My_file.close();

    books.push_back(b);

}

void Library::Show_Books()
{   
    if(books.empty())
    {
        cout<<"No books available\n";
        return;
    }
    for(auto &e :books)
    {
        cout<<"ID: "<< e.ID<<" "<<e.Name<<" "<<e.Author<<" "<<e.Available<<endl;
    }
}


void Library::Borrow_Book()
{
    cout<<"Enter Book ID to borrow:";
    int book_id;
    cin>>book_id;
    bool found = false;
    for(auto &e : books)
    {
        if(e.ID == book_id && e.Available > 0)
        {
            found = true;
            e.Available--;
            cout<<"Book borrowed successfully\n";
            cout<<"Remaining copies: "<<e.Available<<endl;
            return;
        }
    }
    if(!found)
    {
        cout<<"No books availabe to borrow"<<endl;
    }
}

void Library::Return_Book()
{
    cout<<"Enter Book ID to return:";
    int book_id;
    cin>>book_id;
    bool  found = false;
    for(auto &e : books)
    {
        if(e.ID == book_id)
        {   
            found = true;
            e.Available++;
            cout<<"Book returned successfully"<<endl;
            cout<<"Available copies: "<< e.Available<<endl;
            return;
        }
    }
    if(!found)
    {
        cout<<"book is not borrowd book"<<endl;
    }
   
}

void Library::Search_Book()
{
    cout<<"Enter Book ID to Search:";
    int book_id;
    cin>>book_id;
    int book_remaining = 0;
    bool  found = false;
    for(auto &e : books)
    {
        if(e.ID == book_id)
        {   
            found = true;
            book_remaining = e.Available;
            cout<<"Book found successfully"<<endl;
        }
    }
    if(!found)
    {
        cout<<"book is not  found"<<endl;
    }
    cout<<"Available copies: "<< book_remaining<<endl;
}




int main()
{   
    Library ms;
    
    
    int op;
    do{
        cout<<" \n1 Add Book\n2 Show Books\n3 Borrow Book\n4 Return Book\n5 Search Book\n6 Exit\nEnter choice:";
        cin>>op;
        switch (op)
        {
        case 1:
        {
            
            ms.Add_Book();
            
            cout<<"Book added successfully"<<endl;
            break;
        }
        case 2:
        {
            ms.Show_Books(); 
            break;
        }
        case 3:
        {
            ms.Borrow_Book();
            break;
        }
        case 4:
        {
            ms.Return_Book();
            break;
        }
        case 5:
        {
            ms.Search_Book();
            break;
        }
        case 6:
        {
            cout<<"EXIT\n";
            break;
        }
            
        default:
            break;
        }

    }while(op != 6);

    return 0;
}
