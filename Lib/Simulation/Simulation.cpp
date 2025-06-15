#include "Simulation.hpp"
#include "raylib.h"
#include "../Particle/ParticleEmpty.hpp"
#include "../Particle/ParticleSand.hpp"
#include "../Utility.hpp"

Simulation::Simulation(int rows, int cols, int pSize, int particlesPerClick, int spawnRadius)
    : rows(rows), cols(cols), particleSize(pSize), particlesPerClick(particlesPerClick), spawnRadius(spawnRadius)
{
    InitGrid(currentGrid);
    InitGrid(updatedGrid);
}

void Simulation::Render(int posX, int posY)
{
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            updatedGrid[i][j]->Render(j * particleSize, i * particleSize);
}

void Simulation::Update()
{
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            currentGrid[i][j]->Update(currentGrid, updatedGrid, rows, cols, i, j); 
}

void Simulation::InitGrid(std::vector<std::vector<std::unique_ptr<Particle>>>& grid)
{
    // init, or clear a grid
    grid.resize(rows);

    for (int i = 0; i < rows; ++i) 
    {
        grid[i].resize(cols);

        for (int j = 0; j < cols; ++j) 
            grid[i][j] = std::make_unique<EmptyParticle>(particleSize);
    }
}

void Simulation::Reset()
{
    currentGrid.swap(updatedGrid);
    InitGrid(updatedGrid);
}

bool Simulation::IsInGrid(int x, int y)
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void Simulation::SpawnParticle(const Vector2& mousePos)
{
    int gridX = int(mousePos.y) / particleSize;
    int gridY = int(mousePos.x) / particleSize;

    // mouse coordinate might be off-screen — check bounds first
    if (IsInGrid(gridX, gridY))
        currentGrid[gridX][gridY] = std::make_unique<SandParticle>(particleSize);
}

void Simulation::SpawnParticles(const Vector2& mousePos)
{
    int x = int(mousePos.y) / particleSize;
    int y = int(mousePos.x) / particleSize;

    for (int i = 0; i < particlesPerClick; ++i)
    {
        int gridX = x + RandomInt(-spawnRadius, spawnRadius);
        int gridY = y + RandomInt(-spawnRadius, spawnRadius);

        // mouse coordinate might be off-screen — check bounds first
        if (IsInGrid(gridX, gridY))
            currentGrid[gridX][gridY] = std::make_unique<SandParticle>(particleSize);
    }
}
