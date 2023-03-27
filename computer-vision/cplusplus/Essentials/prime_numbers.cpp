//
// Created by Shabnam on 3/27/2023.
//

#include <iostream>

using namespace std;

bool isPrime(int);

int main(int argc, char** argv){
    for(int i {2}; i < 100; ++i){
        if(!isPrime(i)) cout << i << endl;
    }

}

bool isPrime(int num){
    for(int i {2}; i < num; ++i){
        if(num % i == 0) return true;
    }
    return false;
}
