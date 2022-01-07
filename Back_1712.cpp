#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
}

long long sum(std::vector<int> &a)
{
    long long buf;
    buf = 0;
    for(auto n: a){
        buf += n;
    }
    return buf;
}

