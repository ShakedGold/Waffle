#pragma once

namespace Waffle {
    struct GLFWInitException {
        static void Throw() {
            throw "Failed to init glfw";
        }
    };
    struct GLFWWindowException {
        static void Throw() {
            throw "Failed to create window";
        }
    };
}