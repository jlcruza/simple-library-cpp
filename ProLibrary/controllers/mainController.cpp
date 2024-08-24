#ifndef _CONTROLLER_
#define _CONTROLLER_
#include <iostream>
#include <list>
#include "../utils/inputUtil.cpp"
#include "../models/Author.cpp"
#include "../models/Book.cpp"

using namespace std;

class MainController
{
public:
    MainController() {}

    int printMenu()
    {
        cout << endl;
        cout << "Type the number of the option you want:" << endl;
        cout << "[1] Store new book" << endl;
        cout << "[2] See all stored books" << endl;
        cout << "[0] Exit" << endl;
        return inputUtil.getInt("Option #: ");
    }

    void storeNewBook()
    {
        cout << endl;
        cout << "Store new book was selected" << endl;

        string bookTile = inputUtil.getString("Type the book's title: ");
        string firstName = inputUtil.getString("Type the author first name: ");
        string lastName = inputUtil.getString("Type the author last name: ");
        int bookYear = inputUtil.getInt("Type the book release year: ");

        Author author(firstName, lastName);
        Book book(bookTile, author, bookYear);
        allBooks.push_back(book);

        cout << "Thanks! The following book was successfully stored:" << endl;
        cout << book.getFormattedBookInfo() << endl;
    }

    void seeAllBooks()
    {
        cout << endl;
        cout << "See all books was selected" << endl;

        for (Book book : allBooks)
        {
            cout << book.getFormattedBookInfo() << endl;
        }
    }

private:
    InputUtil inputUtil;
    list<Book> allBooks;
};

#endif