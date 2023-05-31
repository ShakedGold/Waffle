#pragma once

#include <imgui.h>

namespace Waffle {
    class WaffleComponent {
    public:
        virtual void Render() const;
    };
}