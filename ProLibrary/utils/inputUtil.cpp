#ifndef _INPUT_
#define _INPUT_
#include <string>
#include <iostream>
#include <limits>

using namespace std;

const string NO_VALUE = "";

class InputUtil
{
public:
    InputUtil() {}

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

private:
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