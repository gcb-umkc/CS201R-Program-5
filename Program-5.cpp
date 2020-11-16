
#include <iostream>
#include <vector>
using namespace std;

//Main recursive function that calculates how to reach a goal token path
bool GameFunction(int goal, int numTokens, int turnsLeft, vector<int>& path) {
    path.push_back(numTokens);

    //Checks for base case of reaching goal
    if (numTokens == goal) {   
        path.push_back(numTokens);
        return true;
    }
    //Otherwise checks for the base case of maximum depth
    else if (turnsLeft == 0) {
        //Backtracks and removes unviable path if cannot reach the goal at maximum depth
        path.erase(path.begin(), path.end());
        return false;
    }
    else {
        //Tries a branch of giving back half if the number is even
        if (numTokens % 2 == 0 && GameFunction(goal, numTokens / 2, turnsLeft - 1, path)) {
            path.push_back(numTokens);
            return true;
        }
        else {
            //Backtracks if the number is not divisible by 2 and the path is not viable
            path.erase(path.begin(), path.end());
        }
        //Tries a branch of adding 25 more tokens
        if (GameFunction(goal, numTokens + 25, turnsLeft - 1, path)) {
            path.push_back(numTokens);
            return true;
        }
    }
}
int main()
{
    vector<int> path;
    int numTurns;
    int goal;

    //Takes user input for the game
    cout << "Enter the goal amount of tokens: ";
    cin >> goal;
    cout << "Enter the maximum amount of turns: ";
    cin >> numTurns;

    //Calls recursive function
    if (GameFunction(goal, 13, numTurns, path)) {
        int turns = path.size() - 2;
        cout << goal << " found in " << turns << " " << ((turns > 1) ? "turns" : "turn") << endl;

        //Reports the vector in reverse order
        cout << "The path is: " << endl;
        for (int i = path.size() - 1; i > 0; i--) {
            cout << path.at(i) << endl;
        }
    }
    else {
        //If the number cannot be found at specified number of turns
        cout << "No path to " << goal << " was found in " << numTurns << " turns" << endl;
    }
    
}

