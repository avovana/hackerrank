#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
auto extraLongFactorials(int n) {
    vector<int> res;

    res.push_back(1);

    int carry = 0;

    for(int i = 2 ; i <= n; ++i) {
        for(int j = 0; j < res.size(); ++j) {
            auto temp = res[j] * i + carry;
            carry = 0;

            res[j] = temp % 10;
            carry = temp / 10;
            }

        while(carry) {
            res.push_back(carry%10);
            carry /= 10;
        }
    }

    return res;
}

int main()
{
    ifstream fin("../input.txt");

    int n;
    fin >> n;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto res = extraLongFactorials(n);

    for(int i = res.size() - 1; i >=0; --i)
        cout << res[i];

    return 0;
}

