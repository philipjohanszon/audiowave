#include "HighpassFilter.h"

HighpassFilter::HighpassFilter(float lowestValue) {
    this->m_lowestValue = lowestValue;
}

float HighpassFilter::calculate(float value) {
    if (value < m_lowestValue) {
        return m_lowestValue;
    }

    return value;
}
