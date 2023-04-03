#pragma once
#include <d3d11.h>

class SwapChain;

class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* deviceContext);
	~DeviceContext();

	bool Init();
	bool Release();

	
public:
	bool clearRenderTargetColor(SwapChain* swapChain, float red, float green, float blue, float alpha);


private:
	ID3D11DeviceContext* mDeviceContext;
};

