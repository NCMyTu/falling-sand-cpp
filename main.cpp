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

const int FPS = 60;

const float UPDATE_RATE = 1.0f / FPS + 0.02f;

int main()
{
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

    SetTargetFPS(FPS);

    float tick = 0.0f;
    bool canSpawnParticle = false;
    
    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        tick += dt;

        if (tick > UPDATE_RATE)
        {
            // throttle particle spawning to match update rate
            // if they spawn too fast they WILL move incorrectly (mid air shifting for sand particles)
            tick -= UPDATE_RATE;
            canSpawnParticle = true;
        }

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && canSpawnParticle) 
        {
            Vector2 mouse = GetMousePosition();
            int gridX = int(mouse.y) / PARTICLE_SIZE;
            int gridY = int(mouse.x) / PARTICLE_SIZE;

            // mouse coordinate might be off-screen — check bounds first
            if (gridX >= 0 && gridX < ROWS && gridY >= 0 && gridY < COLS)
                sim.currentGrid[gridX][gridY] = std::make_unique<SandParticle>(PARTICLE_SIZE);
        }

        sim.Update();

        BeginDrawing();
            ClearBackground(BLACK);

            sim.Render(0, 0);

            DrawFPS(10, 10);

        EndDrawing();

        sim.Reset();

        canSpawnParticle = false;
    }

    CloseWindow();
}