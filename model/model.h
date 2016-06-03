#ifndef HEXAGRID_H
#define HEXAGRID_H

constexpr float hexagrid_radius = 10.0f;
constexpr float ball_radius = hexagrid_radius * 0.9;
enum Direction {NE, N, NW, SW, S, SE};

constexpr int num_of_hexagrids(int level)
{
    return (3 * level * level) - (3 * level) + 1
}

#endif // HEXAGRID_H
