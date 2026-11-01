//SwiftCamel.h
#pragma once
#include "Ground.h"

class SwiftCamel : public Ground {
public:
    SwiftCamel();
    double getRestDuration(int rest_count) const override;
};
