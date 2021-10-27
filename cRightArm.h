#pragma once

#include "framework.h"
#include "cCubeNode.h"

class cRightArm : public cCubeNode
{
public:
	cRightArm();
	~cRightArm();

	virtual void Setup() override;
};

