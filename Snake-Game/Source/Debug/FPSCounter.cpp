#include "FPSCounter.h"

#include "imgui.h"
#include "../../Engine/Debug/StringFormatter.h"

void FPSCounter::DrawFpsText(const float deltaTime)
{
    _elapsedTime += deltaTime;
    _frameCount++;

    if (_elapsedTime >= 1.0f) {
        _fps = static_cast<float>(_frameCount) / _elapsedTime;
        _elapsedTime = 0.0f;
        _frameCount = 0;
    }

    const auto fps_text = StringFormatter::Combine("FPS: $", _fps);
    
    ImGui::Text(fps_text.c_str());
}
