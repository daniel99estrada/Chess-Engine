#include <iostream>

int array[64];

void printBoard();



class Piece {
public:
    char symbol;
    bool color;

    virtual char getSymbol () = 0; 
};

class King :public Piece {
public:
    King(bool c) {
        color = c;
    }

    char getSymbol() override {
        return color ? 'K' : 'k';
    }    
};

void printBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i * 8 + j] = j;
            std::cout << array[i * 8 + j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    printBoard();
    King whiteKing(true);
    King blackKing(false);

    std::cout << "White King: " << whiteKing.getSymbol() << std::endl;
    std::cout << "Black King: " << blackKing.getSymbol() << std::endl;
    return 0;
}