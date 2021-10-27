#pragma once

#include "cCharacter.h"
#include "cBody.h"

class cCubeNode;

class cCubeMan : public cCharacter
{
public:
	cCubeMan();
	virtual ~cCubeMan();

protected:
	cCubeNode* m_pRoot;

public:
	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
};

