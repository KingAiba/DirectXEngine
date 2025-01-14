////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_

//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <directxmath.h>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace DirectX;
using namespace std;

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: ModelClass
////////////////////////////////////////////////////////////////////////////////
class  ModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		//XMFLOAT4 color;
		XMFLOAT2 texture;
		XMFLOAT3 normal;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*, char*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	ID3D11ShaderResourceView* GetTexture();

	void ApplyTransformations(XMMATRIX translation, XMMATRIX scale, float rotation);
	XMMATRIX GetTransform();

	XMMATRIX GetPosition();
	XMMATRIX GetScale();
	float GetRotation();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void ReleaseTexture();

	bool LoadModel(char*);
	bool LoadObjModel(char*);
	void ReleaseModel();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass* m_Texture;

	ModelType* m_model;
	unsigned long* m_modelIndices;

	XMMATRIX m_position;
	XMMATRIX m_scale;
	float m_rotation;
};

#endif