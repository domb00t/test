#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
// TODO сделать кадровую развертку

class Point {
public:
  Point() : x(0), y(0) {}
  explicit Point(int x, int y) : x(x), y(y) {}
  ~Point() = default;
  void move(int x, int y);
  void setPos(int x, int y);
  int getX() const { return x; }
  int getY() const { return y; }

private:
  int x;
  int y;
};

void Point ::move(int x = 0, int y = 0) {
  this->x += x;
  this->y += y;
}

void Point ::setPos(int x, int y) {
  this->x = x;
  this->y = y;
}

class Field {
public:
  Field() = delete;
  Field(int hight, int width);
  ~Field();

  void setPointPos(const Point &point);

private:
  char **field;
  int hight;
  int width;

  friend std ::ostream &operator<<(std ::ostream &os, const Field &field);
};

Field ::Field(int hight, int width)
    : field(new char *[hight]), hight(hight), width(width) {
  for (int i = 0; i < hight; ++i) {
    field[i] = new char[width];
  }
  for (int i = 0; i < hight; ++i) {
    for (int j = 0; j < width; ++j) {
      field[i][j] = '-';
    }
  }
}

Field ::~Field() {
  for (int i = 0; i < hight; ++i) {
    delete[] field[i];
  }
  delete[] field;
}

void Field ::setPointPos(const Point &point) {
  static Point buf_point(point.getX(), point.getY());
  static int count = 0;
  if (count == 0) {
    field[point.getX()][point.getY()] = '#';
    ++count;
  } else {
    field[point.getX()][point.getY()] = '#';
    field[buf_point.getX()][buf_point.getY()] = '-';
    buf_point.setPos(point.getX(), point.getY());
  }
}

std ::ostream &operator<<(std ::ostream &os, const Field &field) {
  for (int i = 0; i < field.hight; ++i) {
    os << '\t';
    for (int j = 0; j < field.width; ++j) {
      os << field.field[i][j];
    }
    os << std ::endl;
  }
  return os;
}

void frame(Field &field, Point &point) {
  std ::cout << field;
  point.move(0, 1); // UB out_of_range
  field.setPointPos(point);
  // std :: cout << "\n\n";
  std ::this_thread ::sleep_for(
      std ::chrono ::milliseconds(25)); // delay between frames
  std ::system("cls");
}

int main() {
  char c;
  std ::cout << "Start: " << std ::endl;
  do {
    std ::cin >> c;
  } while (c != 'n' && c != 'y');
  if (c == 'y') {
    Field field(10, 100); // field size
    Point point;
    while (true) {
      frame(field, point);
    }
  }
  return 0;
}
