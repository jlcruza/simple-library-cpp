#ifndef _AUTHOR_
#define _AUTHOR_

#include <string>

using namespace std;

// Class Author
// Contains the first and last name of an author.
// This class can also returns the name formatted
// as Doe, John
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

#endif