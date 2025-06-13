#pragma once
#include "raylib.h"
#include "Particle.hpp"
#include <vector>
#include <memory>

class SandParticle: public Particle
{
public:
    SandParticle(int size, Color color);
    SandParticle(int size);
    ~SandParticle() = default;

    void Update(std::vector<std::vector<std::unique_ptr<Particle>>>& grid, int gridW, int gridH, int row, int col) override;
};