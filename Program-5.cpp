
#include <iostream>
using namespace std;

static int goal = 35;
int count = 0;

void GameFunction(int numTokens, int turnsLeft, int count) {

    if (turnsLeft == 0) {
        cout << "Unable to reach number of tokens" << endl;
        return;
    }
    else if (numTokens == goal) {   
        cout << "Reached " << goal << " tokens at " << count << endl;
        return;
    }
    else {
        if (numTokens < goal) {
            numTokens += 25;
        }
        else {
            if (numTokens % 2) {
                numTokens /= 2;
            }
            else {
                numTokens += 25;
            }
        }
        cout << "Tokens Remaining: " << numTokens << endl;
        count++;
        GameFunction(numTokens, turnsLeft - 1, count);
    }
}
int main()
{
    GameFunction(13, 100, 0);
}

