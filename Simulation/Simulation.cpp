#include "Simulation.hpp"
#include "raylib.h"
#include "../Particle/ParticleEmpty.hpp"
#include <iostream>
#include "../Particle/ParticleSand.hpp"
#include <utility>

Simulation::Simulation(int rows, int cols, int pSize)
    : rows(rows), cols(cols), particleSize(pSize)
{
    InitGrid(currentGrid);
    InitGrid(updatedGrid);
}

Simulation::~Simulation()
{}

void Simulation::Render(int posX, int posY)
{
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            updatedGrid[i][j]->Render(j * particleSize, i * particleSize);
}

void Simulation::Update()
{
    // update currentGrid to updatedGrid
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
    std::swap(currentGrid, updatedGrid);
    InitGrid(updatedGrid);
}