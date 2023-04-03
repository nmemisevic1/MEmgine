#include "DeviceContext.h"
#include "SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* deviceContext): mDeviceContext(deviceContext)
{
}

DeviceContext::~DeviceContext()
{
}

bool DeviceContext::Init()
{
	return false;
}

bool DeviceContext::Release()
{
	mDeviceContext->Release();
	delete this;
	return true;
}

bool DeviceContext::clearRenderTargetColor(SwapChain* swapChain, float red, float green, float blue, float alpha)
{
	FLOAT color[4] = { red, green, blue, alpha };
	mDeviceContext->ClearRenderTargetView(swapChain->mRenderTargetView, color);

	return true;
}
