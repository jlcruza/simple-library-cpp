#ifndef _INPUT_
#define _INPUT_
#include <string>
#include <iostream>

using namespace std;

// Assigning "" to a string is sometimes ugly.
// We can set that in a constant a use it instead
// for readability sake.
const string NO_VALUE = "";

// Class InputUtil
// As an util class, this one group here logic that otherwise
// would be redundant in the other files. Experienced developers
// know the importance of Don't Repeat Yourself (DRY).
// This class will handle getting the input from the user.
class InputUtil
{
public:
    // Default constructor. Nothing special needed to do here.
    InputUtil() {}

    // This methond will prompt the user with the specified
    // message in the param promptMessage until we get
    // a valid int. This can even be enhanced to accept only 
    // a range of values.
    int getInt(string promptMessage)
    {
        int inputInt = 0;
        bool inputSuccessful = false;

        while (!inputSuccessful)
        {
            cout << promptMessage << endl;
            cin >> inputInt;

            // cin.fail() tell us if the value the user provided was
            // of the expected data type.
            inputSuccessful = !cin.fail();

            // In case of failure, we need to reset cin
            // so that we can use it again
            clearInputOnFail(inputSuccessful);
        }

        return inputInt;
    }

    // This methond will prompt the user with the specified
    // message in the param promptMessage until we get
    // a non empty string.
    string getString(string promptMessage)
    {
        string inputStr = NO_VALUE;
        bool inputSuccessful = false;

        while (!inputSuccessful)
        {
            cout << promptMessage << endl;
            cin >> inputStr;

            // cin.fail() tell us if the value the user provided was
            // of the expected data type.
            inputSuccessful = !inputStr.empty();

            // In case of failure, we need to reset cin
            // so that we can use it again
            clearInputOnFail(inputSuccessful);
        }
        return inputStr;
    }

private:
    // This method knows how and when to clean cin.
    // It's a private method as it was designed specifically for
    // this class.
    void clearInputOnFail(bool inputSuccessful)
    {
        if (!inputSuccessful)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

#endif