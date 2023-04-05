#pragma once

#include <d3d11.h>

class GraphicsEngine;
class DeviceContext;

class PixelShader
{

public:
	PixelShader();
	~PixelShader();
	bool init(const void* shaderByteCode, size_t sizeByteCode);

	bool release();

private:
	ID3D11PixelShader* mPixelShader;

private:
	friend class GraphicsEngine;
	friend class DeviceContext;
};

