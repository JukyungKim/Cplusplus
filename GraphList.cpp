#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vertex[5];

    vertex[0].push_back(1);
    vertex[0].push_back(4);

    vertex[1].push_back(0);

    vertex[2].push_back(4);

    vertex[3].push_back(4);

    vertex[4].push_back(0);
    vertex[4].push_back(2);
    vertex[4].push_back(3);

    for(int i = 0; i < 5; i++){
        for(auto v: vertex[i]){
            cout << v;
        }
        cout << endl;
    }

    return 0;
}

