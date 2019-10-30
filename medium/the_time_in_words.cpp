#include <bits/stdc++.h>
#include <map>

using namespace std;

map<int, string> hourToStr = 
{
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
};

vector<string> ones {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string res;

    if(m == 0)
        res = hourToStr[h] + " o' clock";
    else {
        auto spesWord = " past ";
        if(30 < m && m < 60) {
            m = 60 - m;
            spesWord = " to ";
            h++;
        }

        if (m == 30) {
            res = "half";
            spesWord = " past ";
        } else if (m % 15 == 0) {
            res = "quarter";
        } else {
            int tenNums = m / 10;
            if(tenNums == 0) {
                auto minutes = m == 1 ? " minute" : " minutes";
                res = ones[m] + minutes;
            }
            else if (tenNums == 1)
                res = teens[m % 10] + " minutes";
            else
                res = tens[tenNums] + " " + ones[m % 10] + " minutes";
        }

        res = res + spesWord + hourToStr[h];
    }  

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
