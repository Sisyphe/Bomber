#include "imganim.h"
#include <iostream>

ImgAnim::ImgAnim(const sf::Texture &Img, const unsigned int &nbFrame, const unsigned int &line)
: sf::Sprite(Img)
{
    m_animRow=0;
    //Le constructeur par défaut prend en compte qu'il n'y a aucun offset
    setTextureRect(sf::IntRect(0,0,Img.getSize().x/nbFrame,Img.getSize().y/line));
    m_xOffset=0;
    m_yOffset=0;
    m_size=nbFrame;
}


void ImgAnim::setAnimRow(const unsigned int &row)
{
    m_animRow=row;
    refreshSubRect();
}

int ImgAnim::animRow() const
{
    return m_animRow;
}

void ImgAnim::setFrameDim(const unsigned int &w, const unsigned int &h)
{
    sf::IntRect tRect = getTextureRect();
    setTextureRect(sf::IntRect(tRect.left,tRect.top,tRect.left+w,tRect.top+h));
}

sf::IntRect ImgAnim::frameDim() const
{
    sf::IntRect tRect = getTextureRect();
    return sf::IntRect(0,0,tRect.width,tRect.height);
}

void ImgAnim::setOffset(const unsigned int &x, const unsigned int &y)
{
    m_xOffset=x;
    m_yOffset=y;

    refreshSubRect();
}

sf::IntRect ImgAnim::offset() const
{
    return sf::IntRect(0,0,m_xOffset,m_yOffset);
}

int unsigned ImgAnim::getSize() const
{
    return m_size;
}

void ImgAnim::setSize(const unsigned int &size)
{
    m_size=size;
}


void ImgAnim::setFrame(const unsigned int &count)
{
    Anim::setFrame(count);
    refreshSubRect();
}

void ImgAnim::refreshSubRect()
{
    sf::IntRect tRect = getTextureRect();
    std::cout<<tRect.width*currentFrame()+m_xOffset<<std::endl;
    setTextureRect(sf::IntRect(tRect.width*currentFrame()+m_xOffset,
                            tRect.height*m_animRow+m_yOffset,
                            tRect.width*(currentFrame()+1)+m_xOffset,
                            tRect.height*m_animRow+tRect.height+m_yOffset));
}

void ImgAnim::draw(sf::RenderTarget& Target, sf::RenderStates states) const
{
    ImgAnim* th = const_cast<ImgAnim*>(this);
    th->update();
    Target.draw(static_cast<sf::Sprite>(*this),states);
}
