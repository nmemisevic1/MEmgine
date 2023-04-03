#include "GraphicsEngine.h"
#include "SwapChain.h"

GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	D3D_DRIVER_TYPE driverTypes[] = { D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_REFERENCE };
	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
	HRESULT result;
	for (UINT index = 0; index < ARRAYSIZE(driverTypes); index++)
	{
		HRESULT result = D3D11CreateDevice(NULL, driverTypes[index], NULL, 0, NULL, 0, D3D11_SDK_VERSION, &mDevice, NULL, &mDeviceContext);
		if (SUCCEEDED(result)) {
			mDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&mDXGIDevice);
			mDXGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&mDXGIAdapter);
			mDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&mDXGIFactory);
			return true;
		}
	}
	return false;
}

bool GraphicsEngine::release()
{
	if (mDeviceContext) mDeviceContext->Release();
	if (mDevice) mDevice->Release();

	return true;
}

SwapChain* GraphicsEngine::createSwapChain()
{
	return new SwapChain();
}

GraphicsEngine* GraphicsEngine::getInstance()
{
	static GraphicsEngine instance;
	return &instance;
}
