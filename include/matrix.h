#include <array>

template <int Rows, int Cols> struct Matrix {
    std::array<double, Rows * Cols> data{};

    struct RowProxy {
        double *rowStart;

        double &operator[](int c) {
            return rowStart[c];
        }
        const double &operator[](int c) const {
            return rowStart[c];
        }
    };

    RowProxy operator[](int r) {
        return RowProxy{data.data() + r * Cols};
    }
    const RowProxy operator[](int r) const {
        return RowProxy{const_cast<double *>(data.data() + r * Cols)};
    }
};
