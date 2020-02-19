#pragma once

#include "../System.h"

class Renderer final : public System
{
public:
    virtual void update( float dt ) override;
};

