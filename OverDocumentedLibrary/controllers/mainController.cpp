#ifndef _CONTROLLER_
#define _CONTROLLER_
#include <iostream>
#include <list>
#include "../utils/inputUtil.cpp"
#include "../models/Author.cpp"
#include "../models/Book.cpp"

using namespace std;

// Class MainController
// Contains the heavy logic of everything the main file can execute.
class MainController
{
public:
    MainController() {}

    // Will print the main menu so that the user can select an option.
    int printMenu()
    {
        cout << endl;
        cout << "Type the number of the option you want:" << endl;
        cout << "[1] Store new book" << endl;
        cout << "[2] See all stored books" << endl;
        cout << "[0] Exit" << endl;
        return inputUtil.getInt("Option #: ");
    }

    // Will ask the user to enter the information for the new book.
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

    // Will print all the stored book so far to the user.
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
    // The util class to handle user input (good and bad).
    InputUtil inputUtil;

    // The in-memory database where the books will be stored.
    // lists are a data structure and unlike array they don't 
    // have a defined size.
    list<Book> allBooks;
};

#endif