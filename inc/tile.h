#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile
{
    public:

        Tile();
        ~Tile();
        Tile(int n_id, const std::string& n_tex_file_name, bool n_is_wall);
        int size() const;

    public:

        int id;
        sf::Texture* texture;
        bool is_wall;
};

#endif // TILE_H
