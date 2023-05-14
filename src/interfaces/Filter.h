#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
    virtual ~Filter() {}
    virtual float calculate(float value) = 0;
};

#endif

