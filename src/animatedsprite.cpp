#include "animatedsprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
{
    m_current_sprite_index=0;
    m_frame_rate=8;
    m_is_playing=false;
    m_anim_row=0;
}

void AnimatedSprite::loadFromImage
(
        const sf::Image& n_image,
        int n_line_count,
        int n_column_count,
        int n_anim_count,
        int n_frame_count
)
{
    sf::IntRect frame_rect;

    m_anim_count=n_anim_count;
    m_frame_count=n_frame_count;
    if(m_anim_count==0) m_anim_count=n_line_count;
    if(m_frame_count==0) m_frame_count=n_column_count;
    int w=n_image.getSize().x/n_column_count;
    int h=n_image.getSize().y/n_line_count;
    m_textures.clear();
    m_sprites.clear();
    setOrigin(w/2.f,h/2.f);

    for(int i=0;i<n_line_count;++i)
    {
        for(int j=0;j<n_column_count;++j)
        {
            frame_rect.top=i*h;
            frame_rect.left=j*w;
            frame_rect.height=(i+1)*h;
            frame_rect.width=(j+1)*w;
            m_textures.push_back(new sf::Texture);
            m_textures.back()->loadFromImage(n_image,frame_rect);
            frame_rect.top=0;
            frame_rect.left=0;
            frame_rect.height=h;
            frame_rect.width=w;
            m_sprites.push_back(new sf::Sprite(*m_textures.back(),frame_rect));
        }
    }
}

void AnimatedSprite::updateFrame()
{
    float elapsed_seconds=m_clock.getElapsedTime().asSeconds();
    m_clock.restart();
    m_current_sprite_index+=m_frame_rate*elapsed_seconds;
    if(m_current_sprite_index>m_frame_count)
        m_current_sprite_index-=m_frame_count;
}

sf::Sprite* AnimatedSprite::currentSprite() const
{
    return m_sprites[((int)m_current_sprite_index)+m_anim_row*m_frame_count];
}

void AnimatedSprite::play()
{
    if(!m_is_playing)
    {
        m_is_playing=true;
        m_clock.restart();
    }
}

void AnimatedSprite::play(const std::string& n_anim_name,float n_frame_rate)
{
    setAnim(n_anim_name);
    m_frame_rate=n_frame_rate;
    play();
}

bool AnimatedSprite::isPlaying() const
{
    return m_is_playing;
}

void AnimatedSprite::stop()
{
    m_is_playing=false;
    m_current_sprite_index=1;
}

sf::FloatRect AnimatedSprite::getBounds() const
{
    return getTransform().transformRect(currentSprite()->getLocalBounds());
}

void AnimatedSprite::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    if(isPlaying())
    {
        AnimatedSprite* th=const_cast<AnimatedSprite*>(this);
        th->updateFrame();
    }
    if(m_sprites.size()!=0)
    {
        states.transform*=getTransform();
        target.draw(*currentSprite(),states);
    }
}

void AnimatedSprite::setAnim(const std::string& n_anim_name)
{
    m_anim_row=m_anim_rows[n_anim_name];
}

void AnimatedSprite::addAnimRow(int n_row,const std::string& n_anim_name)
{
    m_anim_rows[n_anim_name]=n_row;
}
