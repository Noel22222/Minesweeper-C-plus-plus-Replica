#include "board.hpp"

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