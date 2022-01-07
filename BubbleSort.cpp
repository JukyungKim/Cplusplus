#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& vec);

int main()
{
    vector<int> vec = {4, 2, 1, 8, 10};

    sort(vec);

    for(vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++){
        cout << *itr << endl;
    }

    return 0;
}

void sort(vector<int>& vec)
{
    for(vector<int>::iterator itrBase = vec.begin(); itrBase != vec.end(); itrBase++){
        for(vector<int>::iterator itrSub = itrBase + 1; itrSub != vec.end(); itrSub++){
            if(*itrBase > *itrSub){
                int temp;

                temp = *itrBase;
                *itrBase = *itrSub;
                *itrSub = temp;    
            }
        }
    }
}

