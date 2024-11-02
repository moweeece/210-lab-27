// COMSC-210 | Mauricio Espinosa | Lab 27
// IDE Used: Visual Studio Code & Github

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

using villagerInfo = tuple<int, string, string>;

int main() {
    // declarations
    map<string, villagerInfo> villagerData;
    int userChoice, friendshipLevel;
    string villagerName, species, catchphrase;

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
        if (userChoice <= 0 || userChoice > 6)
        {
            cout << "Invalid Input" << endl;
            continue;
        }

        switch(userChoice) 
        {
            case 1: {
                // add villager

                cout << "Villager name: ";
                getline(cin, villagerName);
                cout << endl;

                cout << "Friendship Level: ";
                cin >> friendshipLevel;
                cin.ignore();
                cout << endl;

                cout << "Species: ";
                getline(cin, species);
                cout << endl;

                cout << "Catchphrase: ";
                getline(cin, catchphrase);
                cout << endl;

                // create a tuple with the user's inputted information
                villagerData[villagerName] = make_tuple(friendshipLevel, species, catchphrase);

                cout << villagerName << " added." << endl;

                break;
            }

            case 2: {
                // delete villager
                cout << "Which villager would you like to delete?: ";
                getline(cin, villagerName);
                cout << endl;

                // check if that villager is present in the container
                if(villagerData.erase(villagerName))
                {
                    cout << villagerName << " deleted." << endl;
                }
                else
                {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 3: {
                // increase friendship
                cout << "Which villager would you like to increase friendship?: ";
                getline(cin, villagerName);
                cout << endl;

                // check if that villager is present in the container
                auto itIncrease = villagerData.find(villagerName);
                if(itIncrease != villagerData.end())      // if the iterator does NOT reach the end of the container, then a match must be found
                {
                    get<0>(itIncrease->second)++;
                    cout << villagerName << "'s friendship increased." << endl;
                }
                else
                {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 4: {
                // decrease friendship
                cout << "Which villager would you like to decrease friendship?: ";
                getline(cin, villagerName);
                cout << endl;

                // check if that villager is present in the container
                auto itDecrease = villagerData.find(villagerName);
                if(itDecrease != villagerData.end())      // if the iterator does NOT reach the end of the container, then a match must be found
                {
                    if(get<0>(itDecrease->second) > 0)    // if the friendship level is greater than 0, its safe to decrement (keeping it non-negative)
                    {
                        get<0>(itDecrease->second)--;
                        cout << villagerName << "'s friendship decreased." << endl;
                    }
                    else
                    {
                        cout << "Friendship level cannot be less than 0." << endl;
                    }
                }
                else
                {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 5: {
                // search for villager
                cout << "Which villager would you like to search for?: ";
                getline(cin, villagerName);
                cout << endl;
                
                // search for the villager
                auto itSearch = villagerData.find(villagerName);
                if(itSearch != villagerData.end())      // if the iterator does NOT reach the end of the container, then a match must be found
                {
                    cout << "Villager found!" << endl;
                }
                else
                {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 6: {
                // exit
                break;
            }

            default: {
                break;
            }
        }
            
        // display contents of villager data
        cout << "Villager Details:" << endl;
        
        for (const auto& data : villagerData)
        {
            const string& villagerName = data.first;   // gets the name from the map
            const villagerInfo& info = data.second;    // gets the tuple from the map

            cout << villagerName << " [" << get<0>(info) << ", " << get<1>(info) << ", " << get<2>(info) << "]" << endl;
        }
        cout << endl;        

    } while (userChoice != 6);

    return 0;
}