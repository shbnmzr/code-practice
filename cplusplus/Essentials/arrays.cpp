//
// Created by Shabnam on 3/10/2023.
//

#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int arr[5] {};
    int* ip = arr;
     *ip = 1;
     ip++;
     *ip = 2;
     *(++ip) = 5;
     for(const auto& e: arr){
         cout << e << endl;
     }


    return 0;
}