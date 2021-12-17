#include <iostream>

int** createMatrix(int rows, int columns);
void deleteMatrix(int** M, int rows);
void printMatrix(int **M, int rows, int columns, const char pre[]);
int** inputMatrix(int &rows, int &columns);
int** snailMatrix(int rows, int columns);

int main() {
    int n,m;
  
    do {
        std::cout << "Input row's number: ";
        std::cin >> n;
        std::cout << "Input column's number: ";
        std::cin >> m;
    } while (n < 1 or m < 1);
    
    int** I = snailMatrix(n,m);
    printMatrix(I,n,m,"I = \n");
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

int** snailMatrix(int rows, int columns) {

    int** M = createMatrix(rows,columns);
    int x = 0; // current cell --- like columns
    int y = 0; // current cell | like rows
    short dir = 1; // direction;

    // 0 - right
    // 1 - down
    // 2 - left
    // 3 - up
  
    //---Next_prints---for square matrix and for rectangle matrix
  
    // square matrix

    if (rows == columns) {
        //---First_print---right
        int temp = 1;
        int size = rows;
        for (int i = 0; i < size; ++i) {
            M[x][y] = temp++;
            y++;
        }
        y--;
  
        int steps = size - 1; // how much to print at time 
        short int flag = 1; // guarantees every step two times
  
        while (steps != 0) {
            switch (dir) {

                case 0: // right
                    for (int i = 0; i < steps; ++i) {
                        y++;
                        M[x][y] = temp++;
                    }; break;
      
                case 1: // down
                    for(int i = 0; i < steps; ++i) {
                        x++;
                        M[x][y] = temp++;
                    }; break;
      
                case 2: // left
                    for (int i = 0; i < steps; ++i) {
                        y--;
                        M[x][y] = temp++;
                    }; break;
      
                case 3: // up
                    for (int i = 0; i < steps; ++i) {
                        x--;
                        M[x][y] = temp++;
                    }; break;
            }
    
            flag = (flag + 1) % 2;
            steps = steps - 1 * flag; // "steps" will decrease every two iterates of cycle
            dir = (dir + 1) % 4; // "dir" will change from 0 to 3 every iterate of cycle, it guarantees change of print direction
        } 
    } 
  
  //rectangle matrix
  
    else {
      
        int temp = 1;
      
        // ---First_print---right
      
        for (int i = 0; i < columns; ++i) {
            M[x][y] = temp++;
            y++;
        }
        y--;
      
        int stepsx = rows -  1;
        int stepsy = columns - 1;
      
        while (stepsx != -1 and stepsy != -1) {
            switch (dir) {
            
                case 0: // right
                    for (int i = 0; i < stepsy; ++i) {
                        y++;
                            M[x][y] = temp++;
                    }; 
                    stepsy--;
                    break;
      
                case 1: // down
                    for(int i = 0; i < stepsx; ++i) {
                        x++;
                            M[x][y] = temp++;
                    }; 
                    stepsx--;
                    break;
      
                case 2: // left
                    for (int i = 0; i < stepsy; ++i) {
                        y--;
                            M[x][y] = temp++;
                    }; 
                    stepsy--;
                    break;
      
                case 3: // up
                    for (int i = 0; i < stepsx; ++i) {
                        x--;
                        M[x][y] = temp++;
                    }; 
                    stepsx--;
                    break;
            
            }
            dir = (dir + 1) % 4;
        }
    }
    return M;
}
