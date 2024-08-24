#include <iostream>
#include "controllers/mainController.cpp"
#include "enums/menuOptions.cpp"
#include "models/Author.cpp"
#include "models/Book.cpp"
using namespace std;

int main()
{
    MainController controller;
    cout << "Welcome to Simple Library in C++!" << endl;

    int option = NO_OPTION_SELECTED;
    while (option != EXIT_OPTION)
    {
        option = controller.printMenu();

        switch (option)
        {
        case STORE_NEW_BOOK:
            controller.storeNewBook();
            break;
        case SEE_ALL_BOOKS:
            controller.seeAllBooks();
            break;
        default:
            break;
        }
    }

    cout << "Good-Bye!" << endl;
    exit(EXIT_SUCCESS);
}
