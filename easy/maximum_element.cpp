#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> stack;
    vector<int> auxiliaryStack;
    int n;

    std::cin >> n;

    while(n--) {
        int type;
        std::cin >> type;

        switch (type) {
            case 1:
                int val;
                std::cin >> val;
                if(stack.empty()) {
                    stack.push_back(val);
                    auxiliaryStack.push_back(val);
                } else {
                    stack.push_back(val);
                    if(val > auxiliaryStack.back())
                        auxiliaryStack.push_back(val);
                    else
                        auxiliaryStack.push_back(auxiliaryStack.back());
                }
                
                break;
            case 2:
                stack.pop_back();
                auxiliaryStack.pop_back();
                break;
            case 3:
                //std::cout << *std::max_element(begin(stack), end(stack)) << '\n'; //slow
                std::cout << auxiliaryStack.back() << '\n';
                break;
            default:
                break;
        }
    }

    return 0;
}
