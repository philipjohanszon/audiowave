#pragma once

#include "../interfaces/Filter.h"

class HighpassFilter: public Filter {
    public:
        HighpassFilter(float lowestValue);

        float calculate(float value) override;

    private:
        float m_lowestValue;
};

