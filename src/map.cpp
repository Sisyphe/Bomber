#include "map.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Map::Map():
    m_x_size(0),
    m_y_size(0),
    m_tile_size(0)
{
}

int Map::tileSize() const
{
    return m_tile_size;
}

void Map::setTileSize(int n_size)
{
    m_tile_size=n_size;

    for(int i=0;i<m_x_size;++i)
    {
        for(int j=0;j<m_y_size;++j)
        {
            m_sprites.at(i).at(j).setPosition(j*m_tile_size,i*m_tile_size);
        }
    }
}

void Map::loadFromFile(const std::string& n_file_name)
{
    std::ifstream file(n_file_name.c_str(),std::ios::in);

    if(file)
    {
        file >> m_x_size >> m_y_size;
        m_map.resize(m_x_size);
        m_sprites.resize(m_x_size);
        for(int i=0;i<m_x_size;++i)
        {
            m_map.at(i).resize(m_y_size);
            m_sprites.at(i).resize(m_y_size);
            for(int j=0;j<m_y_size;++j)
            {
                file >> m_map.at(i).at(j);
            }
        }

        file.close();

        updateTextures();
    }
    else std::cerr << "Cannot open file : "<< n_file_name << std::endl;
}

void Map::updateTextures()
{
    setTileSize(m_tile_size);

    std::map<int,Tile*>::iterator it=m_tiles.begin();
    for(;it!=m_tiles.end();++it)
    {
        setTile(*((*it).second));
    }
}

void Map::setTile(Tile& n_tile)
{
    if(m_tile_size==n_tile.size())
    {
        m_tiles[n_tile.id]=&n_tile;

        for(int i=0;i<m_x_size;++i)
        {
            for(int j=0;j<m_y_size;++j)
            {
                if(m_map.at(i).at(j)==n_tile.id)
                {
                    m_sprites.at(i).at(j).setTexture(*n_tile.texture,true);
                }
            }
        }
    }
    else std::cerr<<"Wrong texture size"<<std::endl;
}

bool Map::isTileBlocking(int x, int y, sf::FloatRect bounds) const
{
    try
    {
        sf::FloatRect tile_bounds=m_sprites.at(y).at(x).getGlobalBounds();
        if(tile_bounds.intersects(bounds))
        {
            int id=m_map.at(y).at(x);
            return m_tiles.at(id)->is_wall;
        }
    }
    catch(std::out_of_range)
    {
        std::cerr<<"Index out of range"<<std::endl;
    }
    return false;
}

void Map::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    states.transform*=getTransform();

    for(int i=0;i<m_x_size;++i)
    {
        for(int j=0;j<m_y_size;++j)
        {
            target.draw(m_sprites.at(i).at(j),states);
        }
    }
}

std::ostream& operator<<(std::ostream& out,const Map& n_map)
{
    for(int i=0;i<n_map.m_x_size;++i)
    {
        out<<std::endl;
        for(int j=0;j<n_map.m_y_size;++j)
        {
            out << n_map.m_map[i][j];
        }
    }

    return out;
}
