#pragma once
#include "WaffleComponent.h"

#include <string>

namespace Waffle {
    class WaffleButton : public WaffleComponent {
    public:
        explicit WaffleButton(const std::string& label);
        void Render() const override;
    private:
        const std::string m_Label;
    };
}