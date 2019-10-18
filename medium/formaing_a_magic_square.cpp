#include <bits/stdc++.h>
#include <numeric>
#include <limits>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<int>> magic_squares_in_row = {
        {6,1,8,7,5,3,2,9,4},
        {8,1,6,3,5,7,4,9,2},
        {6,7,2,1,5,9,8,3,4},
        {8,3,4,1,5,9,6,7,2},
        {2,7,6,9,5,1,4,3,8},
        {4,3,8,9,5,1,2,7,6},
        {2,9,4,7,5,3,6,1,8},
        {4,9,2,3,5,7,8,1,6}
    };

    vector<int> almost_square_in_row;
    for(int row = 0; row < s.size(); ++row)
        for(int col = 0; col < s.size(); ++col)
            almost_square_in_row.push_back(s[row][col]);

    int prev_difference = numeric_limits<int>::max();

    for(int i = 0; i < magic_squares_in_row.size(); ++i) {
        auto it_a = begin(almost_square_in_row);
        auto &magic_square_in_row = magic_squares_in_row[i];

        int difference = 0;

        for_each(begin(magic_square_in_row), end(magic_square_in_row),[&](auto &x){
                auto el = *it_a++;
                auto el_diff = (x > el) ? x - el : el - x;

                difference += el_diff;
            });

        if(difference < prev_difference)
            prev_difference = difference;
    }

    return prev_difference;
}

int main()
{
    ifstream fin("../input.txt");

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++)
            fin >> s[i][j];

        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    return 0;
}

