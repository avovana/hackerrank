#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
/*
//1 Work Version
//main algorithm - find elements after last sorted and put it
//but we need special case - find "1" - 1st sorted value

void find1(vector<int> &A) {
    auto firstElemIter = begin(A);
    auto oneIter = find(begin(A), end(A), 1);

    while (oneIter != firstElemIter) {
        if (oneIter == firstElemIter + 1 || oneIter == firstElemIter + 2) {
            std::rotate(firstElemIter, oneIter, firstElemIter + 3);
            break;
        }

        auto dist = distance(firstElemIter, oneIter);
        while (dist >= 3) {
            auto leftBound = oneIter - 2;
            auto rightBound = oneIter;
            auto someIt = std::rotate(leftBound, rightBound, rightBound + 1);
            oneIter = leftBound;
            dist = distance(firstElemIter, oneIter);
        }
    }
}

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
    auto lastSortedElemIter = A.begin();
    
    find1(A);

    auto nextSortedValIt = find(lastSortedElemIter, end(A), 2);

    while (lastSortedElemIter + 1 != end(A)) {
        //if (nextSortedValIt == begin(A)) {
        //    nextSortedValIt = find(lastSortedElemIter, end(A), 2);
        //    continue;
        //}

        if (nextSortedValIt == lastSortedElemIter + 1) {
            lastSortedElemIter++;
            nextSortedValIt = find(lastSortedElemIter, end(A), *nextSortedValIt + 1); 
            continue;
        }

        if (nextSortedValIt == lastSortedElemIter + 2) {
            if (nextSortedValIt + 1 == end(A))
                return "NO";

            auto leftBound = lastSortedElemIter + 1;
            auto rightBound = lastSortedElemIter + 4;
            std::rotate(leftBound, nextSortedValIt, rightBound);

            lastSortedElemIter++;
            nextSortedValIt = find(lastSortedElemIter, end(A), *lastSortedElemIter + 1);
            continue;
        }

        auto dist = distance(lastSortedElemIter, nextSortedValIt);
        while (dist >= 3) {
            auto leftBound = nextSortedValIt - 2;
            auto rightBound = nextSortedValIt;
            auto someIt = std::rotate(leftBound, rightBound, rightBound + 1);
            nextSortedValIt = leftBound;
            dist = distance(lastSortedElemIter, nextSortedValIt);
        }
    }

    return "YES";
}
*/

//2 Work Version
// main algorithm - to put next element on firstUnordered position
string larrysArray(vector<int> A) {
    auto firstUnsorted = begin(A);
    auto nextToBeSorted = find(begin(A), end(A), 1);

    while (firstUnsorted != end(A) - 1) {
        if (nextToBeSorted == firstUnsorted) {
            firstUnsorted++;
            nextToBeSorted = find(begin(A), end(A), *nextToBeSorted + 1);
            continue;
        }

        if (nextToBeSorted == firstUnsorted + 1) {
            if (firstUnsorted + 2 == end(A))
                return "NO";

            std::rotate(firstUnsorted, nextToBeSorted, firstUnsorted + 3);
            nextToBeSorted = find(begin(A), end(A), *firstUnsorted + 1);
            firstUnsorted++;
            continue;
        }

        while (distance(firstUnsorted, nextToBeSorted) >= 2) {
            auto leftBound = nextToBeSorted - 2;
            auto rightBound = nextToBeSorted;
            std::rotate(leftBound, rightBound, rightBound + 1);
            nextToBeSorted = leftBound;
        }
    }

    return "YES";
}

int main()
{
    ifstream fin("../input.txt");
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

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
