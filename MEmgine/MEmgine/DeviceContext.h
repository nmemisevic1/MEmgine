#pragma once
#include <d3d11.h>

class SwapChain;
class VertexBuffer;

class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* deviceContext);
	~DeviceContext();

	bool Init();
	bool Release();

	
public:
	void setVertexBuffer(VertexBuffer* vertexBuffer);
	bool clearRenderTargetColor(SwapChain* swapChain, float red, float green, float blue, float alpha);
	void drawTriangleList(UINT sizeList, UINT startVertexIndex);
	void setViewportSize(UINT width, UINT height);

private:
	ID3D11DeviceContext* mDeviceContext;
};

