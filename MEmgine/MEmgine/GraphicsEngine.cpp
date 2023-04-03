#include "GraphicsEngine.h"

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

	for (UINT index = 0; index < ARRAYSIZE(driverTypes); index++)
	{
		HRESULT result = D3D11CreateDevice(NULL, driverTypes[index], NULL, 0, NULL, 0, D3D11_SDK_VERSION, &mDevice, NULL, &mDeviceContext);
		if (SUCCEEDED(result)) return true;
	}
	return false;
}

bool GraphicsEngine::release()
{
	if (mDeviceContext) mDeviceContext->Release();
	if (mDevice) mDevice->Release();

	return true;
}

GraphicsEngine* GraphicsEngine::getInstance()
{
	static GraphicsEngine* instance = new GraphicsEngine();
	return instance;
}
