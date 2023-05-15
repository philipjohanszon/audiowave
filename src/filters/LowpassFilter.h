#pragma once

#include "../interfaces/Filter.h"

class LowpassFilter: public Filter {
    public:
        LowpassFilter(float highestValue);

        float calculate(float value) override;

    private:
        float m_highestValue;
};

