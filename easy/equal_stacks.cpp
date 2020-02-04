#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    vector<int> h1_heights;
    vector<int> h2_heights;
    vector<int> h3_heights;

    for(auto it = h1.rbegin() ; it != h1.rend(); ++it) {    
        auto block = *it;
        h1_heights.empty() ? h1_heights.push_back(block) : h1_heights.push_back(h1_heights.back() + block);
    }

    for(auto it = h2.rbegin() ; it != h2.rend(); ++it) {
        auto block = *it;
        h2_heights.empty() ? h2_heights.push_back(block) : h2_heights.push_back(h2_heights.back() + block);
    }

    for(auto it = h3.rbegin() ; it != h3.rend(); ++it) {
        auto block = *it;
        h3_heights.empty() ? h3_heights.push_back(block) : h3_heights.push_back(h3_heights.back() + block);
    }

    for(auto it = h1_heights.rbegin() ; it != h1_heights.rend(); ++it) {
        auto height1 = *it;

        for(auto it2 = h2_heights.rbegin() ; it2 != h2_heights.rend(); ++it2) {
            auto height2 = *it2;

            if(height1 < height2) {
                continue;
            } else if(height1 > height2) {
                break;
            } else if(height1 == height2) {
                for(auto it3 = h3_heights.rbegin() ; it3 != h3_heights.rend(); ++it3) {
                    auto height3 = *it3;

                    if(height1 < height3) {
                        continue;
                    } else if (height1 == height3){
                        return height1;   
                    } else {
                        break;
                    }  
                }
            }
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n1N2N3_temp;
    getline(cin, n1N2N3_temp);

    vector<string> n1N2N3 = split_string(n1N2N3_temp);

    int n1 = stoi(n1N2N3[0]);

    int n2 = stoi(n1N2N3[1]);

    int n3 = stoi(n1N2N3[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split_string(h1_temp_temp);

    vector<int> h1(n1);

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        int h1_item = stoi(h1_temp[h1_itr]);

        h1[h1_itr] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split_string(h2_temp_temp);

    vector<int> h2(n2);

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        int h2_item = stoi(h2_temp[h2_itr]);

        h2[h2_itr] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split_string(h3_temp_temp);

    vector<int> h3(n3);

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        int h3_item = stoi(h3_temp[h3_itr]);

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

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
