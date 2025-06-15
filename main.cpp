#include "raylib.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Lib/Particle/Particle.hpp"
#include "Lib/Particle/ParticleSand.hpp"
#include "Lib/Particle/ParticleEmpty.hpp"
#include "Lib/Simulation/Simulation.hpp"

constexpr int SCREEN_WIDTH = 1500;
constexpr int SCREEN_HEIGHT = 900;
    
constexpr int PARTICLE_SIZE = 15;

constexpr int FPS = 60;

constexpr float SPAWN_RATE = 0.07f;

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

    constexpr int ROWS = int(SCREEN_HEIGHT / PARTICLE_SIZE);
    constexpr int COLS = int(SCREEN_WIDTH / PARTICLE_SIZE);
    
    Simulation sim(ROWS, COLS, PARTICLE_SIZE, 5, 2);

    SetTargetFPS(FPS);

    float tick = 0.0f;
    bool canSpawnParticle = false;
    
    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        tick += dt;

        if (tick > SPAWN_RATE)
        {
            // throttle particle spawning to match update rate
            // if they spawn too fast they WILL move incorrectly (mid air shifting for sand particles)
            tick -= SPAWN_RATE;
            canSpawnParticle = true;
        }

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && canSpawnParticle) 
            sim.SpawnParticles(GetMousePosition());

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