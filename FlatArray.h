#ifndef FLATARRAY
#define FLATARRAY

#include <array>
#include <functional>

// An alias template to allow us to define a one-dimensional std::array using two dimensions
template <typename T, std::size_t Row, std::size_t Col>
using ArrayFlat2d = std::array<T, Row * Col>;

// A modifiable view that allows us to work with an ArrayFlat2d using two dimensions
// This is a view, so the ArrayFlat2d being viewed must stay in scope
template <typename T, std::size_t Row, std::size_t Col>
class ArrayView2d
{
private:
    // You might be tempted to make m_arr a reference to an ArrayFlat2d,
    // but this makes the view non-copy-assignable since references can't be reseated.
    // Using std::reference_wrapper gives us reference semantics and copy assignability.
    std::reference_wrapper<ArrayFlat2d<T, Row, Col>> m_arr {};

public:
    ArrayView2d(ArrayFlat2d<T, Row, Col> &arr)
        : m_arr { arr }
    {}

    // Get element via single subscript (using operator[])
    T& operator[](int i) { return m_arr.get()[static_cast<std::size_t>(i)]; }
    const T& operator[](int i) const { return m_arr.get()[static_cast<std::size_t>(i)]; }

    // Get element via 2d subscript (using operator(), since operator[] doesn't support multiple dimensions prior to C++23)
    T& operator()(int row, int col) { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }
    const T& operator()(int row, int col) const { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }

    // in C++23, you can uncomment these since multidimensional operator[] is supported
//    T& operator[](int row, int col) { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }
//    const T& operator[](int row, int col) const { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }

    int rows() const { return static_cast<int>(Row); }
    int cols() const { return static_cast<int>(Col); }
    int length() const { return static_cast<int>(Row * Col); }
};

#endif
