#pragma once
#include "raylib.h"
#include "Particle.hpp"
#include <vector>
#include <memory>

class EmptyParticle: public Particle
{
public:
    EmptyParticle(int size, Color color);
    EmptyParticle(int size);
    ~EmptyParticle() = default;

    void Update(
        std::vector<std::vector<std::unique_ptr<Particle>>>& currGrid, 
        std::vector<std::vector<std::unique_ptr<Particle>>>& newGrid, 
        int gridW, int gridH, int row, int col
    ) override;
};