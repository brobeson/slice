#ifndef SLICE_H
#define SLICE_H

#include <iterator>

namespace detail {
template <typename Container> class slice {
public:
  slice(Container &c, int i, int j) : mc{c}, mi{i}, mj{j} {}

  [[nodiscard]] auto begin() { return std::next(std::begin(mc), mi); }
  [[nodiscard]] auto end() { return std::next(std::begin(mc), mj); }

private:
  Container &mc;
  int mi;
  int mj;
};
} // namespace detail

template <typename Container>
[[nodiscard]] auto slice(Container &c, int i, int j) {
  return detail::slice<Container>(c, i, j);
}

#endif
