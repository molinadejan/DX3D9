#pragma once

#include "framework.h"
#include "cCubeNode.h"

class cRightLeg : public cCubeNode
{
public:
	cRightLeg();
	~cRightLeg();

	virtual void Setup() override;
};

