#include "slice.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
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

TEST_CASE("Benchmark the slice performance") {
  const std::vector<int> numbers{1, 2, 3, 4, 5, 6};
  BENCHMARK("Slice") {
    return slice(numbers, 1, 4);
  };
}
