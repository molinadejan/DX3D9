#pragma once

class cCamera;
class cCubePC;
class cGrid;

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	cCubePC*  m_pCubePC;
	cCamera*  m_pCamera;
	cGrid*	  m_pGrid;

public:
	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	/*void Setup_Line();
	void Draw_Line();

	void Setup_Tri();
	void Draw_Tri();*/
};

