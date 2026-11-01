//TerraBoots.h
#pragma once
#include "Ground.h"

class TerraBoots : public Ground {
public:
    TerraBoots();
    double getRestDuration(int rest_count) const override;

};

