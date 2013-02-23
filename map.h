#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Map : public sf::Sprite
{
    public:
        Map();
        void loadFromFile(const std::string& n_file_name);
        void setTextureSize(int n_size);
        void setTexture(int n_texture_id, sf::Texture &n_tex);
        void updateTextures();
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        friend std::ostream& operator<<(std::ostream& out,const Map& n_map);

    protected:
        std::vector<std::vector<int> > m_map;
        std::vector<std::vector<sf::Sprite> > m_sprites;
        std::map<int,sf::Texture> m_textures;
        int m_x_size;
        int m_y_size;
        int m_texture_size;
};

#endif // MAP_H
