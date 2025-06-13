#include "ParticleEmpty.hpp"
#include "raylib.h"
#include <vector>
#include <memory>

EmptyParticle::EmptyParticle(int size, Color color)
    : Particle(size, color)
{}

EmptyParticle::EmptyParticle(int size)
    : Particle(size, Color{0, 0, 0, 255})
{}

void EmptyParticle::Update(
        std::vector<std::vector<std::unique_ptr<Particle>>>& currGrid, 
        std::vector<std::vector<std::unique_ptr<Particle>>>& newGrid, 
        int gridW, int gridH, int row, int col
    )
{}