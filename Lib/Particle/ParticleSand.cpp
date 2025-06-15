#include "Particle.hpp"
#include "ParticleSand.hpp"
#include "ParticleEmpty.hpp"
#include "raylib.h"
#include <vector>
#include <memory>
#include <utility>
#include "../Utility.hpp"

SandParticle::SandParticle(int size, Color color)
    : Particle(size, color)
{}

SandParticle::SandParticle(int size)
    : Particle(size, Color{194, 178, 128, 255})
{}   

void SandParticle::Update(
    std::vector<std::vector<std::unique_ptr<Particle>>>& currGrid, 
    std::vector<std::vector<std::unique_ptr<Particle>>>& newGrid, 
    int gridW, int gridH, int row, int col
) {
    // bottom of grid, do nothing
    if (row >= gridW - 1)
    {
        newGrid[row][col] = std::move(currGrid[row][col]);
        return;
    }

    if (Particle::IsType<EmptyParticle>(currGrid[row + 1][col]))
    {
        newGrid[row + 1][col] = std::move(currGrid[row][col]);
        return;
    }
    else if (Particle::IsType<SandParticle>(currGrid[row + 1][col]))
    {
        bool canDownLeft = (col > 0) && (Particle::IsType<EmptyParticle>(currGrid[row + 1][col - 1]));
        bool canDownRight = (col < gridH - 1) && (Particle::IsType<EmptyParticle>(currGrid[row + 1][col + 1]));

        // choose a random direction if both are free
        if (canDownLeft && canDownRight)
            if (RandomFloat(0.0f, 1.0f) < 0.5f)
                newGrid[row + 1][col - 1] = std::move(currGrid[row][col]);
            else
                newGrid[row + 1][col + 1] = std::move(currGrid[row][col]);
        else if (canDownLeft)
            newGrid[row + 1][col - 1] = std::move(currGrid[row][col]);
        else if (canDownRight)
            newGrid[row + 1][col + 1] = std::move(currGrid[row][col]); 
        else
            newGrid[row][col] = std::move(currGrid[row][col]);
    }
}