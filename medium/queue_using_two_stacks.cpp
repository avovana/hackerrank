#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void process(const vector<int> &ops, const vector<int> &vals) {
    vector<int> mainStack;
    vector<int> helpStack;

    for (int i = 0; i < ops.size(); ++i) {
        int op = ops[i];
        int val = vals[i];

        switch (op) {
        case 1:
            mainStack.push_back(val);
            break;

        case 2:
            if (helpStack.empty()) {
                while (!mainStack.empty()) {
                    helpStack.push_back(mainStack.back());
                    mainStack.pop_back();
                }
            }

            helpStack.pop_back();
            break;

        case 3:
            if (helpStack.empty()) {
                while (!mainStack.empty()) {
                    helpStack.push_back(mainStack.back());
                    mainStack.pop_back();
                }
            }

            cout << helpStack.back() << endl;

            break;
        }
    }
}


//exeded time in some tests
void processV1(const vector<int> &ops, const vector<int> &vals) {
	vector<int> mainStack;
	vector<int> helpStack;

	for (int i = 0; i < ops.size(); ++i) {
		int op = ops[i];
		int val = vals[i];

		switch (op) {
		case 1:
			mainStack.push_back(val);
			break;

		case 2:
			for (int i = mainStack.size() - 1; i >= 1; --i) {
				helpStack.push_back(mainStack.back());
				mainStack.pop_back();
			}

			mainStack.pop_back();

			for (int i = helpStack.size() - 1; i >= 0; --i) {
				mainStack.push_back(helpStack.back());
				helpStack.pop_back();
			}

			break;

		case 3:
			for (int i = mainStack.size() - 1; i >= 1; --i) {
				helpStack.push_back(mainStack.back());
				mainStack.pop_back();
			}

			cout << mainStack.front() << endl;

			for (int i = helpStack.size() - 1; i >= 0; --i) {
				mainStack.push_back(helpStack.back());
				helpStack.pop_back();
			}
			break;
		}
	}
}

int main() {
    int num = 0;

    cin >> num;

    vector<int> ops;
    vector<int> vals;

    while (num--) {
        int in;

        cin >> in;
        ops.push_back(in);

        int nextChar = cin.peek();
        if (nextChar == 10 || nextChar == -1)
            vals.push_back(0);
        else {
            cin >> in;
            vals.push_back(in);
        }
    }

    process(ops, vals);

    return 0;
}
