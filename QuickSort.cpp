#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& vec, int pivot, int end);

int main()
{
    vector<int> vec = {6, 8, 3, 2, 5, 7, 9, 1, 10};

    sort(vec, 0, vec.size() - 1);
    
    for(auto v: vec){
        cout << v << endl;
    }

    return 0;
}

void sort(vector<int>& vec, int pivot, int end)
{
    if(pivot >= end) return;

    int i = pivot + 1;
    int j = end;
    
    bool small = false;
    bool big = false;
    int temp;
    
    while(i < j){
        while(vec[pivot] > vec[i] && i <= end){
            i++;
        }
        while(vec[pivot] < vec[j] && j > pivot){
            j--;
        }

        if(i > j){
            temp = vec[j];
            vec[j] = vec[pivot];
            vec[pivot] = temp;
        }
        else{
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }

    sort(vec, pivot, j - 1);
    sort(vec, j + 1, end);
}


