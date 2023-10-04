#include "slice.h"
#include <catch2/catch_test_macros.hpp>
#include <vector>

SCENARIO("A developer can use a slice") {
  GIVEN("a vector of integers") {
    const std::vector<int> numbers{1, 2, 3, 4, 5, 6};
    WHEN("sums a slice") {
      int sum{0};
      for (auto n : slice(numbers, 1, 4)) {
        sum += n;
      }
      THEN("the sum is correct") { CHECK(sum == 9); }
    }
  }
}
