#pragma once

class FPSCounter
{
  public:
    void DrawFpsText(float deltaTime);

  private:
    float _elapsedTime{0.0f};
    int _frameCount{0};
    float _fps{0.0f};
};
