//
// Created by Shabnam on 3/28/2023.
//

#include <iostream>
#include <string>

using namespace std;

int call_by_value(int);
void call_by_reference(int* );
void call_by_reference_operator(const int&);
const string& return_string(int);

int main(int argc, char** argv) {

    auto main_value {7};
    int arr[] {1, 2, 3, 4, 5};
    call_by_reference_operator(main_value);
    cout << "Value in function: " << call_by_value(main_value) << " Value in main: " << main_value << endl;
    call_by_reference_operator(main_value);
    call_by_reference(arr);
    cout << "Value in function: " << arr[0] << " Value in main: " << arr[0] << endl;

    auto s = return_string(75);
    cout << s << endl;
    return 0;
}

int call_by_value(int function_value) {
    return ++function_value;
}

void call_by_reference(int* reference) {
    *reference = 10;
}

void call_by_reference_operator(const int& reference) {
    cout << "This cannot be changed inside the function: " << reference << endl;
}

const string& return_string(int num) {
    static string s = "string is " + to_string(num);
    return s;
}
