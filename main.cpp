//
// Created by Kalev Martinson on 4/30/23.
//
#include <iostream>
#include "move.h"

int main() {
    move scramble = move::identity;
    scramble = move::composite(scramble, move::generators[0]);
    scramble = move::composite(scramble, move::generators[2]);
    scramble = move::composite(scramble, move::generators[5]);
    scramble = move::composite(scramble, move::generators[2]);
    scramble = move::composite(scramble, move::generators[3]);
    scramble = move::composite(scramble, move::generators[3]);
    scramble = move::composite(scramble, move::generators[2]);
    scramble = move::composite(scramble, move::generators[4]);
    scramble = move::composite(scramble, move::generators[0]);
    scramble = move::composite(scramble, move::generators[3]);
    scramble = move::composite(scramble, move::generators[0]);
    scramble = move::composite(scramble, move::generators[0]);
    scramble = move::composite(scramble, move::generators[3]);
    scramble = move::composite(scramble, move::generators[2]);
    scramble = move::composite(scramble, move::generators[2]);
    scramble = move::composite(scramble, move::generators[5]);
    scramble = move::composite(scramble, move::generators[1]);
    scramble = move::composite(scramble, move::generators[5]);
    scramble = move::composite(scramble, move::generators[0]);
    scramble = move::composite(scramble, move::generators[0]);

    std::cout << "Scramble:" << std::endl << scramble.to_string() << std::endl << "Evaluation: " << std::to_string(scramble.evaluate()) << std::endl;

    int maxEval = scramble.evaluate();
    move maxMove = scramble;

    for (int i = 0; i < 6; i++) {
        move move1 = move::composite(scramble,move::generators[i]);
        int move1Eval = move1.evaluate();
        if (move1Eval > maxEval) {
            maxEval = move1Eval;
            maxMove = move1;
        }
        std::cout << "Move 1:" << std::endl << move1.to_string() << std::endl << "Evaluation: " << std::to_string(move1Eval) << std::endl;
        for (int j = 0; j < 6; j++) {
            move move2 = move::composite(move1,move::generators[j]);
            int move2Eval = move2.evaluate();
            if (move2Eval > maxEval) {
                maxEval = move2Eval;
                maxMove = move2;
            }
            std::cout << "Move 2:" << std::endl << move2.to_string() << std::endl << "Evaluation: " << std::to_string(move2Eval) << std::endl;
            for (int k = 0; k < 6; k++) {
                move move3 = move::composite(move2,move::generators[k]);
                int move3Eval = move3.evaluate();
                if (move3Eval > maxEval) {
                    maxEval = move3Eval;
                    maxMove = move3;
                }
                std::cout << "Move 3:" << std::endl << move3.to_string() << std::endl << "Evaluation: " << std::to_string(move3Eval) << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;
    std::cout << "Max move: " << maxMove.to_string() << std::endl << "Max eval: " << std::to_string(maxEval) << std::endl;

    return 0;
}