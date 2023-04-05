#pragma once

#include <d3d11.h>

class GraphicsEngine;
class DeviceContext;

class VertexShader
{

public:
	VertexShader();
	~VertexShader();
	bool init(const void* shaderByteCode, size_t sizeByteCode);
	
	bool release();

private:
	ID3D11VertexShader* mVertexShader;

private:
	friend class GraphicsEngine;
	friend class DeviceContext;
};

