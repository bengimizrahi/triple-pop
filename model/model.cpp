#include "model.h"

#include <iostream>
using namespace std;

/* ...xxxx
 * ..xxxxx
 * .xxxxxx
 * xxxxxxx
 * xxxxxx.
 * xxxxx..
 * xxxx...
 */

Hexamesh::Hexamesh(int level)
: hexagrids_(hexamesh_2d_array_size(level))
{
    function<void(int, int, int)> funcs[] = {
        [this](int y, int x, int idx)
        {
            hexagrids_[idx].reset(new Hexagrid);
            auto* myself = hexagrids_[idx].get();
        },
        [this, level](int y, int x, int idx)
        {
            int width = 2 * level - 1;

            auto* myself = hexagrids_[idx].get();

            if (x < width - 1) {
                auto* se_neigh = hexagrids_[idx + 1].get();
                if (se_neigh) {
                    myself->set_neighbor(Direction::SE, se_neigh);
                    se_neigh->set_neighbor(Direction::NW, myself);
                }
            }

            if (y < width - 1 && x < width - 1) {
                auto* ne_neigh = hexagrids_[idx + width + 1].get();
                myself->set_neighbor(Direction::NE, ne_neigh);
                ne_neigh->set_neighbor(Direction::SW, myself);
            }

            if (y < width - 1) {
                auto* n_neigh = hexagrids_[idx + width].get();
                if (n_neigh) {
                    myself->set_neighbor(Direction::N, n_neigh);
                    n_neigh->set_neighbor(Direction::S, myself);
                }
            }
        },
        [this](int y, int x, int idx)
        {
            const auto* myself = hexagrids_[idx].get();
            int count = 0;
            for (auto d : {NE, N, NW, SW, S, SE}) {
                count += (myself->neighbor(d) == nullptr);
            }
            cout << idx << " " << count;
        }
    };
    for (auto f : funcs) {
        for (int y = 0; y < 2 * level - 1; ++y)
        {
            int i = y - (level - 1);
            int x1 = std::max(i, 0);
            int x2 = (2 * level - 1) + std::min(i, 0);
            for (int x = x1; x < x2; ++x)
            {
                int idx = (2 * level - 1) * y + x;
                f(y, x, idx);
            }
        }
    }
}