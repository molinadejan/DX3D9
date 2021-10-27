#pragma once

#include "cCubeNode.h"
#include "framework.h"

class cBody : public cCubeNode
{
public:
	cBody();
	~cBody();

	virtual void Setup() override;
};

