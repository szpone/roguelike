#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

// int main() {
//   std::list<int> l(100);
//   std::iota(l.begin(), l.end(), 0);

//   std::vector<std::list<int>::iterator> v(l.size());
//   std::iota(v.begin(), v.end(), l.begin());

//   std::cout << "Contents of the list: ";
//   for (auto n : l) {
//     std::cout << n << ' ';
//   }
//   std::cout << '\n';

//   return 0;
// }

// int main() {

//   std::vector<int> v(100);

//   auto it = v.begin();
//   auto end = v.end();

//   std::iota(it, end, 0);

//   for (auto each : v) {
//     std::cout << each << std::endl;
//   }

//   return 0;
// }

// accumulate

// int accumulate() {

//   std::vector<int> v(100);

//   int sum = std::accumulate(v.begin(), v.end(), 0);

//   std::cout << "sum: " << sum << std::endl;

//   return 0;
// }

// sort in descending order

int main() {
    std::vector<int> v{3, 4, 5, 6};

    std::sort(v.begin(), v.end(), std::greater<int>());

    for (auto a : v) {
      std::cout << a << " ";
    };

    return 0;


}
