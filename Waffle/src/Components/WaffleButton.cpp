#include "WaffleButton.h"

namespace Waffle {
    WaffleButton::WaffleButton(const std::string& label) : m_Label(label) {}

    void WaffleButton::Render() const {
        WaffleComponent::Render();
        if (ImGui::Button(m_Label.c_str())) {
            // Button action code
        }
    }
}