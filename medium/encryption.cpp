#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    auto l = s.size();

    auto col = ceil(sqrt(l));
    auto row = floor(sqrt(l));

    string res;
    for(int j = 0; j < col; ++j) {
        for(int i = j; i < s.size(); i = i + col) {
            res.push_back(s[i]);
        }

        if(j != col - 1)
            res.push_back(' ');
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
