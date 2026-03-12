#include <iostream>
#include "library_management_system.h"
using namespace std;

void Library::Load_Books()
{
    ifstream file("books_list.txt");

    Book b;

    while(file >> b.ID >> b.Name >> b.Author >> b.Available)
    {
        books.push_back(b);
    }

    file.close();
}

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
    My_file<<b.ID<<" "<<b.Name<<" "<<b.Author<<" "<<b.Available<<"\n";
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

void Library::Delete_Book(){
    cout<<"Delete Book\n1 book ID\n2 Book Name\nEnter choice:";
    int input;
    cin>>input;

    bool book_name = false;
    if(input == 2)
    {
        book_name = true;
    }
    
    if(book_name)
    {   
        string del_book_name;
        cout<<"Enter deleting  book Name:";
        cin>>del_book_name;
        bool book_found = false;
        for(size_t i =0 ; i< books.size();i++)
        {
            if(books[i].Name == del_book_name)
            {
                book_found = true;
                books.erase(books.begin()+i);
                cout<<"Deleted book sucessfully"<<endl;
                break;
            }
        }
        if(!book_found)
        {
            cout<<"No book Name found in list to delete book"<<endl;
        }
    }
    else{

        int del_book_id;
        cout<<"Enter deleting  book ID:";
        cin>>del_book_id;
        bool book_found = false;
        for(size_t i =0 ; i< books.size();i++)
        {
            if(books[i].ID == del_book_id)
            {
                book_found = true;
                books.erase(books.begin()+i);
                cout<<"Deleted book sucessfully"<<endl;
                break;
            }
        }
        
        if(!book_found)
        {
            cout<<"No book ID found in list to delete book"<<endl;
            return;
        }

        ofstream file("books_list.txt");

        for(auto &b : books)
        {
            file<<b.ID<<" "<<b.Name<<" "<<b.Author<<" "<<b.Available<<"\n";
        }

        file.close();
    }
    
}

void Library::Update_Book()
{   
    cout<<"Which book do you want update Enter Book ID:";
    int input;
    cin>>input;
    cout<<"Update book\n1 Book ID\n2 Book Name\n3 Book Author\n4 Book Available\nEnter your choice:";
    int user_op;
    cin>>user_op;
    
    int t_id;
    string t_name;
    string t_author;
    int t_avalible;

    bool bkfound = false;
    bool book_update = false;
            
    for(auto &e : books)
    {
        if(e.ID == input)
        {   
            bkfound = true;
            switch (user_op)
            {
            case 1:
                {
                    cout<<"Enter update Book ID:";
                    cin>>t_id;
                    e.ID = t_id;
                    book_update = true;
                    break;
                }
            case 2:
                {
                    cout<<"Enter update Book Name:";
                    cin>>t_name;
                    e.Name = t_name;
                    book_update = true;
                    break;
                }
            case 3:
                {
                    cout<<"Enter update Book Author:";
                    cin>>t_author;
                    e.Author = t_author;
                    book_update = true;
                    break;
                }
            case 4:
            {
                cout<<"Enter update Book Availabe No:";
                cin>>t_avalible;
                e.Available = t_avalible;
                book_update = true;
                break;
            }
            default:
                cout<<"Invalid update input"<<endl;
                break;
            }
            
        }
    }
    if(book_update)
    {
       ofstream file("books_list.txt");

        for(auto &b : books)
        {
            file<<b.ID<<" "<<b.Name<<" "<<b.Author<<" "<<b.Available<<"\n";
        }

        file.close();
    }
    if(!bkfound)
    {
        cout<<"Updated book ID not fount in list"<<endl;
    }

}
int main()
{   
    Library ms;

    ms.Load_Books();
    
    
    int op;
    do{
        cout<<" \n1 Add Book\n2 Show Books\n3 Borrow Book\n4 Return Book\n5 Search Book\n6 Delete Book\n7 Update Book\n8 Exit\nEnter choice:";
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
            ms.Delete_Book();
            break;
        }
        case 7:
        {
            ms.Update_Book();
            break;
        }
        case 8:
        {
            cout<<"EXIT\n";
            break;
        }
        
            
        default:
            cout<<"Please Enter valid input"<<endl;
            break;
        }

    }while(op != 8);

    return 0;
}
