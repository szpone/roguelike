#include <iostream>
#include <iterator>
#include <vector>

// reverse iteration

int reverse_order() {

  std::vector<int> v = {1, 2, 3, 4};
  auto it = v.rbegin();
  auto start = v.rend();

  for (; it != start; it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}

// iterators for string

int wordy() {
  std::string s = "Ala ma kota";

  for (auto it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}

// How do iterators describe ranges of items?

// By the start() and end() methods which points out the end and beginning of
// for example, a vector

// How do iterators look like for empty ranges? The same, but they're not going
// to compile;)

// int empty_range() {
//     std::vector<int> v = {};
//     auto start = v.begin();
//     auto end = v.end();

//     std::cout << *start << std::endl;

//     return 0;
// }

// How to iterate over

int iterate_over() {

  std::vector<int> v = {1, 2, 3, 4, 5};
  auto start = v.begin();
  auto end = v.end();

  for (; start != end; start++) {
    std::cout << *start << std::endl;
  }

  return 0;
}
