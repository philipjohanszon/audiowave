#pragma once

#include <SFML/Graphics.hpp>
#include "../interfaces/BaseWave.h"

namespace View {
    void init(bool* viewCanStart, BaseWave* wave);

    void draw ();
};
