#include <iostream>
#include <initializer_list>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>

using namespace std;

template <typename T, std::size_t N>
size_t arraySize(T (&)[N]) noexcept {
  return N;
}

// Capture initializer_list
template <typename T>
void printInitializerList(initializer_list<T> lst) {
  for (auto&& i : lst)
    cout << i << " ";
  cout << endl;
}

template <typename Container, typename Index>
decltype(auto) get(Container& c, Index i) {
  return c[i];
}

int main() {
  // C++'s ability to deduct reference to arrays
  int arr[15];
  cout << "Array size: " << arraySize(arr) << endl;

  printInitializerList({1, 2, 3, 4, 5});

  vector<int> vec = {1, 2, 3};
  cout << get(vec, 2) << endl;

  get(vec, 2) = 5;
  cout << get(vec, 2) << endl;

  return 0;
}
