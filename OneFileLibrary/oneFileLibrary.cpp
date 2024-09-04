#include <iostream>
#include <string>
#include <list>
#include <limits>

using namespace std;

const string NO_VALUE = "";
const int MIN_ALLOWED_YEAR = 1000;

enum MenuOptions
{
    NO_OPTION_SELECTED = -1,
    EXIT_OPTION = 0,
    STORE_NEW_BOOK = 1,
    SEE_ALL_BOOKS = 2
};

class Author
{
private:
    string firstName;
    string lastName;

public:
    Author()
    {
    }

    Author(string t_firstName, string t_lastName)
    {
        setFirstName(t_firstName);
        setLastName(t_lastName);
    }

    // Returns the Authors name in the format: LastName, FirstName
    string getFormattedFullName()
    {
        return getLastName() + ", " + getFirstName();
    }

    string getFirstName()
    {
        return firstName;
    }

    string getLastName()
    {
        return lastName;
    }

    bool isValid()
    {
        return !getFirstName().empty() && !getLastName().empty();
    }

    void setFirstName(string t_firstName)
    {
        if (!t_firstName.empty())
        {
            firstName = t_firstName;
        }
    }
    void setLastName(string t_lastName)
    {
        if (!t_lastName.empty())
        {
            lastName = t_lastName;
        }
    }
};

class Book
{
private:
    string title;
    Author author;
    int year;

public:
    Book(string t_title, Author t_author, int t_year)
    {
        setTitle(t_title);
        setAuthor(t_author);
        setYear(t_year);
    }

    string getTitle()
    {
        return title;
    }

    Author getAuthor()
    {
        return author;
    }

    int getYear()
    {
        return year;
    }

    // Returns the book info in the format of: YYYY - Title by Author
    string getFormattedBookInfo()
    {
        return to_string(getYear()) + " - " + getTitle() + " by " + author.getFormattedFullName();
    }

    void setTitle(string t_title)
    {
        if (!t_title.empty())
        {
            title = t_title;
        }
    }

    void setAuthor(Author t_author)
    {
        if (t_author.isValid())
        {
            author = t_author;
        }
    }

    void setYear(int t_year)
    {
        if (t_year >= MIN_ALLOWED_YEAR)
        {
            year = t_year;
        }
    }
};

list<Book> allBooks;

void clearInputOnFail(bool inputSuccessful)
{
    if (!inputSuccessful)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getInt(string promptMessage)
{
    int inputInt = 0;
    bool inputSuccessful = false;

    while (!inputSuccessful)
    {
        cout << promptMessage << endl;
        cin >> inputInt;

        inputSuccessful = !cin.fail();
        clearInputOnFail(inputSuccessful);
    }

    return inputInt;
}

string getString(string promptMessage)
{
    string inputStr = NO_VALUE;
    bool inputSuccessful = false;

    while (!inputSuccessful)
    {
        cout << promptMessage << endl;
        cin >> inputStr;

        inputSuccessful = !inputStr.empty();
        clearInputOnFail(inputSuccessful);
    }
    return inputStr;
}

int printMenu()
{
    cout << endl;
    cout << "Type the number of the option you want:" << endl;
    cout << "[1] Store new book" << endl;
    cout << "[2] See all stored books" << endl;
    cout << "[0] Exit" << endl;
    return getInt("Option #: ");
}

void storeNewBook()
{
    cout << endl;
    cout << "Store new book was selected" << endl;

    string bookTile = getString("Type the book's title: ");
    string firstName = getString("Type the author first name: ");
    string lastName = getString("Type the author last name: ");
    int bookYear = getInt("Type the book release year: ");

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

int main()
{
    cout << "Welcome to Simple Library in C++!" << endl;

    int option = NO_OPTION_SELECTED;
    while (option != EXIT_OPTION)
    {
        option = printMenu();

        switch (option)
        {
        case STORE_NEW_BOOK:
            storeNewBook();
            break;
        case SEE_ALL_BOOKS:
            seeAllBooks();
            break;
        default:
            break;
        }
    }

    cout << "Good-Bye!" << endl;
    exit(EXIT_SUCCESS);
}
