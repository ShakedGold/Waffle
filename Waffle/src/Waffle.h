#pragma once

#include "Components/WaffleComponents.h"
#include "Window/WaffleWindow.h"

#include <GLFW/glfw3.h>
#include <string>
#include <vector>

namespace Waffle {
    class WaffleScreen {
    private:
        int m_ScreenWidth = 0, m_ScreenHeight = 0;
        std::string m_ScreenTitle;
        GLFWwindow* m_GlfwWindow = nullptr;
        std::vector<WaffleWindow*> m_WaffleWindows;

    public:
        WaffleScreen(int width, int height, const std::string& windowTitle);
        void AddWaffleWindow(WaffleWindow* waffleComponent);
        void Start() const;

    private:
        GLFWwindow* CreateWindow();
        void CreateImGuiContex();
    };
}