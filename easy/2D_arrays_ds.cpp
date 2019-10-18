#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int prev_max_sum = 0;
    bool first_entry = true;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;

            sum += arr[i][j];
            sum += arr[i][j+1];
            sum += arr[i][j+2];

            sum += arr[i+1][j+1];

            sum += arr[i+2][j];
            sum += arr[i+2][j+1];
            sum += arr[i+2][j+2];

            if(first_entry) {
                prev_max_sum = sum;
                first_entry = false;
            }

            if(sum > prev_max_sum)
                prev_max_sum = sum;
        }
    }

    return prev_max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

