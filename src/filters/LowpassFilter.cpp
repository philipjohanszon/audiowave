#include "LowpassFilter.h"

LowpassFilter::LowpassFilter(float highestValue) {
    this->m_highestValue = highestValue;
}

float LowpassFilter::calculate(float value) {
    if (value > m_highestValue) {
        return m_highestValue;
    }

    return value;
}
