//
// Created by Shabnam on 3/29/2023.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    vector<int> vi1 {1, 2, 3, 4, 5, 6, 7};

    cout << vi1.size() << endl;
    cout << vi1.front() << endl;
    cout << vi1.back() << endl;

    for(const auto& e: vi1) {
        cout << "Element " << e << endl;
    }
    vi1.insert(vi1.begin() + 5, 45);
    for(const auto& i: vi1) {
        cout << "Element: " << i << endl;
    }

    vi1.push_back(48);
    for(const auto& i: vi1) {
        cout << "NEW ELEMENTS: " << i << endl;
    }


    return 0;
}
