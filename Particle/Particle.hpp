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
    virtual void Update(
        std::vector<std::vector<std::unique_ptr<Particle>>>& currGrid, 
        std::vector<std::vector<std::unique_ptr<Particle>>>& newGrid, 
        int gridW, int gridH, int row, int col
    );
    
    bool CanUpdate();
    void ResetState();
    void SetUpdated();

    template<typename T>
    static bool IsType(const Particle* p) {
        return dynamic_cast<T*>(p) != nullptr;
    }

    template<typename T>
    static bool IsType(const std::unique_ptr<Particle>& p) {
        return dynamic_cast<T*>(p.get()) != nullptr;
    }
};