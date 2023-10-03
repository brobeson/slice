template <typename Container>
class slice {
  slice(Container& c, int i, int j = c.end());
  auto begin();  /// Return the iterator to the ith element of c.
  auto end(); /// Return the iterator to the jth element of c.
};
