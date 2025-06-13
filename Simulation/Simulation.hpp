#pragma once
#include <vector>
#include <memory>
#include "../Particle/Particle.hpp"

class Simulation
{
public:
    int rows, cols;
    int particleSize;
    std::vector<std::vector<std::unique_ptr<Particle>>> grid;

    Simulation(int rows, int cols, int pSize);
    ~Simulation();

    void Render(int posX, int posY);
    void Update();
};