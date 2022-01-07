#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int array[5][5] ={{1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1},
    {0, 0, 1, 0, 0}};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}