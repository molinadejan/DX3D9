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
	D3DMATERIAL9 m_stMtl;

public:
	void Setup(D3DXCOLOR c, D3DXMATRIX& mat);
	void Render();
};

