#include "Waffle.h"
#include "Exception/Exceptions.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace Waffle {

    WaffleScreen::WaffleScreen(int width, int height, const std::string& title) : m_ScreenWidth(width), m_ScreenHeight(height), m_ScreenTitle(title) {
        if(!glfwInit())
            GLFWInitException::Throw();

        //if CreateWindow Failed
        m_GlfwWindow = CreateWindow();
        if(!m_GlfwWindow)
            GLFWWindowException::Throw();

        // Make the window's context current
        glfwMakeContextCurrent(m_GlfwWindow);

        // ImGui initialization
        CreateImGuiContex();

        // Initialize m_WaffleWindows
        m_WaffleWindows = std::vector<WaffleWindow*>();
    }

    GLFWwindow* WaffleScreen::CreateWindow() {
        return glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, m_ScreenTitle.c_str(), nullptr, nullptr);
    }

    void WaffleScreen::Start() const {
        // Main loop
        while (!glfwWindowShouldClose(m_GlfwWindow)) {
            // Clear the screen
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0,0.5,0.5,1);

            //render all the Waffle Components
            for(const auto& waffleWindow : m_WaffleWindows) {
                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();

                waffleWindow->Render();

                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            }

            // Swap buffers and poll events
            glfwSwapBuffers(m_GlfwWindow);
            glfwPollEvents();
        }

        // Clean up and exit
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwTerminate();
    }

    void WaffleScreen::CreateImGuiContex() {
        ImGui::CreateContext();

        ImGui_ImplGlfw_InitForOpenGL(m_GlfwWindow, true);
        ImGui_ImplOpenGL3_Init("#version 130");
    }

    void WaffleScreen::AddWaffleWindow(WaffleWindow* waffleWindow) {
        m_WaffleWindows.emplace_back(waffleWindow);
    }
}