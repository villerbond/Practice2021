#include <iostream>

int** createMatrix(int rows, int columns);
void deleteMatrix(int** M, int rows);
void printMatrix(int **M, int rows, int columns, const char pre[]);
int** inputMatrix(int &rows, int &columns);
void snailMatrix(int **M, int size);

int main() {
  int n;
  
  do {
      std::cout << "Input size of matrix: ";
      std::cin >> n;
  } while (n < 1);
    
  int **I = inputMatrix(n,n);
  printMatrix(I,n,n,"I = \n");
  std::cout << std::endl;
  snailMatrix(I,n);
  
  deleteMatrix(I,n);
  return 0;
}

int** createMatrix(int rows, int columns) {
  
  int** M = new int*[rows];

  for (int i = 0; i < rows; ++i) {
    M[i] = new int[columns];
  }
  
  return M;
}

void deleteMatrix(int** M, int rows) {
  for (int i = 0; i < rows; ++i) {
    delete[] M[i];
  }
  delete[] M;
}

void printMatrix(int **M, int rows, int columns, const char pre[]) {
  std::cout << pre;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      std::cout << M[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

int** inputMatrix(int &rows, int &columns) {
  int** M = createMatrix(rows,columns);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      std::cout << "matrix(" << i+1 << "," << j+1 << ") = ";
      std::cin >> M[i][j];
    }
  }

  return M;
}

void snailMatrix(int **M, int size) {

  int x = 0; // current cell --- like rows
  int y = 0; // current cell | like columns
  
  short dir = 1; // direction;

  // 0 - right
  // 1 - down
  // 2 - left
  // 3 - up

 //---First_print---right

  for (int i = 0; i < size; ++i) {
    std::cout << M[x][y] << " ";
    y++;
  }
  y--;
  
//---Next_prints---
  
  int steps = size - 1; // how much to print at time 
  short int flag = 1;
  
  while (steps != 0) {
    switch (dir) {

      case 0: // right
        for (int i = 0; i < steps; ++i) {
          y++;
          std::cout << M[x][y] << " ";
        }; break;
      
      case 1: // down
        for(int i = 0; i < steps; ++i) {
          x++;
          std::cout << M[x][y] << " ";
        }; break;
      
      case 2: // left
        for (int i = 0; i < steps; ++i) {
          y--;
          std::cout << M[x][y] << " ";
        }; break;
      
      case 3: // up
        for (int i = 0; i < steps; ++i) {
          x--;
          std::cout << M[x][y] << " ";
        }; break;
    }
    
    flag = (flag + 1) % 2;
    steps = steps - 1 * flag;
    dir = (dir + 1) % 4;;
  } 
}
