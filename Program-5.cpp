
#include <iostream>
using namespace std;

static int goal = 69;
int count = 0;

#include <vector>

bool GameFunction(int numTokens, int turnsLeft, int count, vector<int>& path) {
    count++;
    if (turnsLeft == 0) {
        cout << "Unable to reach number of tokens" << endl;
        return false;
    }
    if (numTokens == goal) {   
        path.push_back(numTokens);
        cout << "Reached " << goal << " tokens at " << count << endl;
        return true;
    }
    else {
        if (numTokens % 2 == 0 && GameFunction(numTokens / 2, turnsLeft - 1, count, path)) {
            path.push_back(numTokens);
        }
        if (GameFunction(numTokens + 25, turnsLeft - 1, count, path)) {
            path.push_back(numTokens);
        }
    }
}
int main()
{
    vector<int> path;
    
    GameFunction(13, 5, 0, path);
    path.push_back(13);

    for (int i = 0; i < path.size(); i++) {
        cout << path.at(i) << endl;
    }
}

