#pragma once

class cCamera;
class cCubePC;
class cGrid;
class cCubeMan;
class cGroup;
class cObject;
class cObjMap;
class iMap;

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	cCubePC*  m_pCubePC;
	cCamera*  m_pCamera;
	cGrid*	  m_pGrid;
	cCubeMan* m_pCubeMan;
	std::vector<cGroup*> m_vecGroup;

	LPDIRECT3DTEXTURE9 m_pTexture;
	std::vector<ST_PT_VERTEX> m_vecVertex;
	std::vector<cGroup*>      m_vecMap;

	iMap* m_pMap;

public:
	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetLight();
	void SetTexture();
	/*void Setup_Line();
	void Draw_Line();

	void Setup_Tri();
	void Draw_Tri();*/

	void DrawTexture();

	void Setup_Obj();
	void Setup_Map();

	void Draw_Obj();
	void Draw_Map();

	void Setup_Surface();
};

