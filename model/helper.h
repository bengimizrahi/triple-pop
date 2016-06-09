#ifndef HELPER_H
#define HELPER_H

#include <cmath>
#include <SFML/System/Vector2.hpp>

template <typename T>
sf::Vector2<T> normal(double angle)
{
    return sf::Vector2<T>(std::cos(angle), std::sin(angle));
}

template <typename T>
sf::Vector2<T> rotate(sf::Vector2<T> vec)
{
    return vec;
}

template <typename T, typename U>
void vector_assign(sf::Vector2<T>& dest, sf::Vector2<U> source)
{
    dest.x = source.x;
    dest.y = source.y;
}

#endif // HELPER_H