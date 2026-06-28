#include <iostream>
#include <cstdint>
#include <vector>

struct Location {
    bool out = false;
    long minimum_cost = 1'000'000'000;
    std::vector<uint32_t> tunnels; // references the id of the tunnel
    long d = 0;
};

struct Tunnel {
    Location& loc_1;
    Location& loc_2;
    long lava_level;
};

int main() {
    uint32_t n; // num of locations
    uint32_t m; // num of tunnels

    std::cin >> n >> m;

    std::vector<Location> locations(n);
    std::vector<Tunnel> tunnels;
    tunnels.reserve(m);

    for (uint32_t i = 0; i < m; ++i) {
        uint32_t locationIndex1;
        uint32_t locationIndex2;
        long lava_level;

        std::cin >> locationIndex1 >> locationIndex2 >> lava_level;
        locationIndex1--;
        locationIndex2--;

        Tunnel t = {locations[locationIndex1], locations[locationIndex2], lava_level};
        tunnels.push_back(t);
        
        locations[locationIndex1].tunnels.push_back(i);
        locations[locationIndex2].tunnels.push_back(i);
    }

    locations[0].minimum_cost = 0;
    uint32_t minimumIndex = 0;
    n--;
    while (minimumIndex != n) {
        auto& loc = locations[minimumIndex];

        for (uint32_t t : loc.tunnels) {
            Tunnel tunnel = tunnels[t];
            
            if (tunnel.loc_1.out == true || tunnel.loc_2.out == true)
                continue;

            if (&loc == &tunnel.loc_1) {
                // loc_2 is the other
                size_t minimumCost = std::abs(loc.d - tunnel.lava_level) + loc.minimum_cost;
                if (tunnel.loc_2.minimum_cost > minimumCost) {
                    tunnel.loc_2.minimum_cost = minimumCost;
                    tunnel.loc_2.d = tunnel.lava_level;
                }

                if (minimumCost <= locations[minimumIndex].minimum_cost || minimumIndex == &loc - locations.data()) {
                    minimumIndex = &tunnel.loc_2 - locations.data();
                }
            } else {
                // loc_1 is the other
                size_t minimumCost = std::abs(loc.d - tunnel.lava_level) + loc.minimum_cost;
                if (tunnel.loc_1.minimum_cost > minimumCost) {
                    tunnel.loc_1.minimum_cost = minimumCost;
                    tunnel.loc_1.d = tunnel.lava_level;
                }

                if (minimumCost <= locations[minimumIndex].minimum_cost || minimumIndex == &loc - locations.data()) {
                    minimumIndex = &tunnel.loc_1 - locations.data();
                }
            }
        }

        loc.out = true;
    }

    std::cout << locations[n].minimum_cost << "\n";

    return 0;
}
