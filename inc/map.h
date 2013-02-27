#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "tile.h"

class Map : public sf::Sprite
{
    public:
        Map();
        void loadFromFile(const std::string& n_file_name);
        void setTileSize(int n_size);
        int tileSize() const;
        void setTile(Tile &n_tile);
        void updateTextures();
        bool isWall(int y,int x) const;
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        friend std::ostream& operator<<(std::ostream& out,const Map& n_map);
        bool isTileBlocking(int x, int y, sf::FloatRect bounds) const;

    protected:
        std::vector<std::vector<int> > m_map;
        std::vector<std::vector<sf::Sprite> > m_sprites;
        std::map<int,Tile*> m_tiles;
        int m_x_size;
        int m_y_size;
        int m_tile_size;
};

#endif // MAP_H
