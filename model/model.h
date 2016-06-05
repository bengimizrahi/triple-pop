#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <memory>
#include <vector>

constexpr float hexagrid_radius = 10.0f;
constexpr float ball_radius = hexagrid_radius * 0.9;
enum Direction {NE, N, NW, SW, S, SE};

constexpr int num_of_hexagrids(int level)
    { return (3 * level * level) - (3 * level) + 1; }

constexpr int hexamesh_2d_array_size(int level)
    { return (2 * level - 1) * (2 * level - 1); }

constexpr int hexamesh_center_idx(int level)
    { return hexamesh_2d_array_size(level) / 2; }

class Hexagrid {
private:
    std::array<Hexagrid*, 6> neighbors_{{}};
};

class Hexamesh {
    Hexamesh() : hexagrid_();
private:
    std::vector<std::unique_ptr<Hexagrid>> hexagrids_;
};

#endif // HEXAGRID_H
