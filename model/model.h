#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
#include <array>
#include <cmath>
#include "helper.h"

constexpr float hexagrid_radius = 10.0f;
constexpr float ball_radius = hexagrid_radius * 0.9f;
enum Direction {NE, N, NW, SW, S, SE};

constexpr float direction_angles[] =
    { M_PI / 6, M_PI_2, 5 * M_PI / 6, 7 * M_PI / 6, 3 * M_PI_2, 11 * M_PI / 6};
constexpr int num_of_hexagrids(int level)
    { return (3 * level * level) - (3 * level) + 1; }

constexpr int hexamesh_2d_array_size(int level)
    { return (2 * level - 1) * (2 * level - 1); }

constexpr int hexamesh_center_idx(int level)
    { return hexamesh_2d_array_size(level) / 2; }

class Hexagrid {
public:
    sf::Vector2f position_vector()
        { return position_vector_; }
    const sf::Vector2f position_vector() const
        { return position_vector_; }
    void set_position_vector(sf::Vector2f vec)
        { vector_assign(position_vector_, vec); }
    Hexagrid* neighbor(Direction direction)
        { return neighbors_[direction]; }
    const Hexagrid* neighbor(Direction direction) const
        { return neighbors_[direction]; }
    void set_neighbor(Direction direction, Hexagrid* neigh)
        { neighbors_[direction] = neigh; }
private:
    sf::Vector2f position_vector_;
    std::array<Hexagrid*, 6> neighbors_{{}};
};

class Hexamesh {
public:
    Hexamesh(int level);
private:
    std::vector<std::unique_ptr<Hexagrid>> hexagrids_;
};

#endif // HEXAGRID_H
