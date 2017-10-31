#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <numeric>

int main() {
    std::list<int> l(100);
    std::iota(l.begin(), l.end(), 0);

    std::vector<std::list<int>::iterator> v(l.size());
    std::iota(v.begin(), v.end(), l.begin());

    std::cout << "Contents of the list: ";
    for(auto n: l) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;


}


int filling() {

    std::vector<int> v(100);

    auto it = v.begin();
    auto end = v.end();

    auto algo = std::iota(it, end, 0);

    std::cout << algo << std::endl;

    return 0;

}
