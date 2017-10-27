#include <iostream>
#include <vector>
#include <iterator>

int main() {
    int x;

    std::vector<int> v;

    std::cout << "Enter as many number as you want:\n";

    while (std::cin >> x) {
        v.push_back(x);
    }

    // std::size_t i = 0;
    // std::size_t greatest_index = 0;
    // std::size_t least_index = 0;
    // while (i < v.size()) {
    //     if (v[i] > v[greatest_index])
    //         greatest_index = i;
    //     if (v[i] < v[least_index])
    //         least_index = i;
    //     i += 1;
    // }

    for (vector<v>::const_iterator iter v.begin();
        iter != students.end(); ++iter) {
        cout << (*iter) << endl;
    }



    // if (v.empty()) {
    //     std::cout << "An empty sequence has no greatest or least element.\n";
    // } else {
    //     std::cout << "Greatest element " << v[greatest_index] << " is at index " << greatest_index << ".\n";
    //     std::cout << "Least element " << v[least_index] << " is at index " << least_index << ".\n";
    // }

    return 0;

}
