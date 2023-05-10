//
// Created by Kalev Martinson on 4/30/23.
//
#include <iostream>
#include <stack>
#include "move.h"

move getBestMove(move& m, int depth) {
    move bestMove = m;
    int bestEval = m.evaluate();
    std::stack<std::tuple<move,int,int>> stack;
    stack.push(std::tuple<move,int,int>(m,depth,-1));
    while (!stack.empty()) {
        std::tuple<move,int,int> popped = stack.top();
        stack.pop();
        move poppedMove = std::get<0>(popped);
        int poppedDepth = std::get<1>(popped);
        int poppedLastMove = std::get<2>(popped);
        int poppedEval = poppedMove.evaluate();
        if (poppedEval > bestEval) {
            bestMove = poppedMove;
            bestEval = poppedEval;
        }
        if (poppedDepth != 0) {
            for (int i = 0; i < move::baseMoves.size(); i++) {
                if (i != -1 && poppedLastMove % 6 == i % 6) {
                    continue;
                }
                stack.push(std::tuple<move,int,int>(move::composite(poppedMove,move::baseMoves[i]),poppedDepth-1,i));
            }
        }
    }
    return bestMove;
}

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

    move bestMove = scramble;
    for (int i = 0; i < 7; i++) {
        bestMove = getBestMove(bestMove, 7);

        std::cout << std::endl << std::endl;
        std::cout << "Max move: " << bestMove.to_string() << std::endl << "Max eval: " << std::to_string(bestMove.evaluate()) << std::endl;

    }


    return 0;
}

