#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void traverse(int nodeIdx, vector<int> &res, const vector<vector<int>> &indexes) {
    auto leftChildNodeValue = indexes[nodeIdx][0];
    if(leftChildNodeValue != -1) {
        auto leftChildNodeIdx = leftChildNodeValue - 1;
        traverse(leftChildNodeIdx, res, indexes);
    }

    auto nodeValue = nodeIdx + 1;
    res.push_back(nodeValue);

    auto rightChildNodeValue = indexes[nodeIdx][1];
    if(rightChildNodeValue != -1) {
        auto rightChildNodeIdx = rightChildNodeValue - 1;
        traverse(rightChildNodeIdx, res, indexes);
    }
}

void getNodesDepth(int nodeIdx, int &currDepth, vector<vector<int>> &depthAndNodes, const vector<vector<int>> &indexes) {
    auto leftChildNodeValue = indexes[nodeIdx][0];
    if(leftChildNodeValue != -1) {
        auto leftChildNodeIdx = leftChildNodeValue - 1;
        getNodesDepth(leftChildNodeIdx, ++currDepth, depthAndNodes, indexes);
    }

    auto nodeValue = nodeIdx + 1;

    if(currDepth >= depthAndNodes.size())
        depthAndNodes.resize(currDepth + 1);

    depthAndNodes[currDepth].push_back(nodeValue);

    auto rightChildNodeValue = indexes[nodeIdx][1];
    if(rightChildNodeValue != -1) {
        auto rightChildNodeIdx = rightChildNodeValue - 1;
        getNodesDepth(rightChildNodeIdx, ++currDepth, depthAndNodes, indexes);
    }

    --currDepth;
}

void debugOutput(const string &str, const vector<vector<int>> &indexes) {
    cout << str << endl;

    for(int i = 0; i < indexes.size(); ++i)
        for(int j = 0; j < indexes[i].size(); ++j)
            cout << "[" << i << "][" << j << "] = " << indexes[i][j] << endl;
}

void debugOutput(const string &str, const vector<int> &container) {
    cout << str << endl;

    for (int i = 0; i < container.size(); ++i)
        cout << container[i] << " ";

    cout << endl;
    cout << endl;
}

void swapNodesAtDepth(int depth, const vector<vector<int>> &depthAndNodes, vector<vector<int>> &indexes) {
    vector<int> nodesAtDepth;

    for(int i = 0; i < depthAndNodes[depth].size(); ++i)
        nodesAtDepth.push_back(depthAndNodes[depth][i]);

    for(auto i : nodesAtDepth) {
        auto leftChild = indexes[i - 1][0];
        auto rightChild = indexes[i - 1][1];

        indexes[i - 1][0] = rightChild;
        indexes[i - 1][1] = leftChild;
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> res;

    //debugOutput("indexes:", indexes);

    vector<vector<int>> depthAndNodes;

    auto nodeIdx = 0;
    auto currDepth = 1;

    getNodesDepth(nodeIdx, currDepth, depthAndNodes, indexes);
    //debugOutput("depthAndNodes:", depthAndNodes);

    auto maxDepth = depthAndNodes.size() - 1;

    //vector<int> resOfTraverseForDebug;
    //traverse(nodeIdx, resOfTraverseForDebug, indexes);
    //debugOutput("traverse:", resOfTraverseForDebug);

    vector<int> resOfTraverse;
    for(int i = 0; i < queries.size(); ++i) {
        int k = queries[i];
        for (int multiple = 1; k * multiple < maxDepth; ++multiple) {
            swapNodesAtDepth(k * multiple, depthAndNodes, indexes);

            //Debug
            //vector<int> resOfTraverseForDebug;
            //traverse(nodeIdx, resOfTraverseForDebug, indexes);
            //debugOutput("traverse:", resOfTraverseForDebug);
        }

        traverse(nodeIdx, resOfTraverse, indexes);
        //string str_output = "queries[" + to_string(i) + "] = " + to_string(k) + ":";
        //debugOutput(str_output, resOfTraverse);
        res.push_back(resOfTraverse);
        resOfTraverse.clear();
    }

    return res;
}

int main()
{
    ifstream fin("../input.txt");

    int n;
    fin >> n;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            fin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    fin >> queries_count;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        fin >> queries_item;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }


    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            cout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                cout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

/* Wrong assumption
 *
 * Assumed that this formula will help me to calculate max depth of a tree:
 * n <= 2^h
 *  - numbers of nodes less or equal 2 in a degree of height
 * So if we know _n_ we can calculate max height:
 * h = log2(n)
 * But this works only with full binary tree

 /main { ...auto maxDepth = calcMaxDepthOfATree(indexes); ...}

auto log(double a, double b) {
    return log(b) / log(a);
}

int computePowerOf2_v1(int num) {
    int complete2s = log(num) / log(2);
    double reminder = fmod(log(2), log(num));

    int additional2BecauseTheReminder = reminder != 0 ? 1 : 0;
    return complete2s + additional2BecauseTheReminder;
}

int computePowerOf2_v2(int num) {
    int complete2s = 0;
    int additional2BecauseTheReminder = 0;

    if(num%2)
        ++additional2BecauseTheReminder;

    while(num>=1) {
        num>>=1;
        ++complete2s;
    }

    return complete2s + additional2BecauseTheReminder;
}

int calcMaxDepthOfATree(vector<vector<int>> indexes) {
    int powersOf2 = computePowerOf2_v2(indexes.size());
    return powersOf2;
}

*/
