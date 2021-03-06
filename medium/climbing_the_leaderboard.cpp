#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>
#include <chrono>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> res;

    auto last_element_it = unique(begin(scores), end(scores));
    scores.erase(last_element_it, end(scores));

    for(int i = 0; i < alice.size(); ++i) {
        auto curr_score = alice[i];
        auto place_to_insert_rev_it = upper_bound(rbegin(scores), rend(scores), curr_score);
        auto place_to_insert_it = (place_to_insert_rev_it+1).base();
        scores.insert(place_to_insert_it+1, curr_score);

        auto score_rev_it = upper_bound(rbegin(scores), rend(scores), curr_score);
        auto score_it = (score_rev_it).base();

        auto rank = distance(begin(scores), score_it);
        res.push_back(rank+1);
    }

    return res;
}

int main()
{
    ifstream fin("../input.txt");

    int scores_count;
    fin >> scores_count;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    string scores_temp_temp;
    getline(fin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    fin >> alice_count;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    string alice_temp_temp;
    getline(fin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    vector<int> result = climbingLeaderboard(scores, alice);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    cout << duration << " ns";
    cout << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

