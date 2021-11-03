#pragma once
#include "framework.h"

class iMap;

class cCharacter
{
public:
	cCharacter();
	virtual ~cCharacter();

protected:
	float m_fRotY;
	D3DXVECTOR3 m_vDirection;
	D3DXVECTOR3 m_vPosition;
	D3DXMATRIXA16 m_matWorld;

	iMap* m_pMap;

public:
	virtual void Setup();
	virtual void Update(iMap* map);
	virtual void Render();
	virtual D3DXVECTOR3& GetPosition();
};

