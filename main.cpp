#include <iostream>
#include <vector>

bool solveKnight(std::vector<std::vector<int>>& board, int row, int col, int count);
bool isValidMove(const std::vector<std::vector<int>>& board, int row1, int col1, int row2, int col2);
void printBoard(const std::vector<std::vector<int>>& table);

int main() {

    std::vector<std::vector<int>> chessBoard(8, std::vector<int>(8, -1));
    chessBoard[0][0] = 0;
    if (solveKnight(chessBoard, 0, 0, 1)){
        printBoard(chessBoard);
    } else {
        std::cout << "No Solution";
    }

    return 0;
}

bool solveKnight(std::vector<std::vector<int>>& board, int row, int col, int count) {
    if (count == board.size() * board[row].size()) return true;

    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[r].size(); c++) {
            if (isValidMove(board, row, col, r, c)) {
                board[r][c] = count;
                if (solveKnight(board, r, c, count + 1)) return true;
                board[r][c] = -1;
            }
        }
    }
    return false;
}
bool isValidMove(const std::vector<std::vector<int>>& board, int row1, int col1, int row2, int col2) {
    if (row1 == row2 && col1 == col2) return false;
    if (board[row2][col2] != -1) return false;
    return (std::abs(row2 - row1) == 2 && std::abs(col2 - col1) == 1) ||
           (std::abs(row2 - row1) == 1 && std::abs(col2 - col1) == 2);
}
void printBoard(const std::vector<std::vector<int>>& table) {
    std::cout << "=======================" << std::endl;
    for (const auto& row : table) {
        for (int col : row) {
            if (col < 10 && col != -1) {
                std::cout << "0" << col << " ";
            } else {
                std::cout << col << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "=======================" << std::endl;
}
/*
C:\Users\mciga\CLionProjects\nKnight\cmake-build-debug\nKnight.exe
=======================
00 11 08 05 02 13 16 19
09 06 01 12 17 20 03 14
30 27 10 07 04 15 18 21
63 24 31 28 35 22 47 44
32 29 26 23 48 45 36 57
25 62 51 34 39 56 43 46
52 33 60 49 54 41 58 37
61 50 53 40 59 38 55 42
=======================

Process finished with exit code 0
 */