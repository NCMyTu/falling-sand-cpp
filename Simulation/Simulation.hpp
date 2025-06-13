#pragma once
#include <vector>
#include <memory>
#include "../Particle/Particle.hpp"

class Simulation
{
public:
    int rows, cols;
    int particleSize;
    std::vector<std::vector<std::unique_ptr<Particle>>> currentGrid;
    std::vector<std::vector<std::unique_ptr<Particle>>> updatedGrid;

    Simulation(int rows, int cols, int pSize);
    ~Simulation();

    void Render(int posX, int posY);
    void Update();
    void InitGrid(std::vector<std::vector<std::unique_ptr<Particle>>>& grid);
    void Reset();
};