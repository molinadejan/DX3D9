#pragma once

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	std::vector<ST_PC_VERTEX> m_vecLineVertex;
	std::vector<ST_PC_VERTEX> m_vecTriVertex;

public:
	void Setup();
	void Update();
	void Render();

	void Setup_Line();
	void Draw_Line();

	void Setup_Tri();
	void Draw_Tri();
};

