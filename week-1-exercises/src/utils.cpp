#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int largest(vector<int> v){

    int len = size(v);

    int i;
    int temp = v[0];

    for(i; i<len; i++){
        if(v.at(i) > temp){
            temp = v.at(i);
        }
        
    } 
    return temp;
}