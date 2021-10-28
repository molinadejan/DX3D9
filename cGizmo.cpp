#include "cGizmo.h"
#include "framework.h"

cGizmo::cGizmo()
{
	D3DXMatrixIdentity(&m_matR);
}

cGizmo::~cGizmo()
{
}

void cGizmo::Setup(D3DXCOLOR c, D3DXMATRIX& mat)
{
	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient = c;
	m_stMtl.Diffuse = c;
	m_stMtl.Specular = c;

	m_matR = mat;
	ST_PC_VERTEX v;

	v.c = c;

	v.p = D3DXVECTOR3(0, 0, 0); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(1, -1, -1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, -1); m_vecVertax.push_back(v);

	v.p = D3DXVECTOR3(0, 0, 0); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(1, -1, 1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(1, -1, -1); m_vecVertax.push_back(v);

	v.p = D3DXVECTOR3(0, 0, 0); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(1, -1, 1); m_vecVertax.push_back(v);

	v.p = D3DXVECTOR3(0, 0, 0); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, -1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); m_vecVertax.push_back(v);

	v.p = D3DXVECTOR3(-1, -1, -1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(1, -1, -1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); m_vecVertax.push_back(v);

	v.p = D3DXVECTOR3(1, -1, -1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(1, -1, 1); m_vecVertax.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); m_vecVertax.push_back(v);
}

void cGizmo::Render()
{
	D3DXMATRIXA16 matWorld, matS;
	D3DXMatrixScaling(&matS, 0.1f, 2.0f, 0.1f);

	matWorld = matS * m_matR;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertax.size() / 3,
		&m_vecVertax[0], sizeof(ST_PC_VERTEX));
}
