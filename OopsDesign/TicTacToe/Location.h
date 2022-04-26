#ifndef __LOCATION_H__
#define __LOCATION_H__

class Location {
public:
    Location() = default;
    Location(int row, int col) : m_row(row), m_col(col) {}

    void setRow(int row) { m_row = row; }
    void setCol(int col) { m_col = col; }

    int getRow() { return m_row; }
    int getCol() { return m_col; }

private:
    int m_row;
    int m_col;
};

#endif
