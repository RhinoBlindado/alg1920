#include <iostream>
#include <random>

int main(int argc, char const *argv[]) {

  if (argc != 4) {
    std::cerr << "Parametros: <size> <min> <max>" << '\n';
    return 1;
  }

  int size, min, max;

  size = atoi(argv[1]);
  min = atoi(argv[2]);
  max = atoi(argv[3]);

  std::cout << size << '\n';

  for (int i = 0; i < size; i++) {
    std::cout << i + 1 << '\t' << min + (rand() % (max - min + 1)) << '\n';
  }

  return 0;
}
