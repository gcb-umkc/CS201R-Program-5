
#include <iostream>
using namespace std;

static int goal = 36;
int count = 0;

#include <vector>

bool GameFunction(int numTokens, int turnsLeft, int count, vector<int>& path) {
    count++;
    path.push_back(numTokens);
    if (numTokens == goal) {   
        path.push_back(numTokens);
        cout << "Reached " << goal << " tokens at depth " << count << endl;
        return true;
    }
    else if (turnsLeft == 0) {
        path.erase(path.begin(), path.end());
        //cout << "Unable to reach number of tokens" << endl;
        return false;
    }
    else {
        if (numTokens % 2 == 0 && GameFunction(numTokens / 2, turnsLeft - 1, count, path)) {
            path.push_back(numTokens);
            return true;
        }
        else {
            path.erase(path.begin(), path.end());
        }
        if (GameFunction(numTokens + 25, turnsLeft - 1, count, path)) {
            path.push_back(numTokens);
            return true;
        }
        else{
            //path.erase(path.begin(), path.end());
        }
    }
}
int main()
{
    vector<int> path;

   
    GameFunction(13, 7, 0, path);

    for (int i = path.size() - 1; i > 0; i--) {
        cout << path.at(i) << endl;

    }
}

