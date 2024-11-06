#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store state names and their populations
    map<string, int> statePopulations;

    // Add some initial state-population pairs
    statePopulations["Uttar Pradesh"]=240,000,000;
    statePopulations["Maharashtra"]=125,000,000;
    statePopulations["Bihar"]=130,000,000;
    statePopulations["West Bengal"]=100,000,000;
    statePopulations["Madhya Pradesh"]=87,000,000 ;

    // Prompt the user for a state name
    string stateName;
    cout << "Enter the name of a state: ";
    cin >> stateName;

    // Search for the state in the map
    map<string, int>::iterator it = statePopulations.find(stateName);

    // Check if the state was found
    if (it != statePopulations.end()) {
        cout << "Population of " << stateName << ": " << it->second << endl;
    } else {
        cout << "State not found." << endl;
    }

    return 0;
}
//O/p:
Enter the name of a state: Maharashtra
Population of Maharashtra: 125000000
Enter the name of a state: Bihar
Population of Bihar: 130000000
Enter the name of a state: Punjab
State not found.
