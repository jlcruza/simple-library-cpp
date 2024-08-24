#include <iostream>     // Give us access to cin and cout commanda

// All of the below includes have guards set up, so there is no risk of duplicates
#include "controllers/mainController.cpp"
#include "enums/menuOptions.cpp"
#include "models/Author.cpp"
#include "models/Book.cpp"

// For begginers, this will make the code a lot more readable. 
// They can later choose whether to keep the practice or not.
using namespace std;

// This is our entry point. I decided to keep it clean and move
// The heavy logic to the other files.
int main()
{
    // MainController is the class containg the main actions we will be taking.
    MainController controller;
    cout << "Welcome to Simple Library in C++!" << endl;

    // NO_OPTION_SELECTED comes from the enum. 
    // Words are more readable than magic numbers.
    int option = NO_OPTION_SELECTED;

    // EXIT_OPTION also comes from the enum and same 
    // reason as above.
    while (option != EXIT_OPTION)
    {
        // Look how clean is this printMenu(), and the best
        // part is, that we know what it will do ....
        // it will print the menu, of course
        option = controller.printMenu();

        // Swtich cases aren't very recommended later on, but
        // is important to know them nevertheless.
        // And switch cases works very well with enums
        // since they are constants.
        switch (option)
        {
        case STORE_NEW_BOOK:
            // There is barely a good comment for this without
            // sounding redundant. That is the power of good names
            // We just instructed the controller handle the process
            // of storing a new book in our in-memory database.
            controller.storeNewBook();
            break;
        case SEE_ALL_BOOKS:
            // Do you want to guess what this does? ...
            // That's right, this will tell the controller to
            // show all the books stored.
            controller.seeAllBooks();
            break;
        default:
            // Is good practice to have the default case even when
            // there is nothing to do. Many times is best to be
            // explicit.
            break;
        }
    }

    cout << "Good-Bye!" << endl;

    // EXIT_SUCCESS equals 0. An exit code of 0 means that the 
    // program completed successfuly.
    exit(EXIT_SUCCESS);
}
