#include "Components/WaffleComponent.h"

#include <vector>
#include <string>

namespace Waffle {
    class WaffleWindow {
    private:
        std::vector<WaffleComponent*> m_Components;
        int m_WindowWidth = 0, m_WindowHeight = 0;
        std::string m_WindowTitle;

    public:
        WaffleWindow(int m_WindowWidth, int m_WindowHeight, const std::string& windowTitle);
        void Render() const;
        void AddComponent(WaffleComponent* component);
        void AddComponents(WaffleComponent* component, ...);
    };
}