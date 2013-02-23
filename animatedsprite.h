#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Transformable, public sf::Drawable
{
    public:
        AnimatedSprite();
        void loadFromImage
        (
                const sf::Image& n_image,
                int n_line_count,
                int n_column_count,
                int n_anim_count=0,
                int n_frame_count=0
        );
        void play();
        void play(const std::string &n_anim_name, float n_frame_rate=8);
        void stop();
        bool isPlaying() const;
        void updateFrame();
        sf::Sprite* currentSprite() const;
        void setAnim(const std::string& n_anim_name);
        void addAnimRow(int n_row,const std::string& n_anim_name);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:
        sf::Clock m_clock;
        std::vector<sf::Texture*> m_textures;
        std::vector<sf::Sprite*> m_sprites;
        float m_current_sprite_index;
        int m_anim_count;
        int m_frame_count;
        bool m_is_playing;
        float m_frame_rate;
        std::map<std::string,int> m_anim_rows;
        int m_anim_row;
};

#endif // ANIMATEDSPRITE_H
