#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> edges;

    edges.push_back({0, 1});
    edges.push_back({0, 2});

    edges.push_back({1, 0});
    edges.push_back({1, 3});

    edges.push_back({2, 0});
    edges.push_back({2, 4});

    edges.push_back({3, 1});

    edges.push_back({4, 2});

    for(auto edge: edges){
        for(int node = 0; node < 2; node++){
            cout << edge[node];
        }
        cout << endl;
    }
    

    return 0;
}