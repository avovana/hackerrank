#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
void debugOutput(const vector<vector<int>> &A);

// Complete the surfaceArea function below.
int surfaceArea(const vector<vector<int>> &A) {
    debugOutput(A);
    int surfaces = 0;

    //1. add sides surfaces
    //iterate rows
    for(int rowIdx = 0; rowIdx < A.size(); ++rowIdx) {
        auto &row = A[rowIdx];
        auto maxHeight = *std::max_element(row.begin(), row.end());

        //iterate heights
        for(int currHeight = 1; currHeight <= maxHeight; ++currHeight) {
            //iterate line - part of a row at currHeight
            for(int col = 0; col < row.size(); col++) {
                int heightOfCubes = row[col];
                bool cubeExistsOnThisHeight = heightOfCubes >= currHeight ? true : false;

                //findSurfaces of this cube
                if(cubeExistsOnThisHeight) {
                        // find neighbors cubes
                        //  1. find neighbors cubes at this row
                        bool cubeAtLeftmostPos = col == 0 ? true : false;
                        if(not cubeAtLeftmostPos) {
                            int heightOfTheLeftCubes = row[col - 1];
                            bool cubeExistsOnThisHeight = heightOfTheLeftCubes >= currHeight ? true : false;
                            if (!cubeExistsOnThisHeight)
                                surfaces++;
                        } else
                            surfaces++;

                        bool cubeAtRightmostPos = col + 1 == row.size() ? true : false;
                        if(not cubeAtRightmostPos) {
                            int heightOfRightCubes = row[col + 1];
                            bool cubeExistsOnThisHeight = heightOfRightCubes >= currHeight ? true : false;
                            if (!cubeExistsOnThisHeight)
                                surfaces++;
                        } else
                            surfaces++;

                        //  2. find neighbors cubes at neighbors rows
                        bool rowAtTopPos = rowIdx == 0 ? true : false;
                        if(not rowAtTopPos) {
                            auto &rowAbove = A[rowIdx - 1];
                            int heightOfTheAboveCubes = rowAbove[col];
                            bool cubeExistsOnThisHeight = heightOfTheAboveCubes >= currHeight ? true : false;
                            if (!cubeExistsOnThisHeight)
                                surfaces++;
                        } else
                            surfaces++;

                        bool rowAtBottomPos = rowIdx + 1 == A.size() ? true : false;
                        if(not rowAtBottomPos) {
                            auto &rowBelow = A[rowIdx + 1];
                            int heightOfThBelowCubes = rowBelow[col];
                            bool cubeExistsOnThisHeight = heightOfThBelowCubes >= currHeight ? true : false;
                            if (!cubeExistsOnThisHeight)
                                surfaces++;
                        } else
                            surfaces++;
                }
            }
        }
    }

    //add top and bottom surfaces
    for(int rowIdx = 0; rowIdx < A.size(); ++rowIdx)
        for(int col = 0; col < A[rowIdx].size(); col++) {
            bool atLeastOneCubeExists = A[rowIdx][col] != 0 ? true : false;
            if(atLeastOneCubeExists)
                surfaces = surfaces + 2;
        }

    return surfaces;
}

int main()
{
    ifstream fin("../input.txt");

    string HW_temp;
    getline(fin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            fin >> A[i][j];
        }

        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    cout << result << "\n";

    return 0;
}

void debugOutput(const vector<vector<int>> &A) {
    for(int i = 0; i < A.size(); ++i) {
        auto &row = A[i];

        auto max_it = std::max_element(row.begin(), row.end());
        cout << "max: " << *max_it << endl;

        for(int col = 0; col < row.size(); ++col)
            cout << "[" << i << "][" << col << "] = " << row[col] << endl;
    }
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
