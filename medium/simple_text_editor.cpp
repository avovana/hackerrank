#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> actions;
    vector<string> args;

    //read input
    int n;
    cin >> n;

    while(n--) {
        int action;
        cin >> action;

        string arg(" ");
        
        if(action != 4)
            cin >> arg;

        actions.push_back(action);
        args.push_back(arg);
    }

    // process data
    vector<string> strStates;

    for (int i = 0; i < actions.size(); ++i) {
        switch (actions[i]) {
        case 1:
        {
            string lastStateStr;
            if(!strStates.empty())
                lastStateStr = strStates.back();

            lastStateStr.append(args[i]);
            strStates.push_back(lastStateStr);
        }
        break;

        case 2:
        {
            int k = stoi(args[i]);
            string lastStateStr = strStates.back();
            lastStateStr.resize(lastStateStr.size() - k);
            strStates.push_back(lastStateStr);
        }
        break;

        case 3:
        {
            string lastStateStr = strStates.back();
            int kth = stoi(args[i]) - 1;
            cout << lastStateStr[kth] << endl;
        }
        break;

        case 4:
            strStates.pop_back();
            break;

        default:
            break;
        }
    }
    /* debug output
    for(auto el : actions)
        cout << el << " ";

    cout << '\n';
    
    for(auto el : args)
        cout << el << " ";
    */
    return 0;
}
