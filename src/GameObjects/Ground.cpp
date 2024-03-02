#include "M5Cardputer.h"

#include "Ground.h"
#include "Components/ImageRenderComponent.h"

Ground::Ground(int _scrollSpeed, int _spacePerPoint)
{
    m_scrollSpeed = _scrollSpeed;
    m_spacePerPoint = _spacePerPoint;

    int neededPoints = (M5Cardputer.Display.width() / m_spacePerPoint) + 2;

    float previous = 0;
    for (int i = 0; i < neededPoints; i++)
    {
        previous = GenerateNextPoint(previous);
        m_points.push_back(previous);
    }
}

void Ground::Update(float _deltaTime) noexcept
{
    m_currentLocation -= m_scrollSpeed * _deltaTime;
    if (m_currentLocation < -2 * m_spacePerPoint)
    {
        m_currentLocation += m_spacePerPoint;
        m_points.pop_front();
        float previous = m_points.back();
        m_points.push_back(GenerateNextPoint(previous));
    }
}

void Ground::Render() noexcept
{
    int previousX = m_currentLocation;
    int previousY = 0;
    int index = 0;
    for (float point : m_points)
    {
        index++;
        // M5Cardputer.Display.println(String(previousX) + "|" + String(GetPosY() + previousY) + "|" + String(m_currentLocation + index * m_spacePerPoint) + "|" + String(GetPosY() + point));
        // delay(3000);
        float renderPosY = GetPosY() + point;
        float previousRenderPosY = GetPosY() + previousY;
        renderPosY = ImageRenderComponent::s_ScreenHeight - renderPosY;
        previousRenderPosY = ImageRenderComponent::s_ScreenHeight - previousRenderPosY;

        M5Cardputer.Display.drawLine(previousX, previousRenderPosY, m_currentLocation + index * m_spacePerPoint, renderPosY, WHITE);
        previousX = m_currentLocation + index * m_spacePerPoint;
        previousY = point;
    }
}

float Ground::GenerateNextPoint(float _previous)
{
    float max = 10;
    float min = -10;

    float difference = (rand() % 20) - 10;
    float value = _previous + difference;

    if (value > max)
        value = max;
    if (value < min)
        value = min;

    return value;
}