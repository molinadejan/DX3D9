#pragma once
#include "framework.h"

class cGizmo
{
public:
	cGizmo();
	~cGizmo();

private:
	std::vector<ST_PC_VERTEX> m_vecVertax;
	D3DXMATRIXA16 m_matR;

public:
	void Setup(D3DCOLOR c, D3DXMATRIX& mat);
	void Render();
};

