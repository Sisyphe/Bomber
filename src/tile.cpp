#include "tile.h"

Tile::Tile():
    id(0),
    is_wall(false)
{
}

Tile::Tile(int n_id, sf::Texture& n_tex, bool n_is_wall):
    id(n_id),
    texture(n_tex),
    is_wall(n_is_wall)
{
}

Tile::Tile(int n_id, const std::string& n_tex_file_name, bool n_is_wall):
    id(n_id),
    is_wall(n_is_wall)
{
    texture.loadFromFile(n_tex_file_name);
}

int Tile::size() const
{
    return texture.getSize().x;
}
