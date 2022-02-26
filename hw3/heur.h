#ifndef HEUR_H
#define HEUR_H

#include "board.h"

class Heuristic
{
public:
    virtual ~Heuristic() { }
    virtual size_t compute(const Board& b) = 0;
};

class BFSHeuristic : public Heuristic
{
public:
    size_t compute(const Board& b);
};

class BlockingHeuristic : public Heuristic
{
public:
    size_t compute(const Board& b);
};

class DependencyHeuristic : public Heuristic
{
public:
    size_t compute(const Board& b);
};


#endif
