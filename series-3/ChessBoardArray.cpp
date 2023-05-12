#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

class ChessBoardArray {
  protected:
    class Row {
      public:
        // Constructor
        Row(ChessBoardArray &a, int i) : chessBoardArray(a), row(i) {}

        int &operator[](int i) const {
            return chessBoardArray.select(row, i);
        }

        int getValue(int col) {
            return chessBoardArray.select(row, col);
        }

        // Fields
      private:
        ChessBoardArray &chessBoardArray;
        int row;
    };

    class ConstRow {
      public:
        ConstRow(const ChessBoardArray &a, int i) : chessBoardArray(a), row(i) {}

        const int &operator[](int i) const {
            return chessBoardArray.select(row, i);
        }

      private:
        const ChessBoardArray &chessBoardArray;
        int row;
    };

  public:
    const Row operator[](int i) {
        return Row(*this, i);
    }

    const ConstRow operator[](int i) const {
        return ConstRow(*this, i);
    }

    // Constructors
    ChessBoardArray(unsigned s = 0, unsigned b = 0) : base(b), size(s) {
        data = new int[getLength()];
        for (unsigned i = 0; i < getLength(); i++) {
            data[i] = 0;
        }
    }

    ChessBoardArray(const ChessBoardArray &a) : base(a.base), size(a.size) {
        data = new int[getLength()];
        for (unsigned i = 0; i < getLength(); i++) {
            data[i] = a.data[i];
        }
    }

    // Destructor
    ~ChessBoardArray() {
        delete[] data;
    }

    ChessBoardArray &operator=(const ChessBoardArray &a) {
        base = a.base;
        size = a.size;

        delete[] data;
        data = new int[a.getLength()];

        for (unsigned i = 0; i < a.getLength(); i++) {
            data[i] = a.data[i];
        }

        return *this;
    }

    int &select(int i, int j) {
        return data[loc(i, j)];
    }

    int &select(int i, int j) const {
        return data[loc(i, j)];
    }

    friend ostream &operator<<(ostream &out, const ChessBoardArray &a) {
        for (unsigned i = a.base; i < a.base + a.size; i++) {
            for (unsigned j = a.base; j < a.base + a.size; j++) {
                int value = (i + j) % 2 == 0 ? a[i][j] : 0;
                out << setw(4) << value;
            }

            out << endl;
        }
        return out;
    }

  private:
    unsigned int base;
    unsigned int size;

    int *data;

    unsigned int getLength() const {
        if (size % 2 == 0) {
            return size * size / 2 + 0;
        } else {
            return size * size / 2 + 1;
        }
    }

    unsigned int loc(int i, int j) const throw(out_of_range) {
        if (i < base || j < base) throw out_of_range("out of bounds");

        unsigned int di = i - base;
        unsigned int dj = j - base;

        if (di >= size || dj >= size) throw out_of_range("out of bounds");
        if ((di + dj) % 2 != 0) throw out_of_range("not valid coordinates");

        return (dj + di * size) / 2;
    }
};
