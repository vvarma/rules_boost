#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptor/type_erased.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <iostream>
#include <vector>
int main() {
  typedef boost::any_range<int, boost::forward_traversal_tag, int,
                           std::ptrdiff_t>
      integer_range;
  std::vector<int> myInts = {1, 2, 3, 4, 5};
  std::vector<int> expected = {2, 4, 6, 8, 10};
  std::vector<int> output;
  integer_range ra =
      myInts | boost::adaptors::transformed([](int x) { return x * 2; });
  boost::copy(ra, std::back_inserter(output));
  if (expected != output) {
    return 1;
  }
  return 0;
}
