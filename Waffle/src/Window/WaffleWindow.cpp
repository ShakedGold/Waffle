#include "WaffleWindow.h"

namespace Waffle {

    WaffleWindow::WaffleWindow(int width, int height, const std::string &windowTitle) : m_WindowWidth(width), m_WindowHeight(height), m_WindowTitle(windowTitle) {
        m_Components = std::vector<WaffleComponent*>();
    }

    void WaffleWindow::Render() const {
        ImGui::Begin(m_WindowTitle.c_str());

        for(auto waffleComponent : m_Components) {
            waffleComponent->Render();
        }

        ImGui::End();
        ImGui::Render();
    }

    void WaffleWindow::AddComponent(WaffleComponent*component) {
        m_Components.emplace_back(component);
    }

    void WaffleWindow::AddComponents(WaffleComponent* component, ...) {
        m_Components.emplace_back(component);

        va_list args;
        va_start(args, component);

        WaffleComponent* nextComponent = va_arg(args, WaffleComponent*);
        while (nextComponent != nullptr) {
            m_Components.emplace_back(nextComponent);
            nextComponent = va_arg(args, WaffleComponent*);
        }

        va_end(args);
    }
}