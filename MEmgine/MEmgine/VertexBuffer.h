#pragma once
#include <d3d11.h>

class DeviceContext;

class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	bool load(void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader);
	bool release();
	UINT getSizeVertexList();

private:
	UINT sizeVertex;
	UINT sizeList;

private:
	ID3D11Buffer* mBuffer;
	ID3D11InputLayout* mLayout;

private:
	friend class DeviceContext;
};

