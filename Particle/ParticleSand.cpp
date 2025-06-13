#include "ParticleSand.hpp"
#include "ParticleEmpty.hpp"
#include "raylib.h"
#include <vector>
#include <memory>

SandParticle::SandParticle(int size, Color color)
    : Particle(size, color)
{}

SandParticle::SandParticle(int size)
    : Particle(size, Color{194, 178, 128, 255})
{}   

void SandParticle::Update(std::vector<std::vector<std::unique_ptr<Particle>>>& grid, int gridW, int gridH, int row, int col)
{
    if (row >= gridW - 1)
        return;

    isUpdated = true;

    if (dynamic_cast<EmptyParticle*>(grid[row + 1][col].get()))
        std::swap(grid[row][col], grid[row + 1][col]);
}