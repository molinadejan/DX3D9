#pragma once
#include "framework.h"

class cPyramid;

class cGrid
{
public:
	cGrid();
	~cGrid();

private:
	std::vector<ST_PC_VERTEX> m_vecVectax;
	std::vector<cPyramid*> m_vecPyramid;

public:
	void Setup(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();
};

