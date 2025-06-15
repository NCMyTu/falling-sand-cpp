#include "Particle.hpp"
#include "raylib.h"
#include <vector>
#include <memory>

Particle::Particle(int size, Color color)
    : size(size), color(color)
{}

Particle::Particle(int size)
    : size(size), color(Color{0, 0, 0, 255})
{}

void Particle::Render(int posX, int posY)
{
    DrawRectangle(posX, posY, size, size, color);
}

// move this particle from currGrid to newGrid
void Particle::Update(
    std::vector<std::vector<std::unique_ptr<Particle>>>& currGrid, 
    std::vector<std::vector<std::unique_ptr<Particle>>>& newGrid, 
    int gridW, int gridH, int row, int col
) {}