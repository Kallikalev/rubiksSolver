//
// Created by Kalev Martinson on 4/30/23.
//

#include <sstream>
#include <utility>
#include "move.h"

move move::identity(std::array<int,48>({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47}));

std::array<move,6> move::generators({
    move(std::array<int,48>({6,7,0,1,2,3,4,5,8,9,32,33,34,13,14,15,30,17,18,19,20,21,28,29,24,25,26,27,10,11,12,31,22,23,16,35,36,37,38,39,40,41,42,43,44,45,46,47})),
    move(std::array<int,48>({24,1,2,3,4,5,30,31,14,15,8,9,10,11,12,13,16,17,18,19,20,21,22,23,40,25,26,27,28,29,46,47,0,33,34,35,36,37,6,7,32,41,42,43,44,45,38,39})),
    move(std::array<int,48>({0,1,34,35,36,5,6,7,8,9,10,11,12,13,14,15,22,23,16,17,18,19,20,21,24,25,2,3,4,29,30,31,32,33,42,43,44,37,38,39,40,41,26,27,28,45,46,47})),
    move(std::array<int,48>({0,1,2,3,4,5,6,7,26,9,10,11,12,13,24,25,16,17,36,37,38,21,22,23,18,19,20,27,28,29,30,31,32,33,34,35,14,15,8,39,46,47,40,41,42,43,44,45})),
    move(std::array<int,48>({0,1,2,3,12,13,14,7,8,9,10,11,40,41,42,15,16,17,18,19,4,5,6,23,24,25,26,27,28,29,30,31,38,39,32,33,34,35,36,37,20,21,22,43,44,45,46,47})),
    move(std::array<int,48>({16,17,18,3,4,5,6,7,0,1,2,11,12,13,14,15,44,45,46,19,20,21,22,23,30,31,24,25,26,27,28,29,32,33,34,35,36,37,38,39,40,41,42,43,8,9,10,47}))
});

move::move() {
    map = identity.map;
}

move::move(std::array<int, 48> init) {
    map = std::make_shared<std::array<int, 48>>(init);
}

move::move(std::shared_ptr<std::array<int, 48>> init) {
    map = std::move(init);
}

bool move::operator==(const move& m) {
    return *map == *m.map;
}

move move::composite(const move& m1, const move& m2) {
    std::shared_ptr<std::array<int, 48>> newMove = std::make_shared<std::array<int, 48>>();
    for (int i = 0; i < m2.map->size(); i++) {
        (*newMove)[i] = (*m1.map)[(*m2.map)[i]];
    }
    return move(newMove);
}

std::string move::to_string() {
    std::stringstream ss;

    ss << "[";
    for (int i = 0; i < map->size(); i++) {
        if (i != 0) {
            ss << ", ";
        }
        ss << std::to_string((*map)[i]);
    }
    ss << "]";
    return ss.str();
}

int move::evaluate() {
    int count = 0;
    for (int i = 0; i < 48; i++) {
        if ((*map)[i] == i) {
            count++;
        }

    }
    return count;
}


move::~move() = default;
