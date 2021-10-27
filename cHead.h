#pragma once

#include "framework.h"
#include "cCubeNode.h"

class cHead : public cCubeNode
{
public:
	cHead();
	~cHead();

	virtual void Setup() override;
};

