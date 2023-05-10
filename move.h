//
// Created by Kalev Martinson on 4/30/23.
//

#ifndef RUBIKSSOLVER_MOVE_H
#define RUBIKSSOLVER_MOVE_H

#define GENERATOR_UP 0
#define GENERATOR_LEFT 1
#define GENERATOR_RIGHT 2
#define GENERATOR_DOWN 3
#define GENERATOR_FRONT 4
#define GENERATOR_BACK 5

#include <array>

class move {

private:
    std::shared_ptr<std::array<int,48>> map; // represent a Rubik's cube as a list of 48 faces, 8 per side and 6 sides
    // and then represent a "move" as a mapping from one state to another

public:
    static std::array<move, 6> generators; // the generating moves are a subset of moves which all others can be built out of
    static move identity; // the identity move is the "do nothing" move, aka the solved cube

    move();
    explicit move(std::shared_ptr<std::array<int,48>> init);
    explicit move(std::array<int,48> init);
    static move composite(const move& m1, const move& m2);
    int evaluate();
    bool operator == (const move& m);
    std::string to_string();

    ~move();
};


#endif //RUBIKSSOLVER_MOVE_H
