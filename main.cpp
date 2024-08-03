#include <iostream>
#include <vector>
#include <bitset>

typedef uint64_t U64;

class Piece {
public:
    char symbol;
    U64 position;

    Piece(char sym, U64 pos) : symbol(sym), position(pos) {}
};

class WhitePawns : public Piece {
public:
    WhitePawns() : Piece('P', 0x00FF000000000000) {}
};

class WhiteRooks : public Piece {
public:
    WhiteRooks() : Piece('R', 0x8100000000000000) {}
};

class WhiteKnights : public Piece {
public:
    WhiteKnights() : Piece('N', 0x4200000000000000) {}
};

class WhiteBishops : public Piece {
public:
    WhiteBishops() : Piece('B', 0x2400000000000000) {}
};

class WhiteQueens : public Piece {
public:
    WhiteQueens() : Piece('Q', 0x1000000000000000) {}
};

class WhiteKings : public Piece {
public:
    WhiteKings() : Piece('K', 0x0800000000000000) {}
};

class BlackPawns : public Piece {
public:
    BlackPawns() : Piece('p', 0x000000000000FF00) {}
};

class BlackRooks : public Piece {
public:
    BlackRooks() : Piece('r', 0x0000000000000081) {}
};

class BlackKnights : public Piece {
public:
    BlackKnights() : Piece('n', 0x0000000000000042) {}
};

class BlackBishops : public Piece {
public:
    BlackBishops() : Piece('b', 0x0000000000000024) {}
};

class BlackQueens : public Piece {
public:
    BlackQueens() : Piece('q', 0x0000000000000010) {}
};

class BlackKings : public Piece {
public:
    BlackKings() : Piece('k', 0x0000000000000008) {}
};

class Board {
public:
    std::vector<Piece> pieces;

    Board(std::vector<Piece> ps) : pieces(ps) {}

    void printBoard() {
        char board[64] = { '0' };

        // Place pieces on the board
        for (const Piece& piece : pieces) {
            for (int i = 0; i < 64; ++i) {
                U64 mask = 1ULL << i;
                if (piece.position & mask) {
                    board[i] = piece.symbol;
                }
            }
        }

        for(int rank = 0; rank < 8; rank++) {
            for(int file = 0; file < 8; file++) {
                std::cout << board[rank * 8 + file] << ' ';
            }
            std::cout << std::endl;
        }
    }
    
};

int main() {
    WhitePawns whitePawns;
    WhiteRooks whiteRooks;
    WhiteKnights whiteKnights;
    WhiteBishops whiteBishops;
    WhiteQueens whiteQueens;
    WhiteKings whiteKings;

    BlackPawns blackPawns;
    BlackRooks blackRooks;
    BlackKnights blackKnights;
    BlackBishops blackBishops;
    BlackQueens blackQueens;
    BlackKings blackKings;

    std::vector<Piece> pieces = { whitePawns, whiteRooks, whiteKnights, whiteBishops, whiteQueens, whiteKings,
                                  blackPawns, blackRooks, blackKnights, blackBishops, blackQueens, blackKings };

    Board board(pieces);
    board.printBoard();

    return 0;
}
