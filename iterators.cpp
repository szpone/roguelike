#include <iostream>
#include <vector>
#include <iterator>


//reverse iteration

// int main() {

//     std::vector<int> v = {1, 2, 3, 4};
//     auto it = v.rbegin();
//     auto start = v.rend();

//     for(; it != start; it++) {
//         std::cout << *it << std::endl;
//     }

//     return 0;
// }


// iterators for string

// int main() {
//     std::string s = "Ala ma kota";

//     for(auto it = s.begin(); it != s.end(); it++) {
//         std::cout << *it << std::endl;
//     }

//     return 0;
// }


// How do iterators describe ranges of items?

// By the start() and end() methods which points out the end and beginning of for example, a vector

// How do iterators look like for empty ranges?

// int main() {
//     std::vector<int> v = {};
//     auto start = v.begin();
//     auto end = v.end();

//     std::cout << *start << std::endl;

//     return 0;
// }


// How to iterate over

// int main() {

//     std::vector<int> v = {1, 2, 3, 4, 5};
//     auto start = v.begin();
//     auto end = v.end();

//     for (; start != end; start++) {
//         std::cout << *start << std::endl;
//     }


//     return 0;
// }





// int main() {
//     int x;

//     std::vector<int> v;

//     std::cout << "Enter as many number as you want:\n";

//     while (std::cin >> x) {
//         v.push_back(x);
//     }

//     std::size_t i = 0;
//     std::size_t greatest_index = 0;
//     std::size_t least_index = 0;
//     while (i < v.size()) {
//         if (v[i] > v[greatest_index])
//             greatest_index = i;
//         if (v[i] < v[least_index])
//             least_index = i;
//         i += 1;
//     }




//     if (v.empty()) {
//         std::cout << "An empty sequence has no greatest or least element.\n";
//     } else {
//         std::cout << "Greatest element " << v[greatest_index] << " is at index " << greatest_index << ".\n";
//         std::cout << "Least element " << v[least_index] << " is at index " << least_index << ".\n";
//     }

//     return 0;

// }
// for (auto start = std::begin(v), end = std::end(v); start != end; start++)
