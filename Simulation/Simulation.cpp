#include "Simulation.hpp"
#include "raylib.h"
#include "../Particle/ParticleEmpty.hpp"

Simulation::Simulation(int rows, int cols, int pSize)
    : rows(rows), cols(cols), particleSize(pSize), grid(rows)
{
    for (int i = 0; i < rows; ++i) 
    {
        grid[i].resize(cols);
        for (int j = 0; j < cols; ++j) 
        {
            grid[i][j] = std::make_unique<EmptyParticle>(particleSize);
        }
    }
}

Simulation::~Simulation()
{}

void Simulation::Render(int posX, int posY)
{
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            grid[i][j]->Render(j * particleSize, i * particleSize);
}

void Simulation::Update()
{
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            if (grid[i][j]->CanUpdate())
            {
                grid[i][j]->Update(grid, rows, cols, i, j);
            }

    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            grid[i][j]->ResetState();
            
}