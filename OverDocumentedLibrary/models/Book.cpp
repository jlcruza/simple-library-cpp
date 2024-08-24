#ifndef _BOOK_
#define _BOOK_

#include <string>
#include "Author.cpp"

using namespace std;

const int MIN_ALLOWED_YEAR = 1000;
// Class Book
// Contains the title, author and year of the book
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

#endif