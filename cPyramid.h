#pragma once
#include "framework.h"

class cPyramid
{
public:
	cPyramid();
	~cPyramid();

private:
	std::vector<ST_PC_VERTEX> m_vecVertax;
	D3DXMATRIXA16 m_matR;

public:
	void Setup(D3DCOLOR c, D3DXMATRIX& mat);
	void Render();
};

