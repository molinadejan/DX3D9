#include "framework.h"
#include "cMainGame.h"
#include "cDeviceManager.h"
#include "cCubePC.h"
#include "cCamera.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pCamera(NULL)
{ }

cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pCubePC);
	SAFE_DELETE(m_pCamera);
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{
	m_pCubePC = new cCubePC;
	m_pCubePC->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubePC->GetPosition());

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{
	if (m_pCubePC)
		m_pCubePC->Update();

	if (m_pCamera)
		m_pCamera->Update();
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	g_pD3DDevice->BeginScene();
	// draw

	m_pCubePC->Render();

	//
	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}

//void cMainGame::Setup_Line()
//{
//	ST_PC_VERTEX v;
//	v.c = D3DCOLOR_XRGB(255, 0, 0);
//
//	v.p = D3DXVECTOR3(0, 2, 0);
//	m_vecLineVertex.push_back(v);
//
//	v.p = D3DXVECTOR3(0, -2, 0);
//	m_vecLineVertex.push_back(v);
//}
//
//void cMainGame::Draw_Line()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecLineVertex.size() / 2, 
//		&m_vecLineVertex[0], sizeof(ST_PC_VERTEX));
//}
//
//void cMainGame::Setup_Tri()
//{
//	ST_PC_VERTEX v;
//
//	v.c = D3DCOLOR_XRGB(255, 0, 0);
//	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
//	m_vecTriVertex.push_back(v);
//
//	v.c = D3DCOLOR_XRGB(0, 255, 0);
//	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
//	m_vecTriVertex.push_back(v);
//
//	v.c = D3DCOLOR_XRGB(0, 0, 255);
//	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
//	m_vecTriVertex.push_back(v);
//}
//
//void cMainGame::Draw_Tri()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTriVertex.size() / 3,
//		&m_vecTriVertex[0], sizeof(ST_PC_VERTEX));
//}
