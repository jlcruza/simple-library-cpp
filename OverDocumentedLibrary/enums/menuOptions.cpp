#ifndef _MENU_
#define _MENU_

// Options used for the main menu. Words are easier to
// understand. For this case, we really don't care about
// the numeric values, we are more interested in valid
// words for the compiler and limited to what we will
// be using in the menu.
enum MenuOptions
{
    NO_OPTION_SELECTED = -1,
    EXIT_OPTION = 0,
    STORE_NEW_BOOK = 1,
    SEE_ALL_BOOKS = 2
};

#endif