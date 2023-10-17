#ifndef SLICE_H
#define SLICE_H

#include <iterator>

namespace detail {
template <typename Container, typename Index> class slice {
public:
  slice(Container &c, const Index i, const Index j) : mc{c}, mi{i}, mj{j} {}

  [[nodiscard]] auto begin() { return std::next(std::begin(mc), mi); }
  [[nodiscard]] auto end() { return std::next(std::begin(mc), mj); }

private:
  Container &mc;
  Index mi;
  Index mj;
};
} // namespace detail

template <typename Container, typename Index>
[[nodiscard]] auto slice(Container &c, const Index i, const Index j) {
  return detail::slice<Container>(c, i, j);
}

#endif
