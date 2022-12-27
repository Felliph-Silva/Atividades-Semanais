#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    /*
    auto maior=[](int n1, int n2)->int
    {
        //With ternary operator:
        (n1 > n2) ? n1 : n2;
        //Traditional method:
        //if (n1 > n2) return n1;
        //else return n2;
    };
    */
    auto maior=[](vector <int> n)->int
    {
        auto n_result = 0;

        for (int i : n)
        {
            n_result = (n_result > i) ? n_result : i;
        }

        return n_result;
    };
    cout << maior({2,313,1231,123,532,32,432,5325,235,124,}) << endl;
    return 0;
}