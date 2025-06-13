#include "raylib.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Particle/Particle.hpp"
#include "Particle/ParticleSand.hpp"
#include "Particle/ParticleEmpty.hpp"
#include "Simulation/Simulation.hpp"

const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 900;
    
const int PARTICLE_SIZE = 20;

const float UPDATE_RATE = 0.03;

int main()
{
    // SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(640, 640, "Falling Sand");

    const int MONITOR = GetCurrentMonitor();
    const int MONITOR_WIDTH = GetMonitorWidth(MONITOR);
    const int MONITOR_HEIGHT = GetMonitorHeight(MONITOR);

    int windowPosX = (MONITOR_WIDTH - SCREEN_WIDTH) / 2;
    int windowPosY = (MONITOR_HEIGHT - SCREEN_HEIGHT) / 2;

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetWindowPosition(windowPosX, windowPosY);

    const int ROWS = int(SCREEN_HEIGHT / PARTICLE_SIZE);
    const int COLS = int(SCREEN_WIDTH / PARTICLE_SIZE);
    
    Simulation sim(ROWS, COLS, PARTICLE_SIZE);

    // SetTargetFPS(60);
    float tick = 0;
    
    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
        {
            Vector2 mouse = GetMousePosition();
            int gridX = int(mouse.x) / PARTICLE_SIZE;
            int gridY = int(mouse.y) / PARTICLE_SIZE;

            if (gridX >= 0 && gridX < COLS && gridY >= 0 && gridY < ROWS)
                sim.grid[gridY][gridX] = std::make_unique<SandParticle>(PARTICLE_SIZE);
        }

        tick += dt;
        if (tick >= UPDATE_RATE)
        {
            tick -= UPDATE_RATE;
            sim.Update();
        }

        BeginDrawing();
            ClearBackground(BLACK);

            sim.Render(0, 0);

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
}