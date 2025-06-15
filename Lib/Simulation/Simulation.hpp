#pragma once
#include <vector>
#include <memory>
#include "../Particle/Particle.hpp"
#include "raylib.h"

class Simulation
{
public:
    int rows, cols;
    int particleSize;
    std::vector<std::vector<std::unique_ptr<Particle>>> currentGrid;
    std::vector<std::vector<std::unique_ptr<Particle>>> updatedGrid;
    int particlesPerClick;
    int spawnRadius;

    Simulation(int rows, int cols, int pSize, int particlesPerTick = 1, int spawnRadius = 5);
    ~Simulation() = default;

    void Render(int posX, int posY);
    void Update();
    void InitGrid(std::vector<std::vector<std::unique_ptr<Particle>>>& grid);
    void Reset();

    bool IsInGrid(int x, int y);
    void SpawnParticle(const Vector2& mousePos);
    void SpawnParticles(const Vector2& mousePos);
};