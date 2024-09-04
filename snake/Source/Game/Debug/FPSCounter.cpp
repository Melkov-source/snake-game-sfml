#include "FPSCounter.h"

#include "imgui.h"

void FPSCounter::DrawFpsText(const float deltaTime)
{
    _elapsedTime += deltaTime;
    _frameCount++;

    if (_elapsedTime >= 1.0f) {
        _fps = static_cast<float>(_frameCount) / _elapsedTime;
        _elapsedTime = 0.0f;
        _frameCount = 0;
    }
    
    ImGui::Text("FPS: %f", _fps);
}
