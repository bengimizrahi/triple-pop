#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <memory>
#include <vector>
#include <array>
#include <cmath>

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
    Hexagrid* neighbor(Direction direction)
        { return neighbors_[direction]; }
    const Hexagrid* neighbor(Direction direction) const
        { return neighbors_[direction]; }
    void set_neighbor(Direction direction, Hexagrid* neigh)
        { neighbors_[direction] = neigh; }
private:
    std::array<Hexagrid*, 6> neighbors_{{}};
};

class Hexamesh {
public:
    Hexamesh(int level);
private:
    std::vector<std::unique_ptr<Hexagrid>> hexagrids_;
};

#endif // HEXAGRID_H
