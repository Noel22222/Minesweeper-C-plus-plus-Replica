#include "board.hpp"
#include <ranges>

Board::Tile::Tile(): _is_a_mine(false), _is_revealed(false), _is_flagged(false), _num(0){

}

void Board::Tile::increment_num(){
    if (_num != 9){
        _num++;
    }
}

bool Board::Tile::reveal(){
    _is_revealed = true;
    return is_mine();
}

void Board::Tile::flag(){
    _is_flagged = !_is_flagged;
}

void Board::Tile::set_mine(){
    _is_a_mine = true;
    _num = 9;
}

bool Board::Tile::is_mine() const{
    return _is_a_mine;
}

bool Board::Tile::is_revealed() const{
    return _is_revealed;
}

int Board::Tile::get_num() const{
    return _num;
}

Board::Board(int width, int height, int num_mines) : width(width), height(height), num_revealed(0){
    // Initialize 2D board
    for (int i = 0; i < height; i++){
        std::vector<Tile> row(width);
        _board.push_back(row);
    }
}

bool Board::reveal_tile(int x, int y){
    if (_board[y][x].reveal()){
        return true;
    } else {
        if (_board[y][x].get_num() == 0){
            
            for (int potential_x = std::max(x - 1, 0); potential_x <= std::min(x + 1, width - 1); potential_x++){
                for (int potential_y = std::max(y - 1, 0); potential_y <= std::min(y + 1, height - 1); potential_y++){
                    if (potential_x != x || potential_y != y){
                        _board[potential_y][potential_x].increment_num();
                    }
                }
            }
        }
    }
}

int get_random(int min, int max){
    srand((unsigned) time(NULL));
    return rand() % (max - min + 1) + min;
}