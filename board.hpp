#ifndef BOARD_HPP
#define BOARD_HPP

#include <iosfwd>

class Board {
    
    // Implemented Tile as a private class within Board since it is exclusively used by Board
    // Board acts as a medium through which the main program can access the Tiles stored in here
    struct Tile {
        void increment_num();
        bool reveal();
        void flag();
        void set_mine();
        bool is_mine() const;
        bool is_revealed() const;
        int get_num() const;

        private:
            bool _is_a_mine = false;
            bool _is_revealed = false;
            bool _is_flagged = false;
            int _num = 0;
    };

    int width;
    int height;
    int num_mines;
    
    friend std::ostream &operator>>(std::ostream &out, const Board::Tile &tile);

    public:
        Board(int width, int height, int num_mines);

        bool reveal_tile(int x, int y);
        void reveal_all();
        Tile get_tile();
        int get_num_revealed();
        void _increment_surrounding(int x, int y);
        


};

std::ostream &operator>>(std::ostream &out, const Board &board);



#endif