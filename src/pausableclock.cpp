#include <pausableclock.h>

PausableClock::PausableClock() : m_elapsedTime(0.f), m_pause(false)
{

}

void PausableClock::Pause()
{
    if(!m_pause)
    {
        m_pause=true;
        m_elapsedTime+=m_clock.getElapsedTime().asSeconds();
    }
}

void PausableClock::Play()
{
    if(m_pause)
    {
        m_pause=false;
        m_clock.restart();
    }
}

bool PausableClock::Toggle()
{
    if(m_pause)
    {
        Play();
        return true;
    }
    Pause();
    return false;
}

void PausableClock::Stop()
{
    Reset();
    m_pause=true;
    m_elapsedTime=0;
}

void PausableClock::Reset()
{
    m_elapsedTime=0;
    m_clock.restart();
    m_pause=false;
    Play();
}

float PausableClock::GetElapsedTime()
{
    if(m_pause)
        return m_elapsedTime;
    return m_clock.getElapsedTime().asSeconds() + m_elapsedTime;
}
