#include "Particle.hpp"
#include "raylib.h"
#include <vector>
#include <memory>

Particle::Particle(int size, Color color)
    : size(size), isUpdated(false), color(color)
{}

Particle::Particle(int size)
    : size(size), isUpdated(false), color(Color{0, 0, 0, 255})
{}

Particle::~Particle()
{}

void Particle::Render(int posX, int posY)
{
    DrawRectangle(posX, posY, size, size, color);
}

void Particle::Update(
    std::vector<std::vector<std::unique_ptr<Particle>>>& currGrid, 
    std::vector<std::vector<std::unique_ptr<Particle>>>& newGrid, 
    int gridW, int gridH, int row, int col
)
{}

bool Particle::CanUpdate()
{
    return !isUpdated;
}

void Particle::ResetState()
{
    isUpdated = false;
}

void Particle::SetUpdated()
{
    isUpdated = true;
}