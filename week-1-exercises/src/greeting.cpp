#include <iostream>
#include <string>
#include "utils.hpp"
#include <vector>

using namespace std;

int main(){

    cout << "The gcd of 8 and 6 is" << gcd(8, 6) << endl;

    vector<int> v{1, 2, 3, 4};
    cout << v[0] << " " << v.at(1) << endl;

    vector<int> a{1, 2, 3, 4, 5, 10, 6};

    cout << largest(a) << endl;

    return 0;
}
