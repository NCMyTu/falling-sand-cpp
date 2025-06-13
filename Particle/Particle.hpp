#pragma once
#include "raylib.h"
#include <vector>
#include <memory>

class Particle
{
protected:
    int size;
    bool isUpdated;
    Color color;
public:
    Particle(int size, Color color);
    Particle(int size);
    virtual ~Particle();

    void Render(int posX, int posY);
    virtual void Update(std::vector<std::vector<std::unique_ptr<Particle>>>& grid, int gridW, int gridH, int row, int col);
    bool CanUpdate();
    void ResetState();
    void SetUpdated();
};