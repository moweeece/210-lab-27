// COMSC-210 | Mauricio Espinosa | Lab 27
// IDE Used: Visual Studio Code & Github

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

using villagerInfo = tuple<int, string, string>;

int main() {
    // declarations
    map<string, villagerInfo> villagerData;
    int userChoice;

    // displays menu and returns user choice
    do
    {
        // menu
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "User Selection: ";
        cin >> userChoice;

        cout << endl;

        // data validation for negative, 0, or greater than 6
        if (userChoice <= 0 && userChoice > 6)
        {
            cout << "Invalid Input" << endl;
        }

        switch(userChoice)
        {
            case 1:
            // add villager
            int friendshipLevel;
            string species;
            string catchphrase;
            cout << "Villager name: ";
            getline (cin, name);

            case 2:
            // delete villager
            case 3:
            // increase friendship
            case 4:
            // decrease friendship
            case 5:
            // search for villager
            case 6:
            // exit
            default:
                break;
        }


        // display contents of villager data
        




    } while (userChoice <= 0 && userChoice > 6);

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}